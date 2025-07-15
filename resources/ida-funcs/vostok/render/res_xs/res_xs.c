void __userpurge vostok::render::res_xs<vostok::render::gs_data>::res_xs<vostok::render::gs_data>(
        vostok::render::res_xs<vostok::render::gs_data> *this@<ecx>,
        int a2@<edi>,
        const vostok::render::xs_descriptor<vostok::render::gs_data> *binder)
{
  vostok::render::res_xs_hw<vostok::render::gs_data> *m_object; // edx
  vostok::render::resource_manager *v4; // ecx
  vostok::render::shader_constant_table *const_table; // eax
  vostok::render::resource_manager *v7; // ecx
  vostok::fixed_vector<vostok::render::buffer_slot,128> *texture_list; // eax
  vostok::render::resource_manager *v9; // ecx
  vostok::render::res_sampler_list *sampler_list; // eax
  vostok::render::resource_manager *v11; // ecx
  vostok::fixed_vector<vostok::render::buffer_slot,128> *buffer_list; // eax
  vostok::fixed_vector<vostok::render::buffer_slot,128> *v13; // ecx
  _DWORD *v14; // eax

  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 20) = 0;
  *(_BYTE *)(a2 + 24) = 0;
  m_object = 0;
  if ( binder->m_hardware_shader.m_object )
  {
    m_object = binder->m_hardware_shader.m_object;
    ++binder->m_hardware_shader.m_object->m_reference_count;
  }
  v4 = *(vostok::render::resource_manager **)(a2 + 4);
  *(_DWORD *)(a2 + 4) = m_object;
  if ( v4 )
  {
    if ( v4->sh_created-- == 1 )
      vostok::render::resource_manager::release_impl<vostok::render::gs_data>(
        v4,
        (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        (const vostok::render::res_xs_hw<vostok::render::gs_data> *)v4);
  }
  const_table = vostok::render::resource_manager::create_const_table(
                  v4,
                  (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                  (stlp_std::priv::_Rb_tree_node_base **)&binder->m_shader_data.constants);
  vostok::intrusive_ptr<vostok::render::shader_constant_table const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::shader_constant_table const ,vostok::render::resource_intrusive_base const ,vostok::threading::single_threading_policy> *)(a2 + 8),
    const_table);
  texture_list = vostok::render::resource_manager::create_texture_list(
                   v7,
                   (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                   (vostok::fixed_vector<vostok::render::buffer_slot,128> *)&binder->m_shader_data.textures);
  vostok::intrusive_ptr<vostok::render::res_texture_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::res_texture_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 12),
    (vostok::render::res_texture_list *)texture_list);
  sampler_list = (vostok::render::res_sampler_list *)vostok::render::resource_manager::create_sampler_list(
                                                       v9,
                                                       (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                                                       &binder->m_shader_data.samplers);
  vostok::intrusive_ptr<vostok::render::res_sampler_list const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::res_sampler_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 16),
    sampler_list);
  buffer_list = vostok::render::resource_manager::create_buffer_list(
                  v11,
                  (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                  &binder->m_shader_data.buffers);
  v13 = 0;
  if ( buffer_list )
  {
    ++buffer_list->m_begin;
    v13 = buffer_list;
  }
  v14 = *(_DWORD **)(a2 + 20);
  *(_DWORD *)(a2 + 20) = v13;
  if ( v14 )
    --*v14;
}


void __userpurge vostok::render::res_xs<vostok::render::ps_data>::res_xs<vostok::render::ps_data>(
        vostok::render::res_xs<vostok::render::ps_data> *this@<ecx>,
        int a2@<edi>,
        const vostok::render::xs_descriptor<vostok::render::ps_data> *binder)
{
  vostok::render::res_xs_hw<vostok::render::ps_data> *m_object; // edx
  vostok::render::resource_manager *v4; // ecx
  vostok::render::shader_constant_table *const_table; // eax
  vostok::render::resource_manager *v7; // ecx
  vostok::fixed_vector<vostok::render::buffer_slot,128> *texture_list; // eax
  vostok::render::resource_manager *v9; // ecx
  vostok::render::res_sampler_list *sampler_list; // eax
  vostok::render::resource_manager *v11; // ecx
  vostok::fixed_vector<vostok::render::buffer_slot,128> *buffer_list; // eax
  vostok::fixed_vector<vostok::render::buffer_slot,128> *v13; // ecx
  _DWORD *v14; // eax

  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 20) = 0;
  *(_BYTE *)(a2 + 24) = 0;
  m_object = 0;
  if ( binder->m_hardware_shader.m_object )
  {
    m_object = binder->m_hardware_shader.m_object;
    ++binder->m_hardware_shader.m_object->m_reference_count;
  }
  v4 = *(vostok::render::resource_manager **)(a2 + 4);
  *(_DWORD *)(a2 + 4) = m_object;
  if ( v4 )
  {
    if ( v4->sh_created-- == 1 )
      vostok::render::resource_manager::release_impl<vostok::render::ps_data>(
        v4,
        (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        (vostok::render::res_xs_hw<vostok::render::gs_data> *)v4);
  }
  const_table = vostok::render::resource_manager::create_const_table(
                  v4,
                  (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                  (stlp_std::priv::_Rb_tree_node_base **)&binder->m_shader_data.constants);
  vostok::intrusive_ptr<vostok::render::shader_constant_table const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::shader_constant_table const ,vostok::render::resource_intrusive_base const ,vostok::threading::single_threading_policy> *)(a2 + 8),
    const_table);
  texture_list = vostok::render::resource_manager::create_texture_list(
                   v7,
                   (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                   (vostok::fixed_vector<vostok::render::buffer_slot,128> *)&binder->m_shader_data.textures);
  vostok::intrusive_ptr<vostok::render::res_texture_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::res_texture_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 12),
    (vostok::render::res_texture_list *)texture_list);
  sampler_list = (vostok::render::res_sampler_list *)vostok::render::resource_manager::create_sampler_list(
                                                       v9,
                                                       (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                                                       &binder->m_shader_data.samplers);
  vostok::intrusive_ptr<vostok::render::res_sampler_list const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::res_sampler_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 16),
    sampler_list);
  buffer_list = vostok::render::resource_manager::create_buffer_list(
                  v11,
                  (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                  &binder->m_shader_data.buffers);
  v13 = 0;
  if ( buffer_list )
  {
    ++buffer_list->m_begin;
    v13 = buffer_list;
  }
  v14 = *(_DWORD **)(a2 + 20);
  *(_DWORD *)(a2 + 20) = v13;
  if ( v14 )
    --*v14;
}


void __userpurge vostok::render::res_xs<vostok::render::vs_data>::res_xs<vostok::render::vs_data>(
        vostok::render::res_xs<vostok::render::vs_data> *this@<ecx>,
        int a2@<edi>,
        const vostok::render::xs_descriptor<vostok::render::vs_data> *binder)
{
  vostok::render::res_xs_hw<vostok::render::vs_data> *m_object; // edx
  vostok::render::resource_manager *v4; // ecx
  vostok::render::shader_constant_table *const_table; // eax
  vostok::render::resource_manager *v7; // ecx
  vostok::fixed_vector<vostok::render::buffer_slot,128> *texture_list; // eax
  vostok::render::resource_manager *v9; // ecx
  vostok::render::res_sampler_list *sampler_list; // eax
  vostok::render::resource_manager *v11; // ecx
  vostok::fixed_vector<vostok::render::buffer_slot,128> *buffer_list; // eax
  vostok::fixed_vector<vostok::render::buffer_slot,128> *v13; // ecx
  _DWORD *v14; // eax

  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 20) = 0;
  *(_BYTE *)(a2 + 24) = 0;
  m_object = 0;
  if ( binder->m_hardware_shader.m_object )
  {
    m_object = binder->m_hardware_shader.m_object;
    ++binder->m_hardware_shader.m_object->m_reference_count;
  }
  v4 = *(vostok::render::resource_manager **)(a2 + 4);
  *(_DWORD *)(a2 + 4) = m_object;
  if ( v4 )
  {
    if ( v4->sh_created-- == 1 )
      vostok::render::resource_manager::release_impl<vostok::render::vs_data>(
        v4,
        (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        (const vostok::render::res_xs_hw<vostok::render::vs_data> *)v4);
  }
  const_table = vostok::render::resource_manager::create_const_table(
                  v4,
                  (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                  (stlp_std::priv::_Rb_tree_node_base **)&binder->m_shader_data.constants);
  vostok::intrusive_ptr<vostok::render::shader_constant_table const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::shader_constant_table const ,vostok::render::resource_intrusive_base const ,vostok::threading::single_threading_policy> *)(a2 + 8),
    const_table);
  texture_list = vostok::render::resource_manager::create_texture_list(
                   v7,
                   (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                   (vostok::fixed_vector<vostok::render::buffer_slot,128> *)&binder->m_shader_data.textures);
  vostok::intrusive_ptr<vostok::render::res_texture_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::res_texture_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 12),
    (vostok::render::res_texture_list *)texture_list);
  sampler_list = (vostok::render::res_sampler_list *)vostok::render::resource_manager::create_sampler_list(
                                                       v9,
                                                       (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                                                       &binder->m_shader_data.samplers);
  vostok::intrusive_ptr<vostok::render::res_sampler_list const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::res_sampler_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 16),
    sampler_list);
  buffer_list = vostok::render::resource_manager::create_buffer_list(
                  v11,
                  (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                  &binder->m_shader_data.buffers);
  v13 = 0;
  if ( buffer_list )
  {
    ++buffer_list->m_begin;
    v13 = buffer_list;
  }
  v14 = *(_DWORD **)(a2 + 20);
  *(_DWORD *)(a2 + 20) = v13;
  if ( v14 )
    --*v14;
}
