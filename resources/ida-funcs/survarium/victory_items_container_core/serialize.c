void __userpurge survarium::victory_items_container_core::serialize(
        survarium::victory_items_container_core *this@<ecx>,
        _DWORD *a2@<esi>,
        vostok::network_core::buffer_writer *writer,
        const unsigned int time_offset)
{
  vostok::network_core::buffer_writer *v4; // ecx
  survarium::gather_victory_items_rule *v5; // ecx
  const survarium::victory_item_core *const *v6; // edi
  vostok::network_core::buffer_writer *v7; // ecx
  unsigned int v8; // [esp+0h] [ebp-10h]
  int i; // [esp+8h] [ebp-8h] BYREF
  unsigned __int8 victory_item_id; // [esp+Fh] [ebp-1h] BYREF

  survarium::usable_object::serialize_usable_object(this, (int)a2, writer, v8);
  i = (a2[85] - a2[84]) >> 2;
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&i,
    v4,
    writer,
    ".\\victory_items_container_core.cpp",
    (const char *)0x6C,
    "survarium::victory_items_container_core::serialize",
    "m_victory_items.size()");
  v6 = (const survarium::victory_item_core *const *)a2[84];
  for ( i = a2[85]; v6 != (const survarium::victory_item_core *const *)i; ++v6 )
  {
    victory_item_id = survarium::gather_victory_items_rule::get_victory_item_id(v5, a2[90], *v6);
    vostok::network_core::buffer_writer::w<unsigned char>(
      &victory_item_id,
      v7,
      writer,
      ".\\victory_items_container_core.cpp",
      (const char *)0x6E,
      "survarium::victory_items_container_core::serialize",
      "m_game_rule.get_victory_item_id( *i )");
  }
}
