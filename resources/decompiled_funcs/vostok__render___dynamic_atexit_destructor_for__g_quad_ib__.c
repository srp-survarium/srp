void __cdecl vostok::render::_dynamic_atexit_destructor_for__g_quad_ib__()
{
  vostok::render::untyped_buffer *m_object; // eax

  m_object = vostok::render::g_quad_ib.m_object;
  if ( vostok::render::g_quad_ib.m_object )
  {
    --vostok::render::g_quad_ib.m_object->m_reference_count;
    if ( !m_object->m_reference_count )
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)vostok::render::g_quad_ib.m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
}
