void __thiscall survarium::game_options::apply_default_graphic(
        survarium::game_options *this,
        survarium::game_options *thisa)
{
  survarium::graphic_preset *v2; // ebp
  survarium::flash_value *v3; // eax
  int i; // ecx
  survarium::video_options_enum option_id; // esi
  int option_value; // esi
  survarium::flash_movie_resource *m_object; // edx
  char *v8; // esi
  int j; // edi
  int v10; // ecx
  int v11; // [esp+28h] [ebp-68h]
  survarium::flash_value new_resolution_data[4]; // [esp+2Ch] [ebp-64h] BYREF
  char v13; // [esp+8Ch] [ebp-4h] BYREF

  v2 = survarium::default_graphic_preset;
  v11 = 10;
  do
  {
    v3 = new_resolution_data;
    for ( i = 3; i >= 0; --i )
    {
      if ( v3 )
      {
        *(_DWORD *)v3->body = 0;
        *(_DWORD *)&v3->body[4] = 0;
      }
      ++v3;
    }
    if ( (new_resolution_data[0].body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)new_resolution_data[0].body + 8))(
        *(_DWORD *)new_resolution_data[0].body,
        new_resolution_data,
        *(_DWORD *)&new_resolution_data[0].body[8]);
      *(_DWORD *)new_resolution_data[0].body = 0;
    }
    option_id = v2->option_id;
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
    option_value = v2->option_value;
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
    m_object = thisa->m_options_ui.m_object;
    *(_DWORD *)&new_resolution_data[3].body[4] = 4;
    *(_DWORD *)&new_resolution_data[3].body[8] = 0;
    Scaleform::GFx::Movie::Invoke(
      m_object->movie->m_movie,
      "root.set_value",
      0,
      (const Scaleform::GFx::Value *)new_resolution_data,
      4u);
    v8 = &v13;
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
    ++v2;
    --v11;
  }
  while ( v11 );
}
