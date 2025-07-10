void __thiscall vostok::render::skeleton_render_model_instance::set_constants(
        vostok::render::skeleton_render_model_instance *this)
{
  const char *m_conflicted_key_name; // edi
  vostok::render::constants_handler<0> *v3; // ebx
  unsigned int v4; // [esp+0h] [ebp-Ch]
  unsigned int v5; // [esp+0h] [ebp-Ch]

  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v3 = (vostok::render::constants_handler<0> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                              + 196);
  vostok::render::constants_handler<0>::set_constant_array<vostok::math::float4>(
    (vostok::render::constants_handler<0> *)this->m_original.m_object->m_bones_matrices_shader_constant,
    (vostok::render::constants_handler<0> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                           + 196),
    (const vostok::math::float4 *)this->m_bones_matrices._M_impl._M_start,
    v4);
  ++*((_DWORD *)m_conflicted_key_name + 23);
  vostok::render::constants_handler<0>::set_constant_array<vostok::math::float4>(
    (vostok::render::constants_handler<0> *)this->m_original.m_object->m_prev_bones_matrices_shader_constant,
    v3,
    (const vostok::math::float4 *)this->m_prev_bones_matrices._M_impl._M_start,
    v5);
  ++*((_DWORD *)m_conflicted_key_name + 23);
}
