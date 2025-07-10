DName *__thiscall DName::DName(DName *this, unsigned __int64 num)
{
  char *v3; // edi
  unsigned __int64 v4; // rcx
  char buf[24]; // [esp+14h] [ebp-1Ch] BYREF

  *((_BYTE *)this + 4) = 0;
  *((_DWORD *)this + 1) &= 0xFFFF00FF;
  v3 = &buf[20];
  this->node = 0;
  buf[20] = 0;
  do
  {
    --v3;
    v4 = num % 0xA;
    num /= 0xAu;
    *v3 = v4 + 48;
  }
  while ( num );
  DName::doPchar(this, v3, &buf[20] - v3);
  return this;
}
