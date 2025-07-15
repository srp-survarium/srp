char __userpurge vostok::render::xs_descriptor<vostok::render::gs_data>::set_texture@<al>(
        vostok::render::xs_descriptor<vostok::render::vs_data> *this@<ecx>,
        int a2@<eax>,
        const char *name,
        vostok::render::res_texture *texture)
{
  unsigned int v5; // ebx
  unsigned int v6; // edi
  const char **v7; // esi
  const char *v8; // eax
  int v9; // eax
  vostok::render::res_texture **v11; // eax
  vostok::render::res_texture *v12; // ecx
  vostok::render::res_texture *v13; // esi
  const char *namea; // [esp+14h] [ebp+4h]

  v5 = (*(_DWORD *)(a2 + 1400) - *(_DWORD *)(a2 + 1396)) / 84;
  v6 = 0;
  if ( !v5 )
    return 0;
  v7 = *(const char ***)(a2 + 1396);
  namea = (const char *)v7;
  while ( 1 )
  {
    v8 = *v7;
    if ( *v7 )
    {
      v9 = name ? strcmp(v8, name) : *v8 != 0;
    }
    else
    {
      if ( !name )
        break;
      v9 = -(*name != 0);
    }
    if ( !v9 )
      break;
    ++v6;
    v7 += 21;
    if ( v6 >= v5 )
      return 0;
  }
  v11 = (vostok::render::res_texture **)&namea[84 * v6 + 80];
  v12 = 0;
  if ( texture )
  {
    ++texture->m_reference_count;
    v12 = texture;
  }
  v13 = *v11;
  *v11 = v12;
  if ( v13 )
  {
    if ( v13->m_reference_count-- == 1 )
      vostok::render::res_texture::destroy_impl(v12);
  }
  return 1;
}
