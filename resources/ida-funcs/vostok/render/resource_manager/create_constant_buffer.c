vostok::render::shader_constant_buffer *__userpurge vostok::render::resource_manager::create_constant_buffer@<eax>(
        vostok::render::resource_manager *this@<ecx>,
        int a2@<eax>,
        const vostok::fixed_string<64> *name,
        vostok::render::enum_shader_type dest,
        _D3D_CBUFFER_TYPE type,
        unsigned int size)
{
  stlp_std::priv::_Rb_tree<vostok::render::shader_constant_buffer *,vostok::render::resource_manager::constant_buffer_predicate,vostok::render::shader_constant_buffer *,stlp_std::priv::_Identity<vostok::render::shader_constant_buffer *>,stlp_std::priv::_SetTraitsT<vostok::render::shader_constant_buffer *>,vostok::render::std_allocator<vostok::render::shader_constant_buffer *> > *v7; // ebx
  vostok::render::shader_constant_buffer *v8; // ecx
  int v9; // esi
  vostok::memory::doug_lea_allocator *v11; // esi
  char *v12; // eax
  vostok::memory::doug_lea_allocator *v13; // ecx
  char *v14; // eax
  stlp_std::priv::_Rb_tree<vostok::render::shader_constant_buffer *,vostok::render::resource_manager::constant_buffer_predicate,vostok::render::shader_constant_buffer *,stlp_std::priv::_Identity<vostok::render::shader_constant_buffer *>,stlp_std::priv::_SetTraitsT<vostok::render::shader_constant_buffer *>,vostok::render::std_allocator<vostok::render::shader_constant_buffer *> > *v15; // ecx
  _D3D_CBUFFER_TYPE v16; // eax
  _D3D_CBUFFER_TYPE v17; // edi
  stlp_std::priv::_Rb_tree_node_base v18; // [esp-4h] [ebp-8Ch]
  const char *v19; // [esp+0h] [ebp-88h]
  const char *v20; // [esp+4h] [ebp-84h]
  unsigned int v21; // [esp+8h] [ebp-80h]
  vostok::render::shader_constant_buffer v22; // [esp+10h] [ebp-78h] BYREF
  _BYTE v23[4]; // [esp+7Ch] [ebp-Ch] BYREF
  stlp_std::priv::_Rb_tree_iterator<vostok::render::shader_constant_buffer *,stlp_std::priv::_SetTraitsT<vostok::render::shader_constant_buffer *> > v24; // [esp+80h] [ebp-8h] BYREF
  vostok::render::shader_constant_buffer *__x; // [esp+84h] [ebp-4h] BYREF

  vostok::render::shader_constant_buffer::shader_constant_buffer(name, size, &v22, dest, type);
  __x = &v22;
  v7 = (stlp_std::priv::_Rb_tree<vostok::render::shader_constant_buffer *,vostok::render::resource_manager::constant_buffer_predicate,vostok::render::shader_constant_buffer *,stlp_std::priv::_Identity<vostok::render::shader_constant_buffer *>,stlp_std::priv::_SetTraitsT<vostok::render::shader_constant_buffer *>,vostok::render::std_allocator<vostok::render::shader_constant_buffer *> > *)(a2 + 557268);
  stlp_std::set<vostok::render::shader_constant_buffer *,vostok::render::resource_manager::constant_buffer_predicate,vostok::render::std_allocator<vostok::render::shader_constant_buffer *>>::find<vostok::render::shader_constant_buffer const *>(
    (const vostok::render::shader_constant_buffer **)&__x,
    (stlp_std::set<vostok::render::shader_constant_buffer *,vostok::render::resource_manager::constant_buffer_predicate,vostok::render::std_allocator<vostok::render::shader_constant_buffer *> > *)(a2 + 557268),
    &v24);
  if ( v24._M_node == (stlp_std::priv::_Rb_tree_node_base *)(a2 + 557268) )
  {
    vostok::render::shader_constant_buffer::~shader_constant_buffer(v8);
    ++*(_DWORD *)(a2 + 12);
    v11 = vostok::render::g_allocator;
    v12 = type_info::raw_name(&vostok::render::shader_constant_buffer `RTTI Type Descriptor');
    v14 = vostok::memory::doug_lea_allocator::malloc_impl(v13, (int)v11, 0x68u, v12, v19, v20, v21);
    if ( v14 )
    {
      vostok::render::shader_constant_buffer::shader_constant_buffer(
        name,
        size,
        (vostok::render::shader_constant_buffer *)v14,
        dest,
        type);
      type = v16;
    }
    else
    {
      type = D3D_CT_CBUFFER;
    }
    v17 = type;
    *(_DWORD *)&v18._M_color = &type;
    *(_BYTE *)(type + 101) = 1;
    stlp_std::priv::_Rb_tree<vostok::render::shader_constant_buffer *,vostok::render::resource_manager::constant_buffer_predicate,vostok::render::shader_constant_buffer *,stlp_std::priv::_Identity<vostok::render::shader_constant_buffer *>,stlp_std::priv::_SetTraitsT<vostok::render::shader_constant_buffer *>,vostok::render::std_allocator<vostok::render::shader_constant_buffer *>>::insert_unique(
      v15,
      (int)v23,
      v7,
      v18);
    return (vostok::render::shader_constant_buffer *)v17;
  }
  else
  {
    v9 = *(_DWORD *)&v24._M_node[1]._M_color;
    vostok::render::shader_constant_buffer::~shader_constant_buffer(v8);
    return (vostok::render::shader_constant_buffer *)v9;
  }
}
