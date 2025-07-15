void __thiscall survarium::artefact_container_core::serialize(
        survarium::artefact_container_core *this,
        vostok::network_core::buffer_writer *writer,
        unsigned int time_offset)
{
  vostok::network_core::buffer_writer *v4; // ecx
  unsigned __int8 *m_end; // esi
  unsigned __int8 v6; // al
  unsigned int v7; // [esp+0h] [ebp-8h]
  unsigned __int8 v8; // [esp+7h] [ebp-1h] BYREF

  survarium::usable_object::serialize_usable_object(
    this,
    (int)this[-1].m_deserialized_users.m_buffer[12].m_store,
    writer,
    v7);
  m_end = this->m_deserialized_users.m_end;
  if ( m_end
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v6 = m_end[298];
  }
  else
  {
    v6 = -1;
  }
  v8 = v6;
  vostok::network_core::buffer_writer::w<unsigned char>(
    &v8,
    v4,
    writer,
    ".\\artefact_container_core.cpp",
    (const char *)0x26,
    "survarium::artefact_container_core::serialize",
    "m_artefact ? m_artefact->id() : artefact_base::id_type( artefact_base::invalid_id )");
}
