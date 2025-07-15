void __thiscall Scaleform::Render::TreeCacheShapeLayer::forceUpdateImages(Scaleform::Render::TreeCacheShapeLayer *this)
{
  Scaleform::Render::TreeNode *pNode; // ebp
  Scaleform::Render::TreeNode *v3; // eax
  Scaleform::Render::ShapeMeshProvider *v4; // ebx
  Scaleform::Render::TreeNode *v5; // eax
  Scaleform::Render::SortKeyInterface *pImpl; // eax
  void *Data; // ecx
  Scaleform::Render::MeshKey *pObject; // ecx
  Scaleform::Render::TreeCacheRoot *pRoot; // ecx
  Scaleform::Render::TreeCacheNode *pParent; // esi
  Scaleform::Render::SortKey v11; // [esp+14h] [ebp-8h] BYREF

  pNode = this->pNode;
  if ( pNode )
    v3 = this->pNode;
  else
    v3 = this->pParent->Scaleform::Render::TreeCacheMeshBase::Scaleform::Render::TreeCacheNode::pNode;
  v4 = *(Scaleform::Render::ShapeMeshProvider **)((*(_DWORD *)(*(_DWORD *)(((unsigned int)v3 & 0xFFFFF000) + 0x14)
                                                             + 4
                                                             * ((int)((int)&v3[-1] - ((unsigned int)v3 & 0xFFFFF000))
                                                              / 28)
                                                             + 20)
                                                 & 0xFFFFFFFE)
                                                + 144);
  if ( pNode )
    v5 = this->pNode;
  else
    v5 = this->pParent->Scaleform::Render::TreeCacheMeshBase::Scaleform::Render::TreeCacheNode::pNode;
  Scaleform::Render::TreeCacheShapeLayer::CreateSortKey(
    &v11,
    this,
    v4,
    this->Layer,
    this->Flags,
    &this->pGradient,
    *(float *)((*(_DWORD *)(*(_DWORD *)(((unsigned int)v5 & 0xFFFFF000) + 0x14)
                          + 4 * ((int)((int)&v5[-1] - ((unsigned int)v5 & 0xFFFFF000)) / 28)
                          + 20)
              & 0xFFFFFFFE)
             + 148));
  if ( v11.pImpl == this->SorterShapeNode.Key.pImpl && v11.Data == this->SorterShapeNode.Key.Data )
  {
    if ( this->pMeshKey.pObject )
      Scaleform::Render::TreeCacheShapeLayer::updateTexture0Matrix(this);
  }
  else
  {
    Scaleform::Render::BundleEntry::ClearBundle(&this->SorterShapeNode);
    v11.pImpl->AddRef(v11.pImpl, v11.Data);
    this->SorterShapeNode.Key.pImpl->Release(this->SorterShapeNode.Key.pImpl, this->SorterShapeNode.Key.Data);
    pImpl = v11.pImpl;
    Data = v11.Data;
    this->SorterShapeNode.Key.pImpl = v11.pImpl;
    this->SorterShapeNode.Key.Data = Data;
    this->ComplexShape = pImpl->Type == SortKey_MeshProvider;
    pObject = this->pMeshKey.pObject;
    if ( pObject )
      Scaleform::Render::MeshKey::Release(pObject);
    this->pMeshKey.pObject = 0;
    pRoot = this->pRoot;
    if ( pRoot )
    {
      pParent = this->pParent;
      if ( pParent )
        Scaleform::Render::TreeCacheRoot::AddToUpdate(pRoot, pParent, 0x1000401u);
    }
  }
  v11.pImpl->Release(v11.pImpl, v11.Data);
}
