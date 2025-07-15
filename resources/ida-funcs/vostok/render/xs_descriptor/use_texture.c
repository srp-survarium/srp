char __userpurge vostok::render::xs_descriptor<vostok::render::gs_data>::use_texture@<al>(
        vostok::render::xs_descriptor<vostok::render::vs_data> *this@<ecx>,
        int a2@<eax>,
        const char *name)
{
  unsigned int v3; // edi
  int v4; // ebx
  const char **i; // esi
  const char *v6; // eax
  int v7; // eax

  v3 = (*(_DWORD *)(a2 + 1400) - *(_DWORD *)(a2 + 1396)) / 84;
  v4 = 0;
  if ( !v3 )
    return 0;
  for ( i = *(const char ***)(a2 + 1396); ; i += 21 )
  {
    v6 = *i;
    if ( *i )
    {
      v7 = name ? strcmp(v6, name) : *v6 != 0;
    }
    else
    {
      if ( !name )
        return 1;
      v7 = -(*name != 0);
    }
    if ( !v7 )
      break;
    if ( ++v4 >= v3 )
      return 0;
  }
  return 1;
}
