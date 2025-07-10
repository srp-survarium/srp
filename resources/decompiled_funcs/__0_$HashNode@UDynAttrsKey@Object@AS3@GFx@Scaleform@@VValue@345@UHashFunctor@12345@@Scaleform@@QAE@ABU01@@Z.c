void __thiscall Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>(
        Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor> *src)
{
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value *p_Second; // ecx

  this->First.Flags = src->First.Flags;
  pNode = src->First.Name.pNode;
  this->First.Name.pNode = pNode;
  ++pNode->RefCount;
  p_Second = &src->Second;
  this->Second = src->Second;
  if ( (src->Second.Flags & 0x1F) > 9 )
  {
    if ( (p_Second->Flags & 0x200) != 0 )
      ++src->Second.Bonus.pWeakProxy->RefCount;
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(p_Second);
  }
}
