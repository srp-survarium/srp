void __thiscall survarium::zone_group::serialize(
        survarium::zone_group *this,
        vostok::network_core::buffer_writer *writer,
        survarium::zone_group *time_offset)
{
  survarium::zone_group *v3; // esi
  unsigned int m_next_recharge_time; // eax
  int v5; // ecx
  bool *v6; // eax
  vostok::network_core::buffer_writer *v7; // ecx
  vostok::network_core::buffer_writer *v8; // eax
  void **M_start; // edi
  void **M_finish; // esi
  unsigned __int8 v11; // [esp+13h] [ebp-5h] BYREF
  bool *v12; // [esp+14h] [ebp-4h] BYREF

  v3 = this;
  if ( !this->keep_all_zones_active )
  {
    m_next_recharge_time = this->m_next_recharge_time;
    if ( m_next_recharge_time )
    {
      this = time_offset;
      v12 = &time_offset->enabled + m_next_recharge_time;
    }
    else
    {
      v12 = 0;
    }
    vostok::network_core::buffer_writer::w<unsigned int>(
      (unsigned __int8 *)&v12,
      (vostok::network_core::buffer_writer *)this,
      writer,
      ".\\generic_anomaly_core.cpp",
      (const char *)0xAC,
      "survarium::zone_group::serialize",
      "m_next_recharge_time ? m_next_recharge_time + time_offset : 0");
    v5 = (char *)v3->zones._M_impl._M_finish - (char *)v3->zones._M_impl._M_start;
    v6 = 0;
    v11 = 0;
    if ( (v5 & 0xFFFFFFFC) != 0 )
    {
      do
      {
        v7 = (vostok::network_core::buffer_writer *)v3->zones._M_impl._M_start[(_DWORD)v6];
        if ( v7[12].serialization_operations_descriptors.gap4 )
        {
          v7 = (vostok::network_core::buffer_writer *)((unsigned __int8)v6 & 7);
          v11 |= 1 << (char)v7;
        }
        v8 = (vostok::network_core::buffer_writer *)(v6 + 1);
        v12 = (bool *)v8;
        if ( ((unsigned __int8)v8 & 7) == 0
          || (v7 = (vostok::network_core::buffer_writer *)(v3->zones._M_impl._M_finish - v3->zones._M_impl._M_start),
              v8 == v7) )
        {
          vostok::network_core::buffer_writer::w<unsigned char>(
            &v11,
            v7,
            writer,
            ".\\generic_anomaly_core.cpp",
            (const char *)0xBB,
            "survarium::zone_group::serialize",
            "current_byte_mask");
          v11 = 0;
        }
        v6 = v12;
      }
      while ( v12 != (bool *)(v3->zones._M_impl._M_finish - v3->zones._M_impl._M_start) );
    }
  }
  M_start = v3->zones._M_impl._M_start;
  M_finish = v3->zones._M_impl._M_finish;
  while ( M_start != M_finish )
  {
    if ( *((_BYTE *)*M_start + 292) )
      (**((void (__thiscall ***)(int, vostok::network_core::buffer_writer *, survarium::zone_group *))*M_start + 82))(
        (int)*M_start + 328,
        writer,
        time_offset);
    ++M_start;
  }
}
