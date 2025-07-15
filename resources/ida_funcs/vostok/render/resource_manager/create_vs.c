vostok::render::res_sampler_list *__userpurge vostok::render::resource_manager::create_vs@<eax>(
        stlp_std::priv::_Rb_tree_node_base *binder@<eax>,
        stlp_std::priv::_Rb_tree<vostok::render::res_xs<vostok::render::vs_data> *,vostok::render::resource_manager::compare_shader_predicate<vostok::render::vs_data>,vostok::render::res_xs<vostok::render::vs_data> *,stlp_std::priv::_Identity<vostok::render::res_xs<vostok::render::vs_data> *>,stlp_std::priv::_SetTraitsT<vostok::render::res_xs<vostok::render::vs_data> *>,vostok::render::std_allocator<vostok::render::res_xs<vostok::render::vs_data> *> > *a2@<ecx>,
        vostok::render::resource_manager *this)
{
  vostok::render::set<vostok::render::res_xs<vostok::render::vs_data> *,vostok::render::resource_manager::compare_shader_predicate<vostok::render::vs_data> > *p_m_v_shaders; // ebx
  const stlp_std::priv::_Rb_tree<vostok::render::res_xs<vostok::render::vs_data> *,vostok::render::resource_manager::compare_shader_predicate<vostok::render::vs_data>,vostok::render::res_xs<vostok::render::vs_data> *,stlp_std::priv::_Identity<vostok::render::res_xs<vostok::render::vs_data> *>,stlp_std::priv::_SetTraitsT<vostok::render::res_xs<vostok::render::vs_data> *>,vostok::render::std_allocator<vostok::render::res_xs<vostok::render::vs_data> *> > *v5; // eax
  vostok::render::res_xs<vostok::render::vs_data> *v7; // eax
  int v8; // eax
  int v9; // esi
  vostok::render::res_xs<vostok::render::vs_data> *v10; // ecx
  vostok::render::grass_render_model *m_object; // edi
  void *v12; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::res_xs<vostok::render::vs_data> *__val; // [esp+10h] [ebp-8h] BYREF
  char v15; // [esp+14h] [ebp-4h]

  p_m_v_shaders = &this->m_v_shaders;
  v5 = stlp_std::priv::_Rb_tree<vostok::render::res_xs<vostok::render::vs_data> *,vostok::render::resource_manager::compare_shader_predicate<vostok::render::vs_data>,vostok::render::res_xs<vostok::render::vs_data> *,stlp_std::priv::_Identity<vostok::render::res_xs<vostok::render::vs_data> *>,stlp_std::priv::_SetTraitsT<vostok::render::res_xs<vostok::render::vs_data> *>,vostok::render::std_allocator<vostok::render::res_xs<vostok::render::vs_data> *>>::_M_find<vostok::render::xs_descriptor<vostok::render::vs_data>>(
         a2,
         &this->m_v_shaders._M_t,
         binder);
  if ( v5 != (const stlp_std::priv::_Rb_tree<vostok::render::res_xs<vostok::render::vs_data> *,vostok::render::resource_manager::compare_shader_predicate<vostok::render::vs_data>,vostok::render::res_xs<vostok::render::vs_data> *,stlp_std::priv::_Identity<vostok::render::res_xs<vostok::render::vs_data> *>,stlp_std::priv::_SetTraitsT<vostok::render::res_xs<vostok::render::vs_data> *>,vostok::render::std_allocator<vostok::render::res_xs<vostok::render::vs_data> *> > *)p_m_v_shaders )
    return (vostok::render::res_sampler_list *)v5->_M_node_count;
  v7 = (vostok::render::res_xs<vostok::render::vs_data> *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                            (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                            0x18u);
  if ( v7 )
  {
    vostok::render::res_xs<vostok::render::vs_data>::res_xs<vostok::render::vs_data>(
      v7,
      (const vostok::render::xs_descriptor<vostok::render::vs_data> *)binder);
    v9 = v8;
  }
  else
  {
    v9 = 0;
  }
  this = (vostok::render::resource_manager *)v9;
  *(_BYTE *)(v9 + 20) = 1;
  stlp_std::priv::_Rb_tree<vostok::render::res_xs<vostok::render::vs_data> *,vostok::render::resource_manager::compare_shader_predicate<vostok::render::vs_data>,vostok::render::res_xs<vostok::render::vs_data> *,stlp_std::priv::_Identity<vostok::render::res_xs<vostok::render::vs_data> *>,stlp_std::priv::_SetTraitsT<vostok::render::res_xs<vostok::render::vs_data> *>,vostok::render::std_allocator<vostok::render::res_xs<vostok::render::vs_data> *>>::insert_unique(
    (stlp_std::priv::_Rb_tree<vostok::render::res_xs<vostok::render::vs_data> *,vostok::render::resource_manager::compare_shader_predicate<vostok::render::vs_data>,vostok::render::res_xs<vostok::render::vs_data> *,stlp_std::priv::_Identity<vostok::render::res_xs<vostok::render::vs_data> *>,stlp_std::priv::_SetTraitsT<vostok::render::res_xs<vostok::render::vs_data> *>,vostok::render::std_allocator<vostok::render::res_xs<vostok::render::vs_data> *> > *)&__val,
    &p_m_v_shaders->_M_t,
    &__val,
    (vostok::render::res_xs<vostok::render::vs_data> *const *)&this);
  if ( !v15 )
  {
    m_object = vostok::render::g_allocator.m_object;
    vostok::render::res_xs<vostok::render::vs_data>::~res_xs<vostok::render::vs_data>(v10, v9);
    v12 = (void *)v9;
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
    BYTE2(m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v12);
    return __val->m_samplers.m_object;
  }
  return (vostok::render::res_sampler_list *)v9;
}
