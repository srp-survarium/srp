void __userpurge survarium::chat_handler::on_message_typed(
        survarium::chat_handler *this@<ecx>,
        int a2@<esi>,
        wchar_t *text,
        const wchar_t *message_chanel)
{
  survarium::messaging_client *v4; // eax

  if ( (*(unsigned __int8 (__thiscall **)(_DWORD, survarium::chat_handler *))(**(_DWORD **)(*(_DWORD *)(a2 + 24) + 952)
                                                                            + 20))(
         *(_DWORD *)(*(_DWORD *)(a2 + 24) + 952),
         this) )
  {
    v4 = (survarium::messaging_client *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 24) + 952) + 68))(*(_DWORD *)(*(_DWORD *)(a2 + 24) + 952));
    survarium::messaging_client::on_message_typed(text, v4, message_chanel);
  }
}
