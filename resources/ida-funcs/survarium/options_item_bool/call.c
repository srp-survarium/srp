void __thiscall survarium::options_item_bool::call(
        survarium::options_item_bool *this,
        survarium::flash_function_handler_params *params)
{
  char v2; // bl
  survarium::flash_value *pRetVal; // esi

  v2 = params->pArgs->body[8];
  this->m_current_value = v2;
  pRetVal = params->pRetVal;
  if ( (*(_DWORD *)&params->pRetVal->body[4] & 0x40) != 0 )
  {
    (*(void (__stdcall **)(survarium::flash_value *, _DWORD))(**(_DWORD **)pRetVal->body + 8))(
      pRetVal,
      *(_DWORD *)&pRetVal->body[8]);
    *(_DWORD *)pRetVal->body = 0;
  }
  pRetVal->body[8] = v2;
  *(_DWORD *)&pRetVal->body[4] = 2;
}
