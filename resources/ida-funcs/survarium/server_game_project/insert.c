void __thiscall survarium::server_game_project::insert(
        survarium::server_game_project *this,
        vostok::physics::world *world,
        survarium::game_world_core *game_world_core)
{
  int v4; // esi
  int v5; // eax
  int v6; // ecx
  survarium::collision_sensor *v7; // ecx
  survarium::damage_zone_core *m_object; // edi
  int v9; // edi
  char *v10; // esi
  int v11; // edi
  survarium::game_world_core *v12; // esi
  survarium::generic_anomaly_core *v13; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::static_collision,vostok::physics::world *>,boost::_bi::list2<boost::arg<1>,boost::_bi::value<vostok::physics::world *> > > v14; // [esp-8h] [ebp-20h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::static_collision,vostok::physics::world *>,boost::_bi::list2<boost::arg<1>,boost::_bi::value<vostok::physics::world *> > > v15; // [esp+10h] [ebp-8h] BYREF

  v4 = 0;
  v5 = 0;
  if ( this->m_artefact_containers_count )
  {
    v6 = 0;
    do
    {
      this->m_artefact_containers[v6].m_game_world_core = game_world_core;
      ++v5;
      ++v6;
    }
    while ( v5 != this->m_artefact_containers_count );
  }
  v14.l_.a2_.t_ = world;
  v14.f_.f_ = (void (__thiscall *)(survarium::static_collision *, vostok::physics::world *))survarium::static_collision::insert;
  stlp_std::for_each<survarium::static_collision *,boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::static_collision,vostok::physics::world *>,boost::_bi::list2<boost::arg<1>,boost::_bi::value<vostok::physics::world *>>>>(
    this->m_static_collision_objects,
    &v15,
    &this->m_static_collision_objects[this->m_static_collision_objects_count],
    v14);
  if ( this->m_damage_zones_count )
  {
    do
    {
      m_object = this->m_damage_zones[v4].m_object;
      if ( !m_object->m_owner )
      {
        survarium::damage_zone_core::activate(m_object, world, v7, 1);
        survarium::game_world_core::register_serializable_object(
          game_world_core,
          &m_object->survarium::serializable_object);
        survarium::game_world_core::register_tickable_object(
          (survarium::game_world_core *)&m_object->survarium::tickable_object,
          (int)game_world_core);
      }
      ++v4;
    }
    while ( v4 != this->m_damage_zones_count );
  }
  v9 = 0;
  if ( this->m_effect_zones_count )
  {
    v15.f_.f_ = 0;
    do
    {
      v10 = (char *)v15.f_.f_ + (unsigned int)this->m_effect_zones;
      *((_DWORD *)v10 + 14) = world;
      survarium::collision_sensor::insert(v7, (int)v10, world);
      (*(void (__thiscall **)(char *, int))(*(_DWORD *)v10 + 44))(v10, 1);
      survarium::game_world_core::register_serializable_object(
        game_world_core,
        (survarium::serializable_object *)(v10 + 44));
      survarium::game_world_core::register_tickable_object(
        (survarium::game_world_core *)(v10 + 32),
        (int)game_world_core);
      v15.f_.f_ = (void (__thiscall *)(survarium::static_collision *, vostok::physics::world *))((char *)v15.f_.f_ + 76);
      ++v9;
    }
    while ( v9 != this->m_effect_zones_count );
  }
  v11 = 0;
  if ( this->m_anomalies_count )
  {
    do
    {
      v12 = (survarium::game_world_core *)this->m_anomalies[v11].m_object;
      (*(void (__thiscall **)(survarium::game_world_core *, vostok::physics::world *))(v12->m_game_events_history.m_items.m_size
                                                                                     + 8))(
        v12,
        world);
      survarium::game_world_core::register_serializable_object(
        game_world_core,
        (survarium::serializable_object *)&v12->m_game_events_history.m_allocator.m_buffer[212]);
      survarium::game_world_core::register_tickable_object(
        (survarium::game_world_core *)&v12->m_game_events_history.m_allocator.m_buffer[200],
        (int)game_world_core);
      survarium::generic_anomaly_core::register_artefacts(v13, v12, (int)game_world_core);
      ++v11;
    }
    while ( v11 != this->m_anomalies_count );
  }
}
