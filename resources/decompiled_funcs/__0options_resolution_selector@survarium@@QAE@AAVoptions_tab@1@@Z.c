void __usercall survarium::options_resolution_selector::options_resolution_selector(
        survarium::options_resolution_selector *this@<ecx>,
        survarium::options_tab *parent_tab@<eax>)
{
  vostok::console_commands::console_command *v3; // eax
  survarium::options_resolution_selector *v4; // ecx

  survarium::options_item_base::options_item_base(this, "r_resolution", parent_tab, 1u, string_selector);
  this->m_values = 0;
  this->m_values_count = 0;
  this->__vftable = (survarium::options_resolution_selector_vtbl *)&survarium::options_resolution_selector::`vftable';
  `vector constructor iterator'(
    (char *)this->m_cached_resolutions,
    0x2Cu,
    512,
    (void *(__thiscall *)(void *))vostok::fixed_string<32>::fixed_string<32>);
  v3 = vostok::console_commands::find("r_monitor_index");
  survarium::options_resolution_selector::fill_resolutions(
    v4,
    this,
    (unsigned __int8)v3[1].~vostok::console_commands::console_command);
}
