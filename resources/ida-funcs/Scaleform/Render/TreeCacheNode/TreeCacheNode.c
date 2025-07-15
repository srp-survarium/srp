void __thiscall Scaleform::Render::TreeCacheNode::TreeCacheNode(
        Scaleform::Render::TreeCacheNode *this,
        Scaleform::Render::TreeNode *pnode,
        Scaleform::Render::Renderer2DImpl *prenderer2D,
        unsigned __int16 flags)
{
  this->pNode = pnode;
  this->pRenderer2D = prenderer2D;
  this->__vftable = (Scaleform::Render::TreeCacheNode_vtbl *)&Scaleform::Render::TreeCacheNode::`vftable';
  this->pRoot = 0;
  this->pParent = 0;
  this->Effects.pEffect = 0;
  this->Depth = 0;
  this->pMask = 0;
  this->Flags = flags;
  this->UpdateFlags = (unsigned int)&Scaleform::Render::D3D1x::pBinary_D3D1xFL1x_FBox2FullShadowHighlight[1376];
  this->pNextUpdate = 0;
  this->SortParentBounds.x1 = 0.0;
  this->SortParentBounds.y1 = 0.0;
  this->SortParentBounds.x2 = 0.0;
  this->SortParentBounds.y2 = 0.0;
  this->pNext = 0;
  this->pPrev = 0;
}
