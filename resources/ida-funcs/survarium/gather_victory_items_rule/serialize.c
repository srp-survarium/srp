void __thiscall survarium::gather_victory_items_rule::serialize(
        survarium::gather_victory_items_rule *this,
        vostok::network_core::buffer_writer *writer,
        unsigned int time_offset)
{
  vostok::network_core::buffer_writer *v4; // ecx
  vostok::network_core::buffer_writer *v5; // ecx
  int v6; // ecx
  vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base> *M_start; // eax
  int v8; // ecx
  __int16 v9; // dx
  survarium::victory_items_container_core *m_object; // ecx
  vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base> *v11; // edi
  vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base> *M_finish; // ebx
  vostok::resources::resource_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base> *v13; // edi
  vostok::resources::resource_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base> *v14; // ebx
  unsigned int v15; // [esp+0h] [ebp-18h]
  int v16; // [esp+10h] [ebp-8h]
  unsigned int m_seed; // [esp+14h] [ebp-4h] BYREF

  m_seed = this->m_spawner_random.m_seed;
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&m_seed,
    (vostok::network_core::buffer_writer *)this,
    writer,
    ".\\gather_victory_items_rule.cpp",
    (const char *)0x66,
    "survarium::gather_victory_items_rule::serialize",
    "m_spawner_random.seed( )");
  vostok::network_core::buffer_writer::w<unsigned char>(
    this->m_team_points,
    v4,
    writer,
    ".\\gather_victory_items_rule.cpp",
    (const char *)0x67,
    "survarium::gather_victory_items_rule::serialize",
    "m_team_points[0]");
  vostok::network_core::buffer_writer::w<unsigned char>(
    &this->m_team_points[1],
    v5,
    writer,
    ".\\gather_victory_items_rule.cpp",
    (const char *)0x68,
    "survarium::gather_victory_items_rule::serialize",
    "m_team_points[1]");
  M_start = this->m_victory_items._M_impl._M_start;
  m_seed = 0;
  if ( M_start != this->m_victory_items._M_impl._M_finish )
  {
    v16 = 0;
    do
    {
      v8 = v16;
      v9 = M_start->m_object->m_user == 0;
      v16 += 4;
      v6 = v8 >> 2;
      ++M_start;
      LOWORD(m_seed) = (v9 << v6) | m_seed;
    }
    while ( M_start != this->m_victory_items._M_impl._M_finish );
  }
  vostok::network_core::buffer_writer::w<unsigned short>(
    (unsigned __int8 *)&m_seed,
    (vostok::network_core::buffer_writer *)v6,
    writer,
    ".\\gather_victory_items_rule.cpp",
    (const char *)0x6E,
    "survarium::gather_victory_items_rule::serialize",
    "items_mask");
  v11 = this->m_victory_items._M_impl._M_start;
  M_finish = this->m_victory_items._M_impl._M_finish;
  while ( v11 != M_finish )
  {
    m_object = (survarium::victory_items_container_core *)v11->m_object;
    if ( !v11->m_object->m_user )
      ((void (__thiscall *)(survarium::victory_items_container_core *, vostok::network_core::buffer_writer *, _DWORD, unsigned int))m_object->survarium::usable_object::survarium::collision_geometry_subscriber::__vftable[1].use_info)(
        m_object,
        writer,
        0,
        time_offset);
    ++v11;
  }
  v13 = this->m_containers._M_impl._M_start;
  v14 = this->m_containers._M_impl._M_finish;
  while ( v13 != v14 )
  {
    survarium::victory_items_container_core::serialize(m_object, &v13->m_object->__vftable, writer, v15);
    ++v13;
  }
}
