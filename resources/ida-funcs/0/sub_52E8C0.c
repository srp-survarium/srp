BOOL __cdecl sub_52E8C0(int a1, unsigned __int8 *a2)
{
  BOOL v3; // [esp+0h] [ebp-14h]
  BOOL v4; // [esp+4h] [ebp-10h]
  BOOL v6; // [esp+Ch] [ebp-8h]
  BOOL v7; // [esp+10h] [ebp-4h]

  v3 = 1;
  if ( (a2[3] & 0x80) != 0 && (a2[3] & 0xC0) != 0xC0 && (a2[2] & 0x80) != 0 && (a2[2] & 0xC0) != 0xC0 )
  {
    if ( *a2 == 240 )
    {
      v7 = a2[1] < 0x90u || (a2[1] & 0xC0) == 0xC0;
      v6 = v7;
    }
    else
    {
      v4 = 1;
      if ( (a2[1] & 0x80) != 0 && !(*a2 == 244 ? a2[1] > 0x8Fu : (a2[1] & 0xC0) == 192) )
        v4 = 0;
      v6 = v4;
    }
    if ( !v6 )
      return 0;
  }
  return v3;
}
