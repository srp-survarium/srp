void __thiscall Scaleform::Render::MorphShapeData::MorphShapeData(
        Scaleform::Render::MorphShapeData *this,
        Scaleform::GFx::Resource *morphTo)
{
  this->__vftable = (Scaleform::Render::MorphShapeData_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::MorphShapeData_vtbl *)&Scaleform::Render::MorphShapeData::`vftable';
  if ( morphTo )
    Scaleform::RefCountImpl::AddRef(morphTo);
  this->pMorphTo.pObject = (Scaleform::Render::ShapeDataInterface *)morphTo;
  this->Container1.Data.Data = 0;
  this->Container1.Data.Size = 0;
  this->Container1.Data.Policy.Capacity = 0;
  this->Container2.Data.Data = 0;
  this->Container2.Data.Size = 0;
  this->Container2.Data.Policy.Capacity = 0;
  this->ShapeData1.__vftable = (Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> >_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->ShapeData1.Status = Status_Clean;
  this->ShapeData1.RefCount = 1;
  this->ShapeData1.__vftable = (Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> >_vtbl *)&Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::`vftable';
  this->ShapeData1.Fills.Data.Data = 0;
  this->ShapeData1.Fills.Data.Size = 0;
  this->ShapeData1.Fills.Data.Policy.Capacity = 0;
  this->ShapeData1.Strokes.Data.Data = 0;
  this->ShapeData1.Strokes.Data.Size = 0;
  this->ShapeData1.Strokes.Data.Policy.Capacity = 0;
  this->ShapeData1.StartX = 0.0;
  this->ShapeData1.StartY = 0.0;
  this->ShapeData1.Data = &this->Container1;
  this->ShapeData1.LastX = 0.0;
  this->ShapeData1.StartingPos = 0;
  this->ShapeData1.LastY = 0.0;
  this->ShapeData2.__vftable = (Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> >_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->ShapeData2.Status = Status_Clean;
  this->ShapeData2.RefCount = 1;
  this->ShapeData2.__vftable = (Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> >_vtbl *)&Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::`vftable';
  this->ShapeData2.Fills.Data.Data = 0;
  this->ShapeData2.Fills.Data.Size = 0;
  this->ShapeData2.Fills.Data.Policy.Capacity = 0;
  this->ShapeData2.Strokes.Data.Data = 0;
  this->ShapeData2.Strokes.Data.Size = 0;
  this->ShapeData2.Strokes.Data.Policy.Capacity = 0;
  this->ShapeData2.StartX = 0.0;
  this->ShapeData2.StartY = 0.0;
  this->ShapeData2.StartingPos = 0;
  this->ShapeData2.LastX = 0.0;
  this->ShapeData2.LastY = 0.0;
  this->ShapeData2.Data = &this->Container2;
}
