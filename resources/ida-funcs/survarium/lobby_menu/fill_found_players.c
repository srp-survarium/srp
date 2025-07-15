void __thiscall survarium::lobby_menu::fill_found_players(survarium::lobby_menu *this, int a2)
{
  int v2; // esi
  survarium::messaging_client *v3; // ebx
  int v4; // eax
  int v5; // edi
  vostok::vectora<survarium::account_list_item> *p_m_found_players_list; // ebx
  int v7; // ecx
  int v8; // eax
  survarium::flash_value *v9; // ecx
  survarium::flash_value *v10; // ecx
  survarium::flash_value *v11; // ecx
  unsigned int v12; // esi
  bool v13; // zf
  Scaleform::GFx::Value pvalue; // [esp+Ch] [ebp-58h] BYREF
  survarium::flash_value value; // [esp+24h] [ebp-40h] BYREF
  Scaleform::GFx::Value v16; // [esp+3Ch] [ebp-28h] BYREF
  int v17; // [esp+54h] [ebp-10h]
  unsigned int v18; // [esp+58h] [ebp-Ch]
  int i; // [esp+5Ch] [ebp-8h]

  v2 = a2;
  v3 = survarium::lobby_menu::messaging_client(this, a2);
  v4 = *(_DWORD *)(a2 + 1600);
  v5 = 0;
  pvalue.pObjectInterface = 0;
  pvalue.Type = VT_Undefined;
  p_m_found_players_list = &v3->m_found_players_list;
  Scaleform::GFx::Movie::CreateArray(*(Scaleform::GFx::Movie **)(*(_DWORD *)(v4 + 264) + 4), &pvalue);
  *(_DWORD *)value.body = 0;
  *(_DWORD *)&value.body[4] = 0;
  v7 = 72;
  v8 = p_m_found_players_list->_M_impl._M_finish - p_m_found_players_list->_M_impl._M_start;
  v18 = 0;
  v17 = v8;
  if ( v8 )
  {
    for ( i = 0; ; v5 = i )
    {
      v16.pObjectInterface = 0;
      v16.Type = VT_Undefined;
      survarium::flash_movie::CreateObject(
        (survarium::flash_movie *)v7,
        *(survarium::flash_value **)(*(_DWORD *)(v2 + 1600) + 264),
        &v16);
      survarium::flash_value::SetUInt(
        v9,
        (int)&value,
        *(unsigned int *)((char *)&p_m_found_players_list->_M_impl._M_start->account_id + v5));
      survarium::flash_value::SetMember(v10, &v16, "id", &value);
      survarium::flash_value::SetString(&value, &p_m_found_players_list->_M_impl._M_start->account_name[v5]);
      survarium::flash_value::SetMember(v11, &v16, "name", &value);
      v12 = v18;
      pvalue.pObjectInterface->SetElement(pvalue.pObjectInterface, (void *)pvalue.mValue.IValue, v18, &v16);
      Scaleform::GFx::Value::~Value(&v16);
      i += 72;
      v13 = ++v12 == v17;
      v18 = v12;
      v2 = a2;
      if ( v13 )
        break;
    }
  }
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(v2 + 1600) + 264) + 4),
    "root.fill_players_search",
    0,
    &pvalue,
    1u);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&value);
  Scaleform::GFx::Value::~Value(&pvalue);
}
