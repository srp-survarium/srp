void __thiscall Scaleform::MsgFormat::BindNonPos(Scaleform::MsgFormat *this)
{
  Scaleform::ResourceFormatter::ValueType v; // [esp+4h] [ebp-30h] BYREF
  Scaleform::ResourceFormatter fr; // [esp+10h] [ebp-24h] BYREF

  v.IsString = 1;
  v.RC_Provider = 0;
  v.Resource.RLong = 0;
  Scaleform::ResourceFormatter::ResourceFormatter(&fr, this, &v);
  if ( Scaleform::MsgFormat::NextFormatter(this) )
    Scaleform::MsgFormat::Bind(this, &fr, 0);
  if ( --this->NonPosParamNum )
    Scaleform::MsgFormat::BindNonPos(this);
  else
    Scaleform::MsgFormat::MakeString(this);
}
