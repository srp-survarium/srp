void __thiscall survarium::shared_statistics::on_victory_item_event_impl(
        survarium::shared_statistics *this,
        unsigned __int8 initiator,
        survarium::match_stats_events_dict_enum event,
        unsigned __int16 count)
{
  survarium::shared_statistics::on_event(this, &this->m_player_stats.elems[initiator], count, event);
}
