void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::MovieDataDef::SceneInfo>::DestructArray(
        Scaleform::GFx::MovieDataDef::SceneInfo *p,
        unsigned int count)
{
  Scaleform::GFx::MovieDataDef::SceneInfo *v2; // esi
  unsigned int v3; // ebp
  volatile LONG *v4; // edi

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      Scaleform::ConstructorMov<Scaleform::GFx::MovieDataDef::FrameLabelInfo>::DestructArray(
        v2->Labels.Data.Data,
        v2->Labels.Data.Size);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v2->Labels.Data.Data);
      v4 = (volatile LONG *)(v2->Name.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(v4 + 1, -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}
