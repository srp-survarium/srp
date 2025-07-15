void __thiscall Scaleform::Render::Renderer2DImpl::EntryChanges(
        Scaleform::Render::Renderer2DImpl *this,
        Scaleform::Render::ContextImpl::Context *context,
        Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,126> *cb,
        bool forceUpdateImages)
{
  Scaleform::Render::Renderer2DImpl *v4; // ebp
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,126>::Page *v5; // ecx
  $1E231573BF54D36D8D040C7EE0E1266F *v6; // ebp
  unsigned int ChangeBits; // eax
  int v8; // esi
  Scaleform::Render::TreeCacheRoot *v9; // edi
  unsigned int v10; // ebx
  unsigned int v11; // eax
  Scaleform::Render::TreeCacheNode *v12; // eax
  bool v13; // bl
  _RTL_CRITICAL_SECTION *p_cs; // edi
  Scaleform::Render::Renderer2DImpl *i; // esi
  Scaleform::Render::TreeCacheRoot *pNext; // esi
  Scaleform::List<Scaleform::Render::TreeCacheNode,Scaleform::Render::TreeCacheNode> *p_RenderRoots; // ebp
  int v18; // eax
  Scaleform::Render::TreeCacheRoot *v19; // [esp+10h] [ebp-Ch]
  unsigned int v20; // [esp+14h] [ebp-8h]
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,126>::Page *pPages; // [esp+24h] [ebp+8h]

  v4 = this;
  pPages = cb->pPages;
  if ( !pPages )
    goto LABEL_29;
  do
  {
    v5 = pPages;
    v20 = 0;
    if ( !pPages->Count )
      goto LABEL_28;
    v6 = &pPages->Items[0].4;
    do
    {
      ChangeBits = v6[-1].ChangeBits;
      if ( !ChangeBits )
        goto LABEL_26;
      v8 = *(_DWORD *)(ChangeBits + 12);
      if ( !v8 )
        goto LABEL_26;
      if ( (v6->ChangeBits & 0x3730) != 0 )
        (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v8 + 4))(v8, v6->ChangeBits);
      v9 = *(Scaleform::Render::TreeCacheRoot **)(v8 + 24);
      v19 = v9;
      if ( ((unsigned int)&Scaleform::Render::D3D1x::pBinary_D3D1xFL1x_FBox2FullShadowHighlight[1516] & v6->ChangeBits) == 0 )
        goto LABEL_21;
      v10 = 0;
      if ( (v6->ChangeBits & 4) != 0 )
      {
        v9 = *(Scaleform::Render::TreeCacheRoot **)(v8 + 24);
        v10 = 0x1000000;
        *(_WORD *)(v8 + 50) ^= (*(_WORD *)(v8 + 50)
                              ^ *(_WORD *)((*(_DWORD *)(*(_DWORD *)((*(_DWORD *)(v8 + 28) & 0xFFFFF000) + 0x14)
                                                      + 4
                                                      * ((int)(*(_DWORD *)(v8 + 28)
                                                             - (*(_DWORD *)(v8 + 28) & 0xFFFFF000)
                                                             - 28)
                                                       / 28)
                                                      + 20)
                                          & 0xFFFFFFFE)
                                         + 6))
                             & 1;
      }
      if ( (v6->ChangeBits & 0x40000) != 0 )
      {
        Scaleform::Render::TreeCacheNode::updateMaskCache(
          (Scaleform::Render::TreeCacheNode *)v8,
          (const Scaleform::Render::TreeNode::NodeData *)(*(_DWORD *)(*(_DWORD *)((*(_DWORD *)(v8 + 28) & 0xFFFFF000)
                                                                                + 0x14)
                                                                    + 4
                                                                    * ((int)(*(_DWORD *)(v8 + 28)
                                                                           - (*(_DWORD *)(v8 + 28) & 0xFFFFF000)
                                                                           - 28)
                                                                     / 28)
                                                                    + 20)
                                                        & 0xFFFFFFFE),
          (unsigned __int16)(*(_WORD *)(v8 + 48) + 1),
          0);
        v9 = v19;
      }
      if ( (v6->ChangeBits & 8) != 0 )
        v10 |= 0x2000000u;
      v11 = (unsigned int)&Scaleform::Render::D3D1x::pBinary_D3D1xFL1x_FBox2FullShadowHighlight[1376] & v6->ChangeBits;
      if ( v11 )
      {
        *(_DWORD *)(v8 + 52) |= v11;
        v10 |= 0x1000000u;
      }
      if ( v9 )
      {
        if ( v10 )
        {
          v12 = *(Scaleform::Render::TreeCacheNode **)(v8 + 36);
          if ( v12 )
            Scaleform::Render::TreeCacheRoot::AddToUpdate(v9, v12, v10);
        }
LABEL_21:
        if ( v9 )
        {
          if ( (v6->ChangeBits & 0x12003) != 0 )
          {
            Scaleform::Render::TreeCacheRoot::AddToUpdate(
              v9,
              (Scaleform::Render::TreeCacheNode *)v8,
              v6->ChangeBits & 0x12003);
            if ( (v6->ChangeBits & 1) != 0 && (*(_BYTE *)(v8 + 50) & 0x20) != 0 )
              Scaleform::Render::TreeCacheRoot::AddToUpdate(
                v9,
                *(Scaleform::Render::TreeCacheNode **)(v8 + 36),
                0x2000001u);
          }
        }
      }
LABEL_26:
      v5 = pPages;
      v6 += 2;
      ++v20;
    }
    while ( v20 < pPages->Count );
    v4 = this;
LABEL_28:
    pPages = v5->pNext;
  }
  while ( v5->pNext );
LABEL_29:
  v13 = forceUpdateImages;
  if ( forceUpdateImages )
  {
    p_cs = &v4->pMeshKeyManager.pObject->KeySetLock.cs;
    EnterCriticalSection(p_cs);
    for ( i = (Scaleform::Render::Renderer2DImpl *)v4->mComplexMeshUpdateList.Root.pNext;
          i != (Scaleform::Render::Renderer2DImpl *)&v4->mComplexMeshUpdateList;
          i = (Scaleform::Render::Renderer2DImpl *)i->ActiveContextSet.Root.Scaleform::Render::ContextImpl::RenderNotify::pPrev )
    {
      Scaleform::Render::ComplexMesh::updateFills((Scaleform::Render::ComplexMesh *)&i[-1].mGlyphCacheParam.TextureHeight);
    }
    LeaveCriticalSection(p_cs);
    v13 = forceUpdateImages;
  }
  pNext = (Scaleform::Render::TreeCacheRoot *)v4->RenderRoots.Root.pNext;
  p_RenderRoots = &v4->RenderRoots;
  while ( 1 )
  {
    v18 = p_RenderRoots ? (int)&p_RenderRoots[-2] : 0;
    if ( pNext == (Scaleform::Render::TreeCacheRoot *)v18 )
      break;
    if ( v13 && Scaleform::Render::ContextImpl::Entry::GetContext(pNext->pNode) == context )
      pNext->forceUpdateImages(pNext);
    Scaleform::Render::TreeCacheRoot::ChainUpdatesByDepth(pNext);
    Scaleform::Render::TreeCacheRoot::UpdateTreeData(pNext);
    pNext = (Scaleform::Render::TreeCacheRoot *)pNext->pNext;
  }
}
