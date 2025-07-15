void __thiscall survarium::options_item_bool::scaleform_call(
        survarium::options_item_bool *this,
        survarium::flash_function_handler_params *params)
{
  char v2; // al

  v2 = params->pArgs->body[8];
  this->m_current_value = v2;
  survarium::flash_value::SetBoolean((survarium::flash_value *)this, (int)params->pRetVal->body, v2);
}
