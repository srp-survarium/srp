void __userpurge vostok::intrusive_ptr<vostok::render::decal_instance,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
        vostok::intrusive_ptr<vostok::render::decal_instance,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<ecx>,
        vostok::memory::detail::call_destructor_predicate *a2@<edi>,
        vostok::intrusive_ptr<vostok::render::decal_instance,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *object,
        vostok::render::decal_instance *objecta)
{
  vostok::render::decal_instance *m_object; // eax
  vostok::render::decal_instance *v6; // esi
  vostok::render::grass_render_model *v7; // edi
  vostok::render::decal_instance *v8; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi

  m_object = object->m_object;
  if ( object->m_object != objecta )
  {
    if ( m_object )
    {
      if ( m_object->m_reference_count-- == 1 )
      {
        v6 = object->m_object;
        v7 = vostok::render::g_allocator.m_object;
        if ( object->m_object )
        {
          vostok::memory::detail::call_destructor_predicate::operator()<vostok::render::decal_instance>(
            v6,
            (vostok::render::decal_instance *)this,
            a2);
          v8 = v6;
          m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(v7->m_reconstruction_info_actuality_tick);
          BYTE2(v7->m_children_resources.m_lock) = 0;
          vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v8);
        }
      }
    }
    object->m_object = objecta;
    if ( objecta )
      ++objecta->m_reference_count;
  }
}
