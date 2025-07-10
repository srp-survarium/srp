vostok::render::shader_constant_buffer *__thiscall vostok::render::resource_manager::create_constant_buffer(
        vostok::render::resource_manager *this,
        vostok::render::resource_manager *name,
        const vostok::fixed_string<64> *dest,
        vostok::render::enum_shader_type type,
        _D3D_CBUFFER_TYPE size,
        unsigned int sizea)
{
  const vostok::render::shader_constant_buffer *const *v6; // eax
  vostok::render::shader_constant_buffer *v7; // ecx
  int v8; // esi
  stlp_std::priv::_Rb_tree<vostok::render::shader_constant_buffer *,vostok::render::resource_manager::constant_buffer_predicate,vostok::render::shader_constant_buffer *,stlp_std::priv::_Identity<vostok::render::shader_constant_buffer *>,stlp_std::priv::_SetTraitsT<vostok::render::shader_constant_buffer *>,vostok::render::std_allocator<vostok::render::shader_constant_buffer *> > *v10; // ecx
  vostok::render::shader_constant_buffer *v11; // esi
  vostok::render::shader_constant_buffer *v12; // eax
  vostok::render::shader_constant_buffer *v13; // esi
  vostok::render::shader_constant_buffer *cbuffer; // [esp+14h] [ebp-74h] BYREF
  vostok::render::shader_constant_buffer *__val; // [esp+18h] [ebp-70h] BYREF
  vostok::render::shader_constant_buffer new_buffer; // [esp+20h] [ebp-68h] BYREF

  vostok::render::shader_constant_buffer::shader_constant_buffer(&new_buffer, dest, type, size, sizea);
  cbuffer = &new_buffer;
  v6 = stlp_std::priv::_Rb_tree<vostok::render::shader_constant_buffer *,vostok::render::resource_manager::constant_buffer_predicate,vostok::render::shader_constant_buffer *,stlp_std::priv::_Identity<vostok::render::shader_constant_buffer *>,stlp_std::priv::_SetTraitsT<vostok::render::shader_constant_buffer *>,vostok::render::std_allocator<vostok::render::shader_constant_buffer *>>::_M_find<vostok::render::shader_constant_buffer const *>(
         (stlp_std::priv::_Rb_tree<vostok::render::shader_constant_buffer *,vostok::render::resource_manager::constant_buffer_predicate,vostok::render::shader_constant_buffer *,stlp_std::priv::_Identity<vostok::render::shader_constant_buffer *>,stlp_std::priv::_SetTraitsT<vostok::render::shader_constant_buffer *>,vostok::render::std_allocator<vostok::render::shader_constant_buffer *> > *)&cbuffer,
         (vostok::render::resource_manager::constant_buffer_predicate *)&new_buffer,
         (const vostok::render::shader_constant_buffer *const *)&name->m_const_buffers,
         (const vostok::render::shader_constant_buffer *const *)&cbuffer);
  if ( v6 == (const vostok::render::shader_constant_buffer *const *)&name->m_const_buffers )
  {
    vostok::render::shader_constant_buffer::~shader_constant_buffer(v7);
    ++name->cb_created;
    v11 = (vostok::render::shader_constant_buffer *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                      (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                      0x68u);
    if ( v11 )
    {
      vostok::render::shader_constant_buffer::shader_constant_buffer(v11, dest, type, size, sizea);
      v13 = v12;
    }
    else
    {
      v13 = 0;
    }
    cbuffer = v13;
    v13->m_is_registered = 1;
    stlp_std::priv::_Rb_tree<vostok::render::shader_constant_buffer *,vostok::render::resource_manager::constant_buffer_predicate,vostok::render::shader_constant_buffer *,stlp_std::priv::_Identity<vostok::render::shader_constant_buffer *>,stlp_std::priv::_SetTraitsT<vostok::render::shader_constant_buffer *>,vostok::render::std_allocator<vostok::render::shader_constant_buffer *>>::insert_unique(
      v10,
      &name->m_const_buffers._M_t,
      &__val,
      &cbuffer);
    return v13;
  }
  else
  {
    v8 = *((_DWORD *)v6 + 4);
    vostok::render::shader_constant_buffer::~shader_constant_buffer(v7);
    return (vostok::render::shader_constant_buffer *)v8;
  }
}
