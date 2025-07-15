void __thiscall Scaleform::GFx::AS2::BooleanObject::SetValue(
        Scaleform::GFx::AS2::BooleanObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value *v)
{
  this->bValue = Scaleform::GFx::AS2::Value::ToBool(v, penv);
}
