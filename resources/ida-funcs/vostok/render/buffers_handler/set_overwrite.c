char __userpurge vostok::render::buffers_handler<0>::set_overwrite@<al>(
        vostok::render::buffers_handler<0> *this@<ecx>,
        int a2@<eax>,
        vostok::render::shader_buffer *name,
        vostok::render::shader_buffer *buffer)
{
  _DWORD *v5; // eax
  unsigned int v6; // ebx
  int v7; // eax
  vostok::render::shader_buffer *v8; // ecx
  int v9; // eax
  unsigned int v10; // edi
  const vostok::render::res_buffer_list *v12; // eax
  _DWORD *v13; // edi
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *v14; // ebx
  unsigned int v15; // ecx
  unsigned int v16; // eax
  int v17; // ecx
  const vostok::render::res_buffer_list *v18; // eax
  vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v19; // [esp+Ch] [ebp-8h] BYREF
  unsigned int v20; // [esp+10h] [ebp-4h]

  v5 = *(_DWORD **)(a2 + 524);
  v6 = 0;
  if ( !*v5 )
    return 0;
  v7 = *v5 + 13060;
  v8 = *(vostok::render::shader_buffer **)v7;
  v9 = (*(_DWORD *)(v7 + 4) - *(_DWORD *)v7) / 84;
  v20 = 0;
  v10 = v9;
  if ( !v9 )
    return 0;
  v19.m_object = v8;
  while ( vostok::detail::strcmp_s((const char *)v19.m_object->m_reference_count, "light_parameters_buffer") )
  {
    v19.m_object = (vostok::render::shader_buffer *)((char *)v19.m_object + 84);
    v20 = ++v6;
    if ( v6 >= v10 )
      return 0;
  }
  v12 = *(const vostok::render::res_buffer_list **)a2;
  if ( *(_DWORD *)a2
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    if ( v12->m_container.m_begin[v6].m_object != name )
    {
      if ( v12 != (const vostok::render::res_buffer_list *)(a2 + 528) )
        vostok::render::res_buffer_list::operator=(v12, (vostok::render::res_buffer_list *)(a2 + 528));
      v19.m_object = 0;
      v13 = (_DWORD *)(a2 + 532);
      v14 = (vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *)(v6 + 1);
      v15 = (*(_DWORD *)(a2 + 536) - *(_DWORD *)(a2 + 532)) >> 2;
      vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::resize(
        (vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *)(v15 - (v15 < (unsigned int)v14 ? v15 - (_DWORD)v14 : 0)),
        (vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 532),
        &v19);
      goto LABEL_14;
    }
    return 0;
  }
  v19.m_object = 0;
  v14 = (vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *)(v6 + 1);
  v13 = (_DWORD *)(a2 + 532);
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::resize(
    v14,
    (vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 532),
    &v19);
LABEL_14:
  vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(&v19);
  v16 = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(a2 + 4) += v20 < *(_DWORD *)(a2 + 4) ? v20 - *(_DWORD *)(a2 + 4) : 0;
  v17 = 0;
  *(_DWORD *)(a2 + 8) = (char *)v14 - ((unsigned int)v14 < v16 ? (unsigned int)v14 - v16 : 0);
  if ( a2 != -528 )
  {
    ++*(_DWORD *)(a2 + 528);
    v17 = a2 + 528;
  }
  v18 = *(const vostok::render::res_buffer_list **)a2;
  *(_DWORD *)a2 = v17;
  if ( v18 )
    --v18->m_reference_count;
  vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(*v13 + 4 * v20),
    name);
  return 1;
}
