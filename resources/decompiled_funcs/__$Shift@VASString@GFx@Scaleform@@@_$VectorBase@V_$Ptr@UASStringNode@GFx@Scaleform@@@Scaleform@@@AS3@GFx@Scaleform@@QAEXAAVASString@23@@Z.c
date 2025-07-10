void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Shift<Scaleform::GFx::ASString>(
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // ebx
  Scaleform::GFx::ASStringNode *pObject; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::AS3::CheckResult v7; // [esp+7h] [ebp-1h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &v7)->Result && this->ValueA.Data.Size )
  {
    p_ValueA = &this->ValueA;
    pObject = this->ValueA.Data.Data->pObject;
    if ( !pObject )
      pObject = &result->pNode->pManager->NullStringNode;
    ++pObject->RefCount;
    pNode = result->pNode;
    if ( result->pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    result->pNode = pObject;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
      p_ValueA,
      0);
  }
}
