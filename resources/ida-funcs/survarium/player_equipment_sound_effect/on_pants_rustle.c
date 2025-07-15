void __usercall survarium::player_equipment_sound_effect::on_pants_rustle(
        survarium::player_equipment_sound_effect *this@<ecx>,
        _DWORD *a2@<eax>)
{
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v3; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v4; // ebx
  int v5; // ecx
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v6; // eax
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v7; // edi
  const vostok::sound::sound_receiver *v8; // [esp+0h] [ebp-20h]
  bool v9; // [esp+4h] [ebp-1Ch]
  vostok::math::float3 v10; // [esp+Ch] [ebp-14h] BYREF
  vostok::sound::sound_instance_proxy *v11; // [esp+18h] [ebp-8h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v12; // [esp+1Ch] [ebp-4h] BYREF

  if ( survarium::player::is_first_view((survarium::player *)this, a2[15]) )
  {
    v3 = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)a2[16];
    v4 = v3 + 37;
    v11 = (vostok::sound::sound_instance_proxy *)((int (__thiscall *)(vostok::resources::resource_base *))v3[40].m_object->m_prev_in_memory_type->link_child_resource)(v3[40].m_object->m_prev_in_memory_type);
    v5 = *(_DWORD *)(*(_DWORD *)(a2[14] + 24) + 32);
    v6 = (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((char *)&loc_11240 + a2[15]);
    v7 = v6 + 8;
    if ( v5 < 3 )
      v7 = &v6[v5 + 8];
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v12,
      v7);
    vostok::sound::sound_emitter::emit_and_play_once(
      (vostok::sound::sound_emitter *)v12.m_object,
      v4,
      v11,
      &v10,
      (const vostok::sound::sound_producer *)1,
      v8,
      v9);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v12);
  }
}
