void __thiscall survarium::options_monitor_index_selector::revert(
        survarium::options_monitor_index_selector *this,
        unsigned __int8 a2,
        unsigned __int8 a3)
{
  survarium::game_options *v4; // ecx
  survarium::options_resolution_selector *v5; // [esp-8h] [ebp-Ch]

  this->m_current_value = this->m_source_value;
  survarium::options_item_base::revert(this);
  v5 = (survarium::options_resolution_selector *)*((_DWORD *)this->m_parent_tab->m_options + 1);
  survarium::options_resolution_selector::fill_resolutions(v5, v5, this->m_current_value);
  survarium::game_options::refill_item_data(v4, a2, a3);
}
