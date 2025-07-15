char __userpurge vostok::render::hw_hiz_occlusion_manager::quary_and_get_results_if_ready@<al>(
        vostok::render::hw_hiz_occlusion_manager *this@<ecx>,
        int a2@<edi>,
        unsigned int *a3@<esi>,
        unsigned __int8 *out_results,
        const unsigned int in_num_results)
{
  int v6; // esi
  vostok::render::res_texture *v7; // ecx
  _BYTE *v8; // esi
  int v9; // edx
  bool v11; // [esp+0h] [ebp-Ch]
  D3D11_MAP mode; // [esp+4h] [ebp-8h] BYREF
  int v13; // [esp+8h] [ebp-4h]

  if ( *(_BYTE *)(a2 + 228) )
    return 1;
  if ( s_hiz5 )
    return 0;
  if ( in_num_results )
  {
    v6 = *(_DWORD *)(a2 + 276);
    if ( v6 )
    {
      mode = 0;
      v8 = vostok::render::res_texture::map2D((vostok::render::res_texture *)this, v6, &mode, 1, a3, v11);
      if ( !v8 )
        return 0;
      v13 = 0;
      if ( *(_DWORD *)(a2 + 264) )
      {
        v7 = *(vostok::render::res_texture **)(a2 + 260);
        while ( 1 )
        {
          v9 = 0;
          if ( v7 )
            break;
LABEL_14:
          v8 += mode;
          if ( (unsigned int)++v13 >= *(_DWORD *)(a2 + 264) )
            goto LABEL_15;
        }
        while ( 1 )
        {
          v7 = (vostok::render::res_texture *)(v9 + v13 * (_DWORD)v7);
          if ( (unsigned int)v7 > in_num_results - 1 )
            break;
          out_results[(_DWORD)v7] = v8[v9];
          v7 = *(vostok::render::res_texture **)(a2 + 260);
          if ( ++v9 >= (unsigned int)v7 )
            goto LABEL_14;
        }
      }
LABEL_15:
      vostok::render::res_texture::unmap2D(v7, *(_DWORD *)(a2 + 276));
    }
  }
  return 1;
}
