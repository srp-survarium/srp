void __thiscall survarium::options_item_int::call(
        survarium::options_item_int *this,
        survarium::flash_function_handler_params *params)
{
  int v3; // edx
  survarium::options_tab *m_parent_tab; // eax
  unsigned __int8 v5; // al
  unsigned __int8 v6; // cl
  int v7; // edi
  int v8; // eax
  bool v9; // zf
  char *v10; // eax
  unsigned __int8 v11; // al
  unsigned __int8 m_values_count; // al
  int m_current_value; // edi
  survarium::flash_value *pRetVal; // esi
  survarium::options_tab *v15; // ecx
  survarium::flash_value new_resolution_data[4]; // [esp+18h] [ebp-60h] BYREF

  v3 = *(_DWORD *)&params->pArgs->body[8];
  m_parent_tab = this->m_parent_tab;
  this->m_current_value = v3;
  if ( m_parent_tab->m_type == video_options_type )
  {
    v5 = *(_BYTE *)(*((_DWORD *)m_parent_tab->m_options + 8) + 29);
    if ( v5 < 5u )
    {
      v6 = 0;
      v7 = 10 * v5;
      while ( 1 )
      {
        v8 = v7 + v6;
        v9 = survarium::g_graphic_presets[0][v8].option_id == this->m_option_item_id;
        v10 = (char *)survarium::g_graphic_presets + 8 * v8;
        if ( v9 )
        {
          v11 = v10[4];
          if ( this->m_values_count > v11 && (_BYTE)v3 != v11 )
            break;
        }
        if ( ++v6 >= 0xAu )
          goto LABEL_8;
      }
      `vector constructor iterator'(
        new_resolution_data[0].body,
        0x18u,
        4,
        (void *(__thiscall *)(void *))survarium::flash_value::flash_value);
      if ( (new_resolution_data[0].body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)new_resolution_data[0].body + 8))(
          *(_DWORD *)new_resolution_data[0].body,
          new_resolution_data,
          *(_DWORD *)&new_resolution_data[0].body[8]);
        *(_DWORD *)new_resolution_data[0].body = 0;
      }
      *(_DWORD *)&new_resolution_data[0].body[4] = 4;
      *(_DWORD *)&new_resolution_data[0].body[8] = 2;
      if ( (new_resolution_data[1].body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)new_resolution_data[1].body + 8))(
          *(_DWORD *)new_resolution_data[1].body,
          &new_resolution_data[1],
          *(_DWORD *)&new_resolution_data[1].body[8]);
        *(_DWORD *)new_resolution_data[1].body = 0;
      }
      *(_DWORD *)&new_resolution_data[1].body[4] = 4;
      *(_DWORD *)&new_resolution_data[1].body[8] = 8;
      if ( (new_resolution_data[2].body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)new_resolution_data[2].body + 8))(
          *(_DWORD *)new_resolution_data[2].body,
          &new_resolution_data[2],
          *(_DWORD *)&new_resolution_data[2].body[8]);
        *(_DWORD *)new_resolution_data[2].body = 0;
      }
      *(_DWORD *)&new_resolution_data[2].body[4] = 4;
      *(_DWORD *)&new_resolution_data[2].body[8] = 5;
      if ( (new_resolution_data[3].body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)new_resolution_data[3].body + 8))(
          *(_DWORD *)new_resolution_data[3].body,
          &new_resolution_data[3],
          *(_DWORD *)&new_resolution_data[3].body[8]);
        *(_DWORD *)new_resolution_data[3].body = 0;
      }
      v15 = this->m_parent_tab;
      *(_DWORD *)&new_resolution_data[3].body[4] = 4;
      *(_DWORD *)&new_resolution_data[3].body[8] = 0;
      Scaleform::GFx::Movie::Invoke(
        v15->m_movie->m_object->movie->m_movie,
        "root.set_value",
        0,
        (const Scaleform::GFx::Value *)new_resolution_data,
        4u);
      `vector destructor iterator'(
        new_resolution_data[0].body,
        0x18u,
        4,
        (void (__thiscall *)(void *))survarium::flash_value::~flash_value);
    }
  }
LABEL_8:
  m_values_count = this->m_values_count;
  if ( this->m_current_value >= m_values_count && m_values_count )
    this->m_current_value = m_values_count - 1;
  m_current_value = this->m_current_value;
  pRetVal = params->pRetVal;
  if ( (*(_DWORD *)&params->pRetVal->body[4] & 0x40) != 0 )
  {
    (*(void (__stdcall **)(survarium::flash_value *, _DWORD))(**(_DWORD **)pRetVal->body + 8))(
      pRetVal,
      *(_DWORD *)&pRetVal->body[8]);
    *(_DWORD *)pRetVal->body = 0;
  }
  *(_DWORD *)&pRetVal->body[8] = m_current_value;
  *(_DWORD *)&pRetVal->body[4] = 4;
}
