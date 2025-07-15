void __thiscall Scaleform::Render::TreeCacheShapeLayer::updateSortKey(Scaleform::Render::TreeCacheShapeLayer *this)
{
  Scaleform::Render::BundleEntry *p_SorterShapeNode; // edi
  Scaleform::Render::Bundle *pObject; // eax
  Scaleform::Render::Bundle *v4; // ebx
  Scaleform::RefCountNTSImpl *v5; // ecx
  Scaleform::Render::TreeNode *pNode; // eax
  signed int v7; // edi
  unsigned __int16 Flags; // bx
  unsigned int Layer; // ebp
  int v10; // edx
  Scaleform::Render::TreeNode *v11; // eax
  Scaleform::Render::SortKey *v12; // edi
  void *Data; // eax
  Scaleform::Render::MeshKey *v14; // ecx
  Scaleform::Render::TreeCacheRoot *pRoot; // ecx
  Scaleform::Render::TreeCacheNode *pParent; // esi
  Scaleform::Render::SortKey result; // [esp+14h] [ebp-8h] BYREF

  p_SorterShapeNode = &this->SorterShapeNode;
  if ( this->SorterShapeNode.pBundle.pObject )
  {
    pObject = this->SorterShapeNode.pBundle.pObject;
    if ( pObject )
      ++pObject->RefCount;
    v4 = this->SorterShapeNode.pBundle.pObject;
    Scaleform::Render::Bundle::RemoveEntry(v4, &this->SorterShapeNode);
    if ( v4 )
      Scaleform::RefCountNTSImpl::Release(v4);
  }
  v5 = p_SorterShapeNode->pBundle.pObject;
  if ( v5 )
    Scaleform::RefCountNTSImpl::Release(v5);
  p_SorterShapeNode->pBundle.pObject = 0;
  p_SorterShapeNode->IndexHint = 0;
  pNode = this->pNode;
  if ( !pNode )
    pNode = this->pParent->Scaleform::Render::TreeCacheMeshBase::Scaleform::Render::TreeCacheNode::pNode;
  v7 = (signed int)&pNode[-1] - ((unsigned int)pNode & 0xFFFFF000);
  Flags = this->Flags;
  Layer = this->Layer;
  v10 = *(_DWORD *)(((unsigned int)pNode & 0xFFFFF000) + 0x14);
  v11 = this->pNode;
  result.pImpl = *(Scaleform::Render::SortKeyInterface **)((*(_DWORD *)(v10 + 4 * (v7 / 28) + 20) & 0xFFFFFFFE) + 148);
  if ( !v11 )
    v11 = this->pParent->Scaleform::Render::TreeCacheMeshBase::Scaleform::Render::TreeCacheNode::pNode;
  v12 = Scaleform::Render::TreeCacheShapeLayer::CreateSortKey(
          &result,
          this,
          *(Scaleform::Render::ShapeMeshProvider **)((*(_DWORD *)(*(_DWORD *)(((unsigned int)v11 & 0xFFFFF000) + 0x14)
                                                                + 4
                                                                * ((int)((int)&v11[-1] - ((unsigned int)v11 & 0xFFFFF000))
                                                                 / 28)
                                                                + 20)
                                                    & 0xFFFFFFFE)
                                                   + 144),
          Layer,
          Flags,
          &this->pGradient,
          *(float *)&result.pImpl);
  v12->pImpl->AddRef(v12->pImpl, v12->Data);
  this->SorterShapeNode.Key.pImpl->Release(this->SorterShapeNode.Key.pImpl, this->SorterShapeNode.Key.Data);
  this->SorterShapeNode.Key.pImpl = v12->pImpl;
  Data = result.Data;
  this->SorterShapeNode.Key.Data = v12->Data;
  result.pImpl->Release(result.pImpl, Data);
  this->ComplexShape = this->SorterShapeNode.Key.pImpl->Type == SortKey_MeshProvider;
  v14 = this->pMeshKey.pObject;
  if ( v14 )
    Scaleform::Render::MeshKey::Release(v14);
  this->pMeshKey.pObject = 0;
  pRoot = this->pRoot;
  if ( pRoot )
  {
    pParent = this->pParent;
    if ( pParent )
      Scaleform::Render::TreeCacheRoot::AddToDepthUpdate(
        pRoot,
        pParent,
        (unsigned int)&vostok::memory::s_CRT_arena[5574201]);
  }
}
