void __thiscall Scaleform::Render::Text::TextFormat::~TextFormat(Scaleform::Render::Text::TextFormat *this)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::Render::Text::HTMLImageTagDesc *v3; // ecx
  volatile LONG *v4; // esi
  volatile LONG *v5; // esi

  pObject = (Scaleform::RefCountVImpl *)this->pFontHandle.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v3 = this->pImageDesc.pObject;
  if ( v3 )
    Scaleform::RefCountNTSImpl::Release(v3);
  v4 = (volatile LONG *)(this->Url.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v4 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
  v5 = (volatile LONG *)(this->FontList.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v5 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v5);
}
