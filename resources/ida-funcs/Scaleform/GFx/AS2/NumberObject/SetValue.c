void __thiscall Scaleform::GFx::AS2::NumberObject::SetValue(
        Scaleform::GFx::AS2::NumberObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value *v)
{
  this->mValue = Scaleform::GFx::AS2::Value::ToNumber(v, penv);
}
