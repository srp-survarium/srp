void __thiscall vostok::render::resource_manager::add_pool_textures(
        vostok::render::resource_manager *this,
        unsigned int offset,
        unsigned int width,
        unsigned int height,
        DXGI_FORMAT format,
        unsigned int *counts,
        unsigned int num_counts,
        unsigned int array_size,
        unsigned int a9)
{
  unsigned int i; // eax
  unsigned int num_mips_for_pool_texture; // esi
  const char *v11; // eax
  int v12; // ebx
  stlp_std::priv::_Rb_tree<vostok::render::texture_pool_key,stlp_std::less<vostok::render::texture_pool_key>,stlp_std::pair<vostok::render::texture_pool_key const ,vostok::render::texture_pool *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::render::texture_pool_key const ,vostok::render::texture_pool *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::texture_pool_key const ,vostok::render::texture_pool *> >,vostok::render::std_allocator<stlp_std::pair<vostok::render::texture_pool_key,vostok::render::texture_pool *> > > *v13; // ecx
  vostok::memory::doug_lea_allocator *v14; // esi
  char *v15; // eax
  vostok::memory::doug_lea_allocator *v16; // ecx
  char *v17; // eax
  stlp_std::map<vostok::render::texture_pool_key,vostok::render::texture_pool *,stlp_std::less<vostok::render::texture_pool_key>,vostok::render::std_allocator<stlp_std::pair<vostok::render::texture_pool_key,vostok::render::texture_pool *> > > *v18; // ecx
  vostok::render::texture_pool *v19; // eax
  vostok::render::texture_pool *v20; // esi
  vostok::buffer_string *v21; // [esp-4h] [ebp-8Ch]
  const char *v22; // [esp+0h] [ebp-88h]
  const char *v23; // [esp+4h] [ebp-84h]
  unsigned int v24; // [esp+8h] [ebp-80h]
  _DWORD v25[3]; // [esp+10h] [ebp-78h] BYREF
  _BYTE v26[64]; // [esp+1Ch] [ebp-6Ch] BYREF
  char v27; // [esp+5Ch] [ebp-2Ch] BYREF
  vostok::render::texture_pool_key __k; // [esp+64h] [ebp-24h] BYREF
  char *string_desc; // [esp+7Ch] [ebp-Ch]
  unsigned int num_textures; // [esp+80h] [ebp-8h]
  unsigned int v31; // [esp+84h] [ebp-4h]

  for ( i = width; ; i = v31 + 1 )
  {
    v31 = i;
    if ( i >= array_size )
      break;
    num_textures = *(_DWORD *)(num_counts + 4 * i) >> width;
    if ( num_textures )
    {
      num_mips_for_pool_texture = vostok::render::get_num_mips_for_pool_texture(height, format);
      v25[0] = v26;
      v25[1] = v26;
      v25[2] = &v27;
      v26[0] = 0;
      v11 = "dxt1";
      if ( counts != (unsigned int *)70 )
        v11 = "dxt5";
      vostok::fs_new::path_string_impl::assignf(
        v25,
        v21,
        (vostok::buffer_string *)"%dx%d %s",
        (const char *)height,
        format,
        v11);
      __k.usage = D3D11_USAGE_DEFAULT;
      string_desc = (char *)v25[0];
      __k.array_size = a9;
      __k.format = (DXGI_FORMAT)counts;
      __k.height = format;
      v12 = *(_DWORD *)(offset + 608476);
      __k.width = height;
      __k.mips = num_mips_for_pool_texture;
      if ( stlp_std::priv::_Rb_tree<vostok::render::texture_pool_key,stlp_std::less<vostok::render::texture_pool_key>,stlp_std::pair<vostok::render::texture_pool_key const,vostok::render::texture_pool *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::render::texture_pool_key const,vostok::render::texture_pool *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::texture_pool_key const,vostok::render::texture_pool *>>,vostok::render::std_allocator<stlp_std::pair<vostok::render::texture_pool_key,vostok::render::texture_pool *>>>::_M_find<vostok::render::texture_pool_key>(
             v13,
             v12 + 4,
             &__k) == (stlp_std::priv::_Rb_tree_node_base *)(v12 + 4) )
      {
        v14 = vostok::render::g_allocator;
        v15 = type_info::raw_name(&vostok::render::texture_pool `RTTI Type Descriptor');
        v17 = vostok::memory::doug_lea_allocator::malloc_impl(v16, (int)v14, 0x3070u, v15, v22, v23, v24);
        if ( v17 )
        {
          vostok::render::texture_pool::texture_pool(
            (int)&__k,
            string_desc,
            (vostok::render::texture_pool *)v17,
            &__k,
            num_textures,
            *(_BYTE *)(v12 + 28));
          v20 = v19;
        }
        else
        {
          v20 = 0;
        }
        *stlp_std::map<vostok::render::texture_pool_key,vostok::render::texture_pool *,stlp_std::less<vostok::render::texture_pool_key>,vostok::render::std_allocator<stlp_std::pair<vostok::render::texture_pool_key,vostok::render::texture_pool *>>>::operator[]<vostok::render::texture_pool_key>(
           v18,
           (stlp_std::priv::_Rb_tree<vostok::render::texture_pool_key,stlp_std::less<vostok::render::texture_pool_key>,stlp_std::pair<vostok::render::texture_pool_key const ,vostok::render::texture_pool *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::render::texture_pool_key const ,vostok::render::texture_pool *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::texture_pool_key const ,vostok::render::texture_pool *> >,vostok::render::std_allocator<stlp_std::pair<vostok::render::texture_pool_key,vostok::render::texture_pool *> > > *)(v12 + 4),
           &__k) = v20;
      }
      height >>= 1;
      format = (unsigned int)format >> 1;
    }
  }
}
