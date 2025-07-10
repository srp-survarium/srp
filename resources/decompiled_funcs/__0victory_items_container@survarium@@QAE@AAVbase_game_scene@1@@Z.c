void __userpurge survarium::victory_items_container::victory_items_container(
        survarium::victory_items_container *this@<ecx>,
        survarium::victory_items_container_core *a2@<esi>,
        survarium::base_game_scene *w)
{
  survarium::victory_items_container_core::victory_items_container_core(a2);
  a2[1].survarium::usable_object::survarium::collision_geometry_subscriber::__vftable = (survarium::victory_items_container_core_vtbl *)w;
  a2->survarium::usable_object::survarium::collision_geometry_subscriber::__vftable = (survarium::victory_items_container_core_vtbl *)&survarium::victory_items_container::`vftable'{for `survarium::collision_geometry_subscriber'};
  a2->survarium::usable_object::survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::victory_items_container::`vftable'{for `survarium::link_resolver'};
}
