void __thiscall survarium::lobby_menu::fill_profiles(survarium::lobby_menu *this, int a2)
{
  int v2; // edi
  int v3; // ebx
  int v4; // eax
  Scaleform::GFx::Movie *v5; // ecx
  survarium::flash_movie *v6; // ecx
  unsigned __int8 v7; // al
  int v8; // ebx
  int v9; // eax
  survarium::flash_value *v10; // ecx
  survarium::flash_value *v11; // ecx
  survarium::flash_value *v12; // ecx
  unsigned int v13; // edi
  survarium::flash_value *v14; // ecx
  survarium::flash_value *v15; // ecx
  survarium::flash_value *v16; // ecx
  survarium::flash_value *v17; // ecx
  survarium::flash_value *v18; // ecx
  bool v19; // cf
  survarium::flash_value *v20; // ecx
  Scaleform::GFx::Value pargs; // [esp+Ch] [ebp-70h] BYREF
  Scaleform::GFx::Value pvalue; // [esp+24h] [ebp-58h] BYREF
  Scaleform::GFx::Value v23; // [esp+3Ch] [ebp-40h] BYREF
  survarium::flash_value value; // [esp+54h] [ebp-28h] BYREF
  int v25; // [esp+6Ch] [ebp-10h]
  int v26; // [esp+70h] [ebp-Ch]
  unsigned int v27; // [esp+74h] [ebp-8h]

  v2 = a2;
  v3 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 160) + 13912) + 60))(*(_DWORD *)(*(_DWORD *)(a2 + 160) + 13912));
  v4 = *(_DWORD *)(a2 + 1600);
  pvalue.pObjectInterface = 0;
  pvalue.Type = VT_Undefined;
  v5 = *(Scaleform::GFx::Movie **)(*(_DWORD *)(v4 + 264) + 4);
  v25 = v3;
  Scaleform::GFx::Movie::CreateArray(v5, &pvalue);
  v7 = *(_BYTE *)(v3 + 608);
  *(_DWORD *)value.body = 0;
  *(_DWORD *)&value.body[4] = 0;
  if ( v7 )
  {
    v27 = 0;
    v8 = v3 + 2112;
    v26 = v7;
    do
    {
      v9 = *(_DWORD *)(v2 + 1600);
      v23.pObjectInterface = 0;
      v23.Type = VT_Undefined;
      survarium::flash_movie::CreateObject(v6, *(survarium::flash_value **)(v9 + 264), &v23);
      survarium::flash_value::SetString(&value, (const char *)(v8 - 1488));
      survarium::flash_value::SetMember(v10, &v23, "nickname", &value);
      survarium::flash_value::SetInt(v11, (int)&value, 1);
      survarium::flash_value::SetMember(v12, &v23, "icon", &value);
      v13 = *(_DWORD *)(v8 - 4) - *(_DWORD *)v8;
      survarium::flash_value::SetUInt(
        (survarium::flash_value *)(*(_DWORD *)(v8 - 8) - *(_DWORD *)v8),
        (int)&value,
        *(_DWORD *)(v8 - 8) - *(_DWORD *)v8);
      survarium::flash_value::SetMember(v14, &v23, "experience_current", &value);
      survarium::flash_value::SetUInt(v15, (int)&value, *(unsigned __int8 *)(v8 + 11));
      survarium::flash_value::SetMember(v16, &v23, "skill_level", &value);
      survarium::flash_value::SetUInt(v17, (int)&value, v13);
      survarium::flash_value::SetMember(v18, &v23, "experience_next_level", &value);
      pvalue.pObjectInterface->SetElement(pvalue.pObjectInterface, (void *)pvalue.mValue.IValue, v27, &v23);
      Scaleform::GFx::Value::~Value(&v23);
      ++v27;
      v2 = a2;
      v8 += 1512;
      --v26;
    }
    while ( v26 );
    v3 = v25;
  }
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(v2 + 1600) + 264) + 4),
    "root.setup_player_profiles",
    0,
    &pvalue,
    1u);
  v19 = *(_BYTE *)(v3 + 608) < 8u;
  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  survarium::flash_value::SetBoolean(v20, (int)&pargs, v19);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(v2 + 1600) + 264) + 4),
    "root.set_add_profile_button_enabled",
    0,
    &pargs,
    1u);
  Scaleform::GFx::Value::~Value(&pargs);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&value);
  Scaleform::GFx::Value::~Value(&pvalue);
}
