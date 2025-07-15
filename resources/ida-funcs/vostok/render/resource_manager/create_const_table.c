vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *__usercall vostok::render::resource_manager::create_const_table@<eax>(
        vostok::render::resource_manager *this@<ecx>,
        const vostok::render::shader_constant_table *proto@<eax>)
{
  vostok::render::set<vostok::render::shader_constant_table *,vostok::render::resource_manager::constant_table_predicate> *p_m_const_tables; // esi
  stlp_std::priv::_Rb_tree<vostok::render::shader_constant_table *,vostok::render::resource_manager::constant_table_predicate,vostok::render::shader_constant_table *,stlp_std::priv::_Identity<vostok::render::shader_constant_table *>,stlp_std::priv::_SetTraitsT<vostok::render::shader_constant_table *>,vostok::render::std_allocator<vostok::render::shader_constant_table *> > *v4; // eax
  vostok::render::shader_constant_table *v5; // ecx
  unsigned int M_node_count; // esi
  void *v8; // eax
  stlp_std::priv::_Rb_tree<vostok::render::shader_constant_table *,vostok::render::resource_manager::constant_table_predicate,vostok::render::shader_constant_table *,stlp_std::priv::_Identity<vostok::render::shader_constant_table *>,stlp_std::priv::_SetTraitsT<vostok::render::shader_constant_table *>,vostok::render::std_allocator<vostok::render::shader_constant_table *> > *v9; // ecx
  vostok::render::shader_constant_table *v10; // eax
  vostok::render::shader_constant_table *v11; // ecx
  vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *M_start; // esi
  vostok::render::shader_constant_table *__k; // [esp+Ch] [ebp-30h] BYREF
  vostok::render::shader_constant_table *__val; // [esp+10h] [ebp-2Ch] BYREF
  vostok::render::shader_constant_table new_table; // [esp+18h] [ebp-24h] BYREF

  vostok::render::shader_constant_table::shader_constant_table(
    (vostok::render::shader_constant_table *)this,
    (int)&new_table,
    proto);
  vostok::render::shader_constant_table::apply_bindings(&new_table, &this->m_const_bindings);
  p_m_const_tables = &this->m_const_tables;
  __k = &new_table;
  v4 = stlp_std::priv::_Rb_tree<vostok::render::shader_constant_table *,vostok::render::resource_manager::constant_table_predicate,vostok::render::shader_constant_table *,stlp_std::priv::_Identity<vostok::render::shader_constant_table *>,stlp_std::priv::_SetTraitsT<vostok::render::shader_constant_table *>,vostok::render::std_allocator<vostok::render::shader_constant_table *>>::_M_find<vostok::render::shader_constant_table const *>(
         &__k,
         &p_m_const_tables->_M_t);
  if ( v4 == (stlp_std::priv::_Rb_tree<vostok::render::shader_constant_table *,vostok::render::resource_manager::constant_table_predicate,vostok::render::shader_constant_table *,stlp_std::priv::_Identity<vostok::render::shader_constant_table *>,stlp_std::priv::_SetTraitsT<vostok::render::shader_constant_table *>,vostok::render::std_allocator<vostok::render::shader_constant_table *> > *)p_m_const_tables )
  {
    v8 = vostok::memory::doug_lea_allocator::malloc_impl(
           (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
           0x20u);
    if ( v8 )
    {
      vostok::render::shader_constant_table::shader_constant_table(&new_table, (int)v8, &new_table);
      __k = v10;
    }
    else
    {
      __k = 0;
    }
    stlp_std::priv::_Rb_tree<vostok::render::shader_constant_table *,vostok::render::resource_manager::constant_table_predicate,vostok::render::shader_constant_table *,stlp_std::priv::_Identity<vostok::render::shader_constant_table *>,stlp_std::priv::_SetTraitsT<vostok::render::shader_constant_table *>,vostok::render::std_allocator<vostok::render::shader_constant_table *>>::insert_unique(
      v9,
      &p_m_const_tables->_M_t,
      &__val,
      &__k);
    v11 = __val;
    M_start = __val->m_const_buffers._M_impl._M_start;
    LOBYTE(M_start[7].m_object) = 1;
    vostok::render::shader_constant_table::~shader_constant_table(v11);
    return M_start;
  }
  else
  {
    M_node_count = v4->_M_node_count;
    vostok::render::shader_constant_table::~shader_constant_table(v5);
    return (vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)M_node_count;
  }
}
