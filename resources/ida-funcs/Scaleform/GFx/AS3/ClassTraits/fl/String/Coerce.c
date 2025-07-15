char __thiscall Scaleform::GFx::AS3::ClassTraits::fl::String::Coerce(
        Scaleform::GFx::AS3::ClassTraits::fl::String *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v4; // ecx
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString r; // [esp+0h] [ebp-4h] BYREF

  r.pNode = (Scaleform::GFx::ASStringNode *)this;
  v4 = value;
  if ( (value->Flags & 0x1F) == 0 || (value->Flags & 0x1F) - 12 <= 3 && !value->value.VS._1.VInt )
  {
    Scaleform::GFx::AS3::Value::Assign(result, 0);
    return 1;
  }
  pStringManager = this->pVM->StringManagerRef->pStringManager;
  r.pNode = &pStringManager->EmptyStringNode;
  ++pStringManager->EmptyStringNode.RefCount;
  if ( Scaleform::GFx::AS3::Value::Convert2String(v4, (Scaleform::GFx::AS3::CheckResult *)&value, &r)->Result )
  {
    Scaleform::GFx::AS3::Value::Assign(result, &r);
    pNode = r.pNode;
    --r.pNode->RefCount;
    if ( !pNode->RefCount )
    {
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      return 1;
    }
    return 1;
  }
  v6 = r.pNode;
  --r.pNode->RefCount;
  if ( !v6->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  return 0;
}
