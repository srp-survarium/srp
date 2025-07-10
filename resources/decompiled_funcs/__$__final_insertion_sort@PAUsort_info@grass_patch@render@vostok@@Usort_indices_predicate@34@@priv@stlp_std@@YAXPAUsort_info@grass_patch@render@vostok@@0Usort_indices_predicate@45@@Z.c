void __usercall stlp_std::priv::__final_insertion_sort<vostok::render::grass_patch::sort_info *,vostok::render::sort_indices_predicate>(
        vostok::render::grass_patch::sort_info *__first@<esi>,
        vostok::render::grass_patch::sort_info *__last@<eax>,
        vostok::render::sort_indices_predicate __comp)
{
  vostok::render::sort_indices_predicate v4; // [esp-Ch] [ebp-24h]

  if ( __last - __first <= 16 )
  {
    if ( __first != __last )
      stlp_std::priv::__insertion_sort<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
        __first,
        __last);
  }
  else
  {
    stlp_std::priv::__insertion_sort<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
      __first,
      __first + 16);
    *(vostok::math::float3 *)&v4.m_patch = __comp.m_view_pos;
    stlp_std::priv::__unguarded_insertion_sort_aux<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
      __first + 16,
      __last,
      (vostok::render::grass_patch::sort_info *)__comp.m_patch,
      v4);
  }
}
