unsigned int __userpurge vostok::console_commands::cc_token::find_id@<eax>(
        vostok::console_commands::cc_token *this@<ecx>,
        int a2@<eax>,
        const char *args)
{
  unsigned int v5; // ebx
  int v6; // esi
  const char **i; // edi
  const char *argsa; // [esp+8h] [ebp+4h]

  if ( !args )
    return -1;
  v5 = *(_DWORD *)(a2 + 68);
  v6 = 0;
  if ( !v5 )
    return -1;
  argsa = *(const char **)(a2 + 64);
  for ( i = (const char **)(argsa + 4); strcmp(*i, args); i += 2 )
  {
    if ( ++v6 >= v5 )
      return -1;
  }
  return *(_DWORD *)&argsa[8 * v6];
}
