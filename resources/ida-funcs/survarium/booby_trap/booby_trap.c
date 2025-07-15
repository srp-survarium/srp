void __thiscall survarium::booby_trap::booby_trap(
        survarium::booby_trap *this,
        survarium::base_game_scene *gw,
        vostok::physics::world *physics_world,
        vostok::math::float4x4 *physics_worlda)
{
  survarium::booby_trap_core::booby_trap_core(this, (int)gw, physics_worlda);
  LODWORD(gw[2].m_inverted_view_matrix.i.y) = &survarium::drawable_object::`vftable';
  LODWORD(gw[2].m_inverted_view_matrix.i.y) = &survarium::booby_trap::`vftable';
  gw->__vftable = (survarium::base_game_scene_vtbl *)&survarium::booby_trap::`vftable'{for `survarium::hittable_object'};
  LODWORD(gw->m_inverted_view_matrix.i.y) = &survarium::booby_trap::`vftable'{for `survarium::collision_geometry_subscriber's `survarium::collision_sensor'};
  LODWORD(gw->m_inverted_view_matrix.i.z) = &survarium::booby_trap::`vftable'{for `survarium::link_resolver's `survarium::collision_sensor'};
  LODWORD(gw->m_inverted_view_matrix.k.z) = &survarium::booby_trap::`vftable'{for `survarium::collision_geometry_subscriber's `survarium::usable_object'};
  LODWORD(gw->m_inverted_view_matrix.k.w) = &survarium::booby_trap::`vftable'{for `survarium::link_resolver's `survarium::usable_object'};
  LODWORD(gw->m_projection_matrix.k.w) = &survarium::booby_trap::`vftable'{for `survarium::tickable_object'};
  LODWORD(gw->m_projection_matrix.c.z) = &survarium::booby_trap::`vftable'{for `survarium::serializable_object'};
  gw->m_mouse_y = (int)&survarium::booby_trap::`vftable'{for `vostok::resources::unmanaged_resource'};
  gw[2].m_inverted_view_matrix.j.x = 0.0;
  gw[2].m_inverted_view_matrix.j.y = 0.0;
  gw[2].m_inverted_view_matrix.j.z = 0.0;
  gw[2].m_inverted_view_matrix.j.w = 0.0;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&gw[2].m_inverted_view_matrix.lines[2],
    0);
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&gw[2].m_inverted_view_matrix.lines[2].elements[1],
    0);
  gw[2].m_inverted_view_matrix.k.w = 0.0;
  LODWORD(gw[2].m_inverted_view_matrix.k.z) = physics_world;
}
