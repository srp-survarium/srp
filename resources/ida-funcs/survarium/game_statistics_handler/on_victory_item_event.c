void __thiscall survarium::game_statistics_handler::on_victory_item_event(
        survarium::game_statistics_handler *this,
        unsigned __int8 player_id,
        survarium::victory_item_event_type event,
        const survarium::victory_item_core *item)
{
  survarium::shared_statistics::on_victory_item_event((survarium::shared_statistics *)this, player_id, event, item);
}
