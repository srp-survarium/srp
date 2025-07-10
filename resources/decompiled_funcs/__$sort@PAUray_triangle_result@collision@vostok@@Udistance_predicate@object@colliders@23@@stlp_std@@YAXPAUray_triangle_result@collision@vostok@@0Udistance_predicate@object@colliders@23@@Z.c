void __usercall stlp_std::sort<vostok::collision::ray_triangle_result *,vostok::collision::colliders::object::distance_predicate>(
        vostok::collision::ray_triangle_result *__first@<eax>,
        vostok::collision::ray_triangle_result *__last@<edi>,
        vostok::collision::colliders::object::distance_predicate __comp)
{
  int v4; // eax
  int i; // ecx

  if ( __first != __last )
  {
    v4 = __last - __first;
    for ( i = 0; v4 != 1; ++i )
      v4 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::collision::ray_triangle_result *,vostok::collision::ray_triangle_result,int,vostok::collision::colliders::object::distance_predicate>(
      __first,
      __last,
      0,
      2 * i,
      __comp);
    stlp_std::priv::__final_insertion_sort<vostok::collision::ray_triangle_result *,vostok::collision::colliders::object::distance_predicate>(
      __first,
      __last,
      __comp);
  }
}
