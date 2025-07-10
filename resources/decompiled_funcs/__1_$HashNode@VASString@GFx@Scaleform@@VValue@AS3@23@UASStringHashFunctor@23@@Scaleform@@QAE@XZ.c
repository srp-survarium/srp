void __thiscall Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::~HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>(
        Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor> *this)
{
  Scaleform::GFx::AS3::Value *p_Second; // esi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  bool v4; // zf
  Scaleform::GFx::ASStringNode *pNode; // ecx

  p_Second = &this->Second;
  if ( (this->Second.Flags & 0x1F) > 9 )
  {
    if ( (this->Second.Flags & 0x200) != 0 )
    {
      pWeakProxy = this->Second.Bonus.pWeakProxy;
      v4 = pWeakProxy->RefCount-- == 1;
      if ( v4 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      p_Second->Flags &= 0xFFFFFDE0;
      p_Second->Bonus.pWeakProxy = 0;
      p_Second->value.VS._1.VInt = 0;
      p_Second->value.VS._2.VObj = 0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_Second);
    }
  }
  pNode = this->First.pNode;
  v4 = this->First.pNode->RefCount-- == 1;
  if ( v4 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
