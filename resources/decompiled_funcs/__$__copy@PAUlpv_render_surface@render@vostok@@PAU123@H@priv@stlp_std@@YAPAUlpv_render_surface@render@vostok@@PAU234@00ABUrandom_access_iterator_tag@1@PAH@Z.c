vostok::render::lpv_render_surface *__usercall stlp_std::priv::__copy<vostok::render::lpv_render_surface *,vostok::render::lpv_render_surface *,int>@<eax>(
        vostok::render::lpv_render_surface *__last@<eax>,
        vostok::render::lpv_render_surface *__result@<ecx>,
        vostok::render::lpv_render_surface *__first)
{
  vostok::render::lpv_render_surface *v3; // edi
  int i; // ebx
  vostok::render::render_model_instance_impl *m_object; // ecx
  vostok::render::render_model_instance_impl *v7; // eax
  vostok::render::render_model_instance_impl *v8; // edx

  v3 = __first;
  for ( i = __last - __first; i > 0; ++__result )
  {
    __result->surface = v3->surface;
    m_object = v3->model.m_object;
    v7 = 0;
    if ( m_object )
    {
      v7 = v3->model.m_object;
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    }
    v8 = __result->model.m_object;
    __result->model.m_object = v7;
    if ( v8 && !_InterlockedExchangeAdd(&v8->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v8->vostok::resources::unmanaged_intrusive_base, v8);
    --i;
    ++v3;
  }
  return __result;
}
