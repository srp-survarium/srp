survarium::delete_udv_functor __usercall stlp_std::for_each<vostok::variant<32> * *,survarium::delete_udv_functor>@<al>(
        vostok::variant<32> **__first@<eax>,
        vostok::variant<32> *a2@<ecx>,
        vostok::variant<32> **__last,
        survarium::delete_udv_functor __f)
{
  char *v5; // esi
  vostok::memory::doug_lea_allocator *v6; // ebx
  vostok::memory::doug_lea_allocator *v7; // ecx
  const char *v9; // [esp+0h] [ebp-Ch]
  const char *v10; // [esp+4h] [ebp-8h]
  unsigned int v11; // [esp+8h] [ebp-4h]

  while ( __first != __last )
  {
    v5 = (char *)*__first;
    v6 = survarium::g_allocator;
    if ( *__first )
    {
      vostok::variant<32>::destroy_previous_variable_if_needed(a2, (int)v5);
      vostok::memory::doug_lea_allocator::free_impl(v7, (int)v6, v5, v9, v10, v11);
    }
    ++__first;
  }
  return __f;
}
