BOOL __thiscall vostok::render::ambient_light::is_occluded(vostok::render::ambient_light *this, int a2)
{
  BOOL result; // eax

  result = 0;
  if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_use_hiz_occlusion_culling )
    return *(_BYTE *)(a2 + 164) != 0;
  return result;
}
