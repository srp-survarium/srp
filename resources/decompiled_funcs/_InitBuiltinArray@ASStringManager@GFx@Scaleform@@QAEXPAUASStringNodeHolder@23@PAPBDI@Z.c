void __thiscall Scaleform::GFx::ASStringManager::InitBuiltinArray(
        Scaleform::GFx::ASStringManager *this,
        Scaleform::GFx::ASStringNodeHolder *nodes,
        const char **strings,
        unsigned int count)
{
  Scaleform::GFx::ASStringNodeHolder *v4; // edi
  const char **v5; // ebx
  Scaleform::GFx::ASStringNodeHolder *ConstStringNode; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > > *v9; // ecx
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::ASStringNode *v11; // ebx

  if ( count )
  {
    v4 = nodes;
    v5 = (const char **)((char *)strings - (char *)nodes);
    strings = (const char **)((char *)strings - (int)nodes);
    do
    {
      ConstStringNode = (Scaleform::GFx::ASStringNodeHolder *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                                this,
                                                                *(char **)((char *)&v4->pNode + (_DWORD)v5),
                                                                strlen(*(const char **)((char *)&v4->pNode + (_DWORD)v5)),
                                                                0x80000000);
      ++ConstStringNode[3].pNode;
      v4->pNode = (Scaleform::GFx::ASStringNode *)ConstStringNode;
      ++ConstStringNode[3].pNode;
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v4->pNode);
      if ( ConstStringNode[3].pNode-- == (Scaleform::GFx::ASStringNode *)1 )
      {
        pNode = ConstStringNode[2].pNode;
        if ( pNode != (Scaleform::GFx::ASStringNode *)ConstStringNode && pNode )
          Scaleform::GFx::ASStringNode::Release(pNode);
        v9 = (Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > > *)&ConstStringNode[1].pNode->8;
        nodes = ConstStringNode;
        Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::RemoveAlt<Scaleform::GFx::ASStringNode *>(
          v9,
          (Scaleform::GFx::ASStringNode *const *)&nodes);
        v10 = ConstStringNode->pNode;
        v11 = ConstStringNode[1].pNode;
        if ( ConstStringNode->pNode )
        {
          if ( ((int)ConstStringNode[4].pNode & 0x40000000) == 0 )
          {
            if ( ConstStringNode[5].pNode >= (Scaleform::GFx::ASStringNode *)0xC )
            {
              Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ConstStringNode->pNode);
            }
            else
            {
              v10->pData = v11[1].pData;
              v11[1].pData = (const char *)v10;
            }
          }
          ConstStringNode->pNode = 0;
        }
        ConstStringNode[2].pNode = (Scaleform::GFx::ASStringNode *)v11->HashFlags;
        v11->HashFlags = (unsigned int)ConstStringNode;
        v5 = strings;
      }
      ++v4;
      --count;
    }
    while ( count );
  }
}
