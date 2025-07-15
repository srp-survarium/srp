void __thiscall vostok::render::texture_storage::~texture_storage(
        vostok::render::texture_storage *this,
        vostok::render::texture_storage *thisa)
{
  stlp_std::priv::_Rb_tree_node_base *i; // edi
  stlp_std::priv::_Rb_tree_node_base *M_parent; // esi
  vostok::render::grass_render_model *m_object; // ebp
  char *p_M_color; // eax
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi

  for ( i = thisa->m_pools._M_t._M_header._M_data._M_left;
        i != (stlp_std::priv::_Rb_tree_node_base *)thisa;
        i = stlp_std::priv::_Rb_global<bool>::_M_increment(i) )
  {
    M_parent = i[1]._M_parent;
    m_object = vostok::render::g_allocator.m_object;
    if ( M_parent )
    {
      vostok::render::texture_pool::~texture_pool(
        (vostok::render::texture_pool *)this,
        (vostok::render::texture_pool *)i[1]._M_parent);
      p_M_color = (char *)&M_parent->_M_color;
      m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
      BYTE2(m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, p_M_color);
      i[1]._M_parent = 0;
    }
  }
  if ( thisa->m_pools._M_t._M_node_count )
  {
    stlp_std::priv::_Rb_tree<vostok::render::res_effect *,vostok::render::effect_manager::compare_predicate<vostok::render::res_effect>,vostok::render::res_effect *,stlp_std::priv::_Identity<vostok::render::res_effect *>,stlp_std::priv::_SetTraitsT<vostok::render::res_effect *>,vostok::render::std_allocator<vostok::render::res_effect *>>::_M_erase(
      &thisa->m_pools._M_t,
      thisa->m_pools._M_t._M_header._M_data._M_parent);
    thisa->m_pools._M_t._M_header._M_data._M_left = (stlp_std::priv::_Rb_tree_node_base *)thisa;
    thisa->m_pools._M_t._M_header._M_data._M_parent = 0;
    thisa->m_pools._M_t._M_header._M_data._M_right = (stlp_std::priv::_Rb_tree_node_base *)thisa;
    thisa->m_pools._M_t._M_node_count = 0;
  }
}
