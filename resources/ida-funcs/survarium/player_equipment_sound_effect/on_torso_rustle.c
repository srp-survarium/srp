void __thiscall survarium::player_equipment_sound_effect::on_torso_rustle(
        survarium::player_equipment_sound_effect *this,
        int a2)
{
  int v2; // ebx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v3; // eax
  const vostok::math::float3 *v4; // eax
  const vostok::sound::sound_receiver *v5; // [esp+0h] [ebp-1Ch]
  bool v6; // [esp+4h] [ebp-18h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v7; // [esp+10h] [ebp-Ch]
  vostok::sound::sound_instance_proxy *v8; // [esp+14h] [ebp-8h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v9; // [esp+18h] [ebp-4h] BYREF

  v2 = a2;
  LOBYTE(a2) = survarium::player::is_first_view((survarium::player *)this, *(_DWORD *)(a2 + 60));
  v3 = *(vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> **)(v2 + 64);
  v7 = v3 + 37;
  v8 = (vostok::sound::sound_instance_proxy *)((int (__thiscall *)(vostok::resources::resource_base *))v3[40].m_object->m_prev_in_memory_type->link_child_resource)(v3[40].m_object->m_prev_in_memory_type);
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v9,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((char *)&loc_1126C + 4 * ((_BYTE)a2 == 0) + *(_DWORD *)(v2 + 60)));
  v4 = (const vostok::math::float3 *)(*(int (__thiscall **)(int))(*(_DWORD *)(*(_DWORD *)(v2 + 60) + 272) + 4))(*(_DWORD *)(v2 + 60) + 272);
  vostok::sound::sound_emitter::emit_and_play_once(
    (vostok::sound::sound_emitter *)v9.m_object,
    v7,
    v8,
    v4 + 4,
    (const vostok::sound::sound_producer *)a2,
    v5,
    v6);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v9);
}
