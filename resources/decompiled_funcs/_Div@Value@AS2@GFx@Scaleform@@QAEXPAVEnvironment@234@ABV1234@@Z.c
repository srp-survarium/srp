void __thiscall Scaleform::GFx::AS2::Value::Div(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value *v)
{
  long double v4; // st7
  double v5; // st6
  double v6; // st7
  double v7; // st7
  double res; // [esp+8h] [ebp-8h]
  double resa; // [esp+8h] [ebp-8h]

  res = Scaleform::GFx::AS2::Value::ToNumber(this, penv);
  v4 = Scaleform::GFx::AS2::Value::ToNumber(v, penv);
  if ( (HIDWORD(res) & 0x7FF00000) == 0x7FF00000 && (unsigned int)&loc_FFFFF & HIDWORD(res) | LODWORD(res) )
    goto LABEL_11;
  v5 = v4;
  v6 = res;
  resa = v5;
  if ( (HIDWORD(resa) & 0x7FF00000) == 0x7FF00000 )
  {
    if ( (unsigned int)&loc_FFFFF & HIDWORD(resa) | LODWORD(resa) )
      goto LABEL_11;
  }
  if ( 0.0 != v5 )
  {
    v7 = v6 / v5;
    goto LABEL_12;
  }
  if ( 0.0 == v6 )
  {
LABEL_11:
    v7 = Scaleform::GFx::NumberUtil::NaN();
  }
  else if ( v6 < 0.0 )
  {
    v7 = Scaleform::GFx::NumberUtil::NEGATIVE_INFINITY();
  }
  else
  {
    v7 = Scaleform::GFx::NumberUtil::POSITIVE_INFINITY();
  }
LABEL_12:
  if ( this->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(this);
  this->T.Type = 3;
  this->NV.NumberValue = v7;
}
