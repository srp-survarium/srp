void __userpurge survarium::game_world_ui::set_player_stats_info(
        survarium::game_world_ui *this@<ecx>,
        int a2@<edi>,
        unsigned __int8 player_id)
{
  survarium::flash_movie *v3; // ecx
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
  Scaleform::GFx::Value pargs; // [esp+8h] [ebp-34h] BYREF
  survarium::flash_value value; // [esp+20h] [ebp-1Ch] BYREF

  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  survarium::flash_movie::CreateObject(
    (survarium::flash_movie *)this,
    *(survarium::flash_value **)(*(_DWORD *)(a2 + 8) + 264),
    &pargs);
  *(_DWORD *)value.body = 0;
  *(_DWORD *)&value.body[4] = 0;
  survarium::flash_movie::CreateObject(
    v3,
    *(survarium::flash_value **)(*(_DWORD *)(a2 + 8) + 264),
    (Scaleform::GFx::Value *)&value);
  survarium::flash_value::SetUInt(v4, (int)&value, player_id);
  survarium::flash_value::SetMember(v5, &pargs, "id", &value);
  survarium::flash_value::SetInt(v6, (int)&value, *(unsigned __int16 *)(a2 + 8 * player_id + 176));
  survarium::flash_value::SetMember(v7, &pargs, "kills", &value);
  survarium::flash_value::SetUInt(v8, (int)&value, *(unsigned __int16 *)(a2 + 8 * player_id + 178));
  survarium::flash_value::SetMember(v9, &pargs, "deaths", &value);
  survarium::flash_value::SetInt(v10, (int)&value, 66);
  survarium::flash_value::SetMember(v11, &pargs, "ping", &value);
  survarium::flash_value::SetInt(v12, (int)&value, *(__int16 *)(a2 + 8 * player_id + 182));
  survarium::flash_value::SetMember(v13, &pargs, "rank", &value);
  survarium::flash_value::SetUInt(v14, (int)&value, 0);
  survarium::flash_value::SetMember(v15, &pargs, "artifacts", &value);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 8) + 264) + 4),
    "root.list_update_player",
    0,
    &pargs,
    1u);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&value);
  Scaleform::GFx::Value::~Value(&pargs);
}
