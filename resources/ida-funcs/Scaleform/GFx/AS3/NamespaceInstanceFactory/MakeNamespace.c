Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *__thiscall Scaleform::GFx::AS3::NamespaceInstanceFactory::MakeNamespace(
        Scaleform::GFx::AS3::NamespaceInstanceFactory *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *result,
        Scaleform::GFx::AS3::Abc::NamespaceKind kind,
        Scaleform::GFx::ASString *uri,
        Scaleform::GFx::AS3::Value *prefix)
{
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc> >::TableType *pTable; // ebx
  Scaleform::HashSetUncachedLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,2> *p_NamespaceSet; // edi
  signed int v8; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *SizeMask; // ebx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *v10; // edi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v13; // ebx
  Scaleform::GFx::AS3::NamespaceInstanceFactory *v14; // [esp+10h] [ebp-Ch]
  Scaleform::GFx::AS3::NamespaceKey key; // [esp+14h] [ebp-8h] BYREF

  pNode = uri->pNode;
  ++pNode->RefCount;
  pTable = this->NamespaceSet.pTable;
  p_NamespaceSet = &this->NamespaceSet;
  v14 = this;
  key.Kind = kind;
  key.URI.pNode = pNode;
  if ( !pTable )
    goto LABEL_9;
  v8 = Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc>>::findIndexCore<Scaleform::GFx::AS3::NamespaceKey>(
         &this->NamespaceSet,
         &key,
         pTable->SizeMask & (kind ^ (4 * ((unsigned int)&vostok::memory::s_CRT_arena[5574199] & pNode->HashFlags))));
  if ( v8 < 0 )
  {
    this = v14;
LABEL_9:
    Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::MakeInstance(
      this->pNamespaceInstanceTraits,
      (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *)&uri,
      kind,
      uri,
      prefix);
    v13 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)uri;
    Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc>>::add<Scaleform::GFx::AS3::Instances::fl::Namespace *>(
      p_NamespaceSet,
      p_NamespaceSet,
      (Scaleform::GFx::AS3::Instances::fl::Namespace *const *)&uri,
      (4 * ((unsigned int)&vostok::memory::s_CRT_arena[5574199] & uri[7].pNode->HashFlags))
    ^ ((int)uri[5].pNode << 28 >> 28));
    v10 = result;
    result->pV = v13;
    goto LABEL_5;
  }
  SizeMask = (Scaleform::GFx::AS3::Instances::fl::Namespace *)pTable[v8 + 1].SizeMask;
  v10 = result;
  result->pV = SizeMask;
  if ( SizeMask )
    SizeMask->RefCount = (SizeMask->RefCount + 1) & 0x8FBFFFFF;
LABEL_5:
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return v10;
}
