unsigned int __cdecl __dtoxmode(char attr, const char *name)
{
  const char *v2; // ecx
  char v3; // dl
  int v4; // edi
  unsigned int v5; // edi
  const unsigned __int8 *v6; // eax
  const unsigned __int8 *v7; // esi

  v2 = name;
  if ( name[1] == 58 )
    v2 = name + 2;
  v3 = *v2;
  if ( (*v2 == 92 || v3 == 47) && !v2[1] || (attr & 0x10) != 0 || (v4 = 0x8000, !v3) )
    v4 = 16448;
  v5 = ~(attr << 7) & 0x80 | 0x100 | v4;
  v6 = _mbsrchr((const unsigned __int8 *)name, 0x2Eu);
  v7 = v6;
  if ( v6 && (!_mbsicmp(v6, ".exe") || !_mbsicmp(v7, ".cmd") || !_mbsicmp(v7, ".bat") || !_mbsicmp(v7, ".com")) )
    v5 |= 0x40u;
  return (v5 >> 3) & 0x38 | v5 | (((v5 >> 3) & 0x38 | v5) >> 6) & 7;
}
