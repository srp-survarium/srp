void __thiscall Scaleform::GFx::ASStringManager::ReleaseBuiltinArray(
        Scaleform::GFx::ASStringManager *this,
        Scaleform::GFx::ASStringNodeHolder *nodes,
        unsigned int count)
{
  unsigned int v3; // ebx
  Scaleform::GFx::ASStringNodeHolder *v4; // ebp
  Scaleform::GFx::ASStringNodeHolder *pNode; // esi
  Scaleform::GFx::ASStringNode *v7; // ecx
  Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > > *v8; // ecx
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::ASStringNode *v10; // edi

  v3 = 0;
  if ( count )
  {
    v4 = nodes;
    do
    {
      pNode = (Scaleform::GFx::ASStringNodeHolder *)v4[v3].pNode;
      if ( pNode[3].pNode-- == (Scaleform::GFx::ASStringNode *)1 )
      {
        v7 = pNode[2].pNode;
        if ( v7 != (Scaleform::GFx::ASStringNode *)pNode && v7 )
          Scaleform::GFx::ASStringNode::Release(v7);
        v8 = (Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > > *)&pNode[1].pNode->8;
        nodes = pNode;
        Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::RemoveAlt<Scaleform::GFx::ASStringNode *>(
          v8,
          (Scaleform::GFx::ASStringNode *const *)&nodes);
        v9 = pNode->pNode;
        v10 = pNode[1].pNode;
        if ( pNode->pNode )
        {
          if ( ((int)pNode[4].pNode & 0x40000000) == 0 )
          {
            if ( pNode[5].pNode >= (Scaleform::GFx::ASStringNode *)0xC )
            {
              Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pNode->pNode);
            }
            else
            {
              v9->pData = v10[1].pData;
              v10[1].pData = (const char *)v9;
            }
          }
          pNode->pNode = 0;
        }
        pNode[2].pNode = (Scaleform::GFx::ASStringNode *)v10->HashFlags;
        v10->HashFlags = (unsigned int)pNode;
      }
      v4[v3++].pNode = 0;
    }
    while ( v3 < count );
  }
}
