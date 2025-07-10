void __thiscall Scaleform::Render::TreeCacheShape::UpdateChildSubtree(
        Scaleform::Render::TreeCacheShape *this,
        Scaleform::Render::TreeCacheNode *pdata,
        unsigned __int16 depth)
{
  int v4; // eax
  Scaleform::Render::Rect<float> *p_SortParentBounds; // edx
  unsigned int v6; // ebp
  Scaleform::Render::TreeCacheNode *v7; // esi
  Scaleform::Render::TreeCacheNode *i; // eax
  Scaleform::Render::Rect<float> *v9; // edx
  Scaleform::Render::ShapeMeshProvider *meshProvider; // [esp+18h] [ebp-8h]
  unsigned int layerCount; // [esp+1Ch] [ebp-4h]
  Scaleform::Render::TreeCacheNode *pnewInsert; // [esp+24h] [ebp+4h]

  Scaleform::Render::TreeCacheNode::UpdateChildSubtree(
    this,
    (const Scaleform::Render::TreeNode::NodeData *)pdata,
    depth);
  meshProvider = (Scaleform::Render::ShapeMeshProvider *)LODWORD(pdata[1].SortParentBounds.x1);
  v4 = meshProvider->GetLayerCount(&meshProvider->Scaleform::Render::MeshProvider);
  layerCount = v4;
  if ( this == (Scaleform::Render::TreeCacheShape *)-80 )
    p_SortParentBounds = 0;
  else
    p_SortParentBounds = &this->SortParentBounds;
  if ( (Scaleform::Render::Rect<float> *)this->Children.Root.pNext == p_SortParentBounds )
  {
    v6 = 0;
    pnewInsert = this->Children.Root.pNext->pPrev;
    if ( v4 )
    {
      do
      {
        v7 = Scaleform::Render::TreeCacheShapeLayer::Create(
               (int)this,
               this,
               meshProvider,
               v6,
               this->Flags & 0xC | 1,
               0,
               COERCE_SCALEFORM_RENDER_TREESHAPE_(*(float *)((*(_DWORD *)(*(_DWORD *)(((int)this->pNode & 0xFFFFF000)
                                                                                    + 0x14)
                                                                        + 4
                                                                        * ((int)((int)&this->pNode[-1]
                                                                               - ((int)this->pNode & 0xFFFFF000))
                                                                         / 28)
                                                                        + 20)
                                                            & 0xFFFFFFFE)
                                                           + 148)));
        if ( v7 )
        {
          Scaleform::Render::TreeCacheNode::UpdateInsertIntoParent(v7, this, pnewInsert, 0, depth);
          pnewInsert = v7;
        }
        ++v6;
      }
      while ( v6 < layerCount );
    }
  }
  else
  {
    for ( i = this->Children.Root.pNext; ; i = i->pNext )
    {
      v9 = this == (Scaleform::Render::TreeCacheShape *)-80 ? 0 : &this->SortParentBounds;
      if ( i == (Scaleform::Render::TreeCacheNode *)v9 )
        break;
      i->Depth = depth;
      i->pRoot = this->pRoot;
    }
  }
}
