void __usercall vostok::render::material_manager::~material_manager(
        vostok::render::material_manager *this@<ecx>,
        int a2@<edi>)
{
  vostok::render::material_effects_entry *v2; // esi
  vostok::render::material_effects_entry *v3; // eax
  vostok::render::grass_render_model *m_object; // ecx
  vostok::render::material_effects_entry *v5; // eax
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi

  v2 = *(vostok::render::material_effects_entry **)a2;
  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  v3 = *(vostok::render::material_effects_entry **)(a2 + 4);
  if ( *(vostok::render::material_effects_entry **)a2 != v3 )
    *(_DWORD *)(a2 + 4) = stlp_std::priv::__copy<vostok::render::material_effects_entry *,vostok::render::material_effects_entry *,int>(
                            v3,
                            v3,
                            *(vostok::render::material_effects_entry **)a2);
  if ( v2 )
  {
    m_object = vostok::render::g_allocator.m_object;
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free((malloc_state *)HIDWORD(m_object->m_reconstruction_info_actuality_tick), (char *)v2);
  }
  if ( *(_DWORD *)(a2 + 28) )
  {
    stlp_std::priv::_Rb_tree<vostok::render::res_effect *,vostok::render::effect_manager::compare_predicate<vostok::render::res_effect>,vostok::render::res_effect *,stlp_std::priv::_Identity<vostok::render::res_effect *>,stlp_std::priv::_SetTraitsT<vostok::render::res_effect *>,vostok::render::std_allocator<vostok::render::res_effect *>>::_M_erase(
      (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::texture_pool *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::texture_pool *> > > *)(a2 + 12),
      *(stlp_std::priv::_Rb_tree_node_base **)(a2 + 16));
    *(_DWORD *)(a2 + 20) = a2 + 12;
    *(_DWORD *)(a2 + 16) = 0;
    *(_DWORD *)(a2 + 24) = a2 + 12;
    *(_DWORD *)(a2 + 28) = 0;
  }
  v5 = *(vostok::render::material_effects_entry **)a2;
  if ( *(_DWORD *)a2 )
  {
    m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, (char *)v5);
  }
  `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.y = 0;
}
