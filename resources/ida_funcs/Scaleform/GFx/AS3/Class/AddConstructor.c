void __thiscall Scaleform::GFx::AS3::Class::AddConstructor(
        Scaleform::GFx::AS3::Class *this,
        Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::ASStringNode *ConstStringNode; // esi
  Scaleform::GFx::ASStringNode *v3; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  int v6; // [esp+0h] [ebp-20h] BYREF
  Scaleform::GFx::ASStringNode *v7; // [esp+4h] [ebp-1Ch]
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [esp+8h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value v9; // [esp+10h] [ebp-10h] BYREF

  v9.Flags = 13;
  v9.Bonus.pWeakProxy = 0;
  v9.value.VS._1.VInt = (int)this;
  if ( this )
    this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                      "constructor",
                      0xBu,
                      0);
  ++ConstStringNode->RefCount;
  key.pFirst = (const Scaleform::GFx::AS3::Object::DynAttrsKey *)&v6;
  v6 = 1;
  v7 = ConstStringNode;
  ++ConstStringNode->RefCount;
  key.pSecond = &v9;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    &obj->DynAttrs.mHash,
    &obj->DynAttrs,
    &key);
  v3 = v7;
  --v7->RefCount;
  if ( !v3->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v3);
  if ( ConstStringNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
  if ( (v9.Flags & 0x1F) > 9 )
  {
    if ( (v9.Flags & 0x200) != 0 )
    {
      pWeakProxy = v9.Bonus.pWeakProxy;
      --v9.Bonus.pWeakProxy->RefCount;
      if ( !pWeakProxy->RefCount )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v9);
    }
  }
}
