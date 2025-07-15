void __thiscall Scaleform::GFx::AS2::Value::Sub(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value *v)
{
  double v4; // [esp+8h] [ebp-10h]
  double v5; // [esp+10h] [ebp-8h]

  v4 = Scaleform::GFx::AS2::Value::ToNumber(this, penv);
  v5 = Scaleform::GFx::AS2::Value::ToNumber(v, penv);
  if ( this->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(this);
  this->T.Type = 3;
  this->NV.NumberValue = v4 - v5;
}


void __thiscall Scaleform::GFx::AS2::Value::Sub(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv,
        int v2)
{
  double v4; // [esp+4h] [ebp-8h]

  v4 = Scaleform::GFx::AS2::Value::ToNumber(this, penv);
  if ( this->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(this);
  this->T.Type = 3;
  this->NV.NumberValue = v4 - (double)v2;
}
