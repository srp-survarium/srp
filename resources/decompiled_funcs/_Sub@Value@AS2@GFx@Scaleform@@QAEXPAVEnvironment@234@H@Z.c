void __thiscall Scaleform::GFx::AS2::Value::Sub(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv,
        int v2)
{
  double v1; // [esp+4h] [ebp-8h]

  v1 = Scaleform::GFx::AS2::Value::ToNumber(this, penv);
  if ( this->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(this);
  this->T.Type = 3;
  this->NV.NumberValue = v1 - (double)v2;
}
