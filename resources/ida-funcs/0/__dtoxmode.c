unsigned int __usercall __dtoxmode@<eax>(int a1@<ebx>, char attr, const char *name)
{
  const char *v3; // ecx
  char v4; // dl
  int v5; // edi
  unsigned int v6; // edi
  char *v7; // eax
  char *v8; // esi

  v3 = name;
  if ( name[1] == 58 )
    v3 = name + 2;
  v4 = *v3;
  if ( (*v3 == 92 || v4 == 47) && !v3[1] || (attr & 0x10) != 0 || (v5 = 0x8000, !v4) )
    v5 = 16448;
  v6 = ~(attr << 7) & 0x80 | 0x100 | v5;
  _mbsrchr(v6, (int)name, name, 0x2Eu);
  v8 = v7;
  if ( v7
    && (!_mbsicmp(a1, v6, v7, ".exe")
     || !_mbsicmp(a1, v6, v8, ".cmd")
     || !_mbsicmp(a1, v6, v8, ".bat")
     || !_mbsicmp(a1, v6, v8, ".com")) )
  {
    v6 |= 0x40u;
  }
  return (v6 >> 3) & 0x38 | v6 | (((v6 >> 3) & 0x38 | v6) >> 6) & 7;
}
