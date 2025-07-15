void __userpurge survarium::player::player(
        survarium::player *this@<ecx>,
        int a2@<edi>,
        const survarium::player_creation_params *params)
{
  vostok::animation::animation_player *v3; // ecx
  vostok::animation::animation_player *v4; // ecx
  unsigned int f; // ecx
  int (__stdcall *v6)(int); // eax
  int v7; // eax
  survarium::interactive_object *m_object; // eax
  const vostok::math::float4x4 *v9; // xmm0_4
  char v10; // al
  vostok::render::skeleton_model_instance *v11; // ecx
  vostok::render::skeleton_model_instance *v12; // eax
  vostok::resources::unmanaged_resource *v13; // edx
  vostok::render::skeleton_model_instance *v14; // ecx
  vostok::render::skeleton_model_instance *v15; // eax
  vostok::resources::unmanaged_resource *v16; // edx
  int v17; // edx
  vostok::physics::bt_character_controller *v18; // eax
  vostok::physics::bt_character_controller *v19; // ecx
  int v20; // edx
  vostok::physics::bt_character_controller *v21; // eax
  vostok::physics::bt_character_controller *v22; // ecx
  char *profile_name; // [esp-8h] [ebp-18h]
  unsigned int pConvertedChars; // [esp+Ch] [ebp-4h] BYREF

  survarium::base_player::base_player((survarium::base_player *)a2, params, &params->game_scene->m_game->m_scheduler);
  vostok::resources::unmanaged_resource::unmanaged_resource((vostok::resources::unmanaged_resource *)(a2 + 288), 1u);
  *(_DWORD *)(a2 + 288) = &survarium::player::`vftable';
  *(_DWORD *)a2 = &survarium::player::`vftable'{for `survarium::inventory_holder'};
  *(_DWORD *)(a2 + 12) = &survarium::player::`vftable'{for `survarium::collision_user'};
  *(_DWORD *)(a2 + 48) = &survarium::player::`vftable'{for `survarium::hit_initiator'};
  *(_DWORD *)(a2 + 56) = &survarium::player::`vftable'{for `survarium::hit_receiver'};
  vostok::animation::animation_player::animation_player(v3, a2 + 552);
  *(_DWORD *)(a2 + 34800) = 0;
  vostok::animation::animation_player::animation_player(v4, a2 + 34812);
  f = (unsigned int)survarium::g_allocator.f_.f_;
  *(int *)((char *)&dword_10DC4 + a2) = 0;
  *(int *)((char *)&dword_10E10 + a2) = 0;
  *(int *)((char *)&dword_10E14 + a2) = 0;
  *(int *)((char *)&dword_10E18 + a2) = 0;
  v6 = *(int (__stdcall **)(int))(*(_DWORD *)f + 16);
  pConvertedChars = f;
  v7 = v6(6144);
  *(int *)((char *)&dword_10E20 + a2) = pConvertedChars;
  *(int *)((char *)&dword_10E1C + a2) = v7;
  *(int *)((char *)&dword_10E24 + a2) = 64;
  *(int *)((char *)&dword_10E28 + a2) = 0;
  *(int *)((char *)&dword_10E2C + a2) = 0;
  survarium::player_stamina::player_stamina(
    (survarium::player_stamina *)((char *)&unk_10E30 + a2),
    &params->initial_stamina);
  survarium::player_stealth::player_stealth(
    (survarium::player_stealth *)((char *)&unk_10E98 + a2),
    &params->initial_stealth);
  *(int *)((char *)&dword_10EC4 + a2) = 0;
  *(int *)((char *)&dword_10EC8 + a2) = 0;
  *(int *)((char *)&dword_10ECC + a2) = 0;
  survarium::player_input::player_input((survarium::player_input *)((char *)&dword_10ED0 + a2));
  *(int *)((char *)&dword_10EE4 + a2) = 0;
  *(int *)((char *)&dword_10EE8 + a2) = 0;
  *((_BYTE *)&dword_10EEC + a2) = 0;
  *(int *)((char *)&dword_10EF0 + a2) = (int)params->damage_collision;
  *(int *)((char *)&dword_10EF4 + a2) = 0;
  *(int *)((char *)&dword_10EF8 + a2) = 0;
  *(int *)((char *)&dword_10EFC + a2) = 0;
  *(int *)((char *)&dword_10F00 + a2) = (int)params->game_scene;
  *(int *)((char *)&dword_10F04 + a2) = (int)params->game_scene->m_game;
  *(int *)((char *)&dword_10F08 + a2) = 0;
  m_object = params->empty_hands.m_object;
  if ( m_object )
  {
    *(int *)((char *)&dword_10F08 + a2) = (int)m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  *(int *)((char *)&dword_10F10 + a2) = 0;
  v9 = clear_value;
  *(int *)((char *)&dword_10F0C + a2) = 0;
  *(int *)((char *)&dword_10F14 + a2) = 0;
  *(int *)((char *)&dword_10F18 + a2) = (int)v9;
  *(int *)((char *)&dword_10F1C + a2) = (int)v9;
  *(int *)((char *)&dword_10F20 + a2) = (int)v9;
  *(int *)((char *)&dword_10F28 + a2) = 0;
  byte_10F30[a2] = params->foot_3rd_view_game_material_id;
  v10 = *(_BYTE *)(a2 + 53);
  byte_10F31[a2] = params->foot_1st_view_game_material_id;
  byte_10F32[a2] = 0;
  byte_10F33[a2] = 1;
  byte_10F34[a2] = 0;
  byte_10F35[a2] = 1;
  byte_10F36[a2] = 1;
  byte_10F78[a2] = 1;
  *(int *)((char *)&dword_10F7C + a2) = 0;
  byte_10F80[a2] = params->initial_info.is_demo_player;
  *(_BYTE *)(a2 + 34671) = v10;
  byte_10F81[a2] = 0;
  profile_name = params->initial_info.profile->profile_name;
  pConvertedChars = 0;
  mbstowcs_s(&pConvertedChars, (wchar_t *)((char *)&unk_10F38 + a2), 0x20u, profile_name, 0xFFFFFFFF);
  *(int *)((char *)&dword_10F2C + a2) = params->initial_info.profile->team;
  v11 = params->character_model.m_object;
  v12 = 0;
  if ( v11 )
  {
    v12 = params->character_model.m_object;
    _InterlockedExchangeAdd(&v11->m_reference_count, 1u);
  }
  v13 = *(vostok::resources::unmanaged_resource **)(a2 + 34800);
  *(_DWORD *)(a2 + 34800) = v12;
  if ( v13 && !_InterlockedExchangeAdd(&v13->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v13->vostok::resources::unmanaged_intrusive_base, v13);
  v14 = params->server_character_model.m_object;
  v15 = 0;
  if ( v14 )
  {
    v15 = params->server_character_model.m_object;
    _InterlockedExchangeAdd(&v14->m_reference_count, 1u);
  }
  v16 = *(vostok::resources::unmanaged_resource **)((char *)&dword_10DC4 + a2);
  *(int *)((char *)&dword_10DC4 + a2) = (int)v15;
  if ( v16 && !_InterlockedExchangeAdd(&v16->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v16->vostok::resources::unmanaged_intrusive_base, v16);
  survarium::inventory::set_holder(*(survarium::inventory **)(a2 + 8), (survarium::inventory_holder *)a2);
  v17 = *(_DWORD *)LODWORD(survarium::g_allocator.f_.f_);
  pConvertedChars = *(_DWORD *)(*(int *)((char *)&dword_10F00 + a2) + 176);
  v18 = (vostok::physics::bt_character_controller *)(*(int (__thiscall **)(_DWORD, int))(v17 + 16))(
                                                      survarium::g_allocator.f_.f_,
                                                      12);
  if ( v18 )
  {
    v19 = (vostok::physics::bt_character_controller *)pConvertedChars;
    v18->m_active = 0;
    v18->m_bt_physics_world = (vostok::physics::bullet_physics_world *)v19;
  }
  else
  {
    v18 = 0;
  }
  *(_DWORD *)(a2 + 34804) = v18;
  vostok::physics::bt_character_controller::initialize(v19, v18);
  v20 = *(_DWORD *)LODWORD(survarium::g_allocator.f_.f_);
  pConvertedChars = *(_DWORD *)(*(int *)((char *)&dword_10F00 + a2) + 176);
  v21 = (vostok::physics::bt_character_controller *)(*(int (__thiscall **)(_DWORD, int))(v20 + 16))(
                                                      survarium::g_allocator.f_.f_,
                                                      12);
  if ( v21 )
  {
    v22 = (vostok::physics::bt_character_controller *)pConvertedChars;
    v21->m_active = 0;
    v21->m_bt_physics_world = (vostok::physics::bullet_physics_world *)v22;
  }
  else
  {
    v21 = 0;
  }
  *(int *)((char *)&dword_10DC8 + a2) = (int)v21;
  vostok::physics::bt_character_controller::initialize(v22, v21);
  *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_10EF0 + a2) + 36) + 8) = a2 + 56;
  survarium::player_parameters_modifyer::apply(params->player_parameters.m_object, (survarium::base_player *)a2);
}
