void __thiscall survarium::game_statistics_handler::on_pain_body_part_regenerated(
        survarium::game_statistics_handler *this,
        unsigned __int8 receiver)
{
  survarium::shared_statistics::reset_received_damage(receiver, &this->m_shared_statistics);
}
