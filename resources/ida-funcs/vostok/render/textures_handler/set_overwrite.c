char __userpurge vostok::render::textures_handler<1>::set_overwrite@<al>(
        vostok::render::textures_handler<1> *this@<ecx>,
        int a2@<eax>,
        const char *name,
        vostok::render::res_texture *texture)
{
  _DWORD *v5; // eax
  unsigned int v6; // edi
  const char ***v7; // eax
  unsigned int v8; // ebx
  unsigned int *v10; // eax
  _DWORD *v11; // ebx
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *v12; // edi
  unsigned int v13; // ecx
  unsigned int v14; // eax
  const char **i; // [esp+10h] [ebp-8h]
  unsigned int v16; // [esp+14h] [ebp-4h]

  v5 = *(_DWORD **)(a2 + 524);
  v6 = 0;
  if ( !*v5 )
    return 0;
  v7 = (const char ***)(*v5 + 2296);
  v16 = 0;
  v8 = ((char *)v7[1] - (char *)*v7) / 84;
  if ( !v8 )
    return 0;
  for ( i = *v7; vostok::detail::strcmp_s(*i, name); i += 21 )
  {
    v16 = ++v6;
    if ( v6 >= v8 )
      return 0;
  }
  v10 = *(unsigned int **)a2;
  if ( *(_DWORD *)a2
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    if ( *(vostok::render::res_texture **)(v10[1] + 4 * v6) != texture )
    {
      if ( v10 != (unsigned int *)(a2 + 528) )
        vostok::render::res_texture_list::operator=(
          (vostok::render::res_texture_list *)(a2 + 528),
          (const vostok::render::res_texture_list *)(a2 + 528),
          *(unsigned int **)a2);
      name = 0;
      v11 = (_DWORD *)(a2 + 532);
      v12 = (vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *)(v6 + 1);
      v13 = (*(_DWORD *)(a2 + 536) - *(_DWORD *)(a2 + 532)) >> 2;
      vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::resize(
        (vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *)(v13 - (v13 < (unsigned int)v12 ? v13 - (_DWORD)v12 : 0)),
        (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 532),
        (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&name);
      goto LABEL_14;
    }
    return 0;
  }
  name = 0;
  v12 = (vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *)(v6 + 1);
  v11 = (_DWORD *)(a2 + 532);
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::resize(
    v12,
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 532),
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&name);
LABEL_14:
  v14 = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(a2 + 4) += v16 < *(_DWORD *)(a2 + 4) ? v16 - *(_DWORD *)(a2 + 4) : 0;
  *(_DWORD *)(a2 + 8) = (char *)v12
                      - (((unsigned int)v12 - v14) & ((unsigned int)((unsigned int)v12 - (unsigned __int64)v14) >> 32));
  vostok::intrusive_ptr<vostok::render::res_texture_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::res_texture_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)a2,
    (vostok::render::res_texture_list *)(a2 + 528));
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    texture,
    (vostok::render::res_texture *)(*v11 + 4 * v16));
  return 1;
}


char __userpurge vostok::render::textures_handler<0>::set_overwrite@<al>(
        vostok::render::textures_handler<0> *this@<ecx>,
        int a2@<eax>,
        vostok::render::res_texture *name,
        vostok::render::res_texture *texture)
{
  _DWORD *v5; // eax
  unsigned int v6; // edi
  int v7; // eax
  vostok::render::res_texture *v8; // ecx
  int v9; // eax
  unsigned int v10; // ebx
  unsigned int *v12; // eax
  _DWORD *v13; // ebx
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *v14; // edi
  unsigned int v15; // ecx
  unsigned int v16; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v17; // [esp+Ch] [ebp-8h] BYREF
  unsigned int v18; // [esp+10h] [ebp-4h]

  v5 = *(_DWORD **)(a2 + 524);
  v6 = 0;
  if ( !*v5 )
    return 0;
  v7 = *v5 + 2296;
  v8 = *(vostok::render::res_texture **)v7;
  v9 = (*(_DWORD *)(v7 + 4) - *(_DWORD *)v7) / 84;
  v18 = 0;
  v10 = v9;
  if ( !v9 )
    return 0;
  v17.m_object = v8;
  while ( vostok::detail::strcmp_s((const char *)v17.m_object->__vftable, "t_probe_cubemap_diffuse") )
  {
    v17.m_object = (vostok::render::res_texture *)((char *)v17.m_object + 84);
    v18 = ++v6;
    if ( v6 >= v10 )
      return 0;
  }
  v12 = *(unsigned int **)a2;
  if ( *(_DWORD *)a2
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    if ( *(vostok::render::res_texture **)(v12[1] + 4 * v6) != name )
    {
      if ( v12 != (unsigned int *)(a2 + 528) )
        vostok::render::res_texture_list::operator=(
          (vostok::render::res_texture_list *)(a2 + 528),
          (const vostok::render::res_texture_list *)(a2 + 528),
          *(unsigned int **)a2);
      v17.m_object = 0;
      v13 = (_DWORD *)(a2 + 532);
      v14 = (vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *)(v6 + 1);
      v15 = (*(_DWORD *)(a2 + 536) - *(_DWORD *)(a2 + 532)) >> 2;
      vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::resize(
        (vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *)(v15 - (v15 < (unsigned int)v14 ? v15 - (_DWORD)v14 : 0)),
        (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 532),
        &v17);
      goto LABEL_14;
    }
    return 0;
  }
  v17.m_object = 0;
  v14 = (vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *)(v6 + 1);
  v13 = (_DWORD *)(a2 + 532);
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::resize(
    v14,
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 532),
    &v17);
LABEL_14:
  v16 = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(a2 + 4) += v18 < *(_DWORD *)(a2 + 4) ? v18 - *(_DWORD *)(a2 + 4) : 0;
  *(_DWORD *)(a2 + 8) = (char *)v14
                      - (((unsigned int)v14 - v16) & ((unsigned int)((unsigned int)v14 - (unsigned __int64)v16) >> 32));
  vostok::intrusive_ptr<vostok::render::res_texture_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::res_texture_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)a2,
    (vostok::render::res_texture_list *)(a2 + 528));
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    name,
    (vostok::render::res_texture *)(*v13 + 4 * v18));
  return 1;
}
