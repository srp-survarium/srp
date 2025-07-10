void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Pop<Scaleform::GFx::ASString>(
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *pObject; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::AS3::CheckResult v7; // [esp+7h] [ebp-5h] BYREF
  Scaleform::Ptr<Scaleform::GFx::ASStringNode> v8; // [esp+8h] [ebp-4h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &v7)->Result && this->ValueA.Data.Size )
  {
    pObject = Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
                &this->ValueA,
                &v8)->pObject;
    if ( !pObject )
      pObject = &result->pNode->pManager->NullStringNode;
    ++pObject->RefCount;
    pNode = result->pNode;
    if ( result->pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v6 = v8.pObject;
    result->pNode = pObject;
    if ( v6 )
    {
      if ( !--v6->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v6);
    }
  }
}
