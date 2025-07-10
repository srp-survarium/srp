char __thiscall survarium::booby_trap_core::use_initialize(
        survarium::booby_trap_core *this,
        survarium::game_camera *user)
{
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v4; // ecx
  survarium::usable_object *v5; // [esp+0h] [ebp-14h]
  survarium::base_player *user_player; // [esp+10h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v2);
  if ( LODWORD(this->m_reconstruction_info_actuality_tick) )
    return 0;
  user_player = (survarium::base_player *)(*((int (__thiscall **)(survarium::game_camera_vtbl *))user->get_projection_matrix
                                           + 8))(user->__vftable);
  survarium::weapon_user_dead_state::finalize(v4);
  if ( !survarium::booby_trap_core::can_defuse((survarium::booby_trap_core *)((char *)this - 328), user_player) )
    return 0;
  vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
    (vostok::intrusive_list<vostok::ai::sensed_visual_object,vostok::ai::sensed_visual_object *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&this->survarium::game_world_object::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags,
    user,
    0);
  if ( this == (survarium::booby_trap_core *)328 )
    v5 = 0;
  else
    v5 = (survarium::usable_object *)this;
  LODWORD(user->m_inverted_view_matrix.i.x) = v5;
  user->m_inverted_view_matrix.i.y = user->m_inverted_view_matrix.i.z;
  return 1;
}
