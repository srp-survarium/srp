void __cdecl stlp_std::priv::__unguarded_linear_insert<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
        vostok::physics::closest_ray_result __val,
        vostok::physics::distance_predicate __comp)
{
  vostok::physics::closest_ray_result *__last; // ecx
  float x; // xmm4_4
  float y; // xmm5_4
  float z; // xmm6_4
  vostok::physics::closest_ray_result *v6; // eax
  float v7; // xmm3_4
  float *i; // edx

  x = __comp.m_from.x;
  y = __comp.m_from.y;
  z = __comp.m_from.z;
  v6 = __last - 1;
  v7 = (float)((float)((float)(__val.hit_point_world.z - __comp.m_from.z)
                     * (float)(__val.hit_point_world.z - __comp.m_from.z))
             + (float)((float)(__val.hit_point_world.x - __comp.m_from.x)
                     * (float)(__val.hit_point_world.x - __comp.m_from.x)))
     + (float)((float)(__val.hit_point_world.y - __comp.m_from.y) * (float)(__val.hit_point_world.y - __comp.m_from.y));
  for ( i = &__last[-1].hit_point_world.z;
        (float)((float)((float)((float)(*i - z) * (float)(*i - z))
                      + (float)((float)(*(i - 1) - y) * (float)(*(i - 1) - y)))
              + (float)((float)(*(i - 2) - x) * (float)(*(i - 2) - x))) > v7;
        i -= 10 )
  {
    *__last = *v6;
    __last = v6--;
  }
  *__last = __val;
}
