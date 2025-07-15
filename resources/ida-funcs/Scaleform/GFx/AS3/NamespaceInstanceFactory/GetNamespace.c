Scaleform::GFx::AS3::Instances::fl::Namespace *__thiscall Scaleform::GFx::AS3::NamespaceInstanceFactory::GetNamespace(
        Scaleform::GFx::AS3::NamespaceInstanceFactory *this,
        Scaleform::GFx::AS3::Abc::NamespaceKind kind,
        const Scaleform::GFx::ASString *uri,
        const Scaleform::GFx::AS3::Value *prefix)
{
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::HashSetUncachedLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,2> *p_NamespaceSet; // ecx
  Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc> > v7; // edi
  unsigned int SizeMask; // ebp
  signed int v9; // eax
  bool v10; // zf
  Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *pNamespaceInstanceTraits; // ebx
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // edi
  Scaleform::GFx::AS3::NamespaceKey key; // [esp+10h] [ebp-8h] BYREF

  pNode = uri->pNode;
  ++pNode->RefCount;
  p_NamespaceSet = &this->NamespaceSet;
  v7.pTable = p_NamespaceSet->pTable;
  SizeMask = 0;
  key.Kind = kind;
  key.URI.pNode = pNode;
  if ( v7.pTable )
  {
    v9 = Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc>>::findIndexCore<Scaleform::GFx::AS3::NamespaceKey>(
           p_NamespaceSet,
           &key,
           v7.pTable->SizeMask & (kind ^ (4 * ((unsigned int)&vostok::memory::s_CRT_arena[5574199] & pNode->HashFlags))));
    if ( v9 >= 0 )
    {
      SizeMask = v7.pTable[v9 + 1].SizeMask;
LABEL_4:
      v10 = pNode->RefCount-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      return (Scaleform::GFx::AS3::Instances::fl::Namespace *)SizeMask;
    }
  }
  pNamespaceInstanceTraits = this->pNamespaceInstanceTraits;
  if ( !pNamespaceInstanceTraits )
    goto LABEL_4;
  pObject = pNamespaceInstanceTraits->pVM->PublicNamespace.pObject;
  v10 = pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return pObject;
}
