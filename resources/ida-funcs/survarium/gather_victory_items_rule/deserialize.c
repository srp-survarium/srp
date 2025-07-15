void __thiscall survarium::gather_victory_items_rule::deserialize(
        survarium::gather_victory_items_rule *this,
        vostok::network_core::buffer_reader *reader,
        unsigned int time_offset)
{
  const unsigned __int8 *m_pointer; // esi
  const unsigned __int8 *v5; // esi
  const unsigned __int8 *v6; // esi
  unsigned __int16 v7; // ax
  survarium::gather_victory_items_rule *v8; // esi
  survarium::victory_items_container_core *M_finish; // ecx
  vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base> *M_start; // edi
  survarium::usable_object **p_m_object; // edi
  vostok::resources::resource_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base> *v12; // esi
  survarium::victory_items_container_core *v13; // [esp+Ch] [ebp-8h]
  survarium::victory_items_container_core *v15; // [esp+10h] [ebp-4h]
  vostok::network_core::buffer_reader *v16; // [esp+1Ch] [ebp+8h]
  vostok::network_core::buffer_reader *v17; // [esp+1Ch] [ebp+8h]

  m_pointer = reader->m_pointer;
  v16 = *(vostok::network_core::buffer_reader **)m_pointer;
  reader->m_pointer = m_pointer + 4;
  this->m_spawner_random.m_seed = (unsigned int)v16;
  v5 = reader->m_pointer;
  HIBYTE(v16) = *v5;
  reader->m_pointer = v5 + 1;
  this->m_team_points[0] = HIBYTE(v16);
  v6 = reader->m_pointer;
  HIBYTE(v16) = *v6;
  reader->m_pointer = v6 + 1;
  this->m_team_points[1] = HIBYTE(v16);
  v7 = vostok::network_core::buffer_reader::r<unsigned short>(reader);
  v8 = this;
  M_finish = (survarium::victory_items_container_core *)this->m_victory_items._M_impl._M_finish;
  M_start = this->m_victory_items._M_impl._M_start;
  v13 = M_finish;
  if ( M_start != (vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base> *)M_finish )
  {
    v17 = 0;
    v15 = (survarium::victory_items_container_core *)v7;
    do
    {
      M_finish = v15;
      if ( ((1 << ((int)v17 >> 2)) & (unsigned int)v15) != 0 )
        M_start->m_object->deserialize(&M_start->m_object->survarium::interactive_object, reader, 0, time_offset);
      v17 = (vostok::network_core::buffer_reader *)((char *)v17 + 4);
      ++M_start;
    }
    while ( M_start != (vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base> *)v13 );
  }
  p_m_object = &v8->m_containers._M_impl._M_start->m_object;
  v12 = v8->m_containers._M_impl._M_finish;
  while ( p_m_object != (survarium::usable_object **)v12 )
    survarium::victory_items_container_core::deserialize(M_finish, *p_m_object++, reader);
}
