void __thiscall Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(
        Scaleform::GFx::AS3::Object *this,
        const Scaleform::GFx::ASString *prop_name,
        const Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::SlotInfo::Attribute a)
{
  Scaleform::GFx::ASStringNode *v4; // eax
  BOOL v5; // [esp+0h] [ebp-10h] BYREF
  Scaleform::GFx::ASStringNode *pNode; // [esp+4h] [ebp-Ch]
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [esp+8h] [ebp-8h] BYREF

  v5 = a == aDontEnum;
  pNode = prop_name->pNode;
  ++pNode->RefCount;
  key.pFirst = (const Scaleform::GFx::AS3::Object::DynAttrsKey *)&v5;
  key.pSecond = v;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    &this->DynAttrs.mHash,
    &this->DynAttrs,
    &key);
  v4 = pNode;
  --pNode->RefCount;
  if ( !v4->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
}
