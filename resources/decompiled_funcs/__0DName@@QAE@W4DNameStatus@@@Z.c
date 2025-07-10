DName *__thiscall DName::DName(DName *this, DNameStatus st)
{
  char v3; // al
  DNameStatusNode *v4; // eax

  *((_DWORD *)this + 1) &= 0xFFFF00FF;
  if ( st == DN_invalid || st == DN_error )
    v3 = st;
  else
    v3 = 0;
  this->node = 0;
  *((_BYTE *)this + 4) = v3;
  if ( st == DN_truncated )
  {
    v4 = DNameStatusNode::make(DN_truncated);
    this->node = v4;
    if ( !v4 )
      *((_BYTE *)this + 4) = 3;
  }
  return this;
}
