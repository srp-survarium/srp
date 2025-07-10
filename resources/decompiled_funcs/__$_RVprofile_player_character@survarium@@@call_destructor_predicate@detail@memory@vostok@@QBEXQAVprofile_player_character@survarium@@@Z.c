void __thiscall vostok::memory::detail::call_destructor_predicate::operator()<survarium::profile_player_character>(
        vostok::memory::detail::call_destructor_predicate *this)
{
  if ( *(_DWORD *)this && !_InterlockedExchangeAdd((volatile signed __int32 *)(*(_DWORD *)this + 496), 0xFFFFFFFF) )
  {
    if ( *(_DWORD *)this )
      vostok::resources::unmanaged_intrusive_base::destroy(
        (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)this + 496),
        (vostok::resources::unmanaged_resource *)(*(_DWORD *)this + 288));
    else
      vostok::resources::unmanaged_intrusive_base::destroy((vostok::resources::unmanaged_intrusive_base *)0x1F0, 0);
  }
}
