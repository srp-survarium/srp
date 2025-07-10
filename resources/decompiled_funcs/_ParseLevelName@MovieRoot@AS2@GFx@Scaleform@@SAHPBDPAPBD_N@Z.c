unsigned int __usercall Scaleform::GFx::AS2::MovieRoot::ParseLevelName@<eax>(
        char *a1@<ecx>,
        unsigned int a2@<ebx>,
        char *pname,
        char **ptail,
        bool caseSensitive)
{
  char v5; // cl
  unsigned int result; // eax
  char v7; // cl
  char v8; // cl
  char v9; // cl
  char v10; // cl
  char v11; // cl
  char v12; // cl
  const char *v13; // [esp-Ch] [ebp-10h]
  char *ptail2; // [esp+0h] [ebp-4h] BYREF

  ptail2 = a1;
  v5 = *pname;
  if ( *pname >= 48 && v5 <= 57 )
  {
    v13 = pname;
    pname = 0;
    result = strtol(a2, v13, &pname, 0xAu);
    *ptail = pname;
    return result;
  }
  if ( v5 != 95 )
    return -1;
  if ( caseSensitive )
  {
    if ( pname[1] != 108 || pname[2] != 101 || pname[3] != 118 || pname[4] != 101 || pname[5] != 108 )
      return -1;
  }
  else
  {
    v7 = pname[1];
    if ( v7 != 108 && v7 != 76 )
      return -1;
    v8 = pname[2];
    if ( v8 != 101 && v8 != 69 )
      return -1;
    v9 = pname[3];
    if ( v9 != 118 && v9 != 86 )
      return -1;
    v10 = pname[4];
    if ( v10 != 101 && v10 != 69 )
      return -1;
    v11 = pname[5];
    if ( v11 != 108 && v11 != 76 )
      return -1;
  }
  v12 = pname[6];
  if ( v12 < 48 || v12 > 57 )
    return -1;
  ptail2 = 0;
  result = strtol(a2, pname + 6, &ptail2, 0xAu);
  *ptail = ptail2;
  return result;
}
