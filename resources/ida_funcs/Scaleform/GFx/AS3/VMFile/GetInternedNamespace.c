Scaleform::GFx::AS3::Instances::fl::Namespace *__thiscall Scaleform::GFx::AS3::VMFile::GetInternedNamespace(
        Scaleform::GFx::AS3::VMFile *this,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  const Scaleform::GFx::AS3::Abc::Multiname *v2; // esi
  Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340> *p_IntNamespaces; // ebx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v5; // eax
  const Scaleform::GFx::AS3::Abc::Multiname **v6; // eax
  unsigned int Ind; // ecx
  int NextIndex; // edx
  int v9; // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v10; // ecx
  int v12; // [esp+Ch] [ebp-Ch] BYREF
  Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key key; // [esp+10h] [ebp-8h] BYREF

  v2 = mn;
  p_IntNamespaces = &this->IntNamespaces;
  v5 = Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Get(
         &this->IntNamespaces,
         mn);
  if ( !v5 )
  {
    v6 = (const Scaleform::GFx::AS3::Abc::Multiname **)this->MakeInternedNamespace(this, &v12, v2);
    Ind = v2->Ind;
    NextIndex = v2->NextIndex;
    mn = (Scaleform::GFx::AS3::Abc::Multiname *)*v6;
    key.NsInd = Ind;
    key.NextMnInd = NextIndex;
    _Add___Hash_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform__V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___345_V__FixedSizeHash_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___5_U__AllocatorLH_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___0BFE__5_U__HashNode_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform__V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___345_V__FixedSizeHash_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___5__5_V__HashsetCachedNodeEntry_U__HashNode_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform__V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___345_V__FixedSizeHash_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___5__Scaleform__UNodeHashF_12__5_V__HashSet_U__HashNode_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform__V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___345_V__FixedSizeHash_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___5__Scaleform__UNodeHashF_12_UNodeAltHashF_12_U__AllocatorLH_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___0BFE__2_V__HashsetCachedNodeEntry_U__HashNode_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform__V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___345_V__FixedSizeHash_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___5__Scaleform__UNodeHashF_12__2__5__Scaleform__QAEXABUKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_2_ABV__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___562__Z(
      &p_IntNamespaces->Entries,
      &key,
      (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *)&mn);
    if ( mn )
    {
      if ( ((unsigned __int8)mn & 1) == 0 )
      {
        v9 = mn[1].Ind;
        v10 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)mn;
        if ( ((unsigned int)&byte_3FFFFF & v9) != 0 )
        {
          mn[1].Ind = v9 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v10);
        }
      }
    }
    v5 = Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Get(
           p_IntNamespaces,
           v2);
  }
  return v5->pObject;
}


Scaleform::GFx::AS3::Instances::fl::Namespace *__thiscall Scaleform::GFx::AS3::VMFile::GetInternedNamespace(
        Scaleform::GFx::AS3::VMFile *this,
        Scaleform::GFx::AS3::Instances::fl::Namespace *nsIndex)
{
  unsigned int v2; // ebx
  Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340> *p_IntNamespaces; // esi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v9; // ecx
  int v10; // eax
  int v11; // eax
  Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key key; // [esp+Ch] [ebp-10h] BYREF
  Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key v14; // [esp+14h] [ebp-8h] BYREF

  v2 = (unsigned int)nsIndex;
  p_IntNamespaces = &this->IntNamespaces;
  key.NsInd = (unsigned int)nsIndex;
  key.NextMnInd = -1;
  v5 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>::NodeHashF>>::findIndexAlt<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>(
         &this->IntNamespaces.Entries.mHash,
         &key);
  if ( v5 < 0 || (v6 = (int)&p_IntNamespaces->Entries.mHash.pTable[2] + 20 * v5) == 0 || (v7 = v6 + 8) == 0 )
  {
    nsIndex = this->MakeInternedNamespace(this, &key, v2)->pV;
    v14.NsInd = v2;
    v14.NextMnInd = -1;
    _Add___Hash_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform__V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___345_V__FixedSizeHash_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___5_U__AllocatorLH_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___0BFE__5_U__HashNode_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform__V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___345_V__FixedSizeHash_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___5__5_V__HashsetCachedNodeEntry_U__HashNode_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform__V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___345_V__FixedSizeHash_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___5__Scaleform__UNodeHashF_12__5_V__HashSet_U__HashNode_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform__V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___345_V__FixedSizeHash_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___5__Scaleform__UNodeHashF_12_UNodeAltHashF_12_U__AllocatorLH_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___0BFE__2_V__HashsetCachedNodeEntry_U__HashNode_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform__V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___345_V__FixedSizeHash_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___5__Scaleform__UNodeHashF_12__2__5__Scaleform__QAEXABUKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_2_ABV__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___562__Z(
      &p_IntNamespaces->Entries,
      &v14,
      (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *)&nsIndex);
    if ( nsIndex )
    {
      if ( ((unsigned __int8)nsIndex & 1) == 0 )
      {
        RefCount = nsIndex->RefCount;
        v9 = nsIndex;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          nsIndex->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v9);
        }
      }
    }
    v14.NsInd = v2;
    v14.NextMnInd = -1;
    v10 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>::NodeHashF>>::findIndexAlt<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>(
            &p_IntNamespaces->Entries.mHash,
            &v14);
    if ( v10 >= 0 )
    {
      v11 = (int)&p_IntNamespaces->Entries.mHash.pTable[2] + 20 * v10;
      if ( v11 )
        return *(Scaleform::GFx::AS3::Instances::fl::Namespace **)(v11 + 8);
    }
    v7 = 0;
  }
  return *(Scaleform::GFx::AS3::Instances::fl::Namespace **)v7;
}
