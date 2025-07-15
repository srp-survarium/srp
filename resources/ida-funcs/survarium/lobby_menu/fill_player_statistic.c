void __thiscall survarium::lobby_menu::fill_player_statistic(
        survarium::lobby_menu *this,
        const survarium::match_player_stats *stats,
        unsigned __int16 *a3)
{
  int v3; // eax
  survarium::flash_value *v4; // ecx
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
  survarium::flash_value *v30; // ecx
  survarium::flash_value *v31; // ecx
  unsigned __int16 v32; // ax
  survarium::flash_value *v33; // ecx
  unsigned __int16 v34; // ax
  survarium::flash_value *v35; // ecx
  unsigned int v36; // [esp-4h] [ebp-54h]
  Scaleform::GFx::Value pargs; // [esp+10h] [ebp-40h] BYREF
  survarium::flash_value value; // [esp+28h] [ebp-28h] BYREF
  char _Dest[16]; // [esp+40h] [ebp-10h] BYREF

  v3 = *(_DWORD *)&stats[44].items_brought;
  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  survarium::flash_movie::CreateObject((survarium::flash_movie *)this, *(survarium::flash_value **)(v3 + 264), &pargs);
  v36 = *a3;
  *(_DWORD *)value.body = 0;
  *(_DWORD *)&value.body[4] = 0;
  survarium::flash_value::SetUInt(v4, (int)&value, v36);
  survarium::flash_value::SetMember(v5, &pargs, "statistics_0", &value);
  survarium::flash_value::SetUInt(v6, (int)&value, a3[1]);
  survarium::flash_value::SetMember(v7, &pargs, "statistics_1", &value);
  survarium::flash_value::SetUInt(v8, (int)&value, a3[2]);
  survarium::flash_value::SetMember(v9, &pargs, "statistics_2", &value);
  survarium::flash_value::SetUInt(v10, (int)&value, a3[3]);
  survarium::flash_value::SetMember(v11, &pargs, "statistics_3", &value);
  survarium::flash_value::SetUInt(v12, (int)&value, a3[4]);
  survarium::flash_value::SetMember(v13, &pargs, "statistics_4", &value);
  survarium::flash_value::SetUInt(v14, (int)&value, a3[5]);
  survarium::flash_value::SetMember(v15, &pargs, "statistics_5", &value);
  survarium::flash_value::SetUInt(v16, (int)&value, 0);
  survarium::flash_value::SetMember(v17, &pargs, "statistics_6", &value);
  survarium::flash_value::SetUInt(v18, (int)&value, 0);
  survarium::flash_value::SetMember(v19, &pargs, "statistics_7", &value);
  survarium::flash_value::SetUInt(v20, (int)&value, a3[8]);
  survarium::flash_value::SetMember(v21, &pargs, "statistics_8", &value);
  survarium::flash_value::SetUInt(v22, (int)&value, a3[9]);
  survarium::flash_value::SetMember(v23, &pargs, "statistics_9", &value);
  survarium::flash_value::SetUInt(v24, (int)&value, a3[10]);
  survarium::flash_value::SetMember(v25, &pargs, "statistics_10", &value);
  survarium::flash_value::SetUInt(v26, (int)&value, a3[11]);
  survarium::flash_value::SetMember(v27, &pargs, "statistics_11", &value);
  sprintf_s<16>((char (*)[16])_Dest, "%d %%", *((unsigned __int8 *)a3 + 28));
  survarium::flash_value::SetString(&value, _Dest);
  survarium::flash_value::SetMember(v28, &pargs, "statistics_12", &value);
  survarium::flash_value::SetUInt(v29, (int)&value, *((unsigned __int8 *)a3 + 29));
  survarium::flash_value::SetMember(v30, &pargs, "level", &value);
  v32 = a3[15];
  if ( v32 )
  {
    survarium::flash_value::SetUInt(v31, (int)&value, v32);
    survarium::flash_value::SetMember(v33, &pargs, "weapon1_dict_id", &value);
  }
  v34 = a3[16];
  if ( v34 )
  {
    survarium::flash_value::SetUInt(v31, (int)&value, v34);
    survarium::flash_value::SetMember(v35, &pargs, "weapon2_dict_id", &value);
  }
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)&stats[44].items_brought + 264) + 4),
    "root.fill_victory_screen_player",
    0,
    &pargs,
    1u);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&value);
  Scaleform::GFx::Value::~Value(&pargs);
}
