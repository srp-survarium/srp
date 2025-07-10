void __thiscall vostok::render::effect_manager::~effect_manager(
        vostok::render::effect_manager *this,
        vostok::render::effect_manager *thisa)
{
  vostok::render::effect_manager *v2; // esi
  stlp_std::priv::_Rb_tree_node_base *M_left; // edi
  vostok::render::grass_render_model *m_object; // ebp
  char *v5; // esi
  char *v6; // eax
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi
  stlp_std::priv::_Rb_tree_node_base *v8; // edi
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::texture_pool *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::texture_pool *> > > *p_m_effect_descriptors_by_texture; // ebp
  char *v10; // esi
  char *v11; // eax
  malloc_state *v12; // esi
  char *M_start; // eax
  malloc_state *v14; // esi
  char *v15; // eax
  malloc_state *v16; // esi
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::texture_pool *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::texture_pool *> > > *p_m_techniques; // esi
  vostok::render::grass_render_model *v18; // [esp+10h] [ebp-4h]

  v2 = thisa;
  M_left = thisa->m_effect_descriptors._M_t._M_header._M_data._M_left;
  if ( M_left != (stlp_std::priv::_Rb_tree_node_base *)&thisa->m_effect_descriptors )
  {
    do
    {
      m_object = vostok::render::g_allocator.m_object;
      if ( M_left[9]._M_right )
      {
        v5 = __RTCastToVoid((void **)M_left[9]._M_right);
        (**(void (__thiscall ***)(stlp_std::priv::_Rb_tree_node_base *, _DWORD))M_left[9]._M_right)(
          M_left[9]._M_right,
          0);
        if ( v5 )
        {
          v6 = v5;
          m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
          BYTE2(m_object->m_children_resources.m_lock) = 0;
          vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v6);
        }
        v2 = thisa;
        M_left[9]._M_right = 0;
      }
      M_left = stlp_std::priv::_Rb_global<bool>::_M_increment(M_left);
    }
    while ( M_left != (stlp_std::priv::_Rb_tree_node_base *)&v2->m_effect_descriptors );
  }
  v8 = v2->m_effect_descriptors_by_texture._M_t._M_header._M_data._M_left;
  p_m_effect_descriptors_by_texture = (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::texture_pool *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::texture_pool *> > > *)&v2->m_effect_descriptors_by_texture;
  if ( v8 != (stlp_std::priv::_Rb_tree_node_base *)&v2->m_effect_descriptors_by_texture )
  {
    do
    {
      v18 = vostok::render::g_allocator.m_object;
      if ( v8[9]._M_right )
      {
        v10 = __RTCastToVoid((void **)v8[9]._M_right);
        (**(void (__thiscall ***)(stlp_std::priv::_Rb_tree_node_base *, _DWORD))v8[9]._M_right)(v8[9]._M_right, 0);
        if ( v10 )
        {
          v11 = v10;
          v12 = (malloc_state *)HIDWORD(v18->m_reconstruction_info_actuality_tick);
          BYTE2(v18->m_children_resources.m_lock) = 0;
          vostok_mspace_free(v12, v11);
        }
        v2 = thisa;
        v8[9]._M_right = 0;
      }
      v8 = stlp_std::priv::_Rb_global<bool>::_M_increment(v8);
    }
    while ( v8 != (stlp_std::priv::_Rb_tree_node_base *)p_m_effect_descriptors_by_texture );
  }
  M_start = (char *)v2->m_effects_deleted_in_pending._M_impl._M_start;
  if ( M_start )
  {
    v14 = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v14, M_start);
    v2 = thisa;
  }
  if ( p_m_effect_descriptors_by_texture->_M_node_count )
  {
    stlp_std::priv::_Rb_tree<vostok::render::res_effect *,vostok::render::effect_manager::compare_predicate<vostok::render::res_effect>,vostok::render::res_effect *,stlp_std::priv::_Identity<vostok::render::res_effect *>,stlp_std::priv::_SetTraitsT<vostok::render::res_effect *>,vostok::render::std_allocator<vostok::render::res_effect *>>::_M_erase(
      p_m_effect_descriptors_by_texture,
      p_m_effect_descriptors_by_texture->_M_header._M_data._M_parent);
    p_m_effect_descriptors_by_texture->_M_header._M_data._M_left = (stlp_std::priv::_Rb_tree_node_base *)p_m_effect_descriptors_by_texture;
    p_m_effect_descriptors_by_texture->_M_header._M_data._M_parent = 0;
    p_m_effect_descriptors_by_texture->_M_header._M_data._M_right = (stlp_std::priv::_Rb_tree_node_base *)p_m_effect_descriptors_by_texture;
    p_m_effect_descriptors_by_texture->_M_node_count = 0;
  }
  if ( v2->m_effect_descriptors._M_t._M_node_count )
  {
    stlp_std::priv::_Rb_tree<vostok::render::res_effect *,vostok::render::effect_manager::compare_predicate<vostok::render::res_effect>,vostok::render::res_effect *,stlp_std::priv::_Identity<vostok::render::res_effect *>,stlp_std::priv::_SetTraitsT<vostok::render::res_effect *>,vostok::render::std_allocator<vostok::render::res_effect *>>::_M_erase(
      (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::texture_pool *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::texture_pool *> > > *)&v2->m_effect_descriptors,
      v2->m_effect_descriptors._M_t._M_header._M_data._M_parent);
    v2->m_effect_descriptors._M_t._M_header._M_data._M_left = &v2->m_effect_descriptors._M_t._M_header._M_data;
    v2->m_effect_descriptors._M_t._M_header._M_data._M_parent = 0;
    v2->m_effect_descriptors._M_t._M_header._M_data._M_right = &v2->m_effect_descriptors._M_t._M_header._M_data;
    v2->m_effect_descriptors._M_t._M_node_count = 0;
  }
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::render::effect_manager::effect_holder_struct *>,vostok::render::effect_manager::effect_holder_struct>(
    (stlp_std::reverse_iterator<vostok::render::effect_manager::effect_holder_struct *>)v2->m_effects._M_impl._M_finish,
    (stlp_std::reverse_iterator<vostok::render::effect_manager::effect_holder_struct *>)v2->m_effects._M_impl._M_start);
  v15 = (char *)v2->m_effects._M_impl._M_start;
  if ( v15 )
  {
    v16 = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v16, v15);
    v2 = thisa;
  }
  p_m_techniques = (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::texture_pool *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::texture_pool *> > > *)&v2->m_techniques;
  if ( p_m_techniques->_M_node_count )
  {
    stlp_std::priv::_Rb_tree<vostok::render::res_effect *,vostok::render::effect_manager::compare_predicate<vostok::render::res_effect>,vostok::render::res_effect *,stlp_std::priv::_Identity<vostok::render::res_effect *>,stlp_std::priv::_SetTraitsT<vostok::render::res_effect *>,vostok::render::std_allocator<vostok::render::res_effect *>>::_M_erase(
      p_m_techniques,
      p_m_techniques->_M_header._M_data._M_parent);
    p_m_techniques->_M_header._M_data._M_left = (stlp_std::priv::_Rb_tree_node_base *)p_m_techniques;
    p_m_techniques->_M_header._M_data._M_parent = 0;
    p_m_techniques->_M_header._M_data._M_right = (stlp_std::priv::_Rb_tree_node_base *)p_m_techniques;
    p_m_techniques->_M_node_count = 0;
  }
  if ( thisa->m_shaders._M_t._M_node_count )
  {
    stlp_std::priv::_Rb_tree<vostok::render::res_effect *,vostok::render::effect_manager::compare_predicate<vostok::render::res_effect>,vostok::render::res_effect *,stlp_std::priv::_Identity<vostok::render::res_effect *>,stlp_std::priv::_SetTraitsT<vostok::render::res_effect *>,vostok::render::std_allocator<vostok::render::res_effect *>>::_M_erase(
      (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::texture_pool *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::texture_pool *> > > *)&thisa->m_shaders,
      thisa->m_shaders._M_t._M_header._M_data._M_parent);
    thisa->m_shaders._M_t._M_header._M_data._M_left = &thisa->m_shaders._M_t._M_header._M_data;
    thisa->m_shaders._M_t._M_header._M_data._M_parent = 0;
    thisa->m_shaders._M_t._M_header._M_data._M_right = &thisa->m_shaders._M_t._M_header._M_data;
    thisa->m_shaders._M_t._M_node_count = 0;
  }
  if ( thisa->m_passes._M_t._M_node_count )
  {
    stlp_std::priv::_Rb_tree<vostok::render::res_effect *,vostok::render::effect_manager::compare_predicate<vostok::render::res_effect>,vostok::render::res_effect *,stlp_std::priv::_Identity<vostok::render::res_effect *>,stlp_std::priv::_SetTraitsT<vostok::render::res_effect *>,vostok::render::std_allocator<vostok::render::res_effect *>>::_M_erase(
      (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::texture_pool *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::texture_pool *> > > *)&thisa->m_passes,
      thisa->m_passes._M_t._M_header._M_data._M_parent);
    thisa->m_passes._M_t._M_header._M_data._M_left = &thisa->m_passes._M_t._M_header._M_data;
    thisa->m_passes._M_t._M_header._M_data._M_parent = 0;
    thisa->m_passes._M_t._M_header._M_data._M_right = &thisa->m_passes._M_t._M_header._M_data;
    thisa->m_passes._M_t._M_node_count = 0;
  }
  if ( thisa->m_shader_cache_info._M_impl._M_start )
    thisa->m_shader_cache_info._M_impl._M_end_of_storage.m_allocator->call_free(
      thisa->m_shader_cache_info._M_impl._M_end_of_storage.m_allocator,
      thisa->m_shader_cache_info._M_impl._M_start);
  `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind = kLEFT;
}
