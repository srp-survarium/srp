void __userpurge survarium::effect_zone::effect_zone(
        survarium::effect_zone *this@<ecx>,
        survarium::effect_zone_construct_params *a2@<esi>,
        const survarium::effect_zone_construct_params *construct_params)
{
  survarium::collision_sensor *v3; // ecx
  _DWORD *v4; // eax

  vostok::resources::unmanaged_resource::unmanaged_resource(this, a2, fs_iterator_class);
  survarium::collision_sensor::collision_sensor(v3, (int)&a2[66]);
  v4[8] = &survarium::tickable_object::`vftable';
  v4[11] = &survarium::serializable_object::`vftable';
  v4[14] = 0;
  v4[18] = ++g_zone_id;
  *v4 = &survarium::effect_zone_core::`vftable'{for `survarium::collision_geometry_subscriber'};
  v4[1] = &survarium::effect_zone_core::`vftable'{for `survarium::link_resolver'};
  v4[8] = &survarium::effect_zone_core::`vftable'{for `survarium::tickable_object'};
  v4[11] = &survarium::effect_zone_core::`vftable'{for `survarium::serializable_object'};
  a2[85].game_world = (survarium::game_world *)&survarium::drawable_object::`vftable';
  *v4 = &survarium::effect_zone::`vftable'{for `survarium::collision_geometry_subscriber'};
  a2->game_world = (survarium::game_world *)&survarium::effect_zone::`vftable'{for `vostok::resources::unmanaged_resource'};
  a2[67].game_world = (survarium::game_world *)&survarium::effect_zone::`vftable'{for `survarium::link_resolver'};
  a2[74].game_world = (survarium::game_world *)&survarium::effect_zone::`vftable'{for `survarium::tickable_object'};
  a2[77].game_world = (survarium::game_world *)&survarium::effect_zone::`vftable'{for `survarium::serializable_object'};
  a2[85].game_world = (survarium::game_world *)&survarium::effect_zone::`vftable'{for `survarium::drawable_object'};
  a2[88].game_world = construct_params->game_world;
}
