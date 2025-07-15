Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *__thiscall Scaleform::GFx::MovieDefImpl::BindTaskData::GetShapeMeshProvider(
        Scaleform::GFx::MovieDefImpl::BindTaskData *this,
        Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *result,
        Scaleform::Render::ShapeMeshProvider *defMeshProv)
{
  Scaleform::Lock *p_ImportSourceLock; // edi
  char v5; // bl
  Scaleform::HashLH<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>,2,Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> >,Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> >::NodeHashF> > *p_BoundShapeMeshProviders; // esi
  int Index; // eax
  int v8; // eax
  Scaleform::Render::ShapeMeshProvider **v9; // eax
  Scaleform::Render::ShapeMeshProvider **p_defMeshProv; // esi
  Scaleform::Render::ShapeMeshProvider *v11; // eax

  p_ImportSourceLock = &this->ImportSourceLock;
  v5 = 0;
  EnterCriticalSection(&this->ImportSourceLock.cs);
  p_BoundShapeMeshProviders = &this->BoundShapeMeshProviders;
  Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF>>::findIndexAlt<unsigned long>(
            (Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> > *)p_BoundShapeMeshProviders,
            (unsigned int *)&defMeshProv);
  if ( Index >= 0
    && (v8 = (int)&p_BoundShapeMeshProviders->mHash.pTable[2 * Index + 2]) != 0
    && (v9 = (Scaleform::Render::ShapeMeshProvider **)(v8 + 4)) != 0 )
  {
    p_defMeshProv = v9;
    v11 = *v9;
    if ( v11 )
      v11->AddRef(&v11->Scaleform::Render::MeshProvider);
  }
  else
  {
    v5 = 1;
    defMeshProv = 0;
    p_defMeshProv = &defMeshProv;
  }
  result->pObject = *p_defMeshProv;
  if ( (v5 & 1) != 0 && defMeshProv )
    defMeshProv->Release(&defMeshProv->Scaleform::Render::MeshProvider);
  LeaveCriticalSection(&p_ImportSourceLock->cs);
  return result;
}
