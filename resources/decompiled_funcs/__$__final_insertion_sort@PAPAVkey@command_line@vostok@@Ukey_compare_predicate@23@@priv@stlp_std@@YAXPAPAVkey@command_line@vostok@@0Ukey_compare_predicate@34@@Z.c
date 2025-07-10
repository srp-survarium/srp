void __usercall stlp_std::priv::__final_insertion_sort<vostok::command_line::key * *,vostok::command_line::key_compare_predicate>(
        vostok::command_line::key **__first@<eax>,
        vostok::command_line::key **__last@<edi>,
        int a3@<ecx>,
        vostok::command_line::key_compare_predicate a4@<sil>,
        vostok::command_line::key **__comp)
{
  vostok::command_line::key **v5; // esi
  vostok::command_line::key_compare_predicate v7; // [esp-4h] [ebp-8h]
  vostok::command_line::key_compare_predicate v8[4]; // [esp+0h] [ebp-4h] BYREF

  *(_DWORD *)v8 = a3;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) <= 64 )
  {
    v8[0] = (vostok::command_line::key_compare_predicate)__comp;
    if ( __first != __last )
      stlp_std::priv::__insertion_sort<vostok::command_line::key * *,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
        __first,
        __last,
        (vostok::command_line::key **)v8,
        v8[0]);
  }
  else
  {
    v5 = __first + 16;
    stlp_std::priv::__insertion_sort<vostok::command_line::key * *,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
      __first,
      __first + 16,
      (vostok::command_line::key **)&__comp,
      a4);
    stlp_std::priv::__unguarded_insertion_sort_aux<vostok::command_line::key * *,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
      v5,
      __last,
      __comp,
      v7);
  }
}
