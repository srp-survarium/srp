Scaleform::GFx::AMP::ImageInfo *__thiscall Scaleform::GFx::AMP::ImageInfo::`vector deleting destructor'(
        Scaleform::GFx::AMP::ImageInfo *this,
        char a2)
{
  volatile LONG *v3; // esi

  v3 = (volatile LONG *)(this->Name.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
