void __thiscall survarium::medkit::deserialize(
        survarium::medkit *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader,
        unsigned int time_offset)
{
  bool v5; // al
  vostok::network_core::buffer_reader *v6; // ecx
  const unsigned __int8 *m_pointer; // esi
  const unsigned __int8 *v8; // esi
  survarium::base_player *v9; // eax
  vostok::threading::mutex *v10; // ecx
  unsigned __int8 i; // dl
  const unsigned __int8 *v12; // esi
  float v13; // xmm0_4
  int v14; // eax
  int v15; // edi
  survarium::medkit::damage_protection *v16; // esi
  const vostok::resources::resource_ptr<survarium::damage_model,vostok::resources::unmanaged_intrusive_base> *v17; // eax
  unsigned __int8 v18; // al
  int v19; // ecx
  vostok::network_core::buffer_reader *readera; // [esp+10h] [ebp+8h]
  vostok::network_core::buffer_reader *client_readera; // [esp+14h] [ebp+Ch]
  vostok::network_core::buffer_reader *client_readerb; // [esp+14h] [ebp+Ch]
  bool time_offset_3; // [esp+1Bh] [ebp+13h]

  survarium::inventory_item::deserialize(&this->survarium::inventory_item, reader, client_reader, time_offset);
  time_offset_3 = this->m_active;
  v5 = vostok::network_core::buffer_reader::r<bool>(reader);
  this->m_active = v5;
  if ( v5 )
  {
    v6 = reader;
    m_pointer = reader->m_pointer;
    client_readera = *(vostok::network_core::buffer_reader **)m_pointer;
    reader->m_pointer = m_pointer + 4;
    this->m_activity_time_ms = (unsigned int)client_readera;
    v8 = reader->m_pointer;
    client_readerb = *(vostok::network_core::buffer_reader **)v8;
    reader->m_pointer = v8 + 4;
    this->m_delay_ms = (unsigned int)client_readerb;
    if ( (double)(unsigned int)client_readerb == 0.0 && this->m_activity_time_ms != this->m_config_activity_time_ms )
    {
      v9 = this->m_inventory->m_holder->cast_to_base_player(this->m_inventory->m_holder);
      vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        (vostok::intrusive_list<survarium::player_params_modifier,survarium::player_params_modifier *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)&(*(survarium::base_player_vtbl **)((char *)&v9->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable + (_DWORD)&loc_11066 + 2))[10].insert,
        &this->m_add_stamina_regen,
        v10);
      v6 = reader;
    }
    for ( i = 0; i < this->m_influences_count; this->m_applied_influence[v14] = v13 )
    {
      v12 = v6->m_pointer;
      v13 = *(float *)v12;
      v6->m_pointer = v12 + 4;
      v14 = i++;
    }
    v15 = 0;
    for ( readera = 0; (unsigned int)readera < this->m_damage_protect_count; ++v15 )
    {
      v16 = &this->m_damage_protect[v15];
      v17 = this->m_inventory->m_holder->damage_model(this->m_inventory->m_holder);
      survarium::damage_model::register_body_part_damage_protector(
        v17->m_object,
        &v16->protector,
        (survarium::damage_model *)v16->body_part_name,
        v16->body_part_name);
      readera = (vostok::network_core::buffer_reader *)((char *)readera + 1);
    }
  }
  if ( time_offset_3 )
  {
    if ( !this->m_active )
    {
      v18 = 0;
      if ( this->m_influences_count )
      {
        do
        {
          v19 = v18++;
          this->m_applied_influence[v19] = 0.0;
        }
        while ( v18 != this->m_influences_count );
      }
      survarium::game_world_core::unregister_tickable_object(this->m_game_world_core, &this->survarium::tickable_object);
    }
  }
  else if ( this->m_active )
  {
    survarium::game_world_core::register_tickable_object(
      (survarium::game_world_core *)&this->survarium::tickable_object,
      (int)this->m_game_world_core);
  }
}
