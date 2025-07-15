void __thiscall survarium::game_world_ui::update_minimap_players(
        survarium::game_world_ui *this,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> a2)
{
  vostok::particle::particle_system_instance_impl *m_object; // ebx
  survarium::base_network_client *v3; // edi
  volatile int m_flags; // eax
  int v5; // edx
  double v6; // st7
  int v7; // eax
  volatile int v8; // eax
  survarium::flash_movie *v9; // ecx
  volatile int v10; // eax
  survarium::flash_movie *v11; // ecx
  survarium::flash_value *v12; // ecx
  survarium::flash_value *v13; // ecx
  survarium::flash_value *v14; // ecx
  survarium::flash_value *v15; // ecx
  survarium::flash_value *v16; // ecx
  survarium::flash_value *v17; // ecx
  vostok::math::float4x4 *v18; // ecx
  vostok::math::float3 *angles; // eax
  survarium::flash_value *v20; // ecx
  survarium::flash_value *v21; // ecx
  survarium::flash_value *v22; // ecx
  survarium::flash_value *v23; // ecx
  survarium::flash_value *v24; // ecx
  survarium::flash_value *v25; // ecx
  vostok::math::float3 *v26; // [esp+Ch] [ebp-84h]
  vostok::math::axis_rotation_order v27; // [esp+10h] [ebp-80h]
  Scaleform::GFx::Value pvalue; // [esp+18h] [ebp-78h] BYREF
  Scaleform::GFx::Value v29; // [esp+30h] [ebp-60h] BYREF
  survarium::flash_value v30; // [esp+48h] [ebp-48h] BYREF
  survarium::base_network_client *v31; // [esp+6Ch] [ebp-24h]
  bool v32[4]; // [esp+70h] [ebp-20h]
  float v33; // [esp+74h] [ebp-1Ch]
  float v34; // [esp+78h] [ebp-18h]
  unsigned int value; // [esp+7Ch] [ebp-14h]
  unsigned int v36; // [esp+80h] [ebp-10h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v37; // [esp+84h] [ebp-Ch] BYREF
  int v38; // [esp+88h] [ebp-8h]

  m_object = a2.m_object;
  v3 = *(survarium::base_network_client **)(*(_DWORD *)(HIDWORD(a2.m_object->m_reconstruction_info_actuality_tick) + 160)
                                          + 13912);
  v31 = v3;
  survarium::base_network_client::get_current_player(v3, &v37);
  if ( v37.m_object )
  {
    m_flags = m_object->vostok::particle::particle_system_instance::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::particle::particle_system_instance::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
    pvalue.pObjectInterface = 0;
    pvalue.Type = VT_Undefined;
    Scaleform::GFx::Movie::CreateArray(*(Scaleform::GFx::Movie **)(*(_DWORD *)(m_flags + 264) + 4), &pvalue);
    v36 = 0;
    LOBYTE(v38) = 0;
    value = 0;
    do
    {
      v3->get_active_player(
        v3,
        (vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *)&a2,
        v38);
      if ( a2.m_object
        && HIBYTE(a2.m_object->m_skeleton_model.m_object)
        && *(_DWORD *)(v37.m_object[88].m_is_playing + 440) == *(_DWORD *)(a2.m_object[88].m_is_playing + 440)
        && LOBYTE(a2.m_object->m_skeleton_model.m_object) )
      {
        v5 = *(_DWORD *)&a2.m_object->m_lods[0].m_emitter_instance_list.gap4;
        v32[0] = *(_DWORD *)(a2.m_object->m_lods[0].m_emitter_instance_list.m_size + 380) != 0;
        v6 = *(float *)((*(int (__thiscall **)(_BYTE *))(v5 + 4))(&a2.m_object->m_lods[0].m_emitter_instance_list.gap4)
                      + 48);
        v7 = *(_DWORD *)&a2.m_object->m_lods[0].m_emitter_instance_list.gap4;
        v34 = v6;
        v33 = -*(float *)((*(int (__thiscall **)(_BYTE *))(v7 + 4))(&a2.m_object->m_lods[0].m_emitter_instance_list.gap4)
                        + 56);
        v8 = m_object->vostok::particle::particle_system_instance::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::particle::particle_system_instance::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
        v29.pObjectInterface = 0;
        v29.Type = VT_Undefined;
        survarium::flash_movie::CreateObject(v9, *(survarium::flash_value **)(v8 + 264), &v29);
        v10 = m_object->vostok::particle::particle_system_instance::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::particle::particle_system_instance::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
        *(_DWORD *)v30.body = 0;
        *(_DWORD *)&v30.body[4] = 0;
        survarium::flash_movie::CreateObject(
          v11,
          *(survarium::flash_value **)(v10 + 264),
          (Scaleform::GFx::Value *)&v30);
        survarium::flash_value::SetUInt(v12, (int)&v30, value);
        survarium::flash_value::SetMember(v13, &v29, "player_id", &v30);
        survarium::flash_value::SetNumber(v14, (int)&v30, v34);
        survarium::flash_value::SetMember(v15, &v29, "player_pos_x", &v30);
        survarium::flash_value::SetNumber(v16, (int)&v30, v33);
        survarium::flash_value::SetMember(v17, &v29, "player_pos_y", &v30);
        (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)&a2.m_object->m_lods[0].m_emitter_instance_list.gap4 + 4))(&a2.m_object->m_lods[0].m_emitter_instance_list.gap4);
        angles = vostok::math::float4x4::get_angles(v18, v26, v27);
        survarium::flash_value::SetNumber(v20, (int)&v30, angles->y);
        survarium::flash_value::SetMember(v21, &v29, "player_rotation_in_rad", &v30);
        survarium::flash_value::SetUInt(v22, (int)&v30, *(_DWORD *)(a2.m_object[88].m_is_playing + 440));
        survarium::flash_value::SetMember(v23, &v29, "team", &v30);
        survarium::flash_value::SetBoolean(v24, (int)&v30, v32[0]);
        survarium::flash_value::SetMember(v25, &v29, "is_carrying_item", &v30);
        pvalue.pObjectInterface->SetElement(pvalue.pObjectInterface, (void *)pvalue.mValue.IValue, v36++, &v29);
        Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v30);
        Scaleform::GFx::Value::~Value(&v29);
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&a2);
        v3 = v31;
      }
      else
      {
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&a2);
      }
      LOBYTE(v38) = v38 + 1;
      ++value;
    }
    while ( (unsigned __int8)v38 < 0x14u );
    Scaleform::GFx::Movie::Invoke(
      *(Scaleform::GFx::Movie **)(*(_DWORD *)(m_object->vostok::particle::particle_system_instance::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::particle::particle_system_instance::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
                                            + 264)
                                + 4),
      "root.update_players",
      0,
      &pvalue,
      1u);
    Scaleform::GFx::Value::~Value(&pvalue);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v37);
}
