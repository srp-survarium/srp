void __usercall stlp_std::sort<vostok::render::grass_patch * *,vostok::render::sort_grass_patch_predicate>(
        vostok::render::grass_patch **__first@<esi>,
        vostok::render::grass_patch **__last@<eax>,
        vostok::render::sort_grass_patch_predicate __comp)
{
  int v4; // eax
  int i; // ecx

  if ( __first != __last )
  {
    v4 = __last - __first;
    for ( i = 0; v4 != 1; ++i )
      v4 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::render::grass_patch * *,vostok::render::grass_patch *,int,vostok::render::sort_grass_patch_predicate>(
      __first,
      __last,
      0,
      2 * i,
      __comp);
    stlp_std::priv::__final_insertion_sort<vostok::render::grass_patch * *,vostok::render::sort_grass_patch_predicate>(
      __first,
      __last,
      __comp);
  }
}
