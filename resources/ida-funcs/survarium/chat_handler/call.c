void __thiscall survarium::chat_handler::call(
        survarium::chat_handler *this,
        survarium::flash_function_handler_params *params)
{
  survarium::flash_value *pArgs; // eax
  const wchar_t *v4; // edi
  wchar_t *v5; // ebx
  survarium::messaging_client *v6; // eax
  survarium::flash_value w_text; // [esp+10h] [ebp-18h] BYREF

  pArgs = params->pArgs;
  *(_DWORD *)w_text.body = 0;
  *(_DWORD *)&w_text.body[4] = 135;
  (*(void (__stdcall **)(_DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)pArgs->body + 16))(
    *(_DWORD *)&pArgs->body[8],
    "text",
    &w_text,
    (*(_DWORD *)&pArgs->body[4] & 0x8F) == 10);
  v4 = *(const wchar_t **)&params->pArgs[1].body[8];
  v5 = *(wchar_t **)&w_text.body[8];
  if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)&this->m_focused + 952) + 20))(*(_DWORD *)(*(_DWORD *)&this->m_focused + 952)) )
  {
    v6 = (survarium::messaging_client *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)&this->m_focused + 952)
                                                                      + 68))(*(_DWORD *)(*(_DWORD *)&this->m_focused
                                                                                       + 952));
    survarium::messaging_client::on_message_typed(v5, v6, v4);
  }
  if ( (w_text.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)w_text.body + 8))(
      *(_DWORD *)w_text.body,
      &w_text,
      *(_DWORD *)&w_text.body[8]);
}
