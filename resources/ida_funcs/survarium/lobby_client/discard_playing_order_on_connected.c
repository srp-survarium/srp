void __usercall survarium::lobby_client::discard_playing_order_on_connected(
        survarium::lobby_client *this@<ecx>,
        int a2@<eax>)
{
  *(_BYTE *)(a2 + 2156) = 1;
}
