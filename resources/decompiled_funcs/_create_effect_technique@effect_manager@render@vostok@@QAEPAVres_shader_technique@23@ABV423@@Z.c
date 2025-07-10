vostok::render::res_shader_technique *__userpurge vostok::render::effect_manager::create_effect_technique@<eax>(
        stlp_std::priv::_Rb_tree_node_base *element@<eax>,
        vostok::render::effect_manager *this)
{
  vostok::render::set<vostok::render::res_shader_technique *,vostok::render::effect_manager::compare_predicate<vostok::render::res_shader_technique> > *p_m_techniques; // ebx
  stlp_std::priv::_Rb_tree<vostok::render::res_shader_technique *,vostok::render::effect_manager::compare_predicate<vostok::render::res_shader_technique>,vostok::render::res_shader_technique *,stlp_std::priv::_Identity<vostok::render::res_shader_technique *>,stlp_std::priv::_SetTraitsT<vostok::render::res_shader_technique *>,vostok::render::std_allocator<vostok::render::res_shader_technique *> > *v5; // eax
  int *v6; // eax
  int *v7; // edi
  stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > > *M_parent; // ecx
  stlp_std::priv::_Rb_tree<vostok::render::res_shader_technique *,vostok::render::effect_manager::compare_predicate<vostok::render::res_shader_technique>,vostok::render::res_shader_technique *,stlp_std::priv::_Identity<vostok::render::res_shader_technique *>,stlp_std::priv::_SetTraitsT<vostok::render::res_shader_technique *>,vostok::render::std_allocator<vostok::render::res_shader_technique *> > *v9; // ecx
  stlp_std::pair<stlp_std::priv::_Rb_tree_iterator<vostok::render::res_shader_technique *,stlp_std::priv::_SetTraitsT<vostok::render::res_shader_technique *> >,bool> __k; // [esp+10h] [ebp-8h] BYREF

  if ( element->_M_left == element->_M_right )
    return 0;
  p_m_techniques = &this->m_techniques;
  __k.first._M_node = element;
  v5 = stlp_std::priv::_Rb_tree<vostok::render::res_shader_technique *,vostok::render::effect_manager::compare_predicate<vostok::render::res_shader_technique>,vostok::render::res_shader_technique *,stlp_std::priv::_Identity<vostok::render::res_shader_technique *>,stlp_std::priv::_SetTraitsT<vostok::render::res_shader_technique *>,vostok::render::std_allocator<vostok::render::res_shader_technique *>>::_M_find<vostok::render::res_shader_technique const *>(
         (const vostok::render::res_shader_technique **)&__k,
         &this->m_techniques._M_t);
  if ( v5 != (stlp_std::priv::_Rb_tree<vostok::render::res_shader_technique *,vostok::render::effect_manager::compare_predicate<vostok::render::res_shader_technique>,vostok::render::res_shader_technique *,stlp_std::priv::_Identity<vostok::render::res_shader_technique *>,stlp_std::priv::_SetTraitsT<vostok::render::res_shader_technique *>,vostok::render::std_allocator<vostok::render::res_shader_technique *> > *)p_m_techniques )
    return (vostok::render::res_shader_technique *)v5->_M_node_count;
  v6 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
         0x18u);
  if ( v6 )
  {
    *v6 = 0;
    v6[2] = 0;
    v6[3] = 0;
    v6[4] = 0;
    *((_BYTE *)v6 + 20) = 0;
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  M_parent = (stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > > *)element->_M_parent;
  this = (vostok::render::effect_manager *)v7;
  v7[1] = (int)M_parent;
  stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>>::operator=(
    M_parent,
    (stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > > *)(v7 + 2),
    (const stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > > *)&element->_M_left);
  *((_BYTE *)v7 + 20) = 1;
  stlp_std::priv::_Rb_tree<vostok::render::res_shader_technique *,vostok::render::effect_manager::compare_predicate<vostok::render::res_shader_technique>,vostok::render::res_shader_technique *,stlp_std::priv::_Identity<vostok::render::res_shader_technique *>,stlp_std::priv::_SetTraitsT<vostok::render::res_shader_technique *>,vostok::render::std_allocator<vostok::render::res_shader_technique *>>::insert_unique(
    v9,
    &p_m_techniques->_M_t,
    &__k,
    (const vostok::render::res_shader_technique **)&this);
  return (vostok::render::res_shader_technique *)v7;
}
