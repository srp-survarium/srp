void __userpurge survarium::anomaly_state::serialize(
        survarium::anomaly_state *this@<ecx>,
        _DWORD *a2@<eax>,
        vostok::network_core::buffer_writer *writer,
        survarium::zone_group *time_offset)
{
  survarium::zone_group *v4; // ebx
  int v6; // eax
  survarium::zone_group **v7; // edi
  survarium::zone_group **i; // esi

  v4 = time_offset;
  v6 = a2[11];
  if ( v6 )
    time_offset = (survarium::zone_group *)((char *)time_offset + v6);
  else
    time_offset = 0;
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&time_offset,
    (vostok::network_core::buffer_writer *)this,
    writer,
    ".\\generic_anomaly_core.cpp",
    (const char *)0x91,
    "survarium::anomaly_state::serialize",
    "m_finish_time_ms ? m_finish_time_ms + time_offset : 0");
  v7 = (survarium::zone_group **)a2[8];
  for ( i = (survarium::zone_group **)a2[7]; i != v7; ++i )
    survarium::zone_group::serialize(*i, writer, v4);
}
