void __cdecl Scaleform::ConstructorMov<Scaleform::Render::Text::StyledText::HTMLImageTagInfo>::DestructArray(
        Scaleform::Render::Text::StyledText::HTMLImageTagInfo *p,
        unsigned int count)
{
  Scaleform::Render::Text::StyledText::HTMLImageTagInfo *v2; // edi
  unsigned int v3; // ebp
  volatile LONG *v4; // esi
  volatile LONG *v5; // esi

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      v4 = (volatile LONG *)(v2->Id.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(v4 + 1, -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
      v5 = (volatile LONG *)(v2->Url.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(v5 + 1, -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v5);
      if ( v2->pTextImageDesc.pObject )
        Scaleform::RefCountNTSImpl::Release(v2->pTextImageDesc.pObject);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}
