void __userpurge survarium::artefact_container::artefact_container(
        survarium::artefact_container *this@<ecx>,
        survarium::artefact_container_core *a2@<esi>,
        survarium::base_game_scene *w)
{
  survarium::artefact_container_core::artefact_container_core(a2);
  a2[1].survarium::usable_object::survarium::collision_geometry_subscriber::__vftable = (survarium::artefact_container_core_vtbl *)w;
  a2->survarium::usable_object::survarium::collision_geometry_subscriber::__vftable = (survarium::artefact_container_core_vtbl *)&survarium::artefact_container::`vftable'{for `survarium::collision_geometry_subscriber'};
  a2->survarium::usable_object::survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::artefact_container::`vftable'{for `survarium::link_resolver'};
}
