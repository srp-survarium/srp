void __userpurge survarium::shared_statistics::on_victory_item_event(
        survarium::shared_statistics *this@<ecx>,
        int a2@<eax>,
        int player_id,
        survarium::victory_item_event_type event,
        const survarium::victory_item_core *item)
{
  _BYTE *v5; // ecx
  _BYTE *v6; // ecx

  if ( event )
  {
    if ( event == victory_item_stolen )
    {
      v6 = (_BYTE *)((*(_DWORD *)(1488 * (unsigned __int8)player_id + *(_DWORD *)(a2 + 6140) + 440) == 0) + a2 + 6144);
      --*v6;
    }
  }
  else
  {
    v5 = (_BYTE *)(*(_DWORD *)(1488 * (unsigned __int8)player_id + *(_DWORD *)(a2 + 6140) + 440) + a2 + 6144);
    ++*v5;
  }
  survarium::victory_item_event_manager::on_event(
    (survarium::victory_item_event_manager *)(a2 + 5080),
    item,
    player_id,
    event);
}
