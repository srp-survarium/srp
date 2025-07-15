void __usercall vostok::render::effect_compiler::~effect_compiler(
        vostok::render::effect_compiler *this@<ecx>,
        int a2@<edi>)
{
  char *v2; // eax
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::xs_descriptor<vostok::render::ps_data> *v4; // ecx
  char *v5; // eax
  malloc_state *v6; // esi
  vostok::render::xs_descriptor<vostok::render::gs_data> *v7; // ecx
  vostok::render::vs_data *v8; // ecx
  vostok::render::resource_manager *v9; // ecx
  _DWORD *v10; // eax
  bool v11; // zf
  _DWORD *v12; // eax
  _DWORD *v13; // eax
  _DWORD *v14; // eax
  char *v15; // eax
  malloc_state *v16; // esi
  char *v17; // eax
  malloc_state *v18; // esi

  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *>,vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>(
    *(stlp_std::reverse_iterator<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *> *)(a2 + 36984),
    *(stlp_std::reverse_iterator<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *> *)(a2 + 36980));
  v2 = *(char **)(a2 + 36980);
  if ( v2 )
  {
    m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v2);
  }
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::render::shader_constant_binding *>,vostok::render::shader_constant_binding>(
    *(stlp_std::reverse_iterator<vostok::render::shader_constant_binding *> *)(a2 + 36964),
    *(stlp_std::reverse_iterator<vostok::render::shader_constant_binding *> *)(a2 + 36960));
  v5 = *(char **)(a2 + 36960);
  if ( v5 )
  {
    v6 = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v6, v5);
  }
  vostok::render::xs_descriptor<vostok::render::ps_data>::~xs_descriptor<vostok::render::ps_data>(v4, a2 + 24800);
  vostok::render::xs_descriptor<vostok::render::gs_data>::~xs_descriptor<vostok::render::gs_data>(v7, a2 + 12644);
  vostok::render::vs_data::~vs_data(v8, a2 + 488);
  v10 = *(_DWORD **)(a2 + 484);
  if ( v10 )
  {
    v11 = (*v10)-- == 1;
    if ( v11 )
      vostok::render::resource_manager::release_impl<vostok::render::vs_data>(
        v9,
        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(const vostok::render::res_xs_hw<vostok::render::vs_data> **)(a2 + 484));
  }
  v12 = *(_DWORD **)(a2 + 56);
  if ( v12 )
  {
    v11 = (*v12)-- == 1;
    if ( v11 )
      vostok::render::resource_manager::release_impl<vostok::render::vs_data>(
        *(vostok::render::resource_manager **)(a2 + 56),
        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(const vostok::render::res_xs_hw<vostok::render::vs_data> **)(a2 + 56));
  }
  v13 = *(_DWORD **)(a2 + 52);
  if ( v13 )
  {
    v11 = (*v13)-- == 1;
    if ( v11 )
      vostok::render::resource_manager::release_impl<vostok::render::gs_data>(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(vostok::render::res_xs_hw<vostok::render::gs_data> **)(a2 + 52));
  }
  v14 = *(_DWORD **)(a2 + 48);
  if ( v14 )
  {
    v11 = (*v14)-- == 1;
    if ( v11 )
      vostok::render::resource_manager::release_impl<vostok::render::ps_data>(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(vostok::render::res_xs_hw<vostok::render::ps_data> **)(a2 + 48));
  }
  v15 = *(char **)(a2 + 36);
  if ( v15 )
  {
    v16 = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v16, v15);
  }
  v17 = *(char **)(a2 + 24);
  if ( v17 )
  {
    v18 = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v18, v17);
  }
  if ( *(_DWORD *)(a2 + 8) )
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 16) + 24))(*(_DWORD *)(a2 + 16), *(_DWORD *)(a2 + 8));
}
