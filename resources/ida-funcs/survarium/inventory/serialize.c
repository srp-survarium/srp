void __userpurge survarium::inventory::serialize(
        survarium::inventory *this@<ecx>,
        int a2@<eax>,
        vostok::network_core::buffer_writer *writer,
        const vostok::network_core::buffer_writer *client_writer,
        unsigned int time_offset)
{
  vostok::network_core::buffer_writer *v6; // ecx
  vostok::network_core::buffer_writer *v7; // ecx
  int v8; // eax
  unsigned __int8 v9; // al
  vostok::network_core::buffer_writer *v10; // ecx
  vostok::network_core::buffer_writer *v11; // ecx
  bool v12; // zf
  vostok::network_core::buffer_writer *v13; // ecx
  unsigned int *v14; // eax
  unsigned int v15; // eax
  unsigned __int8 v16; // al
  _BYTE **v17; // esi
  int v18; // edi
  _BYTE *v19; // ecx
  unsigned __int8 v20; // [esp+12h] [ebp-2h] BYREF
  unsigned __int8 v21; // [esp+13h] [ebp-1h] BYREF

  vostok::network_core::buffer_writer::w<float>(
    (float *)(a2 + 392),
    (vostok::network_core::buffer_writer *)this,
    writer,
    ".\\inventory.cpp",
    (const char *)0x155,
    "survarium::inventory::serialize",
    "m_carried_weight");
  vostok::network_core::buffer_writer::w<bool>(
    (const bool *)(a2 + 396),
    v6,
    writer,
    ".\\inventory.cpp",
    (const char *)0x156,
    "survarium::inventory::serialize",
    "m_need_to_recalculate_weight");
  v8 = *(_DWORD *)(a2 + 380);
  if ( v8 )
    v9 = *(_BYTE *)(v8 + 12);
  else
    v9 = -1;
  v21 = v9;
  vostok::network_core::buffer_writer::w<unsigned char>(
    &v21,
    v7,
    writer,
    ".\\inventory.cpp",
    (const char *)0x158,
    "survarium::inventory::serialize",
    "m_carried_item ? m_carried_item->id() : u8( -1 )");
  if ( *(_DWORD *)(a2 + 380) )
    (*(void (__thiscall **)(_DWORD, vostok::network_core::buffer_writer *, const vostok::network_core::buffer_writer *, unsigned int))(**(_DWORD **)(a2 + 380) + 72))(
      *(_DWORD *)(a2 + 380),
      writer,
      client_writer,
      time_offset);
  vostok::network_core::buffer_writer::w<unsigned char>(
    (unsigned __int8 *)(a2 + 368),
    v10,
    writer,
    ".\\inventory.cpp",
    (const char *)0x15C,
    "survarium::inventory::serialize",
    "m_artefact_slots_count");
  if ( *(_BYTE *)(a2 + 368) )
  {
    v21 = (*(_DWORD *)(a2 + 364) - a2 - 272) >> 2;
    vostok::network_core::buffer_writer::w<unsigned char>(
      &v21,
      v11,
      writer,
      ".\\inventory.cpp",
      (const char *)0x160,
      "survarium::inventory::serialize",
      "slots_begin");
    v12 = *(_BYTE *)(a2 + 368) == 0;
    v21 = 0;
    if ( !v12 )
    {
      do
      {
        v13 = *(vostok::network_core::buffer_writer **)(a2 + 364);
        v14 = &v13->serialization_operations_descriptors.m_size + v21;
        if ( *v14
          && (v13 = (vostok::network_core::buffer_writer *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) != 0 )
        {
          v15 = *v14;
        }
        else
        {
          v15 = 0;
        }
        if ( v15 )
          v16 = *(_BYTE *)(v15 + 298);
        else
          v16 = -1;
        v20 = v16;
        vostok::network_core::buffer_writer::w<unsigned char>(
          &v20,
          v13,
          writer,
          ".\\inventory.cpp",
          (const char *)0x164,
          "survarium::inventory::serialize",
          "art ? art->id() : artefact_base::id_type( artefact_base::invalid_id )");
        ++v21;
      }
      while ( v21 < *(_BYTE *)(a2 + 368) );
    }
  }
  v20 = *(_BYTE *)(a2 + 372);
  vostok::network_core::buffer_writer::w<unsigned char>(
    &v20,
    v11,
    writer,
    ".\\inventory.cpp",
    (const char *)0x168,
    "survarium::inventory::serialize",
    "static_cast< u8 >( m_active_slot )");
  v17 = (_BYTE **)(a2 + 272);
  v18 = 23;
  do
  {
    v19 = *v17;
    if ( *v17
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      if ( v19[284] )
        (*(void (__thiscall **)(_BYTE *, vostok::network_core::buffer_writer *, const vostok::network_core::buffer_writer *, unsigned int))(*(_DWORD *)v19 + 84))(
          v19,
          writer,
          client_writer,
          time_offset);
    }
    ++v17;
    --v18;
  }
  while ( v18 );
}
