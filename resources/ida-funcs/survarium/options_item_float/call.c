void __thiscall survarium::options_item_float::call(
        survarium::options_item_float *this,
        survarium::flash_function_handler_params *params)
{
  survarium::flash_value *pRetVal; // esi
  float v3; // xmm0_4

  pRetVal = params->pRetVal;
  v3 = *(double *)&params->pArgs->body[8];
  this->m_current_value = v3;
  if ( (*(_DWORD *)&pRetVal->body[4] & 0x40) != 0 )
  {
    (*(void (__stdcall **)(survarium::flash_value *, _DWORD))(**(_DWORD **)pRetVal->body + 8))(
      pRetVal,
      *(_DWORD *)&pRetVal->body[8]);
    *(_DWORD *)pRetVal->body = 0;
  }
  *(_DWORD *)&pRetVal->body[4] = 5;
  *(double *)&pRetVal->body[8] = v3;
}
