void __thiscall vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
        vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this,
        const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *object,
        const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *objecta)
{
  vostok::render::light *m_object; // eax
  vostok::render::light *v5; // edi
  vostok::render::grass_render_model *v6; // esi
  vostok::render::light *v7; // eax

  m_object = object->m_object;
  if ( object->m_object != objecta->m_object )
  {
    if ( m_object )
    {
      if ( m_object->m_reference_count-- == 1 )
      {
        v5 = object->m_object;
        v6 = vostok::render::g_allocator.m_object;
        if ( object->m_object )
        {
          vostok::render::light::~light((vostok::render::light *)this);
          BYTE2(v6->m_children_resources.m_lock) = 0;
          vostok_mspace_free((void *)HIDWORD(v6->m_reconstruction_info_actuality_tick), v5);
        }
      }
    }
    v7 = objecta->m_object;
    object->m_object = objecta->m_object;
    if ( v7 )
      ++v7->m_reference_count;
  }
}
