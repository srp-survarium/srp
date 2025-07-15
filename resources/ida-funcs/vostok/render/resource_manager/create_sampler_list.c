const vostok::fixed_vector<vostok::render::sampler_slot,16> *__userpurge vostok::render::resource_manager::create_sampler_list@<eax>(
        vostok::render::resource_manager *this@<ecx>,
        int a2@<eax>,
        vostok::fixed_vector<vostok::render::sampler_slot,16> *smp_list)
{
  stlp_std::priv::_Rb_tree<vostok::render::res_sampler_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_sampler_list>,vostok::render::res_sampler_list *,stlp_std::priv::_Identity<vostok::render::res_sampler_list *>,stlp_std::priv::_SetTraitsT<vostok::render::res_sampler_list *>,vostok::render::std_allocator<vostok::render::res_sampler_list *> > *v3; // edi
  vostok::memory::doug_lea_allocator *v5; // esi
  char *v6; // eax
  vostok::memory::doug_lea_allocator *v7; // ecx
  char *v8; // eax
  vostok::render::res_sampler_list *v9; // ecx
  vostok::render::res_sampler_list *v10; // eax
  vostok::fixed_vector<vostok::render::sampler_slot,16> *v11; // ebx
  stlp_std::priv::_Rb_tree_node_base v12; // [esp-4h] [ebp-20h]
  const char *v13; // [esp+0h] [ebp-1Ch]
  const char *v14; // [esp+4h] [ebp-18h]
  unsigned int v15; // [esp+8h] [ebp-14h]
  _BYTE v16[4]; // [esp+10h] [ebp-Ch] BYREF
  stlp_std::priv::_Rb_tree_iterator<vostok::render::res_sampler_list *,stlp_std::priv::_SetTraitsT<vostok::render::res_sampler_list *> > v17; // [esp+14h] [ebp-8h] BYREF

  v3 = (stlp_std::priv::_Rb_tree<vostok::render::res_sampler_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_sampler_list>,vostok::render::res_sampler_list *,stlp_std::priv::_Identity<vostok::render::res_sampler_list *>,stlp_std::priv::_SetTraitsT<vostok::render::res_sampler_list *>,vostok::render::std_allocator<vostok::render::res_sampler_list *> > *)((char *)&loc_9395C + a2 + 4);
  stlp_std::set<vostok::render::res_sampler_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_sampler_list>,vostok::render::std_allocator<vostok::render::res_sampler_list *>>::find<vostok::fixed_vector<vostok::render::sampler_slot,16>>(
    (stlp_std::set<vostok::render::res_sampler_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_sampler_list>,vostok::render::std_allocator<vostok::render::res_sampler_list *> > *)this,
    (stlp_std::priv::_Rb_tree_iterator<vostok::render::res_sampler_list *,stlp_std::priv::_SetTraitsT<vostok::render::res_sampler_list *> > *)((char *)&loc_9395C + a2 + 4),
    &v17,
    smp_list);
  if ( (stlp_std::priv::_Rb_tree<vostok::render::res_sampler_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_sampler_list>,vostok::render::res_sampler_list *,stlp_std::priv::_Identity<vostok::render::res_sampler_list *>,stlp_std::priv::_SetTraitsT<vostok::render::res_sampler_list *>,vostok::render::std_allocator<vostok::render::res_sampler_list *> > *)v17._M_node != v3 )
    return *(const vostok::fixed_vector<vostok::render::sampler_slot,16> **)&v17._M_node[1]._M_color;
  v5 = vostok::render::g_allocator;
  v6 = type_info::raw_name(&vostok::render::res_sampler_list `RTTI Type Descriptor');
  v8 = vostok::memory::doug_lea_allocator::malloc_impl(v7, (int)v5, 0x620u, v6, v13, v14, v15);
  if ( v8 )
  {
    vostok::render::res_sampler_list::res_sampler_list(
      v9,
      (const vostok::fixed_vector<vostok::render::sampler_slot,16> *)v8,
      smp_list);
    smp_list = (vostok::fixed_vector<vostok::render::sampler_slot,16> *)v10;
  }
  else
  {
    smp_list = 0;
  }
  v11 = smp_list;
  *(_DWORD *)&v12._M_color = &smp_list;
  smp_list[1].m_buffer[2].m_store[28] = 1;
  stlp_std::priv::_Rb_tree<vostok::render::res_sampler_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_sampler_list>,vostok::render::res_sampler_list *,stlp_std::priv::_Identity<vostok::render::res_sampler_list *>,stlp_std::priv::_SetTraitsT<vostok::render::res_sampler_list *>,vostok::render::std_allocator<vostok::render::res_sampler_list *>>::insert_unique(
    (stlp_std::priv::_Rb_tree<vostok::render::res_sampler_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_sampler_list>,vostok::render::res_sampler_list *,stlp_std::priv::_Identity<vostok::render::res_sampler_list *>,stlp_std::priv::_SetTraitsT<vostok::render::res_sampler_list *>,vostok::render::std_allocator<vostok::render::res_sampler_list *> > *)v9,
    (int)v16,
    v3,
    v12);
  return v11;
}
