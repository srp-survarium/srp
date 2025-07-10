void __thiscall survarium::options_item_base::revert(survarium::options_item_base *this)
{
  survarium::flash_value *v2; // eax
  int i; // ecx
  survarium::options_enum m_type; // edi
  int m_option_item_id; // edi
  void (__thiscall *fill_value)(survarium::options_item_base *, survarium::flash_value *); // edx
  survarium::options_tab *m_parent_tab; // ecx
  char *v8; // esi
  int j; // edi
  int v10; // edx
  survarium::flash_value source_data[4]; // [esp+1Ch] [ebp-64h] BYREF
  char v12; // [esp+7Ch] [ebp-4h] BYREF

  v2 = source_data;
  for ( i = 3; i >= 0; --i )
  {
    if ( v2 )
    {
      *(_DWORD *)v2->body = 0;
      *(_DWORD *)&v2->body[4] = 0;
    }
    ++v2;
  }
  m_type = this->m_parent_tab->m_type;
  if ( (source_data[0].body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)source_data[0].body + 8))(
      *(_DWORD *)source_data[0].body,
      source_data,
      *(_DWORD *)&source_data[0].body[8]);
    *(_DWORD *)source_data[0].body = 0;
  }
  *(_DWORD *)&source_data[0].body[8] = m_type;
  m_option_item_id = this->m_option_item_id;
  *(_DWORD *)&source_data[0].body[4] = 4;
  if ( (source_data[1].body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)source_data[1].body + 8))(
      *(_DWORD *)source_data[1].body,
      &source_data[1],
      *(_DWORD *)&source_data[1].body[8]);
    *(_DWORD *)source_data[1].body = 0;
  }
  fill_value = this->fill_value;
  *(_DWORD *)&source_data[1].body[4] = 4;
  *(_DWORD *)&source_data[1].body[8] = m_option_item_id;
  fill_value(this, &source_data[2]);
  if ( (source_data[3].body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)source_data[3].body + 8))(
      *(_DWORD *)source_data[3].body,
      &source_data[3],
      *(_DWORD *)&source_data[3].body[8]);
    *(_DWORD *)source_data[3].body = 0;
  }
  m_parent_tab = this->m_parent_tab;
  *(_DWORD *)&source_data[3].body[4] = 4;
  *(_DWORD *)&source_data[3].body[8] = 1;
  Scaleform::GFx::Movie::Invoke(
    m_parent_tab->m_movie->m_object->movie->m_movie,
    "root.set_value",
    0,
    (const Scaleform::GFx::Value *)source_data,
    4u);
  v8 = &v12;
  for ( j = 3; j >= 0; --j )
  {
    v10 = *((_DWORD *)v8 - 5);
    v8 -= 24;
    if ( (v10 & 0x40) != 0 )
    {
      (*(void (__stdcall **)(char *, _DWORD))(**(_DWORD **)v8 + 8))(v8, *((_DWORD *)v8 + 2));
      *(_DWORD *)v8 = 0;
    }
    *((_DWORD *)v8 + 1) = 0;
  }
}
