Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor> *__thiscall Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::operator=(
        Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor> *__that)
{
  Scaleform::GFx::ASStringNode *pNode; // edi
  Scaleform::GFx::ASStringNode *v4; // ecx

  pNode = __that->First.pNode;
  ++__that->First.pNode->RefCount;
  v4 = this->First.pNode;
  if ( v4->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  this->First.pNode = pNode;
  Scaleform::GFx::AS2::FunctionRefBase::Assign(&this->Second.Callback, &__that->Second.Callback);
  Scaleform::GFx::AS2::Value::operator=(&this->Second.UserData, &__that->Second.UserData);
  return this;
}
