void __usercall vostok::render::custom_config::destroy(
        vostok::render::custom_config *this@<edi>,
        vostok::render::custom_config *in_this@<eax>)
{
  vostok::render::grass_render_model *m_object; // ecx

  if ( this->call_destructors )
    vostok::render::custom_config_value::call_data_destructor(&in_this->m_root);
  if ( this->own_buffer )
  {
    m_object = vostok::render::g_allocator.m_object;
    if ( in_this )
    {
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free((void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick), in_this);
    }
  }
}
