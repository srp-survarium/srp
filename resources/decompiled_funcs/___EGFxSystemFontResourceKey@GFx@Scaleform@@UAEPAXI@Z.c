Scaleform::GFx::GFxSystemFontResourceKey *__thiscall Scaleform::GFx::GFxSystemFontResourceKey::`vector deleting destructor'(
        Scaleform::GFx::GFxSystemFontResourceKey *this,
        char a2)
{
  volatile LONG *v3; // esi
  Scaleform::RefCountVImpl *pObject; // ecx

  v3 = (volatile LONG *)(this->FontName.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  pObject = (Scaleform::RefCountVImpl *)this->pFontProvider.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
