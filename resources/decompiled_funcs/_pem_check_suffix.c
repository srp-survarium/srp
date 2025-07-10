int __cdecl pem_check_suffix(const char *pem_str, const char *suffix)
{
  signed int v2; // ecx
  unsigned int v3; // eax
  const char *v5; // ecx

  v2 = strlen(pem_str);
  v3 = strlen(suffix);
  if ( (int)(v3 + 1) < v2 && (v5 = &pem_str[v2 - v3], !strcmp(v5, suffix)) && *(v5 - 1) == 32 )
    return v5 - 1 - pem_str;
  else
    return 0;
}
