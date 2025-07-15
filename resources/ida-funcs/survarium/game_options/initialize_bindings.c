void __thiscall survarium::game_options::initialize_bindings(survarium::game_options *this, int is_default)
{
  int v2; // edi
  int v3; // eax
  survarium::flash_movie *v4; // ecx
  unsigned int *p_type; // ebx
  int v6; // eax
  survarium::flash_value *v7; // ecx
  survarium::flash_value *v8; // ecx
  survarium::flash_value *v9; // ecx
  survarium::flash_value *v10; // ecx
  survarium::flash_value *v11; // ecx
  survarium::flash_value *v12; // ecx
  survarium::text_translator *v13; // ecx
  survarium::flash_value *v14; // ecx
  survarium::game_options *v15; // ecx
  char v16[516]; // [esp+10h] [ebp-254h] BYREF
  Scaleform::GFx::Value pvalue; // [esp+214h] [ebp-50h] BYREF
  Scaleform::GFx::Value v18; // [esp+22Ch] [ebp-38h] BYREF
  survarium::flash_value value; // [esp+244h] [ebp-20h] BYREF
  int v20; // [esp+25Ch] [ebp-8h]

  v2 = is_default;
  v3 = *(_DWORD *)(is_default + 12);
  pvalue.pObjectInterface = 0;
  pvalue.Type = VT_Undefined;
  Scaleform::GFx::Movie::CreateArray(*(Scaleform::GFx::Movie **)(*(_DWORD *)(v3 + 264) + 4), &pvalue);
  *(_DWORD *)value.body = 0;
  *(_DWORD *)&value.body[4] = 0;
  p_type = (unsigned int *)&survarium::key_bind_descriptions[0].type;
  v20 = 41;
  while ( 1 )
  {
    v6 = *(_DWORD *)(v2 + 12);
    v18.pObjectInterface = 0;
    v18.Type = VT_Undefined;
    survarium::flash_movie::CreateObject(v4, *(survarium::flash_value **)(v6 + 264), &v18);
    survarium::flash_value::SetUInt(v7, (int)&value, *(p_type - 3));
    survarium::flash_value::SetMember(v8, &v18, "action_id", &value);
    survarium::flash_value::SetUInt(v9, (int)&value, *(p_type - 1));
    survarium::flash_value::SetMember(v10, &v18, "group_id", &value);
    survarium::flash_value::SetUInt(v11, (int)&value, *p_type);
    survarium::flash_value::SetMember(v12, &v18, "type", &value);
    survarium::text_translator::translate_text(v13, *(_DWORD *)(v2 + 52) + 13944, (char *)*(p_type - 2), v16);
    survarium::flash_value::SetString(&value, v16);
    survarium::flash_value::SetMember(v14, &v18, "label", &value);
    pvalue.pObjectInterface->PushBack(pvalue.pObjectInterface, (void *)pvalue.mValue.IValue, &v18);
    Scaleform::GFx::Value::~Value(&v18);
    p_type += 26;
    if ( !--v20 )
      break;
    v2 = is_default;
  }
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(is_default + 12) + 264) + 4),
    "root.set_keybindings",
    0,
    &pvalue,
    1u);
  survarium::game_options::reset_bindings(v15, is_default, 1);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&value);
  Scaleform::GFx::Value::~Value(&pvalue);
}
