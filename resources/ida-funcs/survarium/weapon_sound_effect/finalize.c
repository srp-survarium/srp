void __usercall survarium::weapon_sound_effect::finalize(survarium::weapon_sound_effect *this@<ecx>, int a2@<esi>)
{
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *i; // edi
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *j; // edi

  if ( *(_BYTE *)(a2 + 56)
    && !survarium::base_player::is_in_past(
          (survarium::base_player *)this,
          *(_DWORD *)(*(_DWORD *)(a2 + 48) + 8),
          *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 48) + 8) + 736)) )
  {
    for ( i = *(vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> **)(a2 + 12);
          i != *(vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> **)(a2 + 16);
          ++i )
    {
      vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::dec(i);
    }
    *(_DWORD *)(a2 + 16) = *(_DWORD *)(a2 + 12);
    for ( j = *(vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> **)(a2 + 36);
          j != *(vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> **)(a2 + 40);
          ++j )
    {
      vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::dec(j);
    }
    *(_DWORD *)(a2 + 40) = *(_DWORD *)(a2 + 36);
  }
}
