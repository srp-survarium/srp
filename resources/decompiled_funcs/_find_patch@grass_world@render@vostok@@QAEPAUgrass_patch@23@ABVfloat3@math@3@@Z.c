vostok::render::grass_patch *__usercall vostok::render::grass_world::find_patch@<eax>(
        vostok::render::grass_world *this@<eax>,
        const vostok::math::float3 *point@<esi>)
{
  void **M_start; // ecx
  void **M_finish; // edx
  float x; // xmm1_4
  vostok::render::grass_patch *result; // eax
  float z; // xmm0_4

  M_start = this->m_patches._M_impl._M_start;
  M_finish = this->m_patches._M_impl._M_finish;
  if ( M_start == M_finish )
    return 0;
  x = point->x;
  while ( 1 )
  {
    result = (vostok::render::grass_patch *)*M_start;
    if ( x >= *((float *)*M_start + 4101) )
    {
      z = point->z;
      if ( z >= result->m_aabb.min.z && result->m_aabb.max.x >= x && result->m_aabb.max.z >= z )
        break;
    }
    if ( ++M_start == M_finish )
      return 0;
  }
  return result;
}
