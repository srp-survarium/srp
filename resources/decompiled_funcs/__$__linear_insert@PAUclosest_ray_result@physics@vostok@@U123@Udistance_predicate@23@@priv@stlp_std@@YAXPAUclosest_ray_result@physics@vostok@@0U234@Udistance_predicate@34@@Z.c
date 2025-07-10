void __usercall stlp_std::priv::__linear_insert<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
        vostok::physics::closest_ray_result *__first@<esi>,
        vostok::physics::closest_ray_result *__last@<ecx>,
        vostok::physics::closest_ray_result __val,
        vostok::physics::distance_predicate __comp)
{
  if ( (float)((float)((float)((float)(__first->hit_point_world.z - __comp.m_from.z)
                             * (float)(__first->hit_point_world.z - __comp.m_from.z))
                     + (float)((float)(__first->hit_point_world.y - __comp.m_from.y)
                             * (float)(__first->hit_point_world.y - __comp.m_from.y)))
             + (float)((float)(__first->hit_point_world.x - __comp.m_from.x)
                     * (float)(__first->hit_point_world.x - __comp.m_from.x))) <= (float)((float)((float)((float)(__val.hit_point_world.z - __comp.m_from.z) * (float)(__val.hit_point_world.z - __comp.m_from.z))
                                                                                                + (float)((float)(__val.hit_point_world.y - __comp.m_from.y) * (float)(__val.hit_point_world.y - __comp.m_from.y)))
                                                                                        + (float)((float)(__val.hit_point_world.x - __comp.m_from.x)
                                                                                                * (float)(__val.hit_point_world.x - __comp.m_from.x))) )
  {
    stlp_std::priv::__unguarded_linear_insert<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
      __last,
      __val,
      __comp);
  }
  else
  {
    if ( (char *)__last - (char *)__first > 0 )
      memmove((unsigned __int8 *)&__first[1], (unsigned __int8 *)__first, (char *)__last - (char *)__first);
    *__first = __val;
  }
}
