bool __cdecl vostok::fs_new::path_starts_with(const char *path, const char *with)
{
  const char *v3; // eax
  bool v5; // [esp+7h] [ebp-11h]
  const char *i; // [esp+8h] [ebp-10h]
  const char *v7; // [esp+Ch] [ebp-Ch]
  unsigned int next_symbol_in_path; // [esp+10h] [ebp-8h]

  v7 = path;
  for ( i = with; *v7 && *i; ++i )
  {
    if ( *v7 != *i )
    {
      v5 = 0;
      goto LABEL_8;
    }
    ++v7;
  }
  v5 = *i == 0;
LABEL_8:
  if ( !v5 )
    return 0;
  v3 = &path[vostok::strings::length(with)];
  next_symbol_in_path = *v3;
  return !*v3 || next_symbol_in_path == 92 || next_symbol_in_path == 47;
}
