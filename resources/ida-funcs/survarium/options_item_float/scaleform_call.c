void __thiscall survarium::options_item_float::scaleform_call(
        survarium::options_item_float *this,
        survarium::flash_function_handler_params *params)
{
  survarium::flash_value *pRetVal; // esi
  float value; // [esp+10h] [ebp+8h]

  pRetVal = params->pRetVal;
  value = *(double *)&params->pArgs->body[8];
  this->m_current_value = value;
  survarium::flash_value::SetNumber((survarium::flash_value *)this, (int)pRetVal, value);
}
