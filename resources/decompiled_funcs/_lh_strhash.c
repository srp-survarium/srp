int __cdecl lh_strhash(const char *c)
{
  const char *v1; // edx
  unsigned int v2; // esi
  char v3; // al
  int v4; // edi
  unsigned int v5; // eax
  int v6; // esi
  int v7; // ecx

  v1 = c;
  v2 = 0;
  if ( !c )
    return 0;
  v3 = *c;
  if ( !*c )
    return 0;
  v4 = 256;
  do
  {
    v5 = v4 | v3;
    v4 += 256;
    v6 = __ROL4__(v2, (v5 ^ (v5 >> 2)) & 0xF);
    v7 = v5 * v5;
    v3 = *++v1;
    v2 = v7 ^ v6;
  }
  while ( v3 );
  return v2 ^ HIWORD(v2);
}
