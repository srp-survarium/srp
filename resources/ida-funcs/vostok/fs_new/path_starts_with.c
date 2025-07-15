bool __usercall vostok::fs_new::path_starts_with@<al>(const char *path@<esi>, char *with)
{
  bool result; // al
  unsigned int v3; // kr00_4
  int v4; // eax

  result = vostok::strings::starts_with(path, with);
  if ( result )
  {
    v3 = strlen(with);
    v4 = path[v3];
    return !path[v3] || v4 == 92 || v4 == 47;
  }
  return result;
}
