void __thiscall survarium::options_monitor_index_selector::scaleform_call(
        survarium::options_monitor_index_selector *this,
        survarium::flash_function_handler_params *params)
{
  survarium::options_monitor_index_selector *v3; // ecx

  survarium::options_item_int::scaleform_call(this, params);
  survarium::options_monitor_index_selector::refill_resolutions_data(v3, (int)this);
}
