void __thiscall survarium::body_part_parameters::serialize(
        survarium::body_part_parameters *this,
        vostok::network_core::buffer_writer *writer,
        vostok::network_core::buffer_writer *time_offset)
{
  vostok::network_core::buffer_writer *v4; // ecx
  unsigned int m_last_hit_time; // eax
  vostok::network_core::buffer_writer *v6; // ecx
  vostok::network_core::buffer_writer *v7; // ecx
  survarium::serialize_affect_functor v8; // [esp-Ch] [ebp-24h]
  unsigned __int8 v9; // [esp+Fh] [ebp-9h] BYREF
  stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> __last; // [esp+10h] [ebp-8h] BYREF

  vostok::network_core::buffer_writer::w<float>(
    &this->m_health,
    (vostok::network_core::buffer_writer *)this,
    writer,
    ".\\body_part_parameters.cpp",
    (const char *)0x280,
    "survarium::body_part_parameters::serialize",
    "m_health");
  m_last_hit_time = this->m_last_hit_time;
  if ( m_last_hit_time )
  {
    v4 = time_offset;
    __last.first = (survarium::hit_affects_type_enum)((char *)time_offset + m_last_hit_time);
  }
  else
  {
    __last.first = affects_type_death;
  }
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&__last,
    v4,
    writer,
    ".\\body_part_parameters.cpp",
    (const char *)0x281,
    "survarium::body_part_parameters::serialize",
    "m_last_hit_time ? m_last_hit_time + time_offset : 0");
  v9 = this->m_affects.m_end - this->m_affects.m_begin;
  vostok::network_core::buffer_writer::w<unsigned char>(
    &v9,
    v6,
    writer,
    ".\\body_part_parameters.cpp",
    (const char *)0x282,
    "survarium::body_part_parameters::serialize",
    "static_cast< u8 > ( m_affects.size() )");
  v8.time_offset = (unsigned int)writer;
  v8.writer = (const vostok::network_core::buffer_writer *)this->m_affects.m_end;
  stlp_std::for_each<stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> const *,survarium::serialize_affect_functor>(
    this->m_affects.m_begin,
    v7,
    (survarium::serialize_affect_functor *)&__last,
    v8,
    (unsigned int)time_offset);
}
