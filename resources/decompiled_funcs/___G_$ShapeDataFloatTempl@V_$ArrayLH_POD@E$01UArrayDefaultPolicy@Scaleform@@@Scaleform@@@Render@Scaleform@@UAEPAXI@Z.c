Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *__thiscall Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::`scalar deleting destructor'(
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        char a2)
{
  Scaleform::ConstructorMov<Scaleform::Render::StrokeStyleType>::DestructArray(
    this->Strokes.Data.Data,
    this->Strokes.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Strokes.Data.Data);
  Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy>(&this->Fills.Data);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
