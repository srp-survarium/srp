void __thiscall Scaleform::Render::TreeCacheShape::UpdateChildSubtree(
        Scaleform::Render::TreeCacheShape *this,
        const Scaleform::Render::TreeNode::NodeData *pdata,
        int depth)
{
  int v4; // eax
  Scaleform::Render::TreeCacheNode *p_SortParentBounds; // edx
  unsigned int v6; // ebp
  Scaleform::Render::TreeCacheNode *v7; // esi
  Scaleform::Render::TreeCacheNode *i; // eax
  Scaleform::Render::Rect<float> *v9; // edx
  Scaleform::Render::ShapeMeshProvider *v10; // [esp+18h] [ebp-8h]
  unsigned int v11; // [esp+1Ch] [ebp-4h]
  Scaleform::Render::TreeCacheNode *data; // [esp+24h] [ebp+4h]

  Scaleform::Render::TreeCacheNode::UpdateChildSubtree(this, pdata, depth);
  v10 = (Scaleform::Render::ShapeMeshProvider *)pdata[1].__vftable;
  v4 = v10->GetLayerCount(&v10->Scaleform::Render::MeshProvider);
  v11 = v4;
  if ( this == (Scaleform::Render::TreeCacheShape *)-80 )
    p_SortParentBounds = 0;
  else
    p_SortParentBounds = (Scaleform::Render::TreeCacheNode *)&this->SortParentBounds;
  if ( this->Children.Root.pNext == p_SortParentBounds )
  {
    v6 = 0;
    data = this->Children.Root.pNext->pPrev;
    if ( v4 )
    {
      do
      {
        v7 = Scaleform::Render::TreeCacheShapeLayer::Create(
               (int)this,
               this,
               v10,
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
          Scaleform::Render::TreeCacheNode::UpdateInsertIntoParent(v7, this, data, 0, depth);
          data = v7;
        }
        ++v6;
      }
      while ( v6 < v11 );
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
