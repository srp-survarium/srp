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


Scaleform::GFx::AS3::ClassTraits::Traits **__thiscall Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
        Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *this,
        const Scaleform::GFx::AS3::Multiname *mn)
{
  const Scaleform::GFx::AS3::Multiname *v2; // eax
  char v3; // dl
  const Scaleform::GFx::AS3::Multiname *VInt; // esi
  Scaleform::GFx::AS3::ClassTraits::Traits **v5; // eax
  bool v6; // zf
  Scaleform::GFx::AS3::ClassTraits::Traits **v7; // edi
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // ebx
  Scaleform::GFx::AS3::RefCountCollector<328> *pRCC; // ecx
  _DWORD *v11; // ebx
  Scaleform::GFx::AS3::ClassTraits::Traits **v12; // ebp
  unsigned int v13; // edi
  Scaleform::GFx::ASStringNode *VStr; // esi
  Scaleform::GFx::AS3::ClassTraits::Traits **v15; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v16; // [esp-Ch] [ebp-20h]
  Scaleform::GFx::AS3::Instances::fl::Namespace *v17; // [esp-4h] [ebp-18h]
  unsigned int size; // [esp+8h] [ebp-Ch]
  Scaleform::GFx::ASString name; // [esp+Ch] [ebp-8h] BYREF
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *v20; // [esp+10h] [ebp-4h]

  v2 = mn;
  v3 = mn->Kind & 3;
  v20 = this;
  if ( v3 == 2 )
  {
    pObject = mn->Obj.pObject;
    pRCC = pObject[1]._pRCC;
    v11 = &pObject[1].__vftable;
    v12 = 0;
    size = (unsigned int)pRCC;
    v13 = 0;
    while ( v13 < size )
    {
      VStr = v2->Name.value.VS._1.VStr;
      ++VStr->RefCount;
      v16 = *(Scaleform::GFx::AS3::Instances::fl::Namespace **)(*v11 + 4 * v13);
      name.pNode = VStr;
      v15 = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(v20, &name, v16);
      v6 = VStr->RefCount-- == 1;
      v12 = v15;
      if ( v6 )
        Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
      ++v13;
      if ( v12 )
        break;
      v2 = mn;
    }
    return v12;
  }
  else
  {
    VInt = (const Scaleform::GFx::AS3::Multiname *)mn->Name.value.VS._1.VInt;
    ++VInt->Name.Bonus.pWeakProxy;
    v17 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v2->Obj.pObject;
    mn = VInt;
    v5 = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
           this,
           (const Scaleform::GFx::ASString *)&mn,
           v17);
    v6 = VInt->Name.Bonus.pWeakProxy-- == (Scaleform::GFx::AS3::WeakProxy *)1;
    v7 = v5;
    if ( v6 )
      Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)VInt);
    return v7;
  }
}
