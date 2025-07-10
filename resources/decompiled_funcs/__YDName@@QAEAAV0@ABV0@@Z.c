DName *__thiscall DName::operator+=(DName *this, const DName *rd)
{
  if ( *((char *)this + 4) <= 1 )
  {
    if ( rd->node )
    {
      if ( this->node )
        DName::append(this, rd->node);
      else
        DName::operator=(this, rd);
    }
    else
    {
      DName::operator+=(this, (DNameStatus)*((char *)rd + 4));
    }
  }
  return this;
}
