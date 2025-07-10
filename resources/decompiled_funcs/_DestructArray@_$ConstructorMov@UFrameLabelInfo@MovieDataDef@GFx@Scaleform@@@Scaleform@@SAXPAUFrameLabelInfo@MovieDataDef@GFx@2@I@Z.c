void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::MovieDataDef::FrameLabelInfo>::DestructArray(
        Scaleform::GFx::MovieDataDef::FrameLabelInfo *p,
        unsigned int count)
{
  Scaleform::GFx::MovieDataDef::FrameLabelInfo *v2; // edi
  unsigned int v3; // ebp
  volatile LONG *v4; // esi

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      v4 = (volatile LONG *)(v2->Name.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(v4 + 1, -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}
