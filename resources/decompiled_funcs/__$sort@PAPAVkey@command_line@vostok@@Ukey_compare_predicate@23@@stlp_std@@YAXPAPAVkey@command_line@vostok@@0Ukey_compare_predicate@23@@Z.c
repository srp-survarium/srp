void __usercall stlp_std::sort<vostok::command_line::key * *,vostok::command_line::key_compare_predicate>(
        vostok::command_line::key **__first@<esi>,
        vostok::command_line::key **__last@<eax>,
        vostok::command_line::key_compare_predicate __comp)
{
  int v4; // eax
  int i; // ecx

  if ( __first != __last )
  {
    v4 = __last - __first;
    for ( i = 0; v4 != 1; ++i )
      v4 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::command_line::key * *,vostok::command_line::key *,int,vostok::command_line::key_compare_predicate>(
      __first,
      __last,
      0,
      2 * i,
      __comp);
    stlp_std::priv::__final_insertion_sort<vostok::command_line::key * *,vostok::command_line::key_compare_predicate>(
      __first,
      __last,
      __comp);
  }
}
