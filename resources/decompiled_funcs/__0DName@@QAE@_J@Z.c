DName *__thiscall DName::DName(DName *this, __int64 num)
{
  unsigned int v2; // eax
  char *v4; // edi
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // rcx
  bool fSigned; // [esp+13h] [ebp-1Dh]
  char buf[24]; // [esp+14h] [ebp-1Ch] BYREF

  v2 = HIDWORD(num);
  *((_BYTE *)this + 4) = 0;
  *((_DWORD *)this + 1) &= 0xFFFF00FF;
  v4 = &buf[21];
  this->node = 0;
  buf[21] = 0;
  fSigned = 0;
  if ( num < 0 )
  {
    fSigned = 1;
    v2 = (unsigned __int64)-num >> 32;
    LODWORD(num) = -(int)num;
  }
  do
  {
    --v4;
    v6 = __PAIR64__(v2, num) % 0xA;
    v5 = __PAIR64__(v2, num) / 0xA;
    LODWORD(num) = v5;
    *v4 = v6 + 48;
    v2 = HIDWORD(v5);
  }
  while ( __PAIR64__(HIDWORD(v5), num) );
  if ( fSigned )
    *--v4 = 45;
  DName::doPchar(this, v4, &buf[21] - v4);
  return this;
}
