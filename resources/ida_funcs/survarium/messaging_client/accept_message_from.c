bool __userpurge survarium::messaging_client::accept_message_from@<al>(
        survarium::messaging_client *this@<ecx>,
        int a2@<eax>,
        unsigned int sender_account_id,
        messaging::client_type_enum sender_type)
{
  survarium::account_list_item *v4; // esi
  bool result; // al

  result = 1;
  if ( sender_type == account_client_type )
  {
    v4 = *(survarium::account_list_item **)(a2 + 340);
    if ( stlp_std::priv::__find<survarium::account_list_item *,unsigned int>(
           *(survarium::account_list_item **)(a2 + 336),
           v4,
           &sender_account_id) != v4 )
      return 0;
  }
  return result;
}
