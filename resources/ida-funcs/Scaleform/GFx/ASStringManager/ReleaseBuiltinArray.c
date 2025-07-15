void __thiscall Scaleform::GFx::ASStringManager::ReleaseBuiltinArray(
        Scaleform::GFx::ASStringManager *this,
        Scaleform::GFx::ASStringNode *nodes,
        unsigned int count)
{
  unsigned int v3; // ebx
  Scaleform::GFx::ASStringNode *v4; // ebp
  Scaleform::GFx::ASStringNode *v5; // esi
  Scaleform::GFx::ASStringNode *pLower; // ecx
  Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > > *p_StringSet; // ecx
  char *pData; // eax
  Scaleform::GFx::ASStringManager *pManager; // edi

  v3 = 0;
  if ( count )
  {
    v4 = nodes;
    do
    {
      v5 = (Scaleform::GFx::ASStringNode *)*((_DWORD *)&v4->pData + v3);
      if ( v5->RefCount-- == 1 )
      {
        pLower = v5->pLower;
        if ( pLower != v5 && pLower )
          Scaleform::GFx::ASStringNode::Release(pLower);
        p_StringSet = &v5->pManager->StringSet;
        nodes = v5;
        Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::RemoveAlt<Scaleform::GFx::ASStringNode *>(
          p_StringSet,
          &nodes);
        pData = (char *)v5->pData;
        pManager = v5->pManager;
        if ( v5->pData )
        {
          if ( (v5->HashFlags & 0x40000000) == 0 )
          {
            if ( v5->Size >= 0xC )
            {
              Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v5->pData);
            }
            else
            {
              *(_DWORD *)pData = pManager->pFreeTextBuffers;
              pManager->pFreeTextBuffers = (Scaleform::GFx::ASStringManager::TextPage::Entry *)pData;
            }
          }
          v5->pData = 0;
        }
        v5->pLower = pManager->pFreeStringNodes;
        pManager->pFreeStringNodes = v5;
      }
      *((_DWORD *)&v4->pData + v3++) = 0;
    }
    while ( v3 < count );
  }
}
