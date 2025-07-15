void __userpurge vostok::render::constants_handler<1>::set_constant_array<vostok::math::float4>(
        vostok::render::constants_handler<1> *this@<ecx>,
        vostok::render::constants_handler<1> *c,
        const vostok::math::float4 *arg,
        unsigned int array_size)
{
  int m_object_low; // eax

  if ( this[3].m_diff_range_end == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                   + 573) )
  {
    m_object_low = LOWORD(this[1].m_current.m_object);
    if ( m_object_low != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        HIWORD(this[1].m_current.m_object),
        (unsigned __int8)LOWORD(this[1].m_diff_range_end) * HIWORD(this[1].m_diff_range_end),
        c->m_current.m_object->m_const_buffers._M_impl._M_start[m_object_low].m_object,
        (const char *)arg);
  }
}


void __userpurge vostok::render::constants_handler<0>::set_constant_array<vostok::math::float4>(
        vostok::render::constants_handler<0> *this@<ecx>,
        vostok::render::constants_handler<0> *c,
        const vostok::math::float4 *arg,
        unsigned int array_size)
{
  int m_diff_range_start_low; // eax

  if ( this[3].m_diff_range_start == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                     + 572) )
  {
    m_diff_range_start_low = LOWORD(this[1].m_diff_range_start);
    if ( m_diff_range_start_low != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        HIWORD(this[1].m_diff_range_start),
        (unsigned __int8)LOWORD(this->m_current.m_object) * HIWORD(this->m_current.m_object),
        c->m_current.m_object->m_const_buffers._M_impl._M_start[m_diff_range_start_low].m_object,
        (const char *)arg);
  }
}
