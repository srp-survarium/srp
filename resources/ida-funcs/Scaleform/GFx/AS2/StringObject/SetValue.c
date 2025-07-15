void __thiscall Scaleform::GFx::AS2::StringObject::SetValue(
        Scaleform::GFx::AS2::StringObject *this,
        Scaleform::GFx::ASStringNode *penv,
        Scaleform::GFx::AS2::Value *v)
{
  Scaleform::GFx::ASStringNode *v4; // esi

  Scaleform::GFx::AS2::Value::ToStringImpl(
    v,
    (Scaleform::GFx::ASString *)&penv,
    (Scaleform::GFx::AS2::Environment *)penv,
    -1,
    0);
  v4 = penv;
  Scaleform::GFx::ASString::operator=(&this->sValue, (Scaleform::GFx::ASStringNode *)penv->pData);
  if ( v4->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
}
