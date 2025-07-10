DName *__thiscall DName::operator=(DName *this, DNameStatus st)
{
  DNameStatusNode *v3; // eax

  *((_DWORD *)this + 1) &= 0xFFFF00FF;
  *((_BYTE *)this + 4) = st;
  if ( st == DN_truncated )
  {
    v3 = DNameStatusNode::make(DN_truncated);
    this->node = v3;
    if ( !v3 )
      *((_BYTE *)this + 4) = 3;
  }
  else
  {
    this->node = 0;
  }
  return this;
}
