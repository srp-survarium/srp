void __userpurge vostok::render::res_effect::get_max_used_texture_dimension(
        vostok::render::res_effect *this@<ecx>,
        int a2@<eax>,
        unsigned int *out_width,
        unsigned int *out_height)
{
  int v4; // edi
  int v5; // ebx
  vostok::render::res_texture *v6; // ecx
  int v7; // esi
  vostok::render::res_texture *v8; // ecx
  unsigned int v9; // eax
  unsigned int v10; // edx
  int i; // [esp+4h] [ebp-Ch]
  vostok::render::res_texture *j; // [esp+8h] [ebp-8h]
  int v13; // [esp+Ch] [ebp-4h]

  *out_height = 0;
  *out_width = 0;
  v4 = *(_DWORD *)(a2 + 22052);
  for ( i = *(_DWORD *)(a2 + 22056); v4 != i; v4 += 4 )
  {
    v5 = *(_DWORD *)(*(_DWORD *)v4 + 8);
    v13 = *(_DWORD *)(*(_DWORD *)v4 + 12);
    while ( v5 != v13 )
    {
      v6 = *(vostok::render::res_texture **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)v5 + 16) + 12) + 4);
      for ( j = *(vostok::render::res_texture **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)v5 + 16) + 12) + 8);
            v6 != j;
            v6 = (vostok::render::res_texture *)((char *)v6 + 4) )
      {
        v7 = (int)v6->__vftable;
        if ( v6->__vftable )
        {
          vostok::render::res_texture::width(v6, (int)v6->__vftable);
          v9 = vostok::render::res_texture::height(v8, v7);
          if ( v10 > *out_width )
            *out_width = v10;
          if ( v9 > *out_height )
            *out_height = v9;
        }
      }
      v5 += 4;
    }
  }
}
