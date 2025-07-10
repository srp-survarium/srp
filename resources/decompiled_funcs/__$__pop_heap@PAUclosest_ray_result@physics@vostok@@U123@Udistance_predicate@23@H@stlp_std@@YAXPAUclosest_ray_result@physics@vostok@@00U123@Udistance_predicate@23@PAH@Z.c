void __usercall stlp_std::__pop_heap<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate,int>(
        vostok::physics::closest_ray_result *__last@<edx>,
        vostok::physics::closest_ray_result *__result@<eax>,
        vostok::physics::closest_ray_result *__first,
        vostok::physics::closest_ray_result __val,
        vostok::physics::distance_predicate __comp)
{
  unsigned int v5; // edx

  *__result = *__first;
  v5 = (int)((unsigned __int64)(1717986919LL * ((char *)__last - (char *)__first)) >> 32) >> 4;
  stlp_std::__adjust_heap<vostok::physics::closest_ray_result *,int,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
    __first,
    0,
    v5 + (v5 >> 31),
    __val,
    __comp);
}
