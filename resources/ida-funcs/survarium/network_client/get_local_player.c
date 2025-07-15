vostok::memory::detail::call_destructor_predicate *__usercall survarium::network_client::get_local_player@<eax>(
        survarium::network_client *this@<ecx>,
        int a2@<edi>,
        vostok::memory::detail::call_destructor_predicate *a3@<esi>)
{
  bool v3; // zf
  int v4; // eax

  v3 = *(_DWORD *)(a2 + 15544) == 0;
  *(_DWORD *)a3 = 0;
  if ( !v3 )
  {
    vostok::memory::detail::call_destructor_predicate::operator()<survarium::profile_player_character>(a3);
    v4 = *(_DWORD *)(a2 + 15544);
    *(_DWORD *)a3 = v4;
    if ( v4 )
      _InterlockedExchangeAdd((volatile signed __int32 *)(v4 + 496), 1u);
  }
  return a3;
}
