char __thiscall SpeedTree::CParser::ParseString(_DWORD *this, int a2, int a3)
{
  unsigned __int8 *buf; // [esp+Ch] [ebp-120h]
  void **v6; // [esp+14h] [ebp-118h] BYREF
  char v7; // [esp+11Fh] [ebp-Dh]
  int v8; // [esp+128h] [ebp-4h]

  v7 = 0;
  if ( this[1] >= (unsigned int)(a3 + this[2]) )
  {
    buf = (unsigned __int8 *)(this[2] + *this);
    v6 = &SpeedTree::CBasicFixedString<1024>::`vftable';
    SpeedTree::CBasicFixedString<1024>::operator=(buf);
    v8 = 0;
    SpeedTree::CBasicFixedString<1024>::operator=(a2, (int)&v6);
    v8 = -1;
    v6 = &SpeedTree::CBasicFixedString<1024>::`vftable';
    this[2] += a3;
    return 1;
  }
  return v7;
}
