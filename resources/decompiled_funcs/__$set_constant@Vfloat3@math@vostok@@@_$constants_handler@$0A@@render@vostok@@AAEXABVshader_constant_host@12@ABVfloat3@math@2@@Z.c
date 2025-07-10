void __userpurge vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
        const vostok::render::shader_constant_host *c@<eax>,
        vostok::render::constants_handler<0> *this,
        const vostok::math::float3 *arg)
{
  int m_buffer_index; // ecx

  if ( c->m_update_markers[0] == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                 + 572) )
  {
    m_buffer_index = c->m_shader_slots[0].m_buffer_index;
    if ( m_buffer_index != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        c->m_shader_slots[0].m_slot_index,
        (unsigned __int8)c->m_shader_slots[0].m_class_id,
        this->m_current.m_object->m_const_buffers._M_impl._M_start[m_buffer_index].m_object,
        (const char *)arg);
  }
}
