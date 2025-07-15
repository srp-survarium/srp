void __thiscall Scaleform::GFx::AS2::Value::ConvertToNumber(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *pEnv)
{
  double v3; // [esp+4h] [ebp-8h]

  v3 = Scaleform::GFx::AS2::Value::ToNumber(this, pEnv);
  if ( this->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(this);
  this->T.Type = 3;
  this->NV.NumberValue = v3;
}
