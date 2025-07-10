Scaleform::GFx::AS3::ClassTraits::Traits **__thiscall Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
        Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *this,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS3::Instances::fl::Namespace *ns)
{
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor> *v4; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits **p_Second; // edi
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key key; // [esp+Ch] [ebp-8h] BYREF

  pNode = name->pNode;
  ++pNode->RefCount;
  key.Name.pNode = pNode;
  key.pNs.pObject = ns;
  if ( ns )
    ns->RefCount = (ns->RefCount + 1) & 0x8FBFFFFF;
  v4 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::GetAlt<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key>(
         &this->Entries.mHash,
         &key);
  if ( v4 )
    p_Second = &v4->Second;
  else
    p_Second = 0;
  if ( ns )
  {
    if ( ((unsigned __int8)ns & 1) == 0 )
    {
      RefCount = ns->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        ns->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(ns);
      }
    }
  }
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return p_Second;
}
