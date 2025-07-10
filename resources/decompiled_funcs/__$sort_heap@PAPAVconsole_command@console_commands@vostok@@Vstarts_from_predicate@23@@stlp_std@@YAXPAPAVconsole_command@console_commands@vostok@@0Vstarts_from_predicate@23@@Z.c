void __usercall stlp_std::sort_heap<vostok::console_commands::console_command * *,vostok::console_commands::starts_from_predicate>(
        vostok::console_commands::console_command **__first@<esi>,
        vostok::console_commands::console_command **__last@<eax>,
        vostok::console_commands::starts_from_predicate __comp)
{
  int v3; // eax
  vostok::console_commands::console_command *v4; // ecx
  int v5; // edi

  v3 = (char *)__last - (char *)__first;
  if ( (int)(v3 & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v4 = *(vostok::console_commands::console_command **)((char *)__first + v3 - 4);
      *(vostok::console_commands::console_command **)((char *)__first + v3 - 4) = *__first;
      v5 = v3 - 4;
      stlp_std::__adjust_heap<vostok::console_commands::console_command * *,int,vostok::console_commands::console_command *,vostok::console_commands::starts_from_predicate>(
        __first,
        0,
        (v3 - 4) >> 2,
        v4,
        __comp);
      v3 = v5;
    }
    while ( (int)(v5 & 0xFFFFFFFC) > 4 );
  }
}
