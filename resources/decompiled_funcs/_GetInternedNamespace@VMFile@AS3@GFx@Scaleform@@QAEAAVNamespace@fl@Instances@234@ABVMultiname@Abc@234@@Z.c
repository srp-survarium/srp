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
