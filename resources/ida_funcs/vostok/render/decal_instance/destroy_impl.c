void __usercall vostok::render::decal_instance::destroy_impl(
        vostok::render::decal_instance *this@<ecx>,
        vostok::render::decal_instance *a2@<eax>)
{
  vostok::render::grass_render_model *m_object; // edi
  vostok::render::decal_instance *v4; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::memory::detail::call_destructor_predicate *v6; // [esp+0h] [ebp-8h]

  m_object = vostok::render::g_allocator.m_object;
  if ( a2 )
  {
    vostok::memory::detail::call_destructor_predicate::operator()<vostok::render::decal_instance>(a2, this, v6);
    v4 = a2;
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
    BYTE2(m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v4);
  }
}
