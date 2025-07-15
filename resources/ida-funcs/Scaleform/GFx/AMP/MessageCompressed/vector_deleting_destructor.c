Scaleform::GFx::AMP::MessageCompressed *__thiscall Scaleform::GFx::AMP::MessageCompressed::`vector deleting destructor'(
        Scaleform::GFx::AMP::MessageCompressed *this,
        char a2)
{
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->CompressedData.Data.Data);
  this->__vftable = (Scaleform::GFx::AMP::MessageCompressed_vtbl *)&Scaleform::GFx::AMP::Message::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
