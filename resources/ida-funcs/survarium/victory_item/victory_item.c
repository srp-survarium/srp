void __userpurge survarium::victory_item::victory_item(
        survarium::victory_item *this@<ecx>,
        _DWORD *a2@<eax>,
        survarium::game_world *game_world,
        vostok::physics::world *physics_world)
{
  survarium::victory_item_core::victory_item_core(this, (int)a2, physics_world);
  *a2 = &survarium::victory_item::`vftable'{for `survarium::carryable_object'};
  a2[5] = &survarium::victory_item::`vftable'{for `survarium::collision_geometry_subscriber'};
  a2[6] = &survarium::victory_item::`vftable'{for `survarium::link_resolver'};
  a2[22] = &survarium::victory_item::`vftable'{for `survarium::spottable_object'};
  a2[24] = &survarium::victory_item::`vftable'{for `vostok::resources::unmanaged_resource'};
  a2[118] = 0;
  a2[119] = 0;
  a2[120] = game_world;
}
