void __thiscall Scaleform::Render::Text::StyledText::HTMLImageTagInfo::~HTMLImageTagInfo(
        Scaleform::Render::Text::StyledText::HTMLImageTagInfo *this)
{
  volatile LONG *v2; // esi
  volatile LONG *v3; // esi

  v2 = (volatile LONG *)(this->Id.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v2 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v2);
  v3 = (volatile LONG *)(this->Url.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  if ( this->pTextImageDesc.pObject )
    Scaleform::RefCountNTSImpl::Release(this->pTextImageDesc.pObject);
}
