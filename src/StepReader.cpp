#include <iostream>

#include <StepReader.hpp>

#include <STEPControl_Reader.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepTools.hxx>
#include <StepData_StepModel.hxx>
#include <Interface_EntityIterator.hxx>
#include <Standard_Transient.hxx>
#include <TDF_Label.hxx>
#include <StepRepr_NextAssemblyUsageOccurrence.hxx>
#include <StepBasic_Product.hxx>
#include <StepBasic_ProductDefinition.hxx>
#include <StepBasic_ProductDefinitionFormation.hxx>
#include <StepBasic_ProductDefinitionRelationship.hxx>
#include <TCollection_AsciiString.hxx>
#include <TCollection_HAsciiString.hxx>
#include <TCollection_ExtendedString.hxx>
#include <GProp_GProps.hxx>
#include <BRepGProp.hxx>
#include <gp_Pnt.hxx>
#include <BRepBndLib.hxx>
#include <Bnd_OBB.hxx>

#include <TopExp.hxx>
#include <BRepExtrema_ShapeProximity.hxx>
#include <TopoDS_Builder.hxx>

class FileDialog {
 private:
  /* data */
 public:
  FileDialog(/* args */) {}
  ~FileDialog() {}
};

class Geometry {
 public:
  Geometry(/* args */) {}
  ~Geometry() {}

 private:
  std::string name;
};

StepReader::StepReader(const std::string& file_name) : file_name_(file_name) {
  STEPControl_Reader reader; 
  IFSelect_ReturnStatus stat = reader.ReadFile(file_name_.c_str());
  switch (stat)
  {
  case IFSelect_RetVoid:
  case IFSelect_RetDone:
    succeeded_ = true;
    break;
  
  default:
    succeeded_ = false;
    break;
  }

  bool show_error_fails_only = true;
  IFSelect_PrintCount mode = IFSelect_CountByItem;
  reader.PrintCheckLoad(show_error_fails_only, mode);

  // Standard_Integer nb_roots = reader.NbRootsForTransfer();
  // std::cout << "Number of roots in STEP file: " << nb_roots << std::endl;
  // Standard_Integer nb_trans = reader.TransferRoots();
  // std::cout << "STEP roots transferred: " << nb_trans << std::endl;
  // std::cout << "Number of resulting shapes is: " << reader.NbShapes() << std::endl;
  // reader.PrintCheckTransfer(show_error_fails_only, mode);

  Handle(Standard_Type) tPD  = STANDARD_TYPE(StepBasic_ProductDefinition);
  Handle(TCollection_HAsciiString) name;

  Interface_EntityIterator iter = reader.StepModel().get()->Entities();
  for (iter.Start(); iter.More(); iter.Next())
  {
    reader.ClearShapes();
    Handle(Standard_Transient) enti = iter.Value();
    // for PD get name of associated product
    if (enti->DynamicType() == tPD) {
      Handle(StepBasic_ProductDefinition) PD = Handle(StepBasic_ProductDefinition)::DownCast(enti);
      if(PD.IsNull()) continue;
      Handle(StepBasic_Product) Prod = (!PD->Formation().IsNull() ? PD->Formation()->OfProduct() : NULL);
      reader.TransferEntity(enti);
      TopoDS_Shape shape = reader.OneShape();
      if (Prod.IsNull())
        name = new TCollection_HAsciiString;
      else if (!Prod->Name().IsNull() && Prod->Name()->UsefullLength() > 0) 
        name = Prod->Name();
      else if (!Prod->Id().IsNull()) 
        name = Prod->Id();
      else 
        name = new TCollection_HAsciiString;
      TCollection_ExtendedString str(name->String());
      std::cout << str << std::endl;
      GProp_GProps propertiesSystemFace;
      BRepGProp::VolumePropertiesGK(shape, propertiesSystemFace);
      double shapeVolume = propertiesSystemFace.Mass();
      gp_Pnt centerOfMass = propertiesSystemFace. CentreOfMass();
      std::cout << shapeVolume <<std::endl;
      std::cout << centerOfMass.X() << " " << centerOfMass.Y() << " " << centerOfMass.Z() <<std::endl;

      Bnd_OBB box;
      BRepBndLib bndlib;
      bndlib.AddOBB(shape, box);
      std::cout << box.XHSize() << " " << box.YHSize() << " " << box.ZHSize() <<std::endl;
    }
  }

}

StepReader::~StepReader() {}