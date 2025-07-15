void __userpurge survarium::options_resolution_selector::options_resolution_selector(
        survarium::options_resolution_selector *this@<ecx>,
        _DWORD *a2@<esi>,
        survarium::options_tab *parent_tab)
{
  _DWORD *v3; // ecx
  int v4; // edx
  _BYTE *v5; // eax
  vostok::console_commands::console_command *v6; // eax
  survarium::options_resolution_selector *v7; // [esp-4h] [ebp-Ch]

  survarium::options_item_int::options_item_int(this, (int)a2, parent_tab, "r_resolution", 1u, 0, 0);
  v3 = a2 + 8;
  *a2 = &survarium::options_resolution_selector::`vftable';
  v4 = 511;
  v5 = a2 + 11;
  do
  {
    *v3 = v5;
    *((_DWORD *)v5 - 2) = v5;
    *((_DWORD *)v5 - 1) = v5 + 32;
    *v5 = 0;
    *v5 = 0;
    v3 += 11;
    v5 += 44;
    --v4;
  }
  while ( v4 >= 0 );
  v6 = vostok::console_commands::find("r_monitor_index");
  survarium::options_resolution_selector::fill_resolutions(
    v7,
    (int)a2,
    (unsigned __int8)v6[1].~vostok::console_commands::console_command);
}
