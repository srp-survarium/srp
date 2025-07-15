void __thiscall survarium::game_world_ui::update_minimap_local_player(survarium::game_world_ui *this, int a2)
{
  survarium::base_network_client *v2; // ebx
  survarium::flash_value *v3; // ecx
  survarium::flash_value *v4; // ecx
  int v5; // edx
  survarium::flash_value *v6; // ecx
  vostok::math::float4x4 *v7; // ecx
  vostok::math::float3 *angles; // eax
  survarium::flash_value *v9; // ecx
  survarium::flash_value *v10; // ecx
  survarium::player *m_object; // eax
  survarium::game_team_id team; // eax
  Scaleform::GFx::Value *v13; // esi
  int i; // edi
  vostok::math::float3 *v15; // [esp+4h] [ebp-C4h]
  vostok::math::axis_rotation_order v16; // [esp+8h] [ebp-C0h]
  float value[16]; // [esp+14h] [ebp-B4h] BYREF
  survarium::flash_value v18; // [esp+54h] [ebp-74h] BYREF
  char v19[24]; // [esp+6Ch] [ebp-5Ch] BYREF
  char v20[24]; // [esp+84h] [ebp-44h] BYREF
  char v21[24]; // [esp+9Ch] [ebp-2Ch] BYREF
  char v22; // [esp+B4h] [ebp-14h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v23; // [esp+C0h] [ebp-8h] BYREF

  v2 = *(survarium::base_network_client **)(*(_DWORD *)(*(_DWORD *)(a2 + 20) + 160) + 13912);
  survarium::base_network_client::get_current_player(v2, &v23);
  if ( v23.m_object && HIBYTE(v23.m_object->m_skeleton_model.m_object) )
  {
    qmemcpy(
      value,
      (const void *)(*(int (__thiscall **)(_BYTE *))(*(_DWORD *)&v23.m_object->m_lods[0].m_emitter_instance_list.gap4 + 4))(&v23.m_object->m_lods[0].m_emitter_instance_list.gap4),
      sizeof(value));
    v3 = &v18;
    do
    {
      survarium::flash_value::flash_value(v3);
      v3 = v4 + 1;
    }
    while ( v5 - 1 >= 0 );
    survarium::flash_value::SetNumber(v3, (int)&v18, value[12]);
    survarium::flash_value::SetNumber(v6, (int)v19, COERCE_FLOAT(LODWORD(value[14]) ^ _mask__NegFloat_));
    angles = vostok::math::float4x4::get_angles(v7, v15, v16);
    survarium::flash_value::SetNumber(v9, (int)v20, angles->y);
    m_object = v2->m_current_player.m_object;
    if ( m_object )
      team = m_object->m_profile->team;
    else
      LOBYTE(team) = 2;
    survarium::flash_value::SetUInt(v10, (int)v21, (unsigned __int8)team);
    Scaleform::GFx::Movie::Invoke(
      *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 8) + 264) + 4),
      "root.update_local_player",
      0,
      (const Scaleform::GFx::Value *)&v18,
      4u);
    v13 = (Scaleform::GFx::Value *)&v22;
    for ( i = 3; i >= 0; --i )
      Scaleform::GFx::Value::~Value(--v13);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v23);
}
