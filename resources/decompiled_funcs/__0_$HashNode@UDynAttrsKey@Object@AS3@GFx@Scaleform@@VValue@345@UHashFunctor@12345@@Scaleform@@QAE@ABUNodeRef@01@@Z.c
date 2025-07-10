void __thiscall Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>(
        Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef *src)
{
  const Scaleform::GFx::AS3::Object::DynAttrsKey *pFirst; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value *pSecond; // ecx

  pFirst = src->pFirst;
  this->First.Flags = src->pFirst->Flags;
  pNode = pFirst->Name.pNode;
  this->First.Name.pNode = pNode;
  ++pNode->RefCount;
  pSecond = (Scaleform::GFx::AS3::Value *)src->pSecond;
  this->Second = *pSecond;
  if ( (pSecond->Flags & 0x1F) > 9 )
  {
    if ( (pSecond->Flags & 0x200) != 0 )
      ++pSecond->Bonus.pWeakProxy->RefCount;
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(pSecond);
  }
}
