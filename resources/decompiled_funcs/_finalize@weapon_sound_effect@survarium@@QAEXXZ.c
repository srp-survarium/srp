void __usercall survarium::weapon_sound_effect::finalize(survarium::weapon_sound_effect *this@<ecx>, int a2@<esi>)
{
  if ( *(_BYTE *)(a2 + 36) )
  {
    vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>>::destroy(
      *(vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> **)(a2 + 8),
      (vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> **)(a2 + 12));
    *(_DWORD *)(a2 + 12) = *(_DWORD *)(a2 + 8);
    vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>>::destroy(
      *(vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> **)(a2 + 24),
      (vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> **)(a2 + 28));
    *(_DWORD *)(a2 + 28) = *(_DWORD *)(a2 + 24);
  }
}
