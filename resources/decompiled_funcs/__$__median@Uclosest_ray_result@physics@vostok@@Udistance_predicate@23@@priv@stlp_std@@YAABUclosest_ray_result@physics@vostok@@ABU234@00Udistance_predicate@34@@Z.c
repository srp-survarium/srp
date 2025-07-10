const vostok::physics::closest_ray_result *__usercall stlp_std::priv::__median<vostok::physics::closest_ray_result,vostok::physics::distance_predicate>@<eax>(
        const vostok::physics::closest_ray_result *__b@<eax>,
        const vostok::physics::closest_ray_result *__c@<ecx>,
        const vostok::physics::closest_ray_result *__a,
        vostok::physics::distance_predicate __comp)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v6; // xmm4_4
  float v7; // xmm6_4

  y = __comp.m_from.y;
  z = __comp.m_from.z;
  v6 = (float)((float)((float)(__b->hit_point_world.z - __comp.m_from.z)
                     * (float)(__b->hit_point_world.z - __comp.m_from.z))
             + (float)((float)(__b->hit_point_world.y - __comp.m_from.y)
                     * (float)(__b->hit_point_world.y - __comp.m_from.y)))
     + (float)((float)(__b->hit_point_world.x - __comp.m_from.x) * (float)(__b->hit_point_world.x - __comp.m_from.x));
  __comp.m_from.y = __c->hit_point_world.y - __comp.m_from.y;
  v7 = __c->hit_point_world.x - __comp.m_from.x;
  __comp.m_from.z = __c->hit_point_world.z - __comp.m_from.z;
  if ( v6 > (float)((float)((float)((float)(__a->hit_point_world.z - z) * (float)(__a->hit_point_world.z - z))
                          + (float)((float)(__a->hit_point_world.x - __comp.m_from.x)
                                  * (float)(__a->hit_point_world.x - __comp.m_from.x)))
                  + (float)((float)(__a->hit_point_world.y - y) * (float)(__a->hit_point_world.y - y))) )
  {
    if ( (float)((float)((float)(v7 * v7) + (float)(__comp.m_from.z * __comp.m_from.z))
               + (float)(__comp.m_from.y * __comp.m_from.y)) > (float)((float)((float)((float)(__b->hit_point_world.y - y)
                                                                                     * (float)(__b->hit_point_world.y - y))
                                                                             + (float)((float)(__b->hit_point_world.x
                                                                                             - __comp.m_from.x)
                                                                                     * (float)(__b->hit_point_world.x
                                                                                             - __comp.m_from.x)))
                                                                     + (float)((float)(__b->hit_point_world.z - z)
                                                                             * (float)(__b->hit_point_world.z - z))) )
      return __b;
    if ( (float)((float)((float)((float)(__c->hit_point_world.x - __comp.m_from.x)
                               * (float)(__c->hit_point_world.x - __comp.m_from.x))
                       + (float)((float)(__c->hit_point_world.z - z) * (float)(__c->hit_point_world.z - z)))
               + (float)((float)(__c->hit_point_world.y - y) * (float)(__c->hit_point_world.y - y))) <= (float)((float)((float)((float)(__a->hit_point_world.x - __comp.m_from.x) * (float)(__a->hit_point_world.x - __comp.m_from.x)) + (float)((float)(__a->hit_point_world.z - z) * (float)(__a->hit_point_world.z - z))) + (float)((float)(__a->hit_point_world.y - y) * (float)(__a->hit_point_world.y - y))) )
      return __a;
    return __c;
  }
  if ( (float)((float)((float)(v7 * v7) + (float)(__comp.m_from.z * __comp.m_from.z))
             + (float)(__comp.m_from.y * __comp.m_from.y)) > (float)((float)((float)((float)(__a->hit_point_world.x
                                                                                           - __comp.m_from.x)
                                                                                   * (float)(__a->hit_point_world.x
                                                                                           - __comp.m_from.x))
                                                                           + (float)((float)(__a->hit_point_world.z - z)
                                                                                   * (float)(__a->hit_point_world.z - z)))
                                                                   + (float)((float)(__a->hit_point_world.y - y)
                                                                           * (float)(__a->hit_point_world.y - y))) )
    return __a;
  if ( (float)((float)((float)((float)(__c->hit_point_world.x - __comp.m_from.x)
                             * (float)(__c->hit_point_world.x - __comp.m_from.x))
                     + (float)((float)(__c->hit_point_world.z - z) * (float)(__c->hit_point_world.z - z)))
             + (float)((float)(__c->hit_point_world.y - y) * (float)(__c->hit_point_world.y - y))) > (float)((float)((float)((float)(__b->hit_point_world.x - __comp.m_from.x) * (float)(__b->hit_point_world.x - __comp.m_from.x)) + (float)((float)(__b->hit_point_world.z - z) * (float)(__b->hit_point_world.z - z))) + (float)((float)(__b->hit_point_world.y - y) * (float)(__b->hit_point_world.y - y))) )
    return __c;
  return __b;
}
