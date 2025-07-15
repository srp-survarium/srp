void __thiscall survarium::lobby_menu::fill_inventory_contents(survarium::lobby_menu *this, int a2)
{
  int *v3; // eax
  int v4; // edi
  int v5; // eax
  survarium::flash_movie *v6; // ecx
  int v7; // eax
  survarium::flash_value *v8; // ecx
  survarium::flash_value *v9; // ecx
  survarium::flash_value *v10; // ecx
  survarium::flash_value *v11; // ecx
  survarium::flash_value *v12; // ecx
  survarium::flash_value *v13; // ecx
  survarium::flash_value *v14; // ecx
  survarium::flash_value *v15; // ecx
  int v16; // [esp-4h] [ebp-68h]
  Scaleform::GFx::Value pvalue; // [esp+Ch] [ebp-58h] BYREF
  Scaleform::GFx::Value v18; // [esp+24h] [ebp-40h] BYREF
  survarium::flash_value value; // [esp+3Ch] [ebp-28h] BYREF
  unsigned int v20; // [esp+54h] [ebp-10h]
  int v21; // [esp+58h] [ebp-Ch]
  int v22; // [esp+5Ch] [ebp-8h]
  unsigned int v23; // [esp+6Ch] [ebp+8h]

  v3 = (int *)((*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 160) + 13912) + 60))(*(_DWORD *)(*(_DWORD *)(a2 + 160) + 13912))
             + 12712);
  v4 = *v3;
  v22 = v3[1];
  v5 = *(_DWORD *)(a2 + 1600);
  pvalue.pObjectInterface = 0;
  pvalue.Type = VT_Undefined;
  Scaleform::GFx::Movie::CreateArray(*(Scaleform::GFx::Movie **)(*(_DWORD *)(v5 + 264) + 4), &pvalue);
  *(_DWORD *)value.body = 0;
  *(_DWORD *)&value.body[4] = 0;
  v23 = 0;
  while ( v4 != v22 )
  {
    v7 = *(_DWORD *)(a2 + 1600);
    v18.pObjectInterface = 0;
    v18.Type = VT_Undefined;
    survarium::flash_movie::CreateObject(v6, *(survarium::flash_value **)(v7 + 264), &v18);
    v16 = *(_DWORD *)(v4 + 8);
    v21 = *(unsigned __int16 *)(v4 + 12);
    v20 = *(_DWORD *)v4;
    survarium::flash_value::SetInt(v8, (int)&value, v16);
    survarium::flash_value::SetMember(v9, &v18, "id", &value);
    survarium::flash_value::SetInt(v10, (int)&value, v21);
    survarium::flash_value::SetMember(v11, &v18, "dictId", &value);
    survarium::flash_value::SetUInt(v12, (int)&value, *(_DWORD *)v4);
    survarium::flash_value::SetMember(v13, &v18, "condition", &value);
    survarium::flash_value::SetUInt(v14, (int)&value, v20);
    survarium::flash_value::SetMember(v15, &v18, "condition_or_stack", &value);
    pvalue.pObjectInterface->SetElement(pvalue.pObjectInterface, (void *)pvalue.mValue.IValue, v23, &v18);
    Scaleform::GFx::Value::~Value(&v18);
    v4 += 16;
    ++v23;
  }
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 1600) + 264) + 4),
    "root.inventory_list.setupInventoryData",
    0,
    &pvalue,
    1u);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&value);
  Scaleform::GFx::Value::~Value(&pvalue);
}
