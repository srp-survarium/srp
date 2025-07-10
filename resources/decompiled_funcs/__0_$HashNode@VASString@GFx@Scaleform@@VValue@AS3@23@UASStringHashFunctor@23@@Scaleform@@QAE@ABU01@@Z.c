void __thiscall Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>(
        Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor> *src)
{
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value *p_Second; // ecx

  pNode = src->First.pNode;
  this->First.pNode = src->First.pNode;
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
