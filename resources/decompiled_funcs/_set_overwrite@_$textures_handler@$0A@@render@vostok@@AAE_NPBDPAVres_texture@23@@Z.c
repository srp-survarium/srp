char __thiscall vostok::render::textures_handler<0>::set_overwrite(
        vostok::render::textures_handler<0> *this,
        char *name,
        vostok::render::res_texture *texture,
        vostok::render::res_texture *texturea)
{
  int *v4; // eax
  int v5; // eax
  const char **v6; // esi
  unsigned int v7; // edi
  unsigned int v8; // ebp
  const char *v9; // eax
  int v10; // eax
  const vostok::render::res_texture_list *v12; // edi
  vostok::render::res_texture *v13; // ecx
  const char *v14; // esi
  unsigned int v15; // edi
  unsigned int v16; // eax
  const char *v17; // ecx
  const vostok::render::res_texture_list *v18; // eax
  bool v19; // zf
  vostok::render::res_texture *v20; // edx
  vostok::render::res_texture **v21; // eax
  vostok::render::res_texture *v22; // ecx
  vostok::render::res_texture *v23; // esi
  unsigned int v24; // [esp-8h] [ebp-18h]
  unsigned int v25; // [esp-4h] [ebp-14h]

  v4 = (int *)*((_DWORD *)name + 131);
  if ( !*v4 )
    return 0;
  v5 = *v4;
  v6 = *(const char ***)(v5 + 1396);
  v7 = (*(_DWORD *)(v5 + 1400) - (int)v6) / 84;
  v8 = 0;
  if ( !v7 )
    return 0;
  while ( 1 )
  {
    v9 = *v6;
    if ( *v6 )
    {
      v10 = texture ? strcmp(v9, (const char *)texture) : *v9 != 0;
    }
    else
    {
      if ( !texture )
        break;
      v10 = -(LOBYTE(texture->__vftable) != 0);
    }
    if ( !v10 )
      break;
    ++v8;
    v6 += 21;
    if ( v8 >= v7 )
      return 0;
  }
  v12 = *(const vostok::render::res_texture_list **)name;
  if ( *(_DWORD *)name
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v13 = texturea;
    if ( v12->m_container._M_impl._M_start[v8].m_object != texturea )
    {
      if ( v12 != (const vostok::render::res_texture_list *)(name + 528) )
      {
        *((_DWORD *)name + 132) = v12->m_reference_count;
        stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>>::operator=(
          (stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > > *)v13,
          &v12->m_container._M_impl);
        name[544] = v12->m_is_registered;
      }
      v14 = name + 532;
      v15 = v8 + 1;
      v24 = (*((_DWORD *)name + 134) - *((_DWORD *)name + 133)) >> 2;
      texture = 0;
      v16 = vostok::math::max(v24, v8 + 1);
      stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>>::resize(
        (stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > > *)(name + 532),
        v16,
        (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&texture);
      goto LABEL_19;
    }
    return 0;
  }
  v15 = v8 + 1;
  v14 = name + 532;
  texture = 0;
  stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>>::resize(
    (stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > > *)(name + 532),
    v8 + 1,
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&texture);
LABEL_19:
  v25 = *((_DWORD *)name + 2);
  *((_DWORD *)name + 1) += v8 < *((_DWORD *)name + 1) ? v8 - *((_DWORD *)name + 1) : 0;
  *((_DWORD *)name + 2) = vostok::math::max(v15, v25);
  v17 = 0;
  if ( name != (char *)-528 )
  {
    ++*((_DWORD *)name + 132);
    v17 = name + 528;
  }
  v18 = *(const vostok::render::res_texture_list **)name;
  *(_DWORD *)name = v17;
  if ( v18 )
  {
    v19 = v18->m_reference_count-- == 1;
    if ( v19 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v18);
  }
  v20 = texturea;
  v21 = (vostok::render::res_texture **)(*(_DWORD *)v14 + 4 * v8);
  v22 = 0;
  if ( texturea )
  {
    ++texturea->m_reference_count;
    v22 = v20;
  }
  v23 = *v21;
  *v21 = v22;
  if ( v23 )
  {
    v19 = v23->m_reference_count-- == 1;
    if ( v19 )
      vostok::render::res_texture::destroy_impl(v22);
  }
  return 1;
}
