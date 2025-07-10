void __thiscall Scaleform::GFx::AS3::Instances::fl::Array::AS3join(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::ASStringNode *argc,
        Scaleform::GFx::AS3::Value *argv)
{
  const Scaleform::GFx::ASString *v5; // eax
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString sep; // [esp+4h] [ebp-4h] BYREF

  sep.pNode = this->pTraits.pObject->pVM->StringManagerRef->Builtins[14].pNode;
  ++sep.pNode->RefCount;
  if ( !argc
    || Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&argc, &sep)->Result )
  {
    v5 = Scaleform::GFx::AS3::Instances::fl::Array::ToStringInternal(this, (Scaleform::GFx::ASString *)&argc, &sep);
    Scaleform::GFx::AS3::Value::Assign(result, v5);
    v6 = argc;
    --argc->RefCount;
    if ( !v6->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  }
  pNode = sep.pNode;
  --sep.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
