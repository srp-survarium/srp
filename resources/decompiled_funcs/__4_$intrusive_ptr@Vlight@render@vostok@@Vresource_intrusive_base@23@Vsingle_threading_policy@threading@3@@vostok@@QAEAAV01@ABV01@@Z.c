vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *__userpurge vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=@<eax>(
        const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *object@<eax>,
        vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v2; // ebp
  vostok::render::light *v3; // ecx
  vostok::render::light *m_object; // edi
  vostok::render::grass_render_model *v6; // esi

  v2 = this;
  this = 0;
  vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    (vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&this,
    (const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&this,
    object);
  m_object = v2->m_object;
  v2->m_object = (vostok::render::light *)this;
  if ( m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
    {
      v6 = vostok::render::g_allocator.m_object;
      vostok::render::light::~light(v3);
      BYTE2(v6->m_children_resources.m_lock) = 0;
      vostok_mspace_free((void *)HIDWORD(v6->m_reconstruction_info_actuality_tick), m_object);
    }
  }
  return v2;
}
