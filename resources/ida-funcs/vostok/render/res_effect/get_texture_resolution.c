vostok::render::res_effect *__fastcall vostok::render::res_effect::get_texture_resolution(
        vostok::render::res_effect *this,
        int a2)
{
  int *v2; // eax
  int *v3; // edx
  int i; // esi
  int v6; // eax
  int v7; // edx
  int v8; // eax
  int v9; // edx
  unsigned int v10; // eax
  vostok::render::res_texture *v11; // ecx
  int v12; // edx
  unsigned int v13; // eax

  v2 = *(int **)(a2 + 22052);
  v3 = *(int **)(a2 + 22056);
  for ( i = 0; ; ++i )
  {
    if ( v2 == v3 )
      goto LABEL_5;
    if ( i == 12 )
      break;
    ++v2;
  }
  v6 = *v2;
  v7 = *(_DWORD *)(v6 + 8);
  if ( v7 == *(_DWORD *)(v6 + 12) )
  {
LABEL_5:
    this->__vftable = 0;
    this->type = 0;
    return this;
  }
  v8 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v7 + 16) + 12);
  v9 = *(_DWORD *)(v8 + 8) - *(_DWORD *)(v8 + 4);
  this->__vftable = 0;
  this->type = 0;
  if ( v9 >> 2 )
  {
    v10 = vostok::render::res_texture::width((vostok::render::res_texture *)this, **(_DWORD **)(v8 + 4));
    v11->__vftable = (vostok::render::res_texture_vtbl *)v10;
    v13 = vostok::render::res_texture::height(v11, v12);
    this->type = v13;
  }
  return this;
}
