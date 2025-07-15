BOOL __thiscall vostok::render::decal_instance::is_occluded(vostok::render::decal_instance *this, int a2)
{
  BOOL result; // eax

  result = 0;
  if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_use_hiz_occlusion_culling )
    return *(_BYTE *)(a2 + 152) != 0;
  return result;
}
