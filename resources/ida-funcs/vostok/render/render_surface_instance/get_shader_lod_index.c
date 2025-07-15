unsigned __int8 __thiscall vostok::render::render_surface_instance::get_shader_lod_index(
        vostok::render::render_surface_instance *this,
        int a2)
{
  unsigned __int8 result; // al

  if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_shading_quality )
    return 0;
  if ( !vostok::quasi_singleton<vostok::render::options>::pinst->current.m_use_shader_lods )
    return 0;
  result = 1;
  if ( *(float *)(a2 + 44) >= 0.75 )
    return 0;
  return result;
}
