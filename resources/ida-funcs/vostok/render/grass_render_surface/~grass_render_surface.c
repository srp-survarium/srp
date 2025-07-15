void __usercall vostok::render::grass_render_surface::~grass_render_surface(
        vostok::render::grass_render_surface *this@<ecx>,
        const char *a2@<esi>)
{
  unsigned __int16 **p_m_indices; // edi
  unsigned __int16 *m_indices; // eax
  const char *v5; // [esp+0h] [ebp-8h]
  unsigned int v6; // [esp+4h] [ebp-4h]

  p_m_indices = &this->m_indices;
  this->__vftable = (vostok::render::grass_render_surface_vtbl *)&vostok::render::grass_render_surface::`vftable';
  m_indices = this->m_indices;
  if ( m_indices )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)vostok::render::g_allocator,
      (char *)m_indices,
      a2,
      v5,
      v6);
    *p_m_indices = 0;
  }
  vostok::render::render_surface::~render_surface(this);
}
