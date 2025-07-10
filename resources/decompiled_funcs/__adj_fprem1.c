int __usercall __spoils<ecx,st0> _adj_fprem1@<eax>(double a1@<st1>, double a2@<st0>)
{
  int result; // eax
  char v3; // dl
  _BYTE v4[20]; // [esp+0h] [ebp-34h]
  int v5; // [esp+14h] [ebp-20h]
  __int128 v6; // [esp+18h] [ebp-1Ch]

  *(double *)&v6 = a1;
  *(double *)v4 = a2;
  if ( (*(_DWORD *)&v4[6] & 0x7FFF0000) != 0 )
    return _fprem1_common(0, *(__int128 *)v4, *(int *)&v4[16], v5, v6);
  result = *(_DWORD *)&v4[4] | *(_DWORD *)v4;
  if ( a2 != 0.0 )
  {
    *(double *)&v4[12] = a2;
    v3 = 2;
    if ( (WORD4(v6) & 0x7FFFu) <= 0x7FBE )
    {
      v3 = 3;
      *(double *)&v6 = a1 * *(double *)&one_shl_64;
    }
    *(double *)v4 = a2 * *(double *)&one_shl_64;
    return _fprem1_common(v3, *(__int128 *)v4, HIDWORD(*(unsigned __int64 *)&a2), v5, v6);
  }
  return result;
}
