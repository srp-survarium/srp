Scaleform::Render::ColorMatrixFilter *__thiscall Scaleform::Render::ColorMatrixFilter::`vector deleting destructor'(
        Scaleform::Render::ColorMatrixFilter *this,
        char a2)
{
  this->__vftable = (Scaleform::Render::ColorMatrixFilter_vtbl *)&Scaleform::Render::ColorMatrixFilter::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
