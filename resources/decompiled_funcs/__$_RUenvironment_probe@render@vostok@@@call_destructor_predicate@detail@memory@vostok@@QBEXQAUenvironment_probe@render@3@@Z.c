void __usercall vostok::memory::detail::call_destructor_predicate::operator()<vostok::render::environment_probe>(
        vostok::render::environment_probe *const pointer@<edi>,
        vostok::render::environment_probe *a2@<ecx>,
        vostok::memory::detail::call_destructor_predicate *this)
{
  vostok::render::res_texture *v3; // ecx
  vostok::render::res_texture *m_object; // eax
  bool v5; // zf
  vostok::render::res_texture *v6; // eax

  vostok::render::environment_probe::remove_collision(a2);
  m_object = pointer->m_texture_depth.m_object;
  if ( m_object )
  {
    v5 = m_object->m_reference_count-- == 1;
    if ( v5 )
      vostok::render::res_texture::destroy_impl(v3);
  }
  v6 = pointer->m_texture.m_object;
  if ( v6 )
  {
    v5 = v6->m_reference_count-- == 1;
    if ( v5 )
      vostok::render::res_texture::destroy_impl(v3);
  }
}
