void __thiscall survarium::server_game_project::remove(
        survarium::server_game_project *this,
        vostok::physics::world *world,
        survarium::game_world_core *game_world_core)
{
  survarium::collision_sensor *v4; // ecx
  survarium::generic_anomaly_core *m_object; // edi
  survarium::damage_zone_core *m_damage_zones; // ecx
  int v7; // edi
  survarium::effect_zone_core *v8; // edi
  survarium::effect_zone_core_vtbl *v9; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::static_collision,vostok::physics::world *>,boost::_bi::list2<boost::arg<1>,boost::_bi::value<vostok::physics::world *> > > v10; // [esp-8h] [ebp-20h]
  int v11; // [esp+Ch] [ebp-Ch]
  int v12; // [esp+Ch] [ebp-Ch]
  int v13; // [esp+Ch] [ebp-Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::static_collision,vostok::physics::world *>,boost::_bi::list2<boost::arg<1>,boost::_bi::value<vostok::physics::world *> > > v14; // [esp+10h] [ebp-8h] BYREF

  survarium::registry_of_artefacts::unregister_artefacts(
    (vostok::buffer_vector<vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> > *)this,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)&game_world_core->m_registry_of_artefacts);
  v11 = 0;
  if ( this->m_anomalies_count )
  {
    do
    {
      m_object = this->m_anomalies[v11].m_object;
      m_object->deactivate(m_object);
      survarium::game_world_core::unregister_serializable_object(
        game_world_core,
        &m_object->survarium::serializable_object);
      survarium::game_world_core::unregister_tickable_object(game_world_core, &m_object->survarium::tickable_object);
      ++v11;
    }
    while ( v11 != this->m_anomalies_count );
  }
  v12 = 0;
  if ( this->m_damage_zones_count )
  {
    do
    {
      m_damage_zones = (survarium::damage_zone_core *)this->m_damage_zones;
      v7 = *((_DWORD *)&m_damage_zones->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
           + v12);
      if ( !*(_DWORD *)(v7 + 428) )
      {
        survarium::damage_zone_core::deactivate(m_damage_zones, v7, 1);
        survarium::game_world_core::unregister_serializable_object(
          game_world_core,
          (survarium::serializable_object *)(v7 + 328));
        survarium::game_world_core::unregister_tickable_object(
          game_world_core,
          (survarium::tickable_object *)(v7 + 316));
      }
      v4 = (survarium::collision_sensor *)++v12;
    }
    while ( v12 != this->m_damage_zones_count );
  }
  v14.f_.f_ = 0;
  if ( this->m_effect_zones_count )
  {
    v13 = 0;
    do
    {
      v8 = &this->m_effect_zones[v13];
      survarium::collision_sensor::remove(v4, (int)v8);
      v9 = v8->survarium::collision_sensor::survarium::collision_geometry_subscriber::__vftable;
      v8->m_physics_world = 0;
      v9->on_deactivation(v8, 1);
      survarium::game_world_core::unregister_serializable_object(game_world_core, &v8->survarium::serializable_object);
      survarium::game_world_core::unregister_tickable_object(game_world_core, &v8->survarium::tickable_object);
      ++v14.f_.f_;
      ++v13;
    }
    while ( v14.f_.f_ != (void (__thiscall *)(survarium::static_collision *, vostok::physics::world *))this->m_effect_zones_count );
  }
  v10.l_.a2_.t_ = world;
  v10.f_.f_ = survarium::static_collision::remove;
  stlp_std::for_each<survarium::static_collision *,boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::static_collision,vostok::physics::world *>,boost::_bi::list2<boost::arg<1>,boost::_bi::value<vostok::physics::world *>>>>(
    this->m_static_collision_objects,
    &v14,
    &this->m_static_collision_objects[this->m_static_collision_objects_count],
    v10);
}
