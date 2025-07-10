void __thiscall survarium::options_graphics_quality_selector::call(
        survarium::options_graphics_quality_selector *this,
        survarium::flash_function_handler_params *params)
{
  survarium::graphic_preset *v3; // edi
  survarium::flash_value *v4; // eax
  int i; // ecx
  survarium::video_options_enum option_id; // esi
  int option_value; // esi
  survarium::options_tab *m_parent_tab; // ecx
  char *v9; // esi
  int j; // edi
  int v11; // edx
  int v12; // [esp+28h] [ebp-68h]
  survarium::flash_value new_resolution_data[4]; // [esp+2Ch] [ebp-64h] BYREF
  char v14; // [esp+8Ch] [ebp-4h] BYREF
  survarium::flash_function_handler_params *paramsa; // [esp+94h] [ebp+4h]

  survarium::options_item_int::call(this, params);
  if ( this->m_current_value != this->m_values_count - 1 )
  {
    paramsa = 0;
    v12 = 10;
    do
    {
      v3 = &survarium::g_graphic_presets[0][(int)paramsa + 10 * this->m_current_value];
      v4 = new_resolution_data;
      for ( i = 3; i >= 0; --i )
      {
        if ( v4 )
        {
          *(_DWORD *)v4->body = 0;
          *(_DWORD *)&v4->body[4] = 0;
        }
        ++v4;
      }
      if ( (new_resolution_data[0].body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)new_resolution_data[0].body + 8))(
          *(_DWORD *)new_resolution_data[0].body,
          new_resolution_data,
          *(_DWORD *)&new_resolution_data[0].body[8]);
        *(_DWORD *)new_resolution_data[0].body = 0;
      }
      option_id = v3->option_id;
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
      *(_DWORD *)&new_resolution_data[1].body[8] = option_id;
      option_value = v3->option_value;
      *(_DWORD *)&new_resolution_data[1].body[4] = 4;
      if ( (new_resolution_data[2].body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)new_resolution_data[2].body + 8))(
          *(_DWORD *)new_resolution_data[2].body,
          &new_resolution_data[2],
          *(_DWORD *)&new_resolution_data[2].body[8]);
        *(_DWORD *)new_resolution_data[2].body = 0;
      }
      *(_DWORD *)&new_resolution_data[2].body[4] = 4;
      *(_DWORD *)&new_resolution_data[2].body[8] = option_value;
      if ( (new_resolution_data[3].body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)new_resolution_data[3].body + 8))(
          *(_DWORD *)new_resolution_data[3].body,
          &new_resolution_data[3],
          *(_DWORD *)&new_resolution_data[3].body[8]);
        *(_DWORD *)new_resolution_data[3].body = 0;
      }
      m_parent_tab = this->m_parent_tab;
      *(_DWORD *)&new_resolution_data[3].body[4] = 4;
      *(_DWORD *)&new_resolution_data[3].body[8] = 0;
      Scaleform::GFx::Movie::Invoke(
        m_parent_tab->m_movie->m_object->movie->m_movie,
        "root.set_value",
        0,
        (const Scaleform::GFx::Value *)new_resolution_data,
        4u);
      v9 = &v14;
      for ( j = 3; j >= 0; --j )
      {
        v11 = *((_DWORD *)v9 - 5);
        v9 -= 24;
        if ( (v11 & 0x40) != 0 )
        {
          (*(void (__stdcall **)(char *, _DWORD))(**(_DWORD **)v9 + 8))(v9, *((_DWORD *)v9 + 2));
          *(_DWORD *)v9 = 0;
        }
        *((_DWORD *)v9 + 1) = 0;
      }
      paramsa = (survarium::flash_function_handler_params *)((char *)paramsa + 1);
      --v12;
    }
    while ( v12 );
  }
}
