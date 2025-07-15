BOOL __thiscall vostok::render::render_surface_instance::is_occluded(
        vostok::render::render_surface_instance *this,
        int a2)
{
  BOOL result; // eax

  result = 0;
  if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_use_hiz_occlusion_culling )
    return *(_BYTE *)(a2 + 53) != 0;
  return result;
}
