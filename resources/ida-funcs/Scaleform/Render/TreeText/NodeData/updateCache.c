Scaleform::Render::TreeCacheNode *__thiscall Scaleform::Render::TreeText::NodeData::updateCache(
        Scaleform::Render::TreeText::NodeData *this,
        Scaleform::Render::TreeCacheNode *pparent,
        Scaleform::Render::TreeCacheNode *pinsert,
        Scaleform::Render::TreeText *pnode,
        unsigned __int16 depth)
{
  Scaleform::Render::TreeCacheNode *pRenderer; // esi
  Scaleform::Render::TreeCacheNode *v6; // esi
  int v7; // ebp
  bool v8; // bl
  unsigned int v9; // ecx
  int v10; // edi
  Scaleform::Render::TreeCacheText *v11; // eax
  Scaleform::Render::TreeCacheNode *v12; // eax
  int v14; // [esp+10h] [ebp-8h] BYREF
  Scaleform::Render::TreeText::NodeData *v15; // [esp+14h] [ebp-4h]

  pRenderer = pnode->pRenderer;
  v15 = this;
  if ( !pRenderer )
  {
    v6 = pparent;
    v7 = this->Flags & 0x21 | ((unsigned __int8)pparent->Flags | (unsigned __int8)(2 * (this->Flags & 0x20))) & 0xC0;
    v8 = 0;
    do
    {
      if ( v8 )
        break;
      v9 = (int)v6->pNode & 0xFFFFF000;
      v10 = (int)&v6->pNode[-1] - v9;
      v6 = v6->pParent;
      v8 = (*(_WORD *)((*(_DWORD *)(*(_DWORD *)(v9 + 20) + 4 * (v10 / 28) + 20) & 0xFFFFFFFE) + 6) & 0x200) != 0;
    }
    while ( v6 );
    v14 = 74;
    v11 = (Scaleform::Render::TreeCacheText *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                Scaleform::Memory::pGlobalHeap,
                                                pparent,
                                                288,
                                                &v14);
    if ( !v11 )
      return 0;
    Scaleform::Render::TreeCacheText::TreeCacheText(v11, pnode, pparent->pRenderer2D, v7 | (v8 ? 0x200 : 0));
    pRenderer = v12;
    if ( !v12 )
      return 0;
    this = v15;
    pnode->pRenderer = v12;
  }
  Scaleform::Render::TreeCacheNode::UpdateInsertIntoParent(pRenderer, pparent, pinsert, this, depth);
  return pRenderer;
}
