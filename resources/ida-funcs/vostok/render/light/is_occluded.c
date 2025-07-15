BOOL __thiscall vostok::render::light::is_occluded(vostok::render::light *this, int a2)
{
  BOOL result; // eax

  result = 0;
  if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_use_hiz_occlusion_culling )
    return *(_BYTE *)(a2 + 624) != 0;
  return result;
}
