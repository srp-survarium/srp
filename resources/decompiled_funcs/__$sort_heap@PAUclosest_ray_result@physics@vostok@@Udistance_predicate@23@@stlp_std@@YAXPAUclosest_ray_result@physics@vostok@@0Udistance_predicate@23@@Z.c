void __usercall stlp_std::sort_heap<vostok::physics::closest_ray_result *,vostok::physics::distance_predicate>(
        vostok::physics::closest_ray_result *__first@<edi>,
        vostok::physics::closest_ray_result *__last@<eax>,
        vostok::physics::distance_predicate __comp)
{
  vostok::physics::closest_ray_result *v3; // esi

  if ( __last - __first > 1 )
  {
    v3 = __last - 1;
    do
    {
      stlp_std::__pop_heap<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate,int>(
        v3,
        v3,
        __first,
        *v3,
        __comp);
      --v3;
    }
    while ( ((int)v3 + 40 - (int)__first) / 40 > 1 );
  }
}
