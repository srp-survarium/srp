void __usercall stlp_std::sort<vostok::render::grass_patch::sort_info *,vostok::render::sort_indices_predicate>(
        vostok::render::grass_patch::sort_info *__first@<eax>,
        vostok::render::grass_patch::sort_info *__last@<edi>,
        vostok::render::sort_indices_predicate __comp)
{
  int v4; // eax
  int i; // ecx

  if ( __first != __last )
  {
    v4 = __last - __first;
    for ( i = 0; v4 != 1; ++i )
      v4 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,int,vostok::render::sort_indices_predicate>(
      __first,
      __last,
      0,
      2 * i,
      __comp);
    stlp_std::priv::__final_insertion_sort<vostok::render::grass_patch::sort_info *,vostok::render::sort_indices_predicate>(
      __first,
      __last,
      __comp);
  }
}
