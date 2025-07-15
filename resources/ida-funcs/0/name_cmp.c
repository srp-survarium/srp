int __cdecl name_cmp(char *name, char *cmp)
{
  unsigned int v2; // esi
  int result; // eax
  char v4; // al

  v2 = strlen(cmp);
  result = strncmp(name, cmp, v2);
  if ( !result )
  {
    v4 = name[v2];
    return v4 && v4 != 46;
  }
  return result;
}
