int __thiscall survarium::weapon_core_melee_state::on_shot_event(
        survarium::weapon_core_melee_state *this,
        vostok::animation::animation_callback_params *params)
{
  survarium::weapon_core *m_weapon; // eax
  vostok::resources::managed_resource *m_object; // ecx
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v5; // eax
  vostok::particle::particle_system_instance_impl *v6; // ecx
  survarium::weapon_core *v7; // ebx
  survarium::bullet_manager *m_bullet_manager; // eax
  survarium::bullet_manager *v9; // ecx
  const survarium::weapon_core *callback_time_in_ms; // [esp-14h] [ebp-8Ch]
  bool v12; // [esp+0h] [ebp-78h]
  float v13; // [esp+Ch] [ebp-6Ch]
  survarium::hit_receiver *p_m_first; // [esp+10h] [ebp-68h]
  vostok::resources::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base> *p_m_emitter_instance_list; // [esp+14h] [ebp-64h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v16; // [esp+18h] [ebp-60h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v17; // [esp+1Ch] [ebp-5Ch] BYREF
  float v18; // [esp+20h] [ebp-58h]
  float v19; // [esp+24h] [ebp-54h]
  float v20; // [esp+28h] [ebp-50h]
  vostok::math::float3 v21; // [esp+2Ch] [ebp-4Ch] BYREF
  vostok::math::float4x4 v22; // [esp+38h] [ebp-40h] BYREF

  m_weapon = this->m_weapon;
  if ( params->animated_object != m_weapon->m_user )
    return 0;
  m_object = params->animation->m_object;
  if ( m_object != this->m_animations[0][0].m_object && m_object != this->m_animations[0][1].m_object )
    return 0;
  survarium::weapon_core::computed_bullet_transform((survarium::weapon_core *)&v22, (int)m_weapon, &v22);
  v5 = (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this->m_weapon;
  v6 = v5[2].m_object;
  v18 = (float)((float)(v22.i.x + v22.j.x) * 0.0) + v22.k.x;
  v19 = (float)((float)(v22.i.y + v22.j.y) * 0.0) + v22.k.y;
  v20 = (float)((float)(v22.i.z + v22.j.z) * 0.0) + v22.k.z;
  if ( v6 )
    p_m_first = (survarium::hit_receiver *)&v6->m_lods[1].m_emitter_instance_list.m_first;
  else
    p_m_first = 0;
  if ( v6 )
    p_m_emitter_instance_list = (vostok::resources::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base> *)&v6->m_lods[1].m_emitter_instance_list;
  else
    p_m_emitter_instance_list = 0;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v17,
    v5 + 243);
  v13 = *(float *)&v17.m_object->m_lods[2].m_emitter_instance_list.gap4;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v16,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_weapon->m_melee_ammunition);
  v7 = this->m_weapon;
  v21.x = v18 * v13;
  callback_time_in_ms = (const survarium::weapon_core *)params->callback_time_in_ms;
  v21.y = v19 * v13;
  m_bullet_manager = v7->m_bullet_manager;
  v21.z = v20 * v13;
  survarium::bullet_manager::emit_bullet(
    v9,
    m_bullet_manager,
    (const vostok::math::float3 *)&v22.lines[3],
    &v21,
    (const survarium::weapon_ammunition **)&v16,
    v7,
    callback_time_in_ms,
    p_m_emitter_instance_list,
    p_m_first,
    (survarium::hit_receiver *const)1,
    1u,
    v12);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v16);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v17);
  return 1;
}
