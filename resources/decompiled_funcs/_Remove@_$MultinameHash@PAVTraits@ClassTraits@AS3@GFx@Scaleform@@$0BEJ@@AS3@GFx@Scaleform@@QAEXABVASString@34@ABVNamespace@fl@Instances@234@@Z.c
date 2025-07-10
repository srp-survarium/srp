void __thiscall Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Remove(
        Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *this,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS3::Instances::fl::Namespace *ns)
{
  Scaleform::GFx::ASStringNode *pNode; // esi
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key key; // [esp+8h] [ebp-8h] BYREF

  pNode = name->pNode;
  ++pNode->RefCount;
  key.Name.pNode = pNode;
  key.pNs.pObject = ns;
  if ( ns )
    ns->RefCount = (ns->RefCount + 1) & 0x8FBFFFFF;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key>(
    &this->Entries.mHash,
    &key);
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
}
