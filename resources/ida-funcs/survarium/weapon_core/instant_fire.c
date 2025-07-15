void __userpurge survarium::weapon_core::instant_fire(
        survarium::weapon_core *this@<ecx>,
        int a2@<esi>,
        float a3@<xmm0>,
        const survarium::weapon_core *current_time_in_ms)
{
  unsigned int v4; // eax
  survarium::weapon_core *v5; // ecx
  survarium::weapon_core *v6; // ecx
  char v7; // bl
  vostok::math::float3 *dispersed_buckshot_direction; // eax
  survarium::bullet_manager *v9; // eax
  survarium::bullet_manager *v10; // ecx
  survarium::weapon_recoil_calculator *v11; // ecx
  int v12; // ebx
  char v13; // fl
  float v14; // xmm0_4
  char v15; // cf
  char v16; // zf
  char v17; // sf
  char v18; // of
  bool v19; // pf
  vostok::resources::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base> *v20; // [esp-4h] [ebp-88h]
  const survarium::hit_initiator *v21; // [esp+0h] [ebp-84h]
  unsigned int v22; // [esp+Ch] [ebp-78h]
  char v23; // [esp+17h] [ebp-6Dh] BYREF
  survarium::hit_receiver *ignorable_object; // [esp+18h] [ebp-6Ch]
  float v25; // [esp+1Ch] [ebp-68h]
  vostok::math::float3 velocity; // [esp+20h] [ebp-64h] BYREF
  vostok::math::float3 v27; // [esp+2Ch] [ebp-58h] BYREF
  vostok::math::float3 v28; // [esp+38h] [ebp-4Ch] BYREF
  vostok::math::float4x4 result; // [esp+44h] [ebp-40h] BYREF

  if ( debug_macro_helper_ignore_always_47 || *(_BYTE *)(*(_DWORD *)(a2 + 8) + 764) )
  {
    survarium::weapon_core::computed_bullet_transform(this, a2, &result);
    --*(_WORD *)(a2 + 1104);
    survarium::weapon_core::get_dispersed_bullet_direction(v5, a2, a3, &v27, &result);
    v7 = *(_BYTE *)(*(_DWORD *)(a2 + 968) + 344);
    v23 = v7;
    LOBYTE(ignorable_object) = 0;
    if ( v7 )
    {
      do
      {
        v25 = *(float *)(*(_DWORD *)(a2 + 968) + 336);
        dispersed_buckshot_direction = survarium::weapon_core::get_dispersed_buckshot_direction(
                                         v6,
                                         (survarium::weapon_core *)a2,
                                         &v28,
                                         &v27);
        velocity.x = dispersed_buckshot_direction->x * v25;
        v21 = *(const survarium::hit_initiator **)(a2 + 984);
        v20 = *(vostok::resources::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base> **)(a2 + 980);
        velocity.y = dispersed_buckshot_direction->y * v25;
        a3 = dispersed_buckshot_direction->z * v25;
        v9 = *(survarium::bullet_manager **)(a2 + 992);
        velocity.z = a3;
        survarium::bullet_manager::emit_bullet(
          v10,
          v9,
          (const vostok::math::float3 *)&result.lines[3],
          &velocity,
          COERCE_FLOAT(a2 + 968),
          (const survarium::weapon_core *)a2,
          current_time_in_ms,
          v20,
          v21,
          ignorable_object,
          0,
          v22);
        LOBYTE(ignorable_object) = (_BYTE)ignorable_object + 1;
      }
      while ( (_BYTE)ignorable_object != v7 );
    }
    if ( *(_BYTE *)(a2 + 1111) )
      *(_BYTE *)(a2 + 1112) = 0;
    else
      --*(_WORD *)(a2 + 1102);
    (*(void (__thiscall **)(int, const survarium::weapon_core *))(*(_DWORD *)a2 + 164))(a2, current_time_in_ms);
    survarium::weapon_recoil_calculator::fire(
      v11,
      (survarium::weapon_recoil_calculator *)(a2 + 588),
      (unsigned int)current_time_in_ms);
    v12 = *(_DWORD *)(a2 + 664);
    v14 = survarium::player_params_modifiers_container::apply_modifier(
            (survarium::player_params_modifiers_container *)(*(_DWORD *)(*(_DWORD *)(v12 + 8) + 69736) + 448),
            dispersion_modifier,
            a3,
            *(float *)(v12 + 844),
            *(float *)(a2 + 716))
        + *(float *)(a2 + 696);
    if ( *(float *)(v12 + 856) <= v14 )
      v14 = *(float *)(v12 + 856);
    v15 = 0;
    v18 = 0;
    v16 = 0;
    v19 = __SETP__(-1, 0);
    v17 = 1;
    *(_DWORD *)(a2 + 712) = -1;
    *(float *)(a2 + 696) = v14;
    *(float *)(a2 + 700) = v14;
    *(float *)(a2 + 704) = v14;
    *(_DWORD *)(a2 + 708) = 0;
    survarium::transition_helper::start_transition_with_speed(
      (survarium::transition_helper *)(a2 + 696),
      v13,
      0.0,
      *(float *)(*(_DWORD *)(a2 + 664) + 840),
      (unsigned int)current_time_in_ms,
      v22);
    (*(void (__thiscall **)(_DWORD, char))(**(_DWORD **)(a2 + 980) + 4))(*(_DWORD *)(a2 + 980), v23);
  }
  else
  {
    v4 = occurances_left_26;
    if ( occurances_left_26 == -1 )
      v4 = 10;
    occurances_left_26 = v4 - 1;
    if ( v4 )
    {
      v23 = 0;
      vostok::debug::on_error(
        (bool *)&v23,
        process_error_false,
        (bool *)"get_user()->is_alive()",
        ".\\weapon_core.cpp",
        "survarium::weapon_core::instant_fire",
        (const char *)0x2DB);
      if ( vostok::debug::is_debugger_present() || v23 )
        __debugbreak();
    }
  }
}
