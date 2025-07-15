void __thiscall survarium::game_statistics_handler::serialize(
        survarium::game_statistics_handler *this,
        const vostok::network_core::buffer_writer *writer,
        unsigned int time_offset)
{
  survarium::shared_statistics::serialize((survarium::shared_statistics *)this, writer, time_offset);
}
