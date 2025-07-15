BOOL __thiscall vostok::render::environment_probe::is_occluded(vostok::render::environment_probe *this, int a2)
{
  BOOL result; // eax

  result = 0;
  if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_use_hiz_occlusion_culling )
    return *(_BYTE *)(a2 + 616) != 0;
  return result;
}
