void __thiscall survarium::options_monitor_index_selector::revert(survarium::options_monitor_index_selector *this)
{
  survarium::options_monitor_index_selector *v2; // ecx

  this->m_current_value = this->m_source_value;
  survarium::options_item_base::revert(this);
  survarium::options_monitor_index_selector::refill_resolutions_data(v2, (int)this);
}
