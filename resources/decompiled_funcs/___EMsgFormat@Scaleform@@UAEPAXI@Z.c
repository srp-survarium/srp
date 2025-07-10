Scaleform::MsgFormat *__thiscall Scaleform::MsgFormat::`vector deleting destructor'(
        Scaleform::MsgFormat *this,
        char a2)
{
  Scaleform::MsgFormat::~MsgFormat(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
