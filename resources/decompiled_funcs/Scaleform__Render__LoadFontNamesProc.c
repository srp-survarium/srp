int __stdcall Scaleform::Render::LoadFontNamesProc(
        Scaleform::String lpelfe,
        tagNEWTEXTMETRICEXW *__formal,
        unsigned int a3,
        Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *lParam)
{
  void *v4; // esi
  Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeRef key; // [esp+4h] [ebp-8h] BYREF

  Scaleform::String::String(&lpelfe, (const wchar_t *)lpelfe.pData[7].Data);
  key.pFirst = &lpelfe;
  key.pSecond = &lpelfe;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeRef>(
    lParam,
    lParam,
    &key);
  v4 = (void *)(lpelfe.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((lpelfe.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4);
  return 1;
}
