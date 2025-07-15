vostok::render::res_pass *__usercall vostok::render::effect_manager::create_pass@<eax>(
        vostok::render::effect_manager *this@<ecx>,
        vostok::render::res_pass *pass@<eax>)
{
  vostok::render::set<vostok::render::res_pass *,vostok::render::effect_manager::compare_predicate<vostok::render::res_pass> > *p_m_passes; // edi
  stlp_std::priv::_Rb_tree<vostok::render::res_pass *,vostok::render::effect_manager::compare_predicate<vostok::render::res_pass>,vostok::render::res_pass *,stlp_std::priv::_Identity<vostok::render::res_pass *>,stlp_std::priv::_SetTraitsT<vostok::render::res_pass *>,vostok::render::std_allocator<vostok::render::res_pass *> > *v4; // eax
  vostok::render::res_pass *v6; // eax
  vostok::render::res_pass *v7; // eax
  vostok::render::res_pass *v8; // esi
  vostok::render::res_pass *new_pass; // [esp+Ch] [ebp-10h] BYREF
  vostok::render::res_pass *__val[3]; // [esp+10h] [ebp-Ch] BYREF

  p_m_passes = &this->m_passes;
  new_pass = pass;
  v4 = stlp_std::priv::_Rb_tree<vostok::render::res_pass *,vostok::render::effect_manager::compare_predicate<vostok::render::res_pass>,vostok::render::res_pass *,stlp_std::priv::_Identity<vostok::render::res_pass *>,stlp_std::priv::_SetTraitsT<vostok::render::res_pass *>,vostok::render::std_allocator<vostok::render::res_pass *>>::_M_find<vostok::render::res_pass const *>(
         (const vostok::render::res_pass **)&new_pass,
         &this->m_passes._M_t);
  if ( v4 != (stlp_std::priv::_Rb_tree<vostok::render::res_pass *,vostok::render::effect_manager::compare_predicate<vostok::render::res_pass>,vostok::render::res_pass *,stlp_std::priv::_Identity<vostok::render::res_pass *>,stlp_std::priv::_SetTraitsT<vostok::render::res_pass *>,vostok::render::std_allocator<vostok::render::res_pass *> > *)p_m_passes )
    return (vostok::render::res_pass *)v4->_M_node_count;
  v6 = (vostok::render::res_pass *)vostok::memory::doug_lea_allocator::malloc_impl(
                                     (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                     0x1Cu);
  if ( v6 )
  {
    vostok::render::res_pass::res_pass(v6, &pass->m_state, &pass->m_vs, &pass->m_gs, &pass->m_ps);
    v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  new_pass = v8;
  v8->m_registered = 1;
  stlp_std::priv::_Rb_tree<vostok::render::res_pass *,vostok::render::effect_manager::compare_predicate<vostok::render::res_pass>,vostok::render::res_pass *,stlp_std::priv::_Identity<vostok::render::res_pass *>,stlp_std::priv::_SetTraitsT<vostok::render::res_pass *>,vostok::render::std_allocator<vostok::render::res_pass *>>::insert_unique(
    (stlp_std::priv::_Rb_tree<vostok::render::res_pass *,vostok::render::effect_manager::compare_predicate<vostok::render::res_pass>,vostok::render::res_pass *,stlp_std::priv::_Identity<vostok::render::res_pass *>,stlp_std::priv::_SetTraitsT<vostok::render::res_pass *>,vostok::render::std_allocator<vostok::render::res_pass *> > *)__val,
    &p_m_passes->_M_t,
    (stlp_std::priv::_Rb_tree_node_base **)__val,
    &new_pass);
  return v8;
}
