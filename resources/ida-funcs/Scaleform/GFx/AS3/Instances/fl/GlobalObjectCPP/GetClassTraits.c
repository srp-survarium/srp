Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::GetClassTraits(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *this,
        const Scaleform::GFx::ASString *name,
        const Scaleform::GFx::AS3::Instances::fl::Namespace *ns)
{
  bool v4; // zf
  char *pData; // ecx
  Scaleform::GFx::AS3::Instances::fl::ConstStringHash<Scaleform::GFx::AS3::ClassInfo const *> *p_CIRegistrationHash; // edi
  unsigned int v7; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,328>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>::NodeHashF> >::TableType *pTable; // esi
  signed int v9; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,328>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>::NodeHashF> >::TableType *v10; // eax
  int (__cdecl **SizeMask)(_DWORD, _DWORD); // esi
  Scaleform::GFx::ASString *v12; // ebx
  Scaleform::GFx::ASStringNode *pNode; // eax

  v4 = this->CIRegistrationHash.mHash.pTable == 0;
  pData = (char *)name->pNode->pData;
  p_CIRegistrationHash = &this->CIRegistrationHash;
  name = (const Scaleform::GFx::ASString *)pData;
  if ( v4 )
    return 0;
  v7 = Scaleform::String::BernsteinHashFunction(pData, strlen(pData), 0x1505u);
  pTable = p_CIRegistrationHash->mHash.pTable;
  v9 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,328>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>::NodeHashF>>::findIndexCore<Scaleform::GFx::AS3::Instances::fl::ConstStringKey>(
         &this->CIRegistrationHash.mHash,
         (const Scaleform::GFx::AS3::Instances::fl::ConstStringKey *)&name,
         v7 & p_CIRegistrationHash->mHash.pTable->SizeMask);
  if ( v9 < 0 )
    return 0;
  v10 = &pTable[2 * v9 + 2];
  if ( !v10 )
    return 0;
  SizeMask = (int (__cdecl **)(_DWORD, _DWORD))v10->SizeMask;
  if ( !SizeMask || !Scaleform::GFx::ASString::operator==(&ns->Uri, *((const char **)*SizeMask + 2)) )
    return 0;
  v12 = *(Scaleform::GFx::ASString **)((int (__cdecl **)(const Scaleform::GFx::ASString **, Scaleform::GFx::AS3::VM *))SizeMask)[1](
                                        &name,
                                        this->pTraits.pObject->pVM);
  name = v12;
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
    &this->CTraits,
    (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *)&name);
  if ( v12 && ((unsigned __int8)v12 & 1) == 0 )
  {
    pNode = v12[4].pNode;
    if ( ((unsigned int)pNode & 0x3FFFFF) != 0 )
    {
      v12[4].pNode = (Scaleform::GFx::ASStringNode *)((char *)pNode - 1);
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v12);
    }
  }
  return v12;
}
