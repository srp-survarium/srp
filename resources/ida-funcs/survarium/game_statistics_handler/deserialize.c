void __thiscall survarium::game_statistics_handler::deserialize(
        survarium::game_statistics_handler *this,
        vostok::network_core::buffer_reader *reader,
        unsigned int time_offset)
{
  survarium::game_statistics_handler *v4; // ecx

  survarium::shared_statistics::deserialize(
    (survarium::shared_statistics *)this,
    (int)&this->m_shared_statistics,
    reader,
    time_offset);
  survarium::game_statistics_handler::recalculate_scores(v4, (int)this);
}
