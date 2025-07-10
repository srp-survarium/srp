void __usercall vostok::render::light::destroy_impl(vostok::render::light *this@<ecx>, void *a2@<eax>)
{
  vostok::render::grass_render_model *m_object; // esi

  m_object = vostok::render::g_allocator.m_object;
  if ( a2 )
  {
    vostok::render::light::~light(this, (int)a2);
    BYTE2(m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free((void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick), a2);
  }
}
