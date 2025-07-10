void __thiscall vostok::ai::sensors::vision_sensor::reset_frustum_status(vostok::ai::sensors::vision_sensor *this)
{
  vostok::ai::sensors::reset_frustum_status_predicate pred; // [esp+Fh] [ebp-1h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&pred);
  vostok::intrusive_list<vostok::ai::sensed_visual_object,vostok::ai::sensed_visual_object *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::ai::sensors::reset_frustum_status_predicate>(
    &this->m_visible_objects,
    &pred);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&pred);
}
