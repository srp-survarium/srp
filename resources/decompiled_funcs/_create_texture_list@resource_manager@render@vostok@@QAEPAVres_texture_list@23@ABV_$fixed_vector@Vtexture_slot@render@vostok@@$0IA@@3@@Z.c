const vostok::fixed_vector<vostok::render::texture_slot,128> *__userpurge vostok::render::resource_manager::create_texture_list@<eax>(
        vostok::render::resource_manager *this@<ecx>,
        int a2@<eax>,
        vostok::render::res_texture_list *tex_list)
{
  stlp_std::priv::_Rb_tree<vostok::render::res_texture_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_texture_list>,vostok::render::res_texture_list *,stlp_std::priv::_Identity<vostok::render::res_texture_list *>,stlp_std::priv::_SetTraitsT<vostok::render::res_texture_list *>,vostok::render::std_allocator<vostok::render::res_texture_list *> > *v4; // edi
  const stlp_std::priv::_Rb_tree<vostok::render::res_texture_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_texture_list>,vostok::render::res_texture_list *,stlp_std::priv::_Identity<vostok::render::res_texture_list *>,stlp_std::priv::_SetTraitsT<vostok::render::res_texture_list *>,vostok::render::std_allocator<vostok::render::res_texture_list *> > *v5; // eax
  const vostok::fixed_vector<vostok::render::texture_slot,128> *v7; // eax
  vostok::render::res_texture_list *v8; // ecx
  const vostok::fixed_vector<vostok::render::texture_slot,128> *v9; // eax
  const vostok::fixed_vector<vostok::render::texture_slot,128> *v10; // esi
  vostok::render::res_texture_list *__val[2]; // [esp+10h] [ebp-8h] BYREF

  v4 = (stlp_std::priv::_Rb_tree<vostok::render::res_texture_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_texture_list>,vostok::render::res_texture_list *,stlp_std::priv::_Identity<vostok::render::res_texture_list *>,stlp_std::priv::_SetTraitsT<vostok::render::res_texture_list *>,vostok::render::std_allocator<vostok::render::res_texture_list *> > *)(a2 + 532);
  v5 = stlp_std::priv::_Rb_tree<vostok::render::res_texture_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_texture_list>,vostok::render::res_texture_list *,stlp_std::priv::_Identity<vostok::render::res_texture_list *>,stlp_std::priv::_SetTraitsT<vostok::render::res_texture_list *>,vostok::render::std_allocator<vostok::render::res_texture_list *>>::_M_find<vostok::fixed_vector<vostok::render::texture_slot,128>>(
         (stlp_std::priv::_Rb_tree<vostok::render::res_texture_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_texture_list>,vostok::render::res_texture_list *,stlp_std::priv::_Identity<vostok::render::res_texture_list *>,stlp_std::priv::_SetTraitsT<vostok::render::res_texture_list *>,vostok::render::std_allocator<vostok::render::res_texture_list *> > *)this,
         (const stlp_std::priv::_Rb_tree<vostok::render::res_texture_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_texture_list>,vostok::render::res_texture_list *,stlp_std::priv::_Identity<vostok::render::res_texture_list *>,stlp_std::priv::_SetTraitsT<vostok::render::res_texture_list *>,vostok::render::std_allocator<vostok::render::res_texture_list *> > *)(a2 + 532),
         (const vostok::fixed_vector<vostok::render::texture_slot,128> *)tex_list);
  if ( v5 != v4 )
    return (const vostok::fixed_vector<vostok::render::texture_slot,128> *)v5->_M_node_count;
  ++*(_DWORD *)(a2 + 8);
  v7 = (const vostok::fixed_vector<vostok::render::texture_slot,128> *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                                         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                                         0x14u);
  if ( v7 )
  {
    vostok::render::res_texture_list::res_texture_list(v8, v7);
    v10 = v9;
  }
  else
  {
    v10 = 0;
  }
  tex_list = (vostok::render::res_texture_list *)v10;
  v10->m_buffer[0].m_store[8] = 1;
  stlp_std::priv::_Rb_tree<vostok::render::res_texture_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_texture_list>,vostok::render::res_texture_list *,stlp_std::priv::_Identity<vostok::render::res_texture_list *>,stlp_std::priv::_SetTraitsT<vostok::render::res_texture_list *>,vostok::render::std_allocator<vostok::render::res_texture_list *>>::insert_unique(
    (stlp_std::priv::_Rb_tree<vostok::render::res_texture_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_texture_list>,vostok::render::res_texture_list *,stlp_std::priv::_Identity<vostok::render::res_texture_list *>,stlp_std::priv::_SetTraitsT<vostok::render::res_texture_list *>,vostok::render::std_allocator<vostok::render::res_texture_list *> > *)__val,
    v4,
    (stlp_std::priv::_Rb_tree_node_base **)__val,
    &tex_list);
  return v10;
}
