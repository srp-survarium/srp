void __thiscall Scaleform::MsgFormat::BindNonPos(Scaleform::MsgFormat *this)
{
  Scaleform::ResourceFormatter::ValueType v; // [esp+4h] [ebp-30h] BYREF
  Scaleform::ResourceFormatter v3; // [esp+10h] [ebp-24h] BYREF

  v.IsString = 1;
  v.RC_Provider = 0;
  v.Resource.RLong = 0;
  Scaleform::ResourceFormatter::ResourceFormatter(&v3, this, &v);
  if ( Scaleform::MsgFormat::NextFormatter(this) )
    Scaleform::MsgFormat::Bind(this, &v3, 0);
  if ( --this->NonPosParamNum )
    Scaleform::MsgFormat::BindNonPos(this);
  else
    Scaleform::MsgFormat::MakeString(this);
}
