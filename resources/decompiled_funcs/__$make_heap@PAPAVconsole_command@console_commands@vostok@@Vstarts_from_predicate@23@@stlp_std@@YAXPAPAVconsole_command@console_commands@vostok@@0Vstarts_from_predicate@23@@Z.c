void __usercall stlp_std::make_heap<vostok::console_commands::console_command * *,vostok::console_commands::starts_from_predicate>(
        vostok::console_commands::console_command **__first@<edi>,
        vostok::console_commands::console_command **__last,
        vostok::console_commands::starts_from_predicate __comp)
{
  int v3; // ebx
  int i; // esi

  v3 = __last - __first;
  if ( v3 >= 2 )
  {
    for ( i = (v3 - 2) / 2; ; --i )
    {
      stlp_std::__adjust_heap<vostok::console_commands::console_command * *,int,vostok::console_commands::console_command *,vostok::console_commands::starts_from_predicate>(
        __first,
        i,
        v3,
        __first[i],
        __comp);
      if ( !i )
        break;
    }
  }
}
