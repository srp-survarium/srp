void __thiscall Scaleform::Render::MorphShapeData::~MorphShapeData(Scaleform::Render::MorphShapeData *this)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  Scaleform::ConstructorMov<Scaleform::Render::StrokeStyleType>::DestructArray(
    this->ShapeData2.Strokes.Data.Data,
    this->ShapeData2.Strokes.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->ShapeData2.Strokes.Data.Data);
  Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy>(&this->ShapeData2.Fills.Data);
  Scaleform::RefCountImplCore::~RefCountImplCore(&this->ShapeData2);
  Scaleform::ConstructorMov<Scaleform::Render::StrokeStyleType>::DestructArray(
    this->ShapeData1.Strokes.Data.Data,
    this->ShapeData1.Strokes.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->ShapeData1.Strokes.Data.Data);
  Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy>(&this->ShapeData1.Fills.Data);
  Scaleform::RefCountImplCore::~RefCountImplCore(&this->ShapeData1);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Container2.Data.Data);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Container1.Data.Data);
  pObject = (Scaleform::RefCountVImpl *)this->pMorphTo.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
