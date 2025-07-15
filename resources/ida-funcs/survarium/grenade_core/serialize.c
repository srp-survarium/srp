void __thiscall survarium::grenade_core::serialize(
        survarium::grenade_core *this,
        vostok::network_core::buffer_writer *writer,
        vostok::network_core::buffer_writer *time_offset)
{
  survarium::grenade_core *v3; // esi
  char v4; // al
  vostok::network_core::buffer_writer *v5; // ecx
  unsigned int m_deallocation_thread_id; // eax
  int v7; // eax
  vostok::network_core::buffer_writer *v8; // ecx
  int v9; // eax
  vostok::network_core::buffer_writer *v10; // ecx
  const char *v11; // [esp+0h] [ebp-20h]
  unsigned __int8 v12; // [esp+Fh] [ebp-11h] BYREF
  char *v13; // [esp+10h] [ebp-10h] BYREF
  vostok::math::float3 v14; // [esp+14h] [ebp-Ch] BYREF

  v3 = this;
  v4 = (this->m_deallocation_thread_id == -1 ? 0 : 2)
     | (LOBYTE(this->vostok::resources::unmanaged_resource::m_flags.vostok::resources::unmanaged_resource::m_flags) == 0
      ? 0
      : 4);
  LOBYTE(this) = *(_DWORD *)&this->m_inlined_in_fat != 0;
  v12 = (unsigned __int8)this | v4;
  vostok::network_core::buffer_writer::w<unsigned char>(
    &v12,
    (vostok::network_core::buffer_writer *)this,
    writer,
    ".\\grenade_core.cpp",
    (const char *)0xAD,
    "survarium::grenade_core::serialize",
    "current_state");
  m_deallocation_thread_id = v3->m_deallocation_thread_id;
  if ( m_deallocation_thread_id != -1 )
  {
    v13 = (char *)time_offset + m_deallocation_thread_id;
    vostok::network_core::buffer_writer::w<unsigned int>(
      (unsigned __int8 *)&v13,
      time_offset,
      writer,
      ".\\grenade_core.cpp",
      (const char *)0xB1,
      "survarium::grenade_core::serialize",
      "m_explode_time_ms+time_offset");
  }
  if ( *(_DWORD *)&v3->m_inlined_in_fat )
  {
    vostok::network_core::buffer_writer::w<vostok::math::float4x4>(
      (vostok::math::float4x4 *)&v3->m_physics_world,
      v5,
      writer,
      ".\\grenade_core.cpp",
      (const char *)0xB6,
      "survarium::grenade_core::serialize",
      v11);
    v7 = *(_DWORD *)(LODWORD(v3->m_render_transform.c.z) + 20) + 320;
    *(_QWORD *)&v14.x = *(_QWORD *)v7;
    LODWORD(v14.z) = *(_DWORD *)(v7 + 8) ^ _mask__NegFloat_;
    vostok::network_core::buffer_writer::w<vostok::math::float3>(
      &v14,
      v8,
      writer,
      ".\\grenade_core.cpp",
      (const char *)0xB9,
      "survarium::grenade_core::serialize",
      "linear_velocity");
    v9 = *(_DWORD *)(LODWORD(v3->m_render_transform.c.z) + 20) + 336;
    *(_QWORD *)&v14.x = *(_QWORD *)v9;
    LODWORD(v14.z) = *(_DWORD *)(v9 + 8) ^ _mask__NegFloat_;
    vostok::network_core::buffer_writer::w<vostok::math::float3>(
      &v14,
      v10,
      writer,
      ".\\grenade_core.cpp",
      (const char *)0xBC,
      "survarium::grenade_core::serialize",
      "angular_velocity");
  }
}
