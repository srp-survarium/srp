void __thiscall survarium::lobby_menu::fill_ignore_list(survarium::lobby_menu *this, int a2)
{
  int v2; // esi
  survarium::messaging_client *v3; // ebx
  int v4; // eax
  int v5; // edi
  vostok::vectora<survarium::account_list_item> *p_m_ignore_list; // ebx
  int v7; // eax
  survarium::flash_value *v8; // ecx
  survarium::flash_value *v9; // ecx
  survarium::flash_value *v10; // ecx
  survarium::flash_value *v11; // ecx
  survarium::flash_value *v12; // ecx
  unsigned int v13; // eax
  Scaleform::GFx::Value pvalue; // [esp+10h] [ebp-54h] BYREF
  Scaleform::GFx::Value v15; // [esp+28h] [ebp-3Ch] BYREF
  survarium::flash_value value; // [esp+40h] [ebp-24h] BYREF
  int i; // [esp+58h] [ebp-Ch]
  unsigned int v18; // [esp+5Ch] [ebp-8h]

  v2 = a2;
  v3 = survarium::lobby_menu::messaging_client(this, a2);
  v4 = *(_DWORD *)(a2 + 1600);
  v5 = 0;
  pvalue.pObjectInterface = 0;
  pvalue.Type = VT_Undefined;
  p_m_ignore_list = &v3->m_ignore_list;
  Scaleform::GFx::Movie::CreateArray(*(Scaleform::GFx::Movie **)(*(_DWORD *)(v4 + 264) + 4), &pvalue);
  *(_DWORD *)value.body = 0;
  *(_DWORD *)&value.body[4] = 0;
  v7 = p_m_ignore_list->_M_impl._M_finish - p_m_ignore_list->_M_impl._M_start;
  v18 = 0;
  if ( v7 )
  {
    for ( i = 0; ; v5 = i )
    {
      v15.pObjectInterface = 0;
      v15.Type = VT_Undefined;
      survarium::flash_movie::CreateObject(
        (survarium::flash_movie *)0x48,
        *(survarium::flash_value **)(*(_DWORD *)(v2 + 1600) + 264),
        &v15);
      survarium::flash_value::SetUInt(
        v8,
        (int)&value,
        *(unsigned int *)((char *)&p_m_ignore_list->_M_impl._M_start->account_id + v5));
      survarium::flash_value::SetMember(v9, &v15, "id", &value);
      survarium::flash_value::SetString(&value, &p_m_ignore_list->_M_impl._M_start->account_name[v5]);
      survarium::flash_value::SetMember(v10, &v15, "name", &value);
      survarium::flash_value::SetUInt(v11, (int)&value, 3u);
      survarium::flash_value::SetMember(v12, &v15, "icon", &value);
      pvalue.pObjectInterface->SetElement(pvalue.pObjectInterface, (void *)pvalue.mValue.IValue, v18, &v15);
      Scaleform::GFx::Value::~Value(&v15);
      v13 = p_m_ignore_list->_M_impl._M_finish - p_m_ignore_list->_M_impl._M_start;
      ++v18;
      i += 72;
      v2 = a2;
      if ( v18 >= v13 )
        break;
    }
  }
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(v2 + 1600) + 264) + 4),
    "root.set_ignored_list",
    0,
    &pvalue,
    1u);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&value);
  Scaleform::GFx::Value::~Value(&pvalue);
}
