DName *__thiscall DName::operator+=(DName *this, DNameStatus st)
{
  DNameStatusNode *v3; // eax

  if ( *((char *)this + 4) <= 1 )
  {
    if ( !this->node || st == DN_invalid || st == DN_error )
    {
      DName::operator=(this, st);
    }
    else if ( st )
    {
      v3 = DNameStatusNode::make(st);
      DName::append(this, v3);
    }
  }
  return this;
}
