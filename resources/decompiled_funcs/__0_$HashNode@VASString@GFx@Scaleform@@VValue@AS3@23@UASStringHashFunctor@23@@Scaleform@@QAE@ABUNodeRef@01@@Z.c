void __thiscall Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>(
        Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeRef *src)
{
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value *pSecond; // ecx

  pNode = src->pFirst->pNode;
  this->First.pNode = pNode;
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
