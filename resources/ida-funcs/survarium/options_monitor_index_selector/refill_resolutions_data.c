void __usercall survarium::options_monitor_index_selector::refill_resolutions_data(
        survarium::options_monitor_index_selector *this@<ecx>,
        int a2@<esi>)
{
  survarium::game_options *v2; // ecx

  survarium::options_resolution_selector::fill_resolutions(
    (survarium::options_resolution_selector *)this,
    *(_DWORD *)(**(_DWORD **)(a2 + 16) + 4),
    *(_BYTE *)(a2 + 29));
  survarium::game_options::refill_item_data(v2, *(_DWORD *)(*(_DWORD *)(a2 + 16) + 12) + 15072);
}
