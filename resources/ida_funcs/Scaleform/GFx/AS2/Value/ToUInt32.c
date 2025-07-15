unsigned int __thiscall Scaleform::GFx::AS2::Value::ToUInt32(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  double X; // st7
  int v4; // ecx
  double v5; // [esp+8h] [ebp-10h]
  double v; // [esp+10h] [ebp-8h]

  if ( this->T.Type == 4 )
    return this->NV.UInt32Value;
  X = Scaleform::GFx::AS2::Value::ToNumber(this, penv);
  v = X;
  v5 = X;
  if ( (HIDWORD(v5) & 0x7FF00000) == 0x7FF00000 || 0.0 == X )
    return 0;
  if ( X < 0.0 )
  {
    X = -X;
  }
  else if ( X <= 4294967295.0 )
  {
    return (__int64)X;
  }
  v4 = (__int64)fmod(floor(X), 4294967296.0);
  if ( v < 0.0 )
    return -v4;
  return v4;
}
