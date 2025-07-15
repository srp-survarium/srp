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


void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Pop<Scaleform::GFx::AS3::Value>(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        Scaleform::GFx::AS3::Value *result)
{
  const Scaleform::GFx::AS3::Value *v3; // eax
  Scaleform::GFx::AS3::CheckResult v4; // [esp+7h] [ebp-11h] BYREF
  Scaleform::GFx::AS3::Value v5; // [esp+8h] [ebp-10h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &v4)->Result )
  {
    if ( this->ValueA.Data.Size )
    {
      v3 = Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
             &this->ValueA,
             &v5);
      Scaleform::GFx::AS3::Value::Assign(result, v3);
      if ( (v5.Flags & 0x1F) > 9 )
      {
        if ( (v5.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v5);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v5);
      }
    }
  }
}
