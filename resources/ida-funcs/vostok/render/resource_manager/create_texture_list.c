vostok::fixed_vector<vostok::render::buffer_slot,128> *__userpurge vostok::render::resource_manager::create_texture_list@<eax>(
        vostok::render::resource_manager *this@<ecx>,
        int a2@<eax>,
        vostok::fixed_vector<vostok::render::buffer_slot,128> *tex_list)
{
  stlp_std::priv::_Rb_tree_node_base *v4; // edi
  vostok::memory::doug_lea_allocator *v6; // esi
  char *v7; // eax
  vostok::memory::doug_lea_allocator *v8; // ecx
  char *v9; // eax
  vostok::render::res_texture_list *v10; // ecx
  const vostok::fixed_vector<vostok::render::texture_slot,128> *v11; // eax
  vostok::fixed_vector<vostok::render::buffer_slot,128> *v12; // esi
  stlp_std::priv::_Rb_tree<vostok::render::res_texture_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_texture_list>,vostok::render::res_texture_list *,stlp_std::priv::_Identity<vostok::render::res_texture_list *>,stlp_std::priv::_SetTraitsT<vostok::render::res_texture_list *>,vostok::render::std_allocator<vostok::render::res_texture_list *> > v13; // [esp-4h] [ebp-18h] BYREF

  v4 = (stlp_std::priv::_Rb_tree_node_base *)((char *)&loc_9392C + a2 + 4);
  stlp_std::set<vostok::render::res_texture_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_texture_list>,vostok::render::std_allocator<vostok::render::res_texture_list *>>::find<vostok::fixed_vector<vostok::render::texture_slot,128>>(
    (stlp_std::set<vostok::render::res_buffer_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_buffer_list>,vostok::render::std_allocator<vostok::render::res_buffer_list *> > *)this,
    (stlp_std::priv::_Rb_tree_iterator<vostok::render::res_buffer_list *,stlp_std::priv::_SetTraitsT<vostok::render::res_buffer_list *> > *)((char *)&loc_9392C + a2 + 4),
    (stlp_std::priv::_Rb_tree_iterator<vostok::render::res_buffer_list *,stlp_std::priv::_SetTraitsT<vostok::render::res_buffer_list *> > *)&v13._M_node_count,
    tex_list);
  if ( (stlp_std::priv::_Rb_tree_node_base *)v13._M_node_count != v4 )
    return *(vostok::fixed_vector<vostok::render::buffer_slot,128> **)(v13._M_node_count + 16);
  ++*(_DWORD *)(a2 + 8);
  v6 = vostok::render::g_allocator;
  v7 = type_info::raw_name(&vostok::render::res_texture_list `RTTI Type Descriptor');
  v9 = vostok::memory::doug_lea_allocator::malloc_impl(
         v8,
         (int)v6,
         0x114u,
         v7,
         (const char *const)&v13._M_header._M_data._M_parent->_M_color,
         (const char *const)&v13._M_header._M_data._M_left->_M_color,
         (const unsigned int)v13._M_header._M_data._M_right);
  if ( v9 )
  {
    vostok::render::res_texture_list::res_texture_list(
      v10,
      (const vostok::fixed_vector<vostok::render::texture_slot,128> *)v9,
      tex_list);
    tex_list = (vostok::fixed_vector<vostok::render::buffer_slot,128> *)v11;
  }
  else
  {
    tex_list = 0;
  }
  v12 = tex_list;
  *(_DWORD *)&v13._M_header._M_data._M_color = &tex_list;
  tex_list->m_buffer[3].m_store[8] = 1;
  stlp_std::priv::_Rb_tree<vostok::render::res_texture_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_texture_list>,vostok::render::res_texture_list *,stlp_std::priv::_Identity<vostok::render::res_texture_list *>,stlp_std::priv::_SetTraitsT<vostok::render::res_texture_list *>,vostok::render::std_allocator<vostok::render::res_texture_list *>>::insert_unique(
    (stlp_std::priv::_Rb_tree<vostok::render::res_texture_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_texture_list>,vostok::render::res_texture_list *,stlp_std::priv::_Identity<vostok::render::res_texture_list *>,stlp_std::priv::_SetTraitsT<vostok::render::res_texture_list *>,vostok::render::std_allocator<vostok::render::res_texture_list *> > *)v10,
    v4,
    (vostok::render::res_texture_list **)&v13._M_header._M_data._M_right,
    v13);
  return v12;
}
