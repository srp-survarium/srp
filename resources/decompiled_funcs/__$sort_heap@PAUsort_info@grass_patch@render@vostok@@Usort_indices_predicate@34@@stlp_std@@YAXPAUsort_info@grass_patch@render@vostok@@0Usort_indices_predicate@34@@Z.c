void __usercall stlp_std::sort_heap<vostok::render::grass_patch::sort_info *,vostok::render::sort_indices_predicate>(
        vostok::render::grass_patch::sort_info *__first@<edi>,
        vostok::render::grass_patch::sort_info *__last@<eax>,
        vostok::render::sort_indices_predicate __comp)
{
  vostok::render::grass_patch::sort_info *v3; // esi

  if ( __last - __first > 1 )
  {
    v3 = __last - 1;
    do
    {
      stlp_std::__pop_heap<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate,int>(
        v3,
        v3,
        __first,
        *v3,
        __comp);
      --v3;
    }
    while ( ((int)v3 + 20 - (int)__first) / 20 > 1 );
  }
}
