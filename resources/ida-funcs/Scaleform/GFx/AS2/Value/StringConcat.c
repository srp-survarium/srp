void __thiscall Scaleform::GFx::AS2::Value::StringConcat(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::GFx::ASString *str)
{
  Scaleform::GFx::ASStringNode *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::ASString result; // [esp+4h] [ebp-4h] BYREF

  Scaleform::GFx::AS2::Value::ToStringImpl(this, (Scaleform::GFx::ASString *)&penv, penv, -1, 0);
  Scaleform::GFx::ASString::operator+((Scaleform::GFx::ASString *)&penv, &result, str);
  v4 = (Scaleform::GFx::ASStringNode *)penv;
  --penv->Stack.pPageEnd;
  if ( !v4->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  Scaleform::GFx::AS2::Value::DropRefs(this);
  pNode = result.pNode;
  this->NV.Int32Value = (int)result.pNode;
  this->T.Type = 5;
  ++pNode->RefCount;
  v6 = result.pNode;
  --result.pNode->RefCount;
  if ( !v6->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
}
