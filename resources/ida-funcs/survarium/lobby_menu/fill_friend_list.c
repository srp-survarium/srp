void __thiscall survarium::lobby_menu::fill_friend_list(survarium::lobby_menu *this, int a2)
{
  int v2; // esi
  survarium::messaging_client *v3; // ebx
  int v4; // eax
  vostok::vectora<survarium::account_list_item> *p_m_friend_list; // ebx
  survarium::flash_movie *M_start; // ecx
  int v7; // eax
  char *v8; // edi
  survarium::flash_value *v9; // ecx
  survarium::flash_value *v10; // ecx
  survarium::flash_value *v11; // ecx
  survarium::flash_value *v12; // ecx
  survarium::flash_value *v13; // ecx
  survarium::flash_value *v14; // ecx
  unsigned int v15; // eax
  survarium::flash_value *v16; // [esp-8h] [ebp-6Ch]
  Scaleform::GFx::Value pvalue; // [esp+Ch] [ebp-58h] BYREF
  Scaleform::GFx::Value v18; // [esp+24h] [ebp-40h] BYREF
  survarium::flash_value value; // [esp+3Ch] [ebp-28h] BYREF
  survarium::flash_value *v20; // [esp+54h] [ebp-10h]
  int v21; // [esp+58h] [ebp-Ch]
  unsigned int v22; // [esp+5Ch] [ebp-8h]

  v2 = a2;
  v3 = survarium::lobby_menu::messaging_client(this, a2);
  v4 = *(_DWORD *)(a2 + 1600);
  pvalue.pObjectInterface = 0;
  pvalue.Type = VT_Undefined;
  p_m_friend_list = &v3->m_friend_list;
  Scaleform::GFx::Movie::CreateArray(*(Scaleform::GFx::Movie **)(*(_DWORD *)(v4 + 264) + 4), &pvalue);
  *(_DWORD *)value.body = 0;
  *(_DWORD *)&value.body[4] = 0;
  M_start = (survarium::flash_movie *)p_m_friend_list->_M_impl._M_start;
  v7 = (char *)p_m_friend_list->_M_impl._M_finish - (char *)p_m_friend_list->_M_impl._M_start;
  v22 = 0;
  if ( v7 / 72 )
  {
    v21 = 0;
    do
    {
      v18.pObjectInterface = 0;
      v18.Type = VT_Undefined;
      v8 = (char *)M_start + v21;
      v16 = *(survarium::flash_value **)(*(_DWORD *)(v2 + 1600) + 264);
      v20 = (survarium::flash_value *)((char *)M_start + v21);
      survarium::flash_movie::CreateObject(M_start, v16, &v18);
      survarium::flash_value::SetUInt(v9, (int)&value, *(_DWORD *)v8);
      survarium::flash_value::SetMember(v10, &v18, "id", &value);
      survarium::flash_value::SetString(&value, v8 + 4);
      survarium::flash_value::SetMember(v11, &v18, "name", &value);
      survarium::flash_value::SetUInt(v12, (int)&value, 3u);
      survarium::flash_value::SetMember(v13, &v18, "icon", &value);
      survarium::flash_value::SetUInt(v20, (int)&value, v20[2].body[20] != 0 ? 0 : 2);
      survarium::flash_value::SetMember(v14, &v18, "status", &value);
      pvalue.pObjectInterface->SetElement(pvalue.pObjectInterface, (void *)pvalue.mValue.IValue, v22, &v18);
      Scaleform::GFx::Value::~Value(&v18);
      M_start = (survarium::flash_movie *)p_m_friend_list->_M_impl._M_start;
      v15 = p_m_friend_list->_M_impl._M_finish - p_m_friend_list->_M_impl._M_start;
      ++v22;
      v21 += 72;
      v2 = a2;
    }
    while ( v22 < v15 );
  }
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(v2 + 1600) + 264) + 4),
    "root.set_friends_list",
    0,
    &pvalue,
    1u);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&value);
  Scaleform::GFx::Value::~Value(&pvalue);
}
