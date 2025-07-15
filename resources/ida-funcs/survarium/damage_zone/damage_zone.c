void __userpurge survarium::damage_zone::damage_zone(
        survarium::damage_zone *this@<ecx>,
        _DWORD *a2@<eax>,
        survarium::game_world *world)
{
  survarium::damage_zone_core::damage_zone_core(this, (int)a2);
  a2[138] = &survarium::drawable_object::`vftable';
  a2[138] = &survarium::damage_zone::`vftable';
  a2[141] = world;
  a2[142] = 0;
  a2[143] = 0;
  a2[144] = 0;
  a2[145] = 0;
  a2[146] = 0;
  a2[147] = 0;
  a2[148] = 0;
  a2[149] = 0;
  a2[150] = 0;
  a2[151] = 0;
  a2[152] = 0;
  a2[153] = 0;
  a2[154] = 0;
  a2[155] = 0;
  a2[156] = 0;
  *a2 = &survarium::damage_zone::`vftable'{for `vostok::resources::unmanaged_resource'};
  a2[66] = &survarium::damage_zone::`vftable'{for `survarium::collision_geometry_subscriber'};
  a2[67] = &survarium::damage_zone::`vftable'{for `survarium::link_resolver'};
  a2[75] = &survarium::damage_zone::`vftable'{for `survarium::hit_initiator'};
  a2[78] = &survarium::damage_zone::`vftable'{for `survarium::player_actions_subscriber'};
  a2[79] = &survarium::damage_zone::`vftable'{for `survarium::tickable_object'};
  a2[82] = &survarium::damage_zone::`vftable'{for `survarium::serializable_object'};
}
