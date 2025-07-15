void __thiscall Scaleform::GFx::MovieDefImpl::BindTaskData::AddShapeMeshProvider(
        Scaleform::GFx::MovieDefImpl::BindTaskData *this,
        Scaleform::Render::ShapeMeshProvider *defMeshProv,
        Scaleform::Render::ShapeMeshProvider *resolvedMeshProv)
{
  Scaleform::Lock *p_ImportSourceLock; // ebx
  Scaleform::Render::ShapeMeshProvider *v5; // edi
  Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> >::NodeRef key; // [esp+Ch] [ebp-8h] BYREF

  p_ImportSourceLock = &this->ImportSourceLock;
  EnterCriticalSection(&this->ImportSourceLock.cs);
  v5 = resolvedMeshProv;
  if ( resolvedMeshProv )
    resolvedMeshProv->AddRef(&resolvedMeshProv->Scaleform::Render::MeshProvider);
  key.pFirst = &defMeshProv;
  resolvedMeshProv = v5;
  key.pSecond = (const Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *)&resolvedMeshProv;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>,Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>::NodeHashF,Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::ShapeMeshProvider *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>,Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>::NodeRef>(
    &this->BoundShapeMeshProviders.mHash,
    &this->BoundShapeMeshProviders,
    &key);
  if ( resolvedMeshProv )
    resolvedMeshProv->Release(&resolvedMeshProv->Scaleform::Render::MeshProvider);
  LeaveCriticalSection(&p_ImportSourceLock->cs);
}
