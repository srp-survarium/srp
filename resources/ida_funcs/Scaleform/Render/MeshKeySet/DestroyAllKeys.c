void __thiscall Scaleform::Render::MeshKeySet::DestroyAllKeys(Scaleform::Render::MeshKeySet *this)
{
  Scaleform::Render::MeshKey *pNext; // edi
  Scaleform::List<Scaleform::Render::MeshKey,Scaleform::Render::MeshKey> *i; // ebx
  Scaleform::Render::MeshBase *pObject; // esi
  Scaleform::Render::MeshProvider *v5; // ecx
  Scaleform::Render::MeshKey *v6; // esi
  Scaleform::Render::MeshKey *v7; // edi
  Scaleform::RefCountVImpl *v8; // ecx

  pNext = this->Meshes.Root.pNext;
  for ( i = &this->Meshes; pNext != (Scaleform::Render::MeshKey *)i; pNext = pNext->pNext )
  {
    pObject = pNext->pMesh.pObject;
    if ( pObject )
    {
      v5 = pObject->pProvider.pObject;
      if ( v5 )
        v5->Release(v5);
      pObject->pProvider.pObject = 0;
    }
  }
  v6 = this->Meshes.Root.pNext;
  if ( v6 != (Scaleform::Render::MeshKey *)i )
  {
    do
    {
      v7 = v6->pNext;
      if ( v6->pMesh.pObject )
      {
        v8 = (Scaleform::RefCountVImpl *)v6->pMesh.pObject;
        if ( v8 )
          Scaleform::RefCountImpl::Release(v8);
        v6->pMesh.pObject = 0;
      }
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
      v6 = v7;
    }
    while ( v7 != (Scaleform::Render::MeshKey *)i );
  }
  i->Root.pPrev = (Scaleform::Render::MeshKey *)i;
  i->Root.pNext = (Scaleform::Render::MeshKey *)i;
}
