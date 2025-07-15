void __usercall survarium::player_stamina::clear_subscribers(
        vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,208,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this@<ecx>,
        _DWORD *a2@<esi>)
{
  _RTL_CRITICAL_SECTION *v2; // edi

  if ( a2 )
    v2 = (_RTL_CRITICAL_SECTION *)(a2 + 2);
  else
    v2 = 0;
  vostok::threading::mutex::lock((vostok::threading::mutex *)this, v2);
  a2[9] = 0;
  a2[10] = 0;
  *a2 = 0;
  LeaveCriticalSection(v2);
}
