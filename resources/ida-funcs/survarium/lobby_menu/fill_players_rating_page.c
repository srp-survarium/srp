void __thiscall survarium::lobby_menu::fill_players_rating_page(
        survarium::lobby_menu *this,
        vostok::vectora<survarium::player_elo_stats> *players,
        _DWORD *a3)
{
  survarium::player_elo_stats *M_start; // eax
  survarium::flash_movie *v4; // ecx
  _DWORD *v5; // eax
  int v6; // ebx
  survarium::player_elo_stats *v7; // eax
  survarium::flash_value *v8; // ecx
  survarium::flash_value *v9; // ecx
  survarium::flash_value *v10; // ecx
  survarium::flash_value *v11; // ecx
  survarium::flash_value *v12; // ecx
  survarium::flash_value *v13; // ecx
  survarium::flash_value *v14; // ecx
  Scaleform::GFx::Value pvalue; // [esp+10h] [ebp-48h] BYREF
  Scaleform::GFx::Value v16; // [esp+28h] [ebp-30h] BYREF
  survarium::flash_value value; // [esp+40h] [ebp-18h] BYREF

  M_start = players[100]._M_impl._M_start;
  pvalue.pObjectInterface = 0;
  pvalue.Type = VT_Undefined;
  Scaleform::GFx::Movie::CreateArray(*(Scaleform::GFx::Movie **)(*(_DWORD *)&M_start[3].name[44] + 4), &pvalue);
  v5 = a3;
  v6 = *a3;
  *(_DWORD *)value.body = 0;
  *(_DWORD *)&value.body[4] = 0;
  while ( v6 != v5[1] )
  {
    v7 = players[100]._M_impl._M_start;
    v16.pObjectInterface = 0;
    v16.Type = VT_Undefined;
    survarium::flash_movie::CreateObject(v4, *(survarium::flash_value **)&v7[3].name[44], &v16);
    survarium::flash_value::SetUInt(v8, (int)&value, *(_DWORD *)v6);
    survarium::flash_value::SetMember(v9, &v16, "place", &value);
    survarium::flash_value::SetString(&value, (const char *)(v6 + 4));
    survarium::flash_value::SetMember(v10, &v16, "nickname", &value);
    survarium::flash_value::SetUInt(v11, (int)&value, *(unsigned __int16 *)(v6 + 68));
    survarium::flash_value::SetMember(v12, &v16, "ranking", &value);
    survarium::flash_value::SetInt(v13, (int)&value, *(__int16 *)(v6 + 70));
    survarium::flash_value::SetMember(v14, &v16, "ranking_diff", &value);
    pvalue.pObjectInterface->PushBack(pvalue.pObjectInterface, (void *)pvalue.mValue.IValue, &v16);
    Scaleform::GFx::Value::~Value(&v16);
    v5 = a3;
    v6 += 72;
  }
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)&players[100]._M_impl._M_start[3].name[44] + 4),
    "root.ranking_set_data",
    0,
    &pvalue,
    1u);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&value);
  Scaleform::GFx::Value::~Value(&pvalue);
}
