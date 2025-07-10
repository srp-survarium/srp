void __thiscall Scaleform::Render::Text::HTMLImageTagDesc::~HTMLImageTagDesc(
        Scaleform::Render::Text::HTMLImageTagDesc *this)
{
  volatile LONG *v2; // esi
  volatile LONG *v3; // esi
  Scaleform::Render::Image *pObject; // ecx

  v2 = (volatile LONG *)(this->Id.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v2 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v2);
  v3 = (volatile LONG *)(this->Url.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  pObject = this->pImage.pObject;
  if ( pObject )
    pObject->Release(pObject);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
}
