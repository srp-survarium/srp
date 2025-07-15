void __usercall vostok::render::renderer::sort_models_by_distance(
        vostok::render::renderer *this@<ecx>,
        vostok::buffer_vector<vostok::render::render_surface_instance *> *instances@<eax>)
{
  vostok::render::render_surface_instance **m_end; // ebx
  vostok::render::renderer_context *m_renderer_context; // esi
  vostok::render::render_surface_instance **m_begin; // ecx
  int v5; // eax
  int v6; // edx
  vostok::render::sort_by_distance_predicate v7; // [esp+Ch] [ebp-14h]
  vostok::render::render_surface_instance **__first; // [esp+1Ch] [ebp-4h]

  m_end = instances->m_end;
  m_renderer_context = this->m_renderer_context;
  m_begin = instances->m_begin;
  m_renderer_context = (vostok::render::renderer_context *)((char *)m_renderer_context + 21132);
  LODWORD(v7.m_eye_position.x) = m_renderer_context->m_targets;
  m_renderer_context = (vostok::render::renderer_context *)((char *)m_renderer_context + 4);
  LODWORD(v7.m_eye_position.y) = m_renderer_context->m_targets;
  LODWORD(v7.m_eye_position.z) = m_renderer_context->m_family[0].orig_name.m_begin;
  v7.m_from_near_to_far = 0;
  __first = instances->m_begin;
  if ( instances->m_begin != m_end )
  {
    v5 = m_end - m_begin;
    v6 = 0;
    while ( v5 != 1 )
    {
      ++v6;
      v5 >>= 1;
    }
    stlp_std::priv::__introsort_loop<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance *,int,vostok::render::sort_by_distance_predicate>(
      m_begin,
      m_end,
      0,
      2 * v6,
      v7);
    stlp_std::priv::__final_insertion_sort<vostok::render::render_surface_instance * *,vostok::render::sort_by_distance_predicate>(
      __first,
      m_end,
      v7);
  }
}
