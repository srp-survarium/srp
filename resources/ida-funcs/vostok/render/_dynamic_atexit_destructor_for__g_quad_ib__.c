void __usercall vostok::render::_dynamic_atexit_destructor_for__g_quad_ib__(vostok::render::hw_buffer_pool *a1@<esi>)
{
  vostok::render::untyped_buffer *m_object; // eax

  m_object = vostok::render::g_quad_ib.m_object;
  if ( vostok::render::g_quad_ib.m_object )
  {
    --vostok::render::g_quad_ib.m_object->m_reference_count;
    if ( !m_object->m_reference_count )
      vostok::render::resource_intrusive_base::destroy<vostok::render::untyped_buffer>(
        vostok::render::g_quad_ib.m_object,
        a1);
  }
}
