Scaleform::Render::GlyphShape *__thiscall Scaleform::GFx::DrawingContext::PackedShape::`vector deleting destructor'(
        Scaleform::Render::GlyphShape *this,
        char a2)
{
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data.Data.Data);
  Scaleform::ConstructorMov<Scaleform::Render::StrokeStyleType>::DestructArray(
    this->StrokeStyles.Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data,
    this->StrokeStyles.Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(
    Scaleform::Memory::pGlobalHeap,
    this->StrokeStyles.Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data);
  Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy>(&this->FillStyles.Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
