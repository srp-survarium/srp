void __usercall survarium::options_monitor_index_selector::refill_resolutions_data(
        survarium::options_monitor_index_selector *this@<ecx>,
        int a2@<esi>,
        unsigned __int8 a3,
        unsigned __int8 a4)
{
  survarium::options_resolution_selector::fill_resolutions(
    *(survarium::options_resolution_selector **)(a2 + 16),
    *(survarium::options_resolution_selector **)(**(_DWORD **)(a2 + 16) + 4),
    *(_BYTE *)(a2 + 29));
  survarium::game_options::refill_item_data(*(survarium::game_options **)(a2 + 16), a3, a4);
}
