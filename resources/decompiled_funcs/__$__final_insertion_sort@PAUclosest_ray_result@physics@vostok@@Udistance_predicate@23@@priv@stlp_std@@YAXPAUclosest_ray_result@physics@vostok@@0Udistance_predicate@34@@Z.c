void __usercall stlp_std::priv::__final_insertion_sort<vostok::physics::closest_ray_result *,vostok::physics::distance_predicate>(
        vostok::physics::closest_ray_result *__first@<esi>,
        vostok::physics::closest_ray_result *__last@<eax>,
        vostok::physics::distance_predicate __comp)
{
  vostok::physics::distance_predicate v4; // [esp-8h] [ebp-1Ch]

  if ( __last - __first <= 16 )
  {
    if ( __first != __last )
      stlp_std::priv::__insertion_sort<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
        __first,
        __last);
  }
  else
  {
    stlp_std::priv::__insertion_sort<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
      __first,
      __first + 16);
    *(_QWORD *)&v4.m_from.x = *(_QWORD *)&__comp.m_from.elements[1];
    stlp_std::priv::__unguarded_insertion_sort_aux<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
      __first + 16,
      __last,
      (vostok::physics::closest_ray_result *)LODWORD(__comp.m_from.x),
      v4);
  }
}
