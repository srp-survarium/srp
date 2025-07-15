vostok::render::shader_constant_table *__userpurge vostok::render::resource_manager::create_const_table@<eax>(
        vostok::render::resource_manager *this@<ecx>,
        int a2@<eax>,
        stlp_std::priv::_Rb_tree_node_base **proto)
{
  stlp_std::priv::_Rb_tree<vostok::render::shader_constant_table *,vostok::render::resource_manager::constant_table_predicate,vostok::render::shader_constant_table *,stlp_std::priv::_Identity<vostok::render::shader_constant_table *>,stlp_std::priv::_SetTraitsT<vostok::render::shader_constant_table *>,vostok::render::std_allocator<vostok::render::shader_constant_table *> > *v4; // edi
  vostok::render::shader_constant_table *v5; // ecx
  int v6; // esi
  vostok::memory::doug_lea_allocator *v8; // esi
  char *v9; // eax
  vostok::memory::doug_lea_allocator *v10; // ecx
  char *v11; // eax
  stlp_std::priv::_Rb_tree<vostok::render::shader_constant_table *,vostok::render::resource_manager::constant_table_predicate,vostok::render::shader_constant_table *,stlp_std::priv::_Identity<vostok::render::shader_constant_table *>,stlp_std::priv::_SetTraitsT<vostok::render::shader_constant_table *>,vostok::render::std_allocator<vostok::render::shader_constant_table *> > *v12; // ecx
  vostok::render::shader_constant_table *v13; // eax
  int v14; // eax
  stlp_std::priv::_Rb_tree_node_base v15[58]; // [esp-4h] [ebp-3B8h] BYREF
  int v16; // [esp+3A8h] [ebp-Ch] BYREF
  stlp_std::priv::_Rb_tree_iterator<vostok::render::shader_constant_table *,stlp_std::priv::_SetTraitsT<vostok::render::shader_constant_table *> > v17; // [esp+3ACh] [ebp-8h] BYREF

  vostok::render::shader_constant_table::shader_constant_table(
    (vostok::render::shader_constant_table *)this,
    (vostok::render::shader_constant *)&v15[0]._M_right,
    (vostok::render::shader_constant_buffer *)proto);
  vostok::render::shader_constant_table::apply_bindings(
    (const vostok::render::shader_constant_bindings *)((char *)&loc_9464F + a2 + 1),
    (vostok::render::shader_constant_table *)&v15[0]._M_right);
  proto = &v15[0]._M_right;
  v4 = (stlp_std::priv::_Rb_tree<vostok::render::shader_constant_table *,vostok::render::resource_manager::constant_table_predicate,vostok::render::shader_constant_table *,stlp_std::priv::_Identity<vostok::render::shader_constant_table *>,stlp_std::priv::_SetTraitsT<vostok::render::shader_constant_table *>,vostok::render::std_allocator<vostok::render::shader_constant_table *> > *)(a2 + 557244);
  stlp_std::set<vostok::render::shader_constant_table *,vostok::render::resource_manager::constant_table_predicate,vostok::render::std_allocator<vostok::render::shader_constant_table *>>::find<vostok::render::shader_constant_table *>(
    (vostok::render::shader_constant_table **)&proto,
    (stlp_std::set<vostok::render::shader_constant_table *,vostok::render::resource_manager::constant_table_predicate,vostok::render::std_allocator<vostok::render::shader_constant_table *> > *)(a2 + 557244),
    &v17);
  if ( v17._M_node == (stlp_std::priv::_Rb_tree_node_base *)(a2 + 557244) )
  {
    v8 = vostok::render::g_allocator;
    v9 = type_info::raw_name(&vostok::render::shader_constant_table `RTTI Type Descriptor');
    v11 = vostok::memory::doug_lea_allocator::malloc_impl(
            v10,
            (int)v8,
            0x3A0u,
            v9,
            (const char *const)&v15[0]._M_parent->_M_color,
            (const char *const)&v15[0]._M_left->_M_color,
            (const unsigned int)v15[0]._M_right);
    if ( v11 )
    {
      vostok::render::shader_constant_table::shader_constant_table(
        (vostok::render::shader_constant_table *)&v15[0]._M_right,
        (vostok::render::shader_constant *)v11,
        (vostok::render::shader_constant_buffer *)&v15[0]._M_right);
      proto = (stlp_std::priv::_Rb_tree_node_base **)v13;
    }
    else
    {
      proto = 0;
    }
    *(_DWORD *)&v15[0]._M_color = &proto;
    stlp_std::priv::_Rb_tree<vostok::render::shader_constant_table *,vostok::render::resource_manager::constant_table_predicate,vostok::render::shader_constant_table *,stlp_std::priv::_Identity<vostok::render::shader_constant_table *>,stlp_std::priv::_SetTraitsT<vostok::render::shader_constant_table *>,vostok::render::std_allocator<vostok::render::shader_constant_table *>>::insert_unique(
      v12,
      (int)&v16,
      v4,
      v15[0]);
    v14 = *(_DWORD *)(v16 + 16);
    *(_BYTE *)(v14 + 924) = 1;
    v6 = v14;
  }
  else
  {
    v6 = *(_DWORD *)&v17._M_node[1]._M_color;
  }
  vostok::render::shader_constant_table::~shader_constant_table(v5, (int)&v15[0]._M_right);
  return (vostok::render::shader_constant_table *)v6;
}
