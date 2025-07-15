Scaleform::Render::TreeCacheNode *__thiscall Scaleform::Render::TreeShape::NodeData::updateCache(
        Scaleform::Render::TreeShape::NodeData *this,
        Scaleform::Render::TreeCacheNode *pparent,
        Scaleform::Render::TreeCacheNode *pinsert,
        int pnode,
        int depth)
{
  Scaleform::Render::TreeShape *v5; // ebx
  Scaleform::Render::TreeCacheNode *v6; // esi
  Scaleform::Render::ShapeMeshProvider *v7; // ebp
  int v8; // eax
  __int16 v9; // cx
  __int16 v10; // si
  Scaleform::Render::TreeCacheShape *v11; // eax
  Scaleform::Render::TreeCacheNode *v12; // eax

  v5 = (Scaleform::Render::TreeShape *)pnode;
  v6 = *(Scaleform::Render::TreeCacheNode **)(pnode + 12);
  if ( v6 )
    goto LABEL_17;
  v7 = *(Scaleform::Render::ShapeMeshProvider **)((*(_DWORD *)(*(_DWORD *)((pnode & 0xFFFFF000) + 0x14)
                                                             + 4 * ((int)(pnode - (pnode & 0xFFFFF000) - 28) / 28)
                                                             + 20)
                                                 & 0xFFFFFFFE)
                                                + 144);
  pnode = v7->GetLayerCount(&v7->Scaleform::Render::MeshProvider);
  if ( !pparent )
  {
    LOWORD(v8) = 4;
LABEL_6:
    v9 = this->Flags & 0xC;
    if ( (this->Flags & 0xC) == 0 )
      v9 = v8;
    goto LABEL_8;
  }
  v8 = pparent->Flags & 0xC;
  if ( v8 != 12 )
    goto LABEL_6;
  v9 = 12;
LABEL_8:
  v10 = v9
      | this->Flags & 0x221
      | ((unsigned __int8)pparent->Flags | (unsigned __int8)(2 * (this->Flags & 0x20))) & 0xC0;
  if ( Scaleform::Render::StateBag::GetState(&this->States, State_Log) )
    v10 |= 0x80u;
  if ( pnode == 1 )
  {
    v12 = Scaleform::Render::TreeCacheShapeLayer::Create(
            (int)pparent,
            pparent,
            v7,
            0,
            v10,
            v5,
            COERCE_SCALEFORM_RENDER_TREESHAPE_(this->MorphRatio));
  }
  else
  {
    pnode = 74;
    v11 = (Scaleform::Render::TreeCacheShape *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 pparent,
                                                 112,
                                                 &pnode);
    if ( !v11 )
      return 0;
    Scaleform::Render::TreeCacheShape::TreeCacheShape(v11, v5, pparent->pRenderer2D, v10);
  }
  v6 = v12;
  if ( !v12 )
    return 0;
  v5->pRenderer = v12;
LABEL_17:
  Scaleform::Render::TreeCacheNode::UpdateInsertIntoParent(v6, pparent, pinsert, this, depth);
  return v6;
}
