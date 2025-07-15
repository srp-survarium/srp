void __userpurge survarium::game_options::game_options(
        survarium::game_options *this@<ecx>,
        _DWORD *a2@<edi>,
        survarium::game *g)
{
  vostok::render::enum_uro_geometry_quality_values *p_geometry_quality_option; // ecx
  unsigned __int8 *p_option_value; // eax
  int v5; // esi
  unsigned __int8 v6; // dl

  survarium::flash_external_handler::flash_external_handler((survarium::flash_external_handler *)this, a2 + 1);
  a2[1] = &survarium::game_options::`vftable'{for `survarium::flash_external_handler'};
  *a2 = &survarium::game_options::`vftable'{for `vostok::input::handler'};
  a2[3] = 0;
  a2[4] = 0;
  a2[9] = 0;
  a2[10] = 0;
  a2[11] = 0;
  a2[13] = g;
  a2[15] = 72;
  p_geometry_quality_option = &vostok::render::g_graphics_presets[0].geometry_quality_option;
  p_option_value = &survarium::g_graphic_presets[0][0].option_value;
  v5 = 5;
  do
  {
    *p_option_value = *((_BYTE *)p_geometry_quality_option - 4);
    p_option_value[8] = *(_BYTE *)p_geometry_quality_option;
    p_option_value[16] = *((_BYTE *)p_geometry_quality_option + 4);
    p_option_value[24] = *((_BYTE *)p_geometry_quality_option + 8);
    p_option_value[32] = *((_BYTE *)p_geometry_quality_option + 12);
    p_option_value[40] = *((_BYTE *)p_geometry_quality_option + 16);
    p_option_value[48] = *((_BYTE *)p_geometry_quality_option + 20);
    p_option_value[56] = *((_BYTE *)p_geometry_quality_option + 24);
    p_option_value[64] = *((_BYTE *)p_geometry_quality_option + 28);
    v6 = *((_BYTE *)p_geometry_quality_option + 32);
    *((_DWORD *)p_option_value - 1) = 9;
    *((_DWORD *)p_option_value + 1) = 10;
    *((_DWORD *)p_option_value + 3) = 11;
    *((_DWORD *)p_option_value + 5) = 12;
    *((_DWORD *)p_option_value + 7) = 13;
    *((_DWORD *)p_option_value + 9) = 14;
    *((_DWORD *)p_option_value + 11) = 15;
    *((_DWORD *)p_option_value + 13) = 16;
    *((_DWORD *)p_option_value + 15) = 17;
    *((_DWORD *)p_option_value + 17) = 18;
    p_option_value[72] = v6;
    p_geometry_quality_option += 10;
    p_option_value += 80;
    --v5;
  }
  while ( v5 );
}
