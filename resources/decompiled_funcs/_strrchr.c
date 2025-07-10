void __cdecl strrchr(unsigned __int8 *string, unsigned __int8 chr)
{
  unsigned int v2; // ecx
  unsigned __int8 *v3; // edi
  bool v4; // zf

  v2 = strlen((const char *)string) + 1;
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
