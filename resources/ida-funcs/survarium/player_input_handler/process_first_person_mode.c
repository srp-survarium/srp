void __userpurge survarium::player_input_handler::process_first_person_mode(
        survarium::player_input_handler *this@<ecx>,
        survarium::game_action_id a2@<esi>,
        const bool use_mouse_move)
{
  survarium::player_input_handler *v3; // ecx
  survarium::player_input_handler *v4; // ecx
  survarium::player_input_handler *v5; // ecx
  survarium::player_input_handler *v6; // ecx
  float v7; // xmm0_4
  vostok::journaling::journal_usage_enum v8; // eax
  float v9; // xmm0_4
  float v10; // xmm0_4
  survarium::player_input_handler *v11; // ecx
  float v12; // xmm0_4
  int v13; // edi
  float *v14; // ebx
  float *v15; // eax
  survarium::player_input_handler *v16; // ecx
  survarium::player_input_handler *v17; // ecx
  survarium::player_input_handler *v18; // ecx
  survarium::player_input_handler *v19; // ecx
  survarium::player_input_handler *v20; // ecx
  survarium::player_input_handler *v21; // ecx
  survarium::player_input_handler *v22; // ecx
  survarium::player_input_handler *v23; // ecx
  survarium::player_input_handler *v24; // ecx
  survarium::player_input_handler *v25; // ecx
  survarium::player_input_handler *v26; // ecx
  survarium::player_input_handler *v27; // ecx
  survarium::player_input_handler *v28; // ecx
  survarium::player_input_handler *v29; // ecx
  survarium::player_input_handler *v30; // ecx
  survarium::player_input_handler *v31; // ecx
  survarium::player_input_handler *v32; // ecx
  survarium::player_input_handler *v33; // ecx
  survarium::player_input_handler *v34; // ecx
  survarium::player_input_handler *v35; // ecx
  survarium::player_input_handler *v36; // ecx
  survarium::player_input_handler *v37; // ecx
  survarium::player_input_handler *v38; // ecx
  survarium::player_input_handler *v39; // ecx
  survarium::player_input_handler *v40; // ecx
  survarium::player_input_handler *v41; // ecx
  survarium::player_input_handler *v42; // ecx
  survarium::player_input_handler *v43; // ecx
  int v44; // [esp+Ch] [ebp-1Ch] BYREF
  float v45; // [esp+10h] [ebp-18h]
  float v46; // [esp+14h] [ebp-14h]
  _BYTE v47[8]; // [esp+18h] [ebp-10h] BYREF
  _BYTE v48[8]; // [esp+20h] [ebp-8h] BYREF

  if ( *(_DWORD *)(a2 + 672) != *(_DWORD *)(a2 + 676)
    || (this = *(survarium::player_input_handler **)(a2 + 680), this != *(survarium::player_input_handler **)(a2 + 684))
    || *(float *)(a2 + 824) != 0.0
    || *(float *)(a2 + 828) != 0.0
    || *(_DWORD *)(a2 + 832) )
  {
    if ( survarium::player_input_handler::action_present(this, a2, (survarium::action_state_enum *)0xB, &v44) )
      *(_DWORD *)(a2 + 832) |= 1u;
    if ( survarium::player_input_handler::action_present(v3, a2, (survarium::action_state_enum *)0xC, &v44) )
      *(_DWORD *)(a2 + 832) |= 2u;
    if ( survarium::player_input_handler::action_present(v4, a2, (survarium::action_state_enum *)0xE, &v44) )
      *(_DWORD *)(a2 + 832) |= 8u;
    if ( survarium::player_input_handler::action_present(v5, a2, (survarium::action_state_enum *)0xD, &v44) )
      *(_DWORD *)(a2 + 832) |= 4u;
    if ( use_mouse_move )
    {
      if ( survarium::g_mouse_invert )
        v7 = FLOAT_N1_0;
      else
        v7 = s_bm_current_air_resistance;
      v46 = v7;
      v8 = vostok::core::journal_usage();
      v9 = *(float *)(a2 + 148);
      if ( v8 == replay_journal )
        v10 = v9 * g_journaling_mouse_sensitivity.x;
      else
        v10 = (float)(v9 * survarium::g_mouse_sensitivity) * 0.1;
      v45 = v10;
      if ( vostok::core::journal_usage() == replay_journal )
      {
        v12 = *(float *)(a2 + 148) * g_journaling_mouse_sensitivity.y;
      }
      else
      {
        v13 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 820) + 160) + 148);
        v14 = (float *)((*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v13 + 28))(v13, v47) + 4);
        v15 = (float *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v13 + 28))(v13, v48);
        v12 = (float)((float)((float)(*v14 / *v15) * v45) * v46) * 0.95492965;
      }
      v46 = v12;
      if ( survarium::player_input_handler::action_present(v11, a2, (survarium::action_state_enum *)2, &v44) )
        *(float *)(a2 + 824) = (float)(v46 * 0.017453292) + *(float *)(a2 + 824);
      if ( survarium::player_input_handler::action_present(v16, a2, (survarium::action_state_enum *)3, &v44) )
        *(float *)(a2 + 824) = *(float *)(a2 + 824) - (float)(v46 * 0.017453292);
      if ( survarium::player_input_handler::action_present(v17, a2, (survarium::action_state_enum *)1, &v44) )
        *(float *)(a2 + 828) = *(float *)(a2 + 828) - (float)(v45 * 0.017453292);
      if ( survarium::player_input_handler::action_present(v18, a2, 0, &v44) )
        *(float *)(a2 + 828) = (float)(v45 * 0.017453292) + *(float *)(a2 + 828);
    }
    if ( survarium::player_input_handler::action_present(v6, a2, (survarium::action_state_enum *)4, &v44) )
      *(_DWORD *)(a2 + 832) |= 0x10u;
    if ( survarium::player_input_handler::action_present(v19, a2, (survarium::action_state_enum *)0x25, &v44) )
      *(_DWORD *)(a2 + 832) |= v44 != 1 ? 32 : 64;
    if ( survarium::player_input_handler::action_present(v20, a2, (survarium::action_state_enum *)0x26, &v44) )
      *(_DWORD *)(a2 + 832) |= 0x80u;
    if ( survarium::player_input_handler::action_present(v21, a2, (survarium::action_state_enum *)0x27, &v44)
      || survarium::player_input_handler::action_present(v22, a2, (survarium::action_state_enum *)0x28, &v44) )
    {
      *(_DWORD *)(a2 + 832) |= 0x100u;
    }
    if ( survarium::player_input_handler::action_present(v22, a2, (survarium::action_state_enum *)5, &v44)
      || survarium::player_input_handler::action_present(v23, a2, (survarium::action_state_enum *)6, &v44) )
    {
      *(_DWORD *)(a2 + 832) |= 0x200u;
    }
    if ( survarium::player_input_handler::action_present(v23, a2, (survarium::action_state_enum *)7, &v44)
      || survarium::player_input_handler::action_present(v24, a2, (survarium::action_state_enum *)8, &v44) )
    {
      *(_DWORD *)(a2 + 832) |= 0x400u;
    }
    if ( survarium::player_input_handler::action_present(v24, a2, (survarium::action_state_enum *)9, &v44) && !v44 )
      *(_DWORD *)(a2 + 832) |= 0x800u;
    if ( survarium::player_input_handler::action_present(v25, a2, (survarium::action_state_enum *)0xA, &v44) && !v44 )
      *(_DWORD *)(a2 + 832) |= 0x1000u;
    if ( survarium::player_input_handler::action_present(v26, a2, (survarium::action_state_enum *)0x1C, &v44) )
      *(_DWORD *)(a2 + 832) |= 0x2000u;
    if ( survarium::player_input_handler::action_present(v27, a2, (survarium::action_state_enum *)0x1D, &v44) )
      *(_DWORD *)(a2 + 832) |= 0x4000u;
    if ( survarium::player_input_handler::action_present(v28, a2, (survarium::action_state_enum *)0x38, &v44) )
      *(_DWORD *)(a2 + 832) |= 0x8000u;
    if ( survarium::player_input_handler::action_present(v29, a2, (survarium::action_state_enum *)0x39, &v44) )
      *(_DWORD *)(a2 + 832) |= (unsigned int)&_sbh_sizeHeaderList;
    if ( survarium::player_input_handler::action_present(v30, a2, (survarium::action_state_enum *)0x3A, &v44) )
      *(_DWORD *)(a2 + 832) |= (unsigned int)&loc_20000;
    if ( survarium::player_input_handler::action_present(v31, a2, (survarium::action_state_enum *)0x3B, &v44) )
      *(_DWORD *)(a2 + 832) |= (unsigned int)&loc_3FFFF + 1;
    if ( survarium::player_input_handler::action_present(v32, a2, (survarium::action_state_enum *)0x3C, &v44) )
      *(_DWORD *)(a2 + 832) |= 0x80000u;
    if ( survarium::player_input_handler::action_present(v33, a2, (survarium::action_state_enum *)0x3D, &v44) )
      *(_DWORD *)(a2 + 832) |= (unsigned int)&loc_100000;
    if ( survarium::player_input_handler::action_present(v34, a2, (survarium::action_state_enum *)0x3E, &v44) )
      *(_DWORD *)(a2 + 832) |= (unsigned int)&loc_200000;
    if ( survarium::player_input_handler::action_present(v35, a2, (survarium::action_state_enum *)0x29, &v44) )
      *(_DWORD *)(a2 + 832) |= (unsigned int)&loc_400000;
    if ( survarium::player_input_handler::action_present(v36, a2, (survarium::action_state_enum *)0x34, &v44) )
      *(_DWORD *)(a2 + 832) |= 0x800000u;
    if ( survarium::player_input_handler::action_present(v37, a2, (survarium::action_state_enum *)0x35, &v44) )
      *(_DWORD *)(a2 + 832) |= 0x1000000u;
    if ( survarium::player_input_handler::action_present(v38, a2, (survarium::action_state_enum *)0x1E, &v44) )
      *(_DWORD *)(a2 + 832) |= 0x4000000u;
    if ( survarium::player_input_handler::action_present(v39, a2, (survarium::action_state_enum *)0x23, &v44) )
      *(_DWORD *)(a2 + 832) |= 0x8000000u;
    if ( survarium::player_input_handler::action_present(v40, a2, (survarium::action_state_enum *)0x24, &v44) )
      *(_DWORD *)(a2 + 832) |= 0x10000000u;
    if ( survarium::player_input_handler::action_present(v41, a2, (survarium::action_state_enum *)0x1F, &v44) )
      *(_DWORD *)(a2 + 832) |= 0x2000000u;
    if ( survarium::player_input_handler::action_present(v42, a2, (survarium::action_state_enum *)0x20, &v44) )
      *(_DWORD *)(a2 + 832) |= 0x20000000u;
    if ( survarium::player_input_handler::action_present(v43, a2, (survarium::action_state_enum *)0x21, &v44) )
    {
      if ( !v44 )
        *(_DWORD *)(a2 + 832) |= 0x40000000u;
    }
  }
}
