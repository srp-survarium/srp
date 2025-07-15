vostok::render::res_sampler_list *__usercall vostok::render::resource_manager::create_sampler_list@<eax>(
        vostok::render::resource_manager *this@<ecx>,
        const vostok::fixed_vector<vostok::render::sampler_slot,16> *smp_list@<eax>)
{
  vostok::render::set<vostok::render::res_sampler_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_sampler_list> > *p_m_sampler_lists; // esi
  const stlp_std::priv::_Rb_tree<vostok::render::res_sampler_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_sampler_list>,vostok::render::res_sampler_list *,stlp_std::priv::_Identity<vostok::render::res_sampler_list *>,stlp_std::priv::_SetTraitsT<vostok::render::res_sampler_list *>,vostok::render::std_allocator<vostok::render::res_sampler_list *> > *v3; // eax
  const vostok::fixed_vector<vostok::render::sampler_slot,16> *v5; // eax
  vostok::render::res_sampler_list *v6; // ecx
  vostok::render::res_sampler_list *v7; // eax
  vostok::render::res_sampler_list *v8; // edi
  vostok::render::res_sampler_list *lst; // [esp+Ch] [ebp-10h] BYREF
  vostok::render::res_sampler_list *__val[3]; // [esp+10h] [ebp-Ch] BYREF

  p_m_sampler_lists = &this->m_sampler_lists;
  v3 = stlp_std::priv::_Rb_tree<vostok::render::res_sampler_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_sampler_list>,vostok::render::res_sampler_list *,stlp_std::priv::_Identity<vostok::render::res_sampler_list *>,stlp_std::priv::_SetTraitsT<vostok::render::res_sampler_list *>,vostok::render::std_allocator<vostok::render::res_sampler_list *>>::_M_find<vostok::fixed_vector<vostok::render::sampler_slot,16>>(
         (stlp_std::priv::_Rb_tree<vostok::render::res_sampler_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_sampler_list>,vostok::render::res_sampler_list *,stlp_std::priv::_Identity<vostok::render::res_sampler_list *>,stlp_std::priv::_SetTraitsT<vostok::render::res_sampler_list *>,vostok::render::std_allocator<vostok::render::res_sampler_list *> > *)this,
         &this->m_sampler_lists._M_t,
         smp_list);
  if ( v3 != (const stlp_std::priv::_Rb_tree<vostok::render::res_sampler_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_sampler_list>,vostok::render::res_sampler_list *,stlp_std::priv::_Identity<vostok::render::res_sampler_list *>,stlp_std::priv::_SetTraitsT<vostok::render::res_sampler_list *>,vostok::render::std_allocator<vostok::render::res_sampler_list *> > *)p_m_sampler_lists )
    return (vostok::render::res_sampler_list *)v3->_M_node_count;
  v5 = (const vostok::fixed_vector<vostok::render::sampler_slot,16> *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                                        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                                        0x20u);
  if ( v5 )
  {
    vostok::render::res_sampler_list::res_sampler_list(v6, v5);
    v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  lst = v8;
  v8->m_is_registered = 1;
  stlp_std::priv::_Rb_tree<vostok::render::res_sampler_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_sampler_list>,vostok::render::res_sampler_list *,stlp_std::priv::_Identity<vostok::render::res_sampler_list *>,stlp_std::priv::_SetTraitsT<vostok::render::res_sampler_list *>,vostok::render::std_allocator<vostok::render::res_sampler_list *>>::insert_unique(
    (stlp_std::priv::_Rb_tree<vostok::render::res_sampler_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_sampler_list>,vostok::render::res_sampler_list *,stlp_std::priv::_Identity<vostok::render::res_sampler_list *>,stlp_std::priv::_SetTraitsT<vostok::render::res_sampler_list *>,vostok::render::std_allocator<vostok::render::res_sampler_list *> > *)__val,
    &p_m_sampler_lists->_M_t,
    __val,
    &lst);
  return v8;
}
