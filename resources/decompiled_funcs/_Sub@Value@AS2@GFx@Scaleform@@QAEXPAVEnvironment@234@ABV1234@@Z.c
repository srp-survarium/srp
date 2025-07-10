void __thiscall Scaleform::GFx::AS2::Value::Sub(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value *v)
{
  double v1; // [esp+8h] [ebp-10h]
  double v2; // [esp+10h] [ebp-8h]

  v1 = Scaleform::GFx::AS2::Value::ToNumber(this, penv);
  v2 = Scaleform::GFx::AS2::Value::ToNumber(v, penv);
  if ( this->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(this);
  this->T.Type = 3;
  this->NV.NumberValue = v1 - v2;
}
