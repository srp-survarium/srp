vostok::fixed_vector<vostok::render::buffer_slot,128> *__userpurge vostok::render::resource_manager::create_buffer_list@<eax>(
        vostok::render::resource_manager *this@<ecx>,
        int a2@<eax>,
        vostok::fixed_vector<vostok::render::buffer_slot,128> *tex_list)
{
  stlp_std::priv::_Rb_tree_node_base *v3; // edi
  vostok::memory::doug_lea_allocator *v5; // esi
  char *v6; // eax
  vostok::memory::doug_lea_allocator *v7; // ecx
  char *v8; // eax
  vostok::render::res_buffer_list *v9; // ecx
  const vostok::fixed_vector<vostok::render::buffer_slot,128> *v10; // eax
  stlp_std::priv::_Rb_tree<vostok::render::res_buffer_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_buffer_list>,vostok::render::res_buffer_list *,stlp_std::priv::_Identity<vostok::render::res_buffer_list *>,stlp_std::priv::_SetTraitsT<vostok::render::res_buffer_list *>,vostok::render::std_allocator<vostok::render::res_buffer_list *> > v11; // [esp-4h] [ebp-18h] BYREF

  v3 = (stlp_std::priv::_Rb_tree_node_base *)((char *)&loc_93947 + a2 + 1);
  stlp_std::set<vostok::render::res_texture_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_texture_list>,vostok::render::std_allocator<vostok::render::res_texture_list *>>::find<vostok::fixed_vector<vostok::render::texture_slot,128>>(
    (stlp_std::set<vostok::render::res_buffer_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_buffer_list>,vostok::render::std_allocator<vostok::render::res_buffer_list *> > *)this,
    (stlp_std::priv::_Rb_tree_iterator<vostok::render::res_buffer_list *,stlp_std::priv::_SetTraitsT<vostok::render::res_buffer_list *> > *)((char *)&loc_93947 + a2 + 1),
    (stlp_std::priv::_Rb_tree_iterator<vostok::render::res_buffer_list *,stlp_std::priv::_SetTraitsT<vostok::render::res_buffer_list *> > *)&v11._M_node_count,
    tex_list);
  if ( (stlp_std::priv::_Rb_tree_node_base *)v11._M_node_count != v3 )
    return *(vostok::fixed_vector<vostok::render::buffer_slot,128> **)(v11._M_node_count + 16);
  v5 = vostok::render::g_allocator;
  v6 = type_info::raw_name(&vostok::render::res_buffer_list `RTTI Type Descriptor');
  v8 = vostok::memory::doug_lea_allocator::malloc_impl(
         v7,
         (int)v5,
         0x90u,
         v6,
         (const char *const)&v11._M_header._M_data._M_parent->_M_color,
         (const char *const)&v11._M_header._M_data._M_left->_M_color,
         (const unsigned int)v11._M_header._M_data._M_right);
  if ( v8 )
  {
    vostok::render::res_buffer_list::res_buffer_list(
      v9,
      (const vostok::fixed_vector<vostok::render::buffer_slot,128> *)v8,
      tex_list);
    tex_list = (vostok::fixed_vector<vostok::render::buffer_slot,128> *)v10;
  }
  else
  {
    tex_list = 0;
  }
  *(_DWORD *)&v11._M_header._M_data._M_color = &tex_list;
  stlp_std::priv::_Rb_tree<vostok::render::res_buffer_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_buffer_list>,vostok::render::res_buffer_list *,stlp_std::priv::_Identity<vostok::render::res_buffer_list *>,stlp_std::priv::_SetTraitsT<vostok::render::res_buffer_list *>,vostok::render::std_allocator<vostok::render::res_buffer_list *>>::insert_unique(
    (stlp_std::priv::_Rb_tree<vostok::render::res_buffer_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_buffer_list>,vostok::render::res_buffer_list *,stlp_std::priv::_Identity<vostok::render::res_buffer_list *>,stlp_std::priv::_SetTraitsT<vostok::render::res_buffer_list *>,vostok::render::std_allocator<vostok::render::res_buffer_list *> > *)v9,
    v3,
    (vostok::render::res_buffer_list **)&v11._M_header._M_data._M_right,
    v11);
  return tex_list;
}
