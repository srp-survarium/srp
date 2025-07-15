void __thiscall Scaleform::MsgFormat::FinishFormatD(Scaleform::MsgFormat *this)
{
  if ( this->NonPosParamNum )
  {
    this->FirstArgNum = -1;
    Scaleform::MsgFormat::BindNonPos(this);
  }
  else
  {
    Scaleform::MsgFormat::MakeString(this);
  }
}
