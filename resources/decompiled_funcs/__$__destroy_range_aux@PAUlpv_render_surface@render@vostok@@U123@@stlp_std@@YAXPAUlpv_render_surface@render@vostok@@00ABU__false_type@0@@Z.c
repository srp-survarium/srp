void __usercall stlp_std::__destroy_range_aux<vostok::render::lpv_render_surface *,vostok::render::lpv_render_surface>(
        vostok::render::lpv_render_surface *__first@<eax>,
        vostok::render::lpv_render_surface *__last@<edi>)
{
  vostok::render::lpv_render_surface *i; // esi
  vostok::render::render_model_instance_impl *m_object; // eax

  for ( i = __first; i != __last; ++i )
  {
    m_object = i->model.m_object;
    if ( m_object )
    {
      if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(
          &i->model.m_object->vostok::resources::unmanaged_intrusive_base,
          i->model.m_object);
    }
  }
}
