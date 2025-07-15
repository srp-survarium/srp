void __thiscall survarium::lobby_menu::fill_match_statistic(
        survarium::lobby_menu *this,
        const survarium::match_total_stats *stats,
        const vostok::vectora<survarium::player_results_item> *match_players,
        _DWORD *a4)
{
  int v4; // eax
  survarium::flash_value *v5; // ecx
  survarium::flash_value *v6; // ecx
  survarium::flash_value *v7; // ecx
  survarium::flash_value *v8; // ecx
  survarium::flash_value *v9; // ecx
  survarium::flash_value *v10; // ecx
  survarium::flash_value *v11; // ecx
  survarium::flash_value *v12; // ecx
  survarium::flash_value *v13; // ecx
  survarium::flash_value *v14; // ecx
  survarium::flash_value *v15; // ecx
  survarium::flash_value *v16; // ecx
  survarium::flash_value *v17; // ecx
  survarium::flash_value *v18; // ecx
  survarium::flash_value *v19; // ecx
  survarium::flash_value *v20; // ecx
  survarium::flash_value *v21; // ecx
  survarium::flash_value *v22; // ecx
  survarium::flash_value *v23; // ecx
  survarium::flash_value *v24; // ecx
  survarium::flash_value *v25; // ecx
  survarium::flash_value *v26; // ecx
  survarium::flash_value *v27; // ecx
  survarium::flash_value *v28; // ecx
  survarium::flash_value *v29; // ecx
  unsigned __int8 M_start_high; // al
  survarium::flash_value *v31; // ecx
  survarium::flash_value *v32; // ecx
  unsigned __int8 v33; // al
  survarium::flash_value *v34; // ecx
  survarium::flash_value *v35; // ecx
  unsigned __int8 v36; // al
  unsigned int v37; // eax
  survarium::flash_value *v38; // ecx
  survarium::flash_value *v39; // ecx
  survarium::flash_value *v40; // ecx
  survarium::flash_value *v41; // ecx
  unsigned __int8 M_finish; // al
  survarium::flash_value *v43; // ecx
  survarium::flash_value *v44; // ecx
  survarium::flash_value *v45; // ecx
  survarium::flash_value *v46; // ecx
  survarium::flash_value *v47; // ecx
  const survarium::match_total_stats *v48; // esi
  int v49; // eax
  survarium::flash_movie *v50; // ecx
  _DWORD *v51; // eax
  int i; // edi
  survarium::flash_value *v53; // ecx
  survarium::flash_value *v54; // ecx
  survarium::flash_value *v55; // ecx
  survarium::flash_value *v56; // ecx
  survarium::flash_value *v57; // ecx
  survarium::flash_value *v58; // ecx
  survarium::flash_value *v59; // ecx
  survarium::flash_value *v60; // ecx
  survarium::flash_value *v61; // ecx
  survarium::flash_value *v62; // ecx
  survarium::flash_value *v63; // ecx
  survarium::flash_value *v64; // ecx
  survarium::flash_value *v65; // [esp+0h] [ebp-90h]
  survarium::flash_value *v66; // [esp+0h] [ebp-90h]
  Scaleform::GFx::Value pvalue; // [esp+14h] [ebp-7Ch] BYREF
  Scaleform::GFx::Value v68; // [esp+2Ch] [ebp-64h] BYREF
  survarium::flash_value v69; // [esp+44h] [ebp-4Ch] BYREF
  Scaleform::GFx::Value pargs; // [esp+5Ch] [ebp-34h] BYREF
  survarium::flash_value value; // [esp+74h] [ebp-1Ch] BYREF

  v4 = *(_DWORD *)&stats[5].best_match_gunslinger[50];
  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  survarium::flash_movie::CreateObject((survarium::flash_movie *)this, *(survarium::flash_value **)(v4 + 264), &pargs);
  *(_DWORD *)value.body = 0;
  *(_DWORD *)&value.body[4] = 0;
  survarium::flash_value::SetString(&value, (const char *)&match_players->_M_impl._M_finish);
  survarium::flash_value::SetMember(v5, &pargs, "title_0_player", &value);
  survarium::flash_value::SetUInt(v6, (int)&value, LOWORD(match_players[4]._M_impl._M_finish));
  survarium::flash_value::SetMember(v7, &pargs, "title_0_value_0", &value);
  survarium::flash_value::SetString(&value, (const char *)&match_players[4]._M_impl._M_finish + 2);
  survarium::flash_value::SetMember(v8, &pargs, "title_1_player", &value);
  survarium::flash_value::SetUInt(v9, (int)&value, BYTE2(match_players[8]._M_impl._M_finish));
  survarium::flash_value::SetMember(v10, &pargs, "title_1_value_0", &value);
  survarium::flash_value::SetUInt(v11, (int)&value, LOWORD(match_players[8]._M_impl._M_end_of_storage.m_allocator));
  survarium::flash_value::SetMember(v12, &pargs, "title_1_value_1", &value);
  survarium::flash_value::SetString(&value, (const char *)&match_players[8]._M_impl._M_end_of_storage.m_allocator + 2);
  survarium::flash_value::SetMember(v13, &pargs, "title_2_player", &value);
  survarium::flash_value::SetUInt(v14, (int)&value, LOWORD(match_players[12]._M_impl._M_end_of_storage._M_data));
  survarium::flash_value::SetMember(v15, &pargs, "title_2_value_0", &value);
  survarium::flash_value::SetUInt(v16, (int)&value, HIWORD(match_players[12]._M_impl._M_end_of_storage.m_allocator));
  survarium::flash_value::SetMember(v17, &pargs, "title_2_value_1", &value);
  survarium::flash_value::SetString(&value, (const char *)&match_players[12]._M_impl._M_end_of_storage._M_data + 2);
  survarium::flash_value::SetMember(v18, &pargs, "title_3_player", &value);
  survarium::flash_value::SetUInt(v19, (int)&value, HIWORD(match_players[16]._M_impl._M_end_of_storage._M_data));
  survarium::flash_value::SetMember(v20, &pargs, "title_3_value_0", &value);
  survarium::flash_value::SetUInt(v21, (int)&value, LOWORD(match_players[17]._M_impl._M_start));
  survarium::flash_value::SetMember(v22, &pargs, "title_3_value_1", &value);
  survarium::flash_value::SetUInt(v23, (int)&value, HIWORD(match_players[17]._M_impl._M_start));
  survarium::flash_value::SetMember(v24, &pargs, "statistics_exp", &value);
  survarium::flash_value::SetUInt(v25, (int)&value, LOWORD(match_players[17]._M_impl._M_finish));
  survarium::flash_value::SetMember(v26, &pargs, "statistics_score", &value);
  survarium::flash_value::SetNumber(v27, (int)&value, (float)HIWORD(match_players[17]._M_impl._M_finish));
  survarium::flash_value::SetMember(v28, &pargs, "statistics_money", &value);
  if ( LOBYTE(match_players->_M_impl._M_start) )
    M_start_high = HIBYTE(match_players->_M_impl._M_start);
  else
    M_start_high = BYTE2(match_players->_M_impl._M_start);
  survarium::flash_value::SetUInt(v29, (int)&value, M_start_high);
  survarium::flash_value::SetMember(v31, &pargs, "team1_score", &value);
  if ( LOBYTE(match_players->_M_impl._M_start) )
    v33 = BYTE2(match_players->_M_impl._M_start);
  else
    v33 = HIBYTE(match_players->_M_impl._M_start);
  survarium::flash_value::SetUInt(v32, (int)&value, v33);
  survarium::flash_value::SetMember(v34, &pargs, "team2_score", &value);
  v36 = BYTE1(match_players->_M_impl._M_start);
  if ( v36 == 3 )
  {
    v37 = 3;
  }
  else
  {
    v35 = LOBYTE(match_players->_M_impl._M_start) != v36 ? 0 : (survarium::flash_value *)5;
    v37 = (unsigned int)v35;
  }
  survarium::flash_value::SetUInt(v35, (int)&value, v37);
  survarium::flash_value::SetMember(v38, &pargs, "match_result", &value);
  survarium::flash_value::SetUInt(v39, (int)&value, (unsigned int)match_players[17]._M_impl._M_end_of_storage._M_data);
  survarium::flash_value::SetMember(v40, &pargs, "match_id", &value);
  M_finish = (unsigned __int8)match_players[18]._M_impl._M_finish;
  if ( M_finish )
  {
    survarium::flash_value::SetUInt(v41, (int)&value, M_finish);
    survarium::flash_value::SetMember(v43, &pargs, "statistics_reputation_faction", &value);
    survarium::flash_value::SetUInt(v44, (int)&value, HIWORD(match_players[18]._M_impl._M_finish));
    survarium::flash_value::SetMember(v45, &pargs, "statistics_reputation", &value);
  }
  survarium::flash_value::SetUInt(v41, (int)&value, HIWORD(match_players[18]._M_impl._M_start));
  survarium::flash_value::SetMember(v46, &pargs, "statistics_rating", &value);
  v65 = (survarium::flash_value *)(HIWORD(match_players[18]._M_impl._M_start)
                                 - LOWORD(match_players[18]._M_impl._M_start));
  survarium::flash_value::SetInt(v65, (int)&value, (int)v65);
  survarium::flash_value::SetMember(v47, &pargs, "statistics_rating_delta", &value);
  v48 = stats;
  v49 = *(_DWORD *)&stats[5].best_match_gunslinger[50];
  pvalue.pObjectInterface = 0;
  pvalue.Type = VT_Undefined;
  Scaleform::GFx::Movie::CreateArray(*(Scaleform::GFx::Movie **)(*(_DWORD *)(v49 + 264) + 4), &pvalue);
  v51 = a4;
  *(_DWORD *)v69.body = 0;
  *(_DWORD *)&v69.body[4] = 0;
  for ( i = *a4; i != v51[1]; i += 80 )
  {
    v68.pObjectInterface = 0;
    v68.Type = VT_Undefined;
    survarium::flash_movie::CreateObject(
      v50,
      *(survarium::flash_value **)(*(_DWORD *)&v48[5].best_match_gunslinger[50] + 264),
      &v68);
    survarium::flash_value::SetString(&v69, (const char *)i);
    survarium::flash_value::SetMember(v53, &v68, "name", &v69);
    survarium::flash_value::SetUInt(v54, (int)&v69, *(_DWORD *)(i + 64));
    survarium::flash_value::SetMember(v55, &v68, "id", &v69);
    v66 = (survarium::flash_value *)((LOBYTE(match_players->_M_impl._M_start) != *(_BYTE *)(i + 76)) + 1);
    survarium::flash_value::SetUInt(v66, (int)&v69, (unsigned int)v66);
    survarium::flash_value::SetMember(v56, &v68, "team", &v69);
    survarium::flash_value::SetUInt(v57, (int)&v69, *(unsigned __int16 *)(i + 72));
    survarium::flash_value::SetMember(v58, &v68, "kills", &v69);
    survarium::flash_value::SetUInt(v59, (int)&v69, *(unsigned __int16 *)(i + 74));
    survarium::flash_value::SetMember(v60, &v68, "deaths", &v69);
    survarium::flash_value::SetUInt(v61, (int)&v69, *(unsigned __int16 *)(i + 68));
    survarium::flash_value::SetMember(v62, &v68, "score", &v69);
    survarium::flash_value::SetUInt(v63, (int)&v69, *(unsigned __int16 *)(i + 70));
    survarium::flash_value::SetMember(v64, &v68, "rank", &v69);
    pvalue.pObjectInterface->PushBack(pvalue.pObjectInterface, (void *)pvalue.mValue.IValue, &v68);
    Scaleform::GFx::Value::~Value(&v68);
    v51 = a4;
    v48 = stats;
  }
  survarium::flash_value::SetMember((survarium::flash_value *)v50, &pargs, "players", (survarium::flash_value *)&pvalue);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)&v48[5].best_match_gunslinger[50] + 264) + 4),
    "root.fill_victory_screen",
    0,
    &pargs,
    1u);
  v48[5].best_match_support[39] = 0;
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v69);
  Scaleform::GFx::Value::~Value(&pvalue);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&value);
  Scaleform::GFx::Value::~Value(&pargs);
}
