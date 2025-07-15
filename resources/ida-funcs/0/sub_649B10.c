BOOL __cdecl sub_649B10(int a1, unsigned __int8 *a2)
{
  BOOL v3; // [esp+0h] [ebp-18h]
  BOOL v4; // [esp+4h] [ebp-14h]
  BOOL v6; // [esp+Ch] [ebp-Ch]
  BOOL v7; // [esp+10h] [ebp-8h]

  v3 = 1;
  if ( (a2[2] & 0x80) != 0 && !(*a2 == 239 && a2[1] == 191 ? a2[2] > 0xBDu : (a2[2] & 0xC0) == 192) )
  {
    if ( *a2 == 224 )
    {
      v7 = a2[1] < 0xA0u || (a2[1] & 0xC0) == 0xC0;
      v6 = v7;
    }
    else
    {
      v4 = 1;
      if ( (a2[1] & 0x80) != 0 && !(*a2 == 237 ? a2[1] > 0x9Fu : (a2[1] & 0xC0) == 192) )
        v4 = 0;
      v6 = v4;
    }
    if ( !v6 )
      return 0;
  }
  return v3;
}
