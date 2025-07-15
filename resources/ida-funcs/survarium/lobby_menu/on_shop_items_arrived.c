void __thiscall survarium::lobby_menu::on_shop_items_arrived(survarium::lobby_menu *this, int a2)
{
  int v2; // edi
  int v3; // eax
  survarium::lobby_menu *v4; // ecx
  survarium::lobby_menu *v5; // ecx
  survarium::lobby_client *v6; // eax
  survarium::flash_movie *v7; // ecx
  survarium::shop_items_container *v8; // ebx
  int v9; // eax
  survarium::flash_value *v10; // ecx
  survarium::flash_value *v11; // ecx
  survarium::flash_value *v12; // ecx
  survarium::flash_value *v13; // ecx
  survarium::flash_value *v14; // ecx
  survarium::flash_value *v15; // ecx
  survarium::text_translator *v16; // ecx
  survarium::flash_value *v17; // ecx
  survarium::text_translator *v18; // ecx
  survarium::flash_value *v19; // ecx
  survarium::lobby_client *v20; // eax
  unsigned int id; // [esp-4h] [ebp-268h]
  char v22[512]; // [esp+10h] [ebp-254h] BYREF
  Scaleform::GFx::Value pvalue; // [esp+210h] [ebp-54h] BYREF
  Scaleform::GFx::Value v24; // [esp+228h] [ebp-3Ch] BYREF
  survarium::flash_value value; // [esp+240h] [ebp-24h] BYREF
  survarium::lobby_menu *v26; // [esp+258h] [ebp-Ch]
  unsigned int v27; // [esp+25Ch] [ebp-8h]

  v2 = a2;
  v3 = *(_DWORD *)(a2 + 1600);
  pvalue.pObjectInterface = 0;
  pvalue.Type = VT_Undefined;
  Scaleform::GFx::Movie::CreateArray(*(Scaleform::GFx::Movie **)(*(_DWORD *)(v3 + 264) + 4), &pvalue);
  v26 = 0;
  if ( survarium::lobby_menu::lobby_client(v4, a2)->m_shop_items_count )
  {
    v27 = 0;
    do
    {
      v6 = survarium::lobby_menu::lobby_client(v5, v2);
      v8 = &v6->m_shop_items[v27 / 0x108];
      if ( v8->shelf_id == premium_shelf )
      {
        v9 = *(_DWORD *)(v2 + 1600);
        v24.pObjectInterface = 0;
        v24.Type = VT_Undefined;
        survarium::flash_movie::CreateObject(v7, *(survarium::flash_value **)(v9 + 264), &v24);
        id = v8->id;
        *(_DWORD *)value.body = 0;
        *(_DWORD *)&value.body[4] = 0;
        survarium::flash_value::SetUInt(v10, (int)&value, id);
        survarium::flash_value::SetMember(v11, &v24, "id", &value);
        survarium::flash_value::SetUInt(v12, (int)&value, v8->cost);
        survarium::flash_value::SetMember(v13, &v24, "value", &value);
        survarium::flash_value::SetUInt(v14, (int)&value, v8->currency);
        survarium::flash_value::SetMember(v15, &v24, "money_type", &value);
        survarium::text_translator::translate_text(v16, *(_DWORD *)(v2 + 160) + 13944, v8->name, v22);
        survarium::flash_value::SetString(&value, v22);
        survarium::flash_value::SetMember(v17, &v24, "label", &value);
        survarium::text_translator::translate_text(v18, *(_DWORD *)(a2 + 160) + 13944, v8->descr, v22);
        survarium::flash_value::SetString(&value, v22);
        survarium::flash_value::SetMember(v19, &v24, "value2", &value);
        pvalue.pObjectInterface->PushBack(pvalue.pObjectInterface, (void *)pvalue.mValue.IValue, &v24);
        Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&value);
        Scaleform::GFx::Value::~Value(&v24);
        v2 = a2;
      }
      v26 = (survarium::lobby_menu *)((char *)v26 + 1);
      v27 += 264;
      v20 = survarium::lobby_menu::lobby_client((survarium::lobby_menu *)v7, v2);
      v5 = v26;
    }
    while ( (unsigned int)v26 < v20->m_shop_items_count );
  }
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(v2 + 1600) + 264) + 4),
    "root.set_premium_store",
    0,
    &pvalue,
    1u);
  Scaleform::GFx::Value::~Value(&pvalue);
}
