const Scaleform::String *__thiscall Scaleform::GFx::MovieDefImpl::GetNameOfExportedResource(
        Scaleform::GFx::MovieDefImpl *this,
        Scaleform::GFx::ResourceId rid)
{
  Scaleform::GFx::MovieDataDef *pObject; // ecx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v4; // eax
  Scaleform::GFx::MovieDataDef::LoadTaskData *v5; // edi
  Scaleform::HashLH<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>,2,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeHashF> > *p_InvExports; // esi
  int Index; // eax
  int v8; // eax
  int v9; // esi

  pObject = this->pBindData.pObject->pDataDef.pObject;
  v4 = pObject->pData.pObject;
  v5 = 0;
  if ( v4->LoadState < LS_LoadFinished )
  {
    v5 = pObject->pData.pObject;
    EnterCriticalSection(&v4->ResourceLock.cs);
  }
  p_InvExports = &this->pBindData.pObject->pDataDef.pObject->pData.pObject->InvExports;
  Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF>>::findIndexAlt<unsigned long>(
            (Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> > *)p_InvExports,
            &rid.Id);
  if ( Index >= 0 && (v8 = (int)&p_InvExports->mHash.pTable[2 * Index + 2]) != 0 )
    v9 = v8 + 4;
  else
    v9 = 0;
  if ( v5 )
    LeaveCriticalSection(&v5->ResourceLock.cs);
  return (const Scaleform::String *)v9;
}
