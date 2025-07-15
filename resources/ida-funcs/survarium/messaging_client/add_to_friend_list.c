void __userpurge survarium::messaging_client::add_to_friend_list(
        survarium::messaging_client *this@<ecx>,
        int a2@<esi>,
        unsigned int account_id)
{
  survarium::account_list_item *v3; // ebx
  survarium::account_list_item *v4; // eax
  survarium::messaging_client *v5; // [esp-4h] [ebp-Ch]

  if ( *(_DWORD *)(a2 + 136) == 3 )
  {
    v3 = *(survarium::account_list_item **)(a2 + 388);
    v4 = stlp_std::find<survarium::account_list_item *,unsigned int>(
           *(survarium::account_list_item **)(a2 + 384),
           &account_id,
           v3);
    if ( v4 != v3 )
      survarium::messaging_client::send_important_message(
        v5,
        (const char (*)[64])a2,
        (int)v4->account_name,
        0,
        (char *)uri);
  }
}
