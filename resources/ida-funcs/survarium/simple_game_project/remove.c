void __thiscall survarium::simple_game_project::remove(
        survarium::simple_game_project *this,
        vostok::physics::world *world,
        survarium::game_world_core *game_world_core)
{
  vostok::resources::resource_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base> *M_start; // eax
  survarium::generic_anomaly_core *m_object; // edi
  vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *v6; // eax
  survarium::damage_zone *v7; // ecx
  int v8; // edi
  vostok::resources::resource_ptr<survarium::effect_zone,vostok::resources::unmanaged_intrusive_base> *v9; // eax
  void (__thiscall *v10)(survarium::static_collision *, vostok::physics::world *); // ecx
  survarium::effect_zone *v11; // esi
  survarium::effect_zone_core_vtbl **v12; // edi
  survarium::effect_zone_core_vtbl *v13; // eax
  survarium::serializable_object *v14; // eax
  survarium::tickable_object *v15; // eax
  survarium::simple_game_project *v16; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::static_collision,vostok::physics::world *>,boost::_bi::list2<boost::arg<1>,boost::_bi::value<vostok::physics::world *> > > v17; // [esp-8h] [ebp-28h]
  vostok::resources::resource_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base> *v18; // [esp+10h] [ebp-10h]
  vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *v19; // [esp+10h] [ebp-10h]
  void (__thiscall *v20)(survarium::static_collision *, vostok::physics::world *); // [esp+10h] [ebp-10h]
  vostok::resources::resource_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base> *M_finish; // [esp+14h] [ebp-Ch]
  survarium::damage_zone *v22; // [esp+14h] [ebp-Ch]
  survarium::effect_zone *v23; // [esp+14h] [ebp-Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::static_collision,vostok::physics::world *>,boost::_bi::list2<boost::arg<1>,boost::_bi::value<vostok::physics::world *> > > v24; // [esp+18h] [ebp-8h] BYREF

  survarium::registry_of_artefacts::unregister_artefacts(
    (vostok::buffer_vector<vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> > *)this,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)&game_world_core->m_registry_of_artefacts);
  M_start = this->m_anomalies._M_impl._M_start;
  v18 = M_start;
  M_finish = this->m_anomalies._M_impl._M_finish;
  if ( M_start != M_finish )
  {
    while ( 1 )
    {
      m_object = M_start->m_object;
      M_start->m_object->deactivate(M_start->m_object);
      survarium::game_world_core::unregister_serializable_object(
        game_world_core,
        &m_object->survarium::serializable_object);
      survarium::game_world_core::unregister_tickable_object(game_world_core, &m_object->survarium::tickable_object);
      if ( ++v18 == M_finish )
        break;
      M_start = v18;
    }
  }
  v6 = this->m_damage_zones._M_impl._M_start;
  v7 = (survarium::damage_zone *)this->m_damage_zones._M_impl._M_finish;
  v19 = v6;
  v22 = v7;
  if ( v6 != (vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *)v7 )
  {
    while ( 1 )
    {
      v8 = (int)v6->m_object;
      survarium::damage_zone::clear_resources(v7, &v6->m_object->__vftable);
      if ( !*(_DWORD *)(v8 + 428) )
      {
        survarium::damage_zone_core::deactivate(v7, v8, 1);
        survarium::game_world_core::unregister_serializable_object(
          game_world_core,
          (survarium::serializable_object *)(v8 + 328));
        survarium::game_world_core::unregister_tickable_object(
          game_world_core,
          (survarium::tickable_object *)(v8 + 316));
      }
      if ( ++v19 == (vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *)v22 )
        break;
      v6 = v19;
    }
  }
  v9 = this->m_effect_zones._M_impl._M_start;
  v10 = (void (__thiscall *)(survarium::static_collision *, vostok::physics::world *))this->m_effect_zones._M_impl._M_finish;
  v20 = (void (__thiscall *)(survarium::static_collision *, vostok::physics::world *))v9;
  v24.f_.f_ = v10;
  if ( v9 != (vostok::resources::resource_ptr<survarium::effect_zone,vostok::resources::unmanaged_intrusive_base> *)v10 )
  {
    while ( 1 )
    {
      v11 = v9->m_object;
      v12 = (survarium::effect_zone_core_vtbl **)&v9->m_object->survarium::effect_zone_core;
      v23 = v9->m_object;
      survarium::collision_sensor::remove((survarium::collision_sensor *)v10, (int)v12);
      v13 = *v12;
      v12[14] = 0;
      v13->on_deactivation((survarium::effect_zone_core *)v12, 1);
      v14 = v11 ? &v11->survarium::serializable_object : 0;
      survarium::game_world_core::unregister_serializable_object(game_world_core, v14);
      v15 = v23 ? &v23->survarium::tickable_object : 0;
      survarium::game_world_core::unregister_tickable_object(game_world_core, v15);
      v20 = (void (__thiscall *)(survarium::static_collision *, vostok::physics::world *))((char *)v20 + 4);
      if ( v20 == v24.f_.f_ )
        break;
      v9 = (vostok::resources::resource_ptr<survarium::effect_zone,vostok::resources::unmanaged_intrusive_base> *)v20;
    }
  }
  v17.l_.a2_.t_ = world;
  v17.f_.f_ = survarium::static_collision::remove;
  stlp_std::for_each<survarium::static_collision *,boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::static_collision,vostok::physics::world *>,boost::_bi::list2<boost::arg<1>,boost::_bi::value<vostok::physics::world *>>>>(
    this->m_static_collision_objects,
    &v24,
    &this->m_static_collision_objects[this->m_static_collision_objects_count],
    v17);
  survarium::simple_game_project::remove_game_objects(v16, this);
}
