char __thiscall SpeedTree::CParser::ParseHeader(SpeedTree::CParser *this)
{
  int v1; // eax
  void **v3; // [esp+11Ch] [ebp-11Ch] BYREF
  unsigned __int8 str2[256]; // [esp+124h] [ebp-114h] BYREF
  char v5; // [esp+22Bh] [ebp-Dh]
  int v6; // [esp+234h] [ebp-4h]

  v5 = 0;
  if ( *((_DWORD *)this + 1) >= (unsigned int)(*((_DWORD *)this + 2) + 16) )
  {
    v3 = &SpeedTree::CBasicFixedString<1024>::`vftable';
    SpeedTree::CBasicFixedString<1024>::operator=((unsigned __int8 *)&buf);
    v6 = 0;
    if ( !(unsigned __int8)SpeedTree::CParser::ParseString(&v3, 16) || (strcmp(c_pSrtHeader, str2), v1) )
      SpeedTree::CCore::SetError(
        "CParser::ParseHeader, expected header [%s] but got [%s]\n",
        (const char *)c_pSrtHeader,
        (const char *)str2);
    else
      v5 = 1;
    v6 = -1;
    v3 = &SpeedTree::CBasicFixedString<1024>::`vftable';
  }
  return v5;
}
