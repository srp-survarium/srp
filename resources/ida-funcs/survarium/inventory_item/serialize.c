void __thiscall survarium::inventory_item::serialize(
        survarium::inventory_item *this,
        vostok::network_core::buffer_writer *writer,
        const vostok::network_core::buffer_writer *client_writer,
        const unsigned int time_offset)
{
  vostok::network_core::buffer_writer *v5; // ecx
  survarium::inventory *m_inventory; // eax
  vostok::network_core::buffer_writer *v7; // ecx
  unsigned __int8 id; // [esp+Fh] [ebp-1h] BYREF

  vostok::network_core::buffer_writer::w<unsigned short>(
    (unsigned __int8 *)&this->m_amount,
    (vostok::network_core::buffer_writer *)this,
    writer,
    ".\\inventory_item.cpp",
    (const char *)0x31,
    "survarium::inventory_item::serialize",
    "m_amount");
  m_inventory = this->m_inventory;
  if ( m_inventory )
    id = m_inventory->m_holder->cast_to_base_player(m_inventory->m_holder)->id;
  else
    id = -1;
  vostok::network_core::buffer_writer::w<unsigned char>(
    &id,
    v5,
    writer,
    ".\\inventory_item.cpp",
    (const char *)0x33,
    "survarium::inventory_item::serialize",
    "static_cast< u8 >( player_id )");
  if ( this->m_inventory )
  {
    id = this->m_slot_id;
    vostok::network_core::buffer_writer::w<unsigned char>(
      &id,
      v7,
      writer,
      ".\\inventory_item.cpp",
      (const char *)0x35,
      "survarium::inventory_item::serialize",
      "static_cast< u8 >( m_slot_id )");
  }
}
