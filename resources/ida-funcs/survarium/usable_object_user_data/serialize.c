void __fastcall survarium::usable_object_user_data::serialize(
        vostok::network_core::buffer_writer *time_offset,
        int a2,
        survarium::usable_object_user_data *this,
        vostok::network_core::buffer_writer *writer)
{
  survarium::usable_object_user_data *v4; // ebx
  unsigned int start_using_time_ms; // eax
  vostok::network_core::buffer_writer *v6; // ecx

  v4 = this;
  start_using_time_ms = this->start_using_time_ms;
  if ( start_using_time_ms )
    this = (survarium::usable_object_user_data *)((char *)time_offset + start_using_time_ms);
  else
    this = 0;
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&this,
    time_offset,
    writer,
    ".\\collision_user.cpp",
    (const char *)0x10,
    "survarium::usable_object_user_data::serialize",
    "start_using_time_ms ? start_using_time_ms + time_offset : 0");
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&v4->current_progress,
    v6,
    writer,
    ".\\collision_user.cpp",
    (const char *)0x11,
    "survarium::usable_object_user_data::serialize",
    "current_progress");
}
