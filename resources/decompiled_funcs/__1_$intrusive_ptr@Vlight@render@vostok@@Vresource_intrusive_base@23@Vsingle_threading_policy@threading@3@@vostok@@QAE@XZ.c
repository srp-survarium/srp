void __thiscall vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  vostok::render::light *m_object; // eax
  vostok::render::light *v3; // edi
  vostok::render::grass_render_model *v4; // esi

  m_object = this->m_object;
  if ( this->m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
    {
      v3 = this->m_object;
      v4 = vostok::render::g_allocator.m_object;
      if ( this->m_object )
      {
        vostok::render::light::~light((vostok::render::light *)this);
        BYTE2(v4->m_children_resources.m_lock) = 0;
        vostok_mspace_free((void *)HIDWORD(v4->m_reconstruction_info_actuality_tick), v3);
      }
    }
  }
}
