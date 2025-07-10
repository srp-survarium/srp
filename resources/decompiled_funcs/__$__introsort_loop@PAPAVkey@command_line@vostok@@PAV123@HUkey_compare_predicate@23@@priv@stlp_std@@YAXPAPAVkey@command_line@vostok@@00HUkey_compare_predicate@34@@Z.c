void __usercall stlp_std::priv::__introsort_loop<vostok::command_line::key * *,vostok::command_line::key *,int,vostok::command_line::key_compare_predicate>(
        vostok::command_line::key_compare_predicate a1@<sil>,
        vostok::command_line::key **__first,
        vostok::command_line::key **__last,
        vostok::command_line::key **__formal,
        int __depth_limit,
        vostok::command_line::key **__comp)
{
  vostok::command_line::key **v6; // edi
  vostok::command_line::key **v8; // eax
  vostok::command_line::key **v9; // esi

  v6 = __last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    while ( __depth_limit )
    {
      --__depth_limit;
      v8 = (vostok::command_line::key **)stlp_std::priv::__median<vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
                                           __first,
                                           &__first[(v6 - __first) / 2],
                                           v6 - 1,
                                           (vostok::command_line::key_compare_predicate)__comp);
      v9 = stlp_std::priv::__unguarded_partition<vostok::command_line::key * *,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
             __first,
             v6,
             *v8,
             (vostok::command_line::key_compare_predicate)__comp);
      stlp_std::priv::__introsort_loop<vostok::command_line::key * *,vostok::command_line::key *,int,vostok::command_line::key_compare_predicate>(
        v9,
        v6,
        0,
        __depth_limit,
        (vostok::command_line::key_compare_predicate)__comp);
      v6 = v9;
      if ( (int)(((char *)v9 - (char *)__first) & 0xFFFFFFFC) <= 64 )
        return;
    }
    stlp_std::priv::__partial_sort<vostok::command_line::key * *,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
      __first,
      v6,
      v6,
      __comp,
      a1);
  }
}
