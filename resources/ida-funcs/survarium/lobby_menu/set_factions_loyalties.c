void __userpurge survarium::lobby_menu::set_factions_loyalties(
        survarium::lobby_menu *this@<ecx>,
        int a2@<edi>,
        survarium::faction_loyalty_item *loyalties_array,
        unsigned __int8 loyalties_count)
{
  int v5; // eax
  survarium::flash_movie *v6; // ecx
  int v7; // eax
  unsigned int faction_id; // eax
  survarium::flash_value *v9; // ecx
  survarium::flash_value *v10; // ecx
  survarium::flash_value *v11; // ecx
  survarium::flash_value *v12; // ecx
  Scaleform::GFx::Value pvalue; // [esp+8h] [ebp-48h] BYREF
  Scaleform::GFx::Value v14; // [esp+20h] [ebp-30h] BYREF
  survarium::flash_value value; // [esp+38h] [ebp-18h] BYREF
  unsigned int i; // [esp+58h] [ebp+8h]

  v5 = *(_DWORD *)(a2 + 1600);
  pvalue.pObjectInterface = 0;
  pvalue.Type = VT_Undefined;
  Scaleform::GFx::Movie::CreateArray(*(Scaleform::GFx::Movie **)(*(_DWORD *)(v5 + 264) + 4), &pvalue);
  for ( i = 0; i < loyalties_count; ++i )
  {
    v7 = *(_DWORD *)(a2 + 1600);
    v14.pObjectInterface = 0;
    v14.Type = VT_Undefined;
    survarium::flash_movie::CreateObject(v6, *(survarium::flash_value **)(v7 + 264), &v14);
    faction_id = loyalties_array[i].faction_id;
    *(_DWORD *)value.body = 0;
    *(_DWORD *)&value.body[4] = 0;
    survarium::flash_value::SetUInt(v9, (int)&value, faction_id);
    survarium::flash_value::SetMember(v10, &v14, "faction_id", &value);
    survarium::flash_value::SetUInt(v11, (int)&value, loyalties_array[i].loyalty_value);
    survarium::flash_value::SetMember(v12, &v14, "bonus", &value);
    pvalue.pObjectInterface->PushBack(pvalue.pObjectInterface, (void *)pvalue.mValue.IValue, &v14);
    Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&value);
    Scaleform::GFx::Value::~Value(&v14);
  }
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 1600) + 264) + 4),
    "root.set_faction_bonus",
    0,
    &pvalue,
    1u);
  Scaleform::GFx::Value::~Value(&pvalue);
}
