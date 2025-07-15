void __thiscall Scaleform::Render::TreeCacheMeshBase::TreeCacheMeshBase(
        Scaleform::Render::TreeCacheMeshBase *this,
        Scaleform::Render::TreeNode *pnode,
        const Scaleform::Render::SortKey *key,
        Scaleform::Render::Renderer2DImpl *prenderer2D,
        unsigned __int16 flags)
{
  Scaleform::Render::SortKeyInterface *pImpl; // ecx
  void *Data; // eax

  this->pNode = pnode;
  this->pRenderer2D = prenderer2D;
  this->pRoot = 0;
  this->pParent = 0;
  this->Effects.pEffect = 0;
  this->Flags = flags;
  this->pMask = 0;
  this->UpdateFlags = (unsigned int)&Scaleform::Render::D3D1x::pBinary_D3D1xFL1x_FBox2FullShadowHighlight[1376];
  this->pNextUpdate = 0;
  this->Depth = 0;
  this->SortParentBounds.x1 = 0.0;
  this->SortParentBounds.y1 = 0.0;
  this->SortParentBounds.x2 = 0.0;
  this->SortParentBounds.y2 = 0.0;
  this->pNext = 0;
  this->pPrev = 0;
  this->__vftable = (Scaleform::Render::TreeCacheMeshBase_vtbl *)&Scaleform::Render::TreeCacheMeshBase::`vftable';
  this->SorterShapeNode.pNextPattern = 0;
  this->SorterShapeNode.pChain = 0;
  this->SorterShapeNode.ChainHeight = 0;
  this->SorterShapeNode.IndexHint = 0;
  pImpl = key->pImpl;
  this->SorterShapeNode.Key.pImpl = key->pImpl;
  Data = key->Data;
  this->SorterShapeNode.Key.Data = Data;
  pImpl->AddRef(pImpl, Data);
  this->SorterShapeNode.pBundle.pObject = 0;
  this->SorterShapeNode.Removed = 0;
  this->SorterShapeNode.pSourceNode = this;
  this->M.pHandle = &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle;
}
