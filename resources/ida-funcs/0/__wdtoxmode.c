unsigned int __usercall __wdtoxmode@<eax>(int a1@<ebx>, char attr, const wchar_t *name)
{
  const wchar_t *v3; // ecx
  wchar_t v4; // dx
  int v5; // edi
  unsigned int v6; // edi
  wchar_t *v7; // eax
  wchar_t *v8; // esi

  v3 = name;
  if ( name[1] == 58 )
    v3 = name + 2;
  v4 = *v3;
  if ( (*v3 == 92 || v4 == 47) && !v3[1] || (attr & 0x10) != 0 || (v5 = 0x8000, !v4) )
    v5 = 16448;
  v6 = ~(attr << 7) & 0x80 | 0x100 | v5;
  v7 = wcsrchr(name, 0x2Eu);
  v8 = v7;
  if ( v7
    && (!_wcsicmp(a1, v6, v7, (wchar_t *)L".exe")
     || !_wcsicmp(a1, v6, v8, (wchar_t *)L".cmd")
     || !_wcsicmp(a1, v6, v8, (wchar_t *)L".bat")
     || !_wcsicmp(a1, v6, v8, (wchar_t *)L".com")) )
  {
    v6 |= 0x40u;
  }
  return (v6 >> 3) & 0x38 | v6 | (((v6 >> 3) & 0x38 | v6) >> 6) & 7;
}
