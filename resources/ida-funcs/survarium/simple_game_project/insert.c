void __thiscall survarium::simple_game_project::insert(
        survarium::simple_game_project *this,
        vostok::physics::world *world,
        survarium::game_world_core *game_world_core)
{
  void **M_start; // eax
  survarium::simple_game_project *M_finish; // ecx
  vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *v6; // esi
  survarium::damage_zone *m_object; // edi
  survarium::drawable_object *v8; // eax
  survarium::collision_sensor *v9; // ecx
  void (__thiscall *v10)(survarium::static_collision *, vostok::physics::world *); // eax
  int v11; // edi
  survarium::drawable_object *v12; // eax
  survarium::collision_sensor *v13; // ecx
  survarium::serializable_object *v14; // eax
  survarium::game_world_core *v15; // ecx
  vostok::resources::resource_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base> *v16; // edi
  vostok::resources::resource_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base> *v17; // ebx
  survarium::generic_anomaly_core *v18; // esi
  survarium::generic_anomaly_core *v19; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::static_collision,vostok::physics::world *>,boost::_bi::list2<boost::arg<1>,boost::_bi::value<vostok::physics::world *> > > v20; // [esp-8h] [ebp-20h]
  vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *i; // [esp+Ch] [ebp-Ch]
  void (__thiscall *v22)(survarium::static_collision *, vostok::physics::world *); // [esp+Ch] [ebp-Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::static_collision,vostok::physics::world *>,boost::_bi::list2<boost::arg<1>,boost::_bi::value<vostok::physics::world *> > > v23; // [esp+10h] [ebp-8h] BYREF

  M_start = this->m_artefact_containers._M_impl._M_start;
  M_finish = (survarium::simple_game_project *)this->m_artefact_containers._M_impl._M_finish;
  while ( M_start != (void **)M_finish )
    *((_DWORD *)*M_start++ + 22) = game_world_core;
  survarium::simple_game_project::insert_game_objects(M_finish, this);
  v20.l_.a2_.t_ = world;
  v20.f_.f_ = survarium::static_collision::insert;
  stlp_std::for_each<survarium::static_collision *,boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::static_collision,vostok::physics::world *>,boost::_bi::list2<boost::arg<1>,boost::_bi::value<vostok::physics::world *>>>>(
    this->m_static_collision_objects,
    &v23,
    &this->m_static_collision_objects[this->m_static_collision_objects_count],
    v20);
  v6 = this->m_damage_zones._M_impl._M_start;
  for ( i = this->m_damage_zones._M_impl._M_finish; v6 != i; ++v6 )
  {
    m_object = v6->m_object;
    if ( v6->m_object )
      v8 = &m_object->survarium::drawable_object;
    else
      v8 = 0;
    survarium::base_game_scene::register_drawable_object(&this->m_game_scene->m_game->m_game_world, v8);
    if ( !m_object->m_owner )
    {
      survarium::damage_zone_core::activate(m_object, world, v9, 1);
      survarium::game_world_core::register_serializable_object(
        game_world_core,
        &m_object->survarium::serializable_object);
      survarium::game_world_core::register_tickable_object(
        (survarium::game_world_core *)&m_object->survarium::tickable_object,
        (int)game_world_core);
    }
  }
  v10 = (void (__thiscall *)(survarium::static_collision *, vostok::physics::world *))this->m_effect_zones._M_impl._M_start;
  v22 = v10;
  v23.f_.f_ = (void (__thiscall *)(survarium::static_collision *, vostok::physics::world *))this->m_effect_zones._M_impl._M_finish;
  if ( v10 != v23.f_.f_ )
  {
    while ( 1 )
    {
      v11 = *(_DWORD *)v10;
      v12 = *(_DWORD *)v10 ? (survarium::drawable_object *)(v11 + 340) : 0;
      survarium::base_game_scene::register_drawable_object(&this->m_game_scene->m_game->m_game_world, v12);
      *(_DWORD *)(v11 + 320) = world;
      survarium::collision_sensor::insert(v13, v11 + 264, world);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)(v11 + 264) + 44))(v11 + 264, 1);
      v14 = v11 ? (survarium::serializable_object *)(v11 + 308) : 0;
      survarium::game_world_core::register_serializable_object(game_world_core, v14);
      v15 = v11 ? (survarium::game_world_core *)(v11 + 296) : 0;
      survarium::game_world_core::register_tickable_object(v15, (int)game_world_core);
      v22 = (void (__thiscall *)(survarium::static_collision *, vostok::physics::world *))((char *)v22 + 4);
      if ( v22 == v23.f_.f_ )
        break;
      v10 = v22;
    }
  }
  v16 = this->m_anomalies._M_impl._M_start;
  v17 = this->m_anomalies._M_impl._M_finish;
  while ( v16 != v17 )
  {
    v18 = v16->m_object;
    v16->m_object->activate(v16->m_object, world);
    survarium::game_world_core::register_serializable_object(game_world_core, &v18->survarium::serializable_object);
    survarium::game_world_core::register_tickable_object(
      (survarium::game_world_core *)&v18->survarium::tickable_object,
      (int)game_world_core);
    survarium::generic_anomaly_core::register_artefacts(v19, (survarium::game_world_core *)v18, (int)game_world_core);
    ++v16;
  }
}
