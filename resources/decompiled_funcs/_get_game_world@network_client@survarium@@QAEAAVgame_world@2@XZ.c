survarium::game_world *__usercall survarium::network_client::get_game_world@<eax>(
        survarium::network_client *this@<ecx>,
        int a2@<eax>)
{
  return (survarium::game_world *)(*(_DWORD *)(a2 + 24) + 152);
}
