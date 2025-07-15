void __cdecl strrchr(const char *string, unsigned __int8 chr)
{
  unsigned int v2; // ecx
  const char *v3; // edi
  bool v4; // zf

  v2 = strlen(string) + 1;
  v3 = &string[v2 - 1];
  do
  {
    if ( !v2 )
      break;
    v4 = *v3-- == chr;
    --v2;
  }
  while ( !v4 );
}
