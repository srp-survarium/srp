void __thiscall Scaleform::Render::MeshKeySet::DestroyKey(
        Scaleform::Render::MeshKeySet *this,
        Scaleform::Render::MeshKey *key)
{
  Scaleform::Render::MeshBase *pObject; // edi
  Scaleform::Render::MeshProvider *v4; // ecx
  Scaleform::RefCountVImpl *v5; // ecx

  key->pPrev->pNext = key->pNext;
  key->pNext->Scaleform::ListNode<Scaleform::Render::MeshKey>::$5252AFF3D3E939C0FA7A55516A935C36::pPrev = key->pPrev;
  pObject = key->pMesh.pObject;
  if ( pObject )
  {
    v4 = pObject->pProvider.pObject;
    if ( v4 )
      v4->Release(v4);
    pObject->pProvider.pObject = 0;
    v5 = (Scaleform::RefCountVImpl *)key->pMesh.pObject;
    if ( v5 )
      Scaleform::RefCountImpl::Release(v5);
    key->pMesh.pObject = 0;
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, key);
  if ( (Scaleform::List<Scaleform::Render::MeshKey,Scaleform::Render::MeshKey> *)this->Meshes.Root.pNext == &this->Meshes )
    Scaleform::Render::MeshKeyManager::destroyKeySet(this->pManager.pObject, this);
}
