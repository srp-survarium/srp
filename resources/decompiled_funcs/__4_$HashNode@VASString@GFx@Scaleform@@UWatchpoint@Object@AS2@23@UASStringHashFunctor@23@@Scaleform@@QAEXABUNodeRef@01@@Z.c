void __thiscall Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::operator=(
        Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeRef *src)
{
  Scaleform::GFx::ASStringNode *pNode; // edi
  Scaleform::GFx::ASStringNode *v4; // ecx
  const Scaleform::GFx::AS2::Object::Watchpoint *pSecond; // edi
  Scaleform::GFx::AS2::Object::Watchpoint *p_Second; // esi

  pNode = src->pFirst->pNode;
  ++pNode->RefCount;
  v4 = this->First.pNode;
  if ( v4->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  this->First.pNode = pNode;
  pSecond = src->pSecond;
  p_Second = &this->Second;
  Scaleform::GFx::AS2::FunctionRefBase::Assign(&p_Second->Callback, &pSecond->Callback);
  Scaleform::GFx::AS2::Value::operator=(&p_Second->UserData, &pSecond->UserData);
}
