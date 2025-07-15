void __thiscall survarium::victory_item_core::serialize(
        survarium::victory_item_core *this,
        vostok::network_core::buffer_writer *writer,
        const vostok::network_core::buffer_writer *client_writer,
        unsigned int time_offset)
{
  vostok::network_core::buffer_writer *v5; // ecx
  survarium::base_player *m_user; // eax
  vostok::network_core::buffer_writer *M_start; // ecx
  vostok::ai::fsm *v8; // ecx
  vostok::network_core::buffer_writer *v9; // ecx
  survarium::usable_object *v10; // ecx
  unsigned int v11; // [esp+0h] [ebp-10h]
  unsigned __int8 id; // [esp+Fh] [ebp-1h] BYREF

  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&this->m_spotted_mask,
    (vostok::network_core::buffer_writer *)this,
    writer,
    ".\\victory_item_core.cpp",
    (const char *)0x18E,
    "survarium::victory_item_core::serialize",
    "m_spotted_mask");
  m_user = this->m_user;
  if ( m_user )
    id = m_user->id;
  else
    id = -1;
  vostok::network_core::buffer_writer::w<unsigned char>(
    &id,
    v5,
    writer,
    ".\\victory_item_core.cpp",
    (const char *)0x18F,
    "survarium::victory_item_core::serialize",
    "u8( m_user ? m_user->id : -1 )");
  if ( this->m_container )
  {
    M_start = (vostok::network_core::buffer_writer *)this->m_game_rule->m_containers._M_impl._M_start;
    id = 0;
    while ( (survarium::victory_items_container_core *)M_start->serialization_operations_descriptors.m_size != this->m_container )
    {
      ++id;
      M_start = (vostok::network_core::buffer_writer *)((char *)M_start + 4);
    }
  }
  else
  {
    id = -1;
  }
  vostok::network_core::buffer_writer::w<unsigned char>(
    &id,
    M_start,
    writer,
    ".\\victory_item_core.cpp",
    (const char *)0x190,
    "survarium::victory_item_core::serialize",
    "u8( m_container ? m_game_rule->get_container_id( m_container ) : -1 )");
  if ( this->m_user )
  {
    vostok::ai::fsm::serialize(v8, (int)&this->m_logic, writer, client_writer);
    this->m_portable_interactive_object->serialize(
      this->m_portable_interactive_object,
      writer,
      client_writer,
      time_offset);
  }
  else if ( !this->m_container )
  {
    vostok::network_core::buffer_writer::w<vostok::math::float3>(
      &this->m_position,
      (vostok::network_core::buffer_writer *)v8,
      writer,
      ".\\victory_item_core.cpp",
      (const char *)0x19C,
      "survarium::victory_item_core::serialize",
      "m_position");
    vostok::network_core::buffer_writer::w<float>(
      &this->m_orientation,
      v9,
      writer,
      ".\\victory_item_core.cpp",
      (const char *)0x19D,
      "survarium::victory_item_core::serialize",
      "m_orientation");
    survarium::usable_object::serialize_usable_object(v10, (int)&this->survarium::usable_object, writer, v11);
  }
}
