DName *__thiscall DName::operator=(DName *this, char ch)
{
  *((_BYTE *)this + 4) = 0;
  *((_DWORD *)this + 1) &= 0xFFFF00FF;
  this->node = 0;
  if ( ch )
    DName::doPchar(this, &ch, 1);
  return this;
}
