void __userpurge survarium::chat_handler::on_message_typed(
        survarium::chat_handler *this@<ecx>,
        _DWORD *a2@<esi>,
        char *text,
        vostok::messaging::message_channel_enum message_chanel)
{
  int v4; // eax
  survarium::chat_handler *i; // edi
  survarium::messaging_client *v6; // eax
  survarium::messaging_client *v7; // eax
  _BYTE receiver_name[64]; // [esp+8h] [ebp-58h] BYREF
  Scaleform::GFx::Value presult; // [esp+48h] [ebp-18h] BYREF

  if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(a2[4] + 13912) + 32))(*(_DWORD *)(a2[4] + 13912)) )
  {
    memset(receiver_name, 0, sizeof(receiver_name));
    if ( message_chanel == player_private_channel )
    {
      v4 = a2[5];
      presult.pObjectInterface = 0;
      presult.Type = VT_Undefined;
      Scaleform::GFx::Movie::Invoke(
        *(Scaleform::GFx::Movie **)(*(_DWORD *)(v4 + 264) + 4),
        "root.active_tab_id",
        &presult,
        0,
        0);
      for ( i = (survarium::chat_handler *)a2[7];
            i != (survarium::chat_handler *)a2[8] && i[1].m_last_added_tab_id != presult.mValue.IValue;
            i = (survarium::chat_handler *)((char *)i + 68) )
      {
        ;
      }
      v6 = (survarium::messaging_client *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2[4] + 13912) + 68))(*(_DWORD *)(a2[4] + 13912));
      survarium::messaging_client::on_message_typed(i, 4, v6, text);
      Scaleform::GFx::Value::~Value(&presult);
    }
    else
    {
      v7 = (survarium::messaging_client *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2[4] + 13912) + 68))(*(_DWORD *)(a2[4] + 13912));
      survarium::messaging_client::on_message_typed((survarium::chat_handler *)receiver_name, message_chanel, v7, text);
    }
  }
}
