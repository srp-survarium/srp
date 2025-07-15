Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Value::ToStringValue(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::ASStringNode *sm)
{
  Scaleform::GFx::AS3::CheckResult *v3; // edi
  Scaleform::GFx::ASStringNode *v5; // eax

  v3 = result;
  sm = (Scaleform::GFx::ASStringNode *)((char *)sm[10].pLower + 32);
  ++sm->RefCount;
  v3->Result = 1;
  if ( Scaleform::GFx::AS3::Value::Convert2String(
         this,
         (Scaleform::GFx::AS3::CheckResult *)&result,
         (Scaleform::GFx::ASString *)&sm)->Result )
    Scaleform::GFx::AS3::Value::Assign(this, (const Scaleform::GFx::ASString *)&sm);
  else
    v3->Result = 0;
  v5 = sm;
  --sm->RefCount;
  if ( !v5->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  return v3;
}
