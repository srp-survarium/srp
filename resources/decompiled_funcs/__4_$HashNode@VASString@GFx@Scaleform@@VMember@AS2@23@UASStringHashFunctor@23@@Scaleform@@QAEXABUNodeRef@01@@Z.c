void __thiscall Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::operator=(
        Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeRef *src)
{
  Scaleform::GFx::ASStringNode *pNode; // edi
  Scaleform::GFx::ASStringNode *v4; // ecx
  const Scaleform::GFx::AS2::Member *pSecond; // edi
  Scaleform::GFx::AS2::Member *p_Second; // esi

  pNode = src->pFirst->pNode;
  ++pNode->RefCount;
  v4 = this->First.pNode;
  if ( v4->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  this->First.pNode = pNode;
  pSecond = src->pSecond;
  p_Second = &this->Second;
  Scaleform::GFx::AS2::Value::operator=(&p_Second->mValue, &pSecond->mValue);
  p_Second->mValue.T.PropFlags = pSecond->mValue.T.PropFlags;
}
