void __thiscall survarium::lobby_menu::set_player_elo_rating(
        survarium::lobby_menu *this,
        int place,
        unsigned int elo,
        unsigned __int16 last_elo,
        unsigned __int16 a5)
{
  survarium::flash_value *v5; // ecx
  survarium::flash_value *v6; // ecx
  survarium::lobby_menu *v7; // ecx
  survarium::lobby_client *v8; // eax
  survarium::flash_value *v9; // ecx
  survarium::flash_value *v10; // ecx
  survarium::flash_value *v11; // ecx
  survarium::flash_value *v12; // ecx
  survarium::flash_value *v13; // ecx
  Scaleform::GFx::Value pargs; // [esp+10h] [ebp-30h] BYREF
  survarium::flash_value v15; // [esp+28h] [ebp-18h] BYREF

  *(_DWORD *)v15.body = 0;
  *(_DWORD *)&v15.body[4] = 0;
  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  survarium::flash_movie::CreateObject(
    (survarium::flash_movie *)this,
    *(survarium::flash_value **)(*(_DWORD *)(place + 1600) + 264),
    &pargs);
  survarium::flash_value::SetUInt(v5, (int)&v15, elo);
  survarium::flash_value::SetMember(v6, &pargs, "place", &v15);
  v8 = survarium::lobby_menu::lobby_client(v7, place);
  survarium::flash_value::SetString(&v15, v8->account_nickname);
  survarium::flash_value::SetMember(v9, &pargs, "nickname", &v15);
  survarium::flash_value::SetUInt(v10, (int)&v15, last_elo);
  survarium::flash_value::SetMember(v11, &pargs, "ranking", &v15);
  survarium::flash_value::SetInt(v12, (int)&v15, last_elo - a5);
  survarium::flash_value::SetMember(v13, &pargs, "ranking_diff", &v15);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(place + 1600) + 264) + 4),
    "root.ranking_set_player",
    0,
    &pargs,
    1u);
  Scaleform::GFx::Value::~Value(&pargs);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v15);
}
