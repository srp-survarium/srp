void __thiscall survarium::booby_trap_core::serialize(
        survarium::booby_trap_core *this,
        vostok::network_core::buffer_writer *writer,
        unsigned int time_offset)
{
  vostok::network_core::buffer_writer *v4; // ecx
  vostok::network_core::buffer_writer *v5; // ecx
  vostok::network_core::buffer_writer *v6; // ecx
  survarium::usable_object *v7; // ecx
  const char *v8; // [esp+0h] [ebp-18h]
  unsigned int v9; // [esp+0h] [ebp-18h]
  unsigned __int8 m_class_id; // [esp+13h] [ebp-5h] BYREF
  char *v11; // [esp+14h] [ebp-4h] BYREF

  m_class_id = this->m_class_id;
  vostok::network_core::buffer_writer::w<unsigned char>(
    &m_class_id,
    (vostok::network_core::buffer_writer *)this,
    writer,
    ".\\booby_trap_core.cpp",
    (const char *)0x193,
    "survarium::booby_trap_core::serialize",
    "static_cast< u8 > ( m_trap_state )");
  if ( this->m_class_id )
  {
    vostok::network_core::buffer_writer::w<vostok::math::float4x4>(
      (vostok::math::float4x4 *)&this->grm_satisfaction_tree_hook.left_,
      v4,
      writer,
      ".\\booby_trap_core.cpp",
      (const char *)0x197,
      "survarium::booby_trap_core::serialize",
      v8);
    vostok::network_core::buffer_writer::w<unsigned int>(
      (unsigned __int8 *)&this->vostok::resources::unmanaged_resource::vostok::resources::unmanaged_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags,
      v5,
      writer,
      ".\\booby_trap_core.cpp",
      (const char *)0x198,
      "survarium::booby_trap_core::serialize",
      "m_state_timer");
    v11 = (char *)this->m_sub_fat.m_object + time_offset;
    vostok::network_core::buffer_writer::w<unsigned int>(
      (unsigned __int8 *)&v11,
      v6,
      writer,
      ".\\booby_trap_core.cpp",
      (const char *)0x19A,
      "survarium::booby_trap_core::serialize",
      "m_deploy_time_in_ms + time_offset");
    if ( this->m_class_id == fs_iterator_class )
      survarium::usable_object::serialize_usable_object(v7, (int)&this[-1].m_transform, writer, v9);
  }
}
