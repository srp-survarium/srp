void __thiscall vostok::ai::sensors::vision_sensor::delete_not_in_frustum(vostok::ai::sensors::vision_sensor *this)
{
  vostok::ai::sensors::cleaning_not_in_frustum_predicate predicate; // [esp+30h] [ebp-4h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&predicate);
  predicate.objects_to_clean = &this->m_visible_objects;
  vostok::intrusive_list<vostok::ai::sensed_visual_object,vostok::ai::sensed_visual_object *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::remove_if<vostok::ai::sensors::cleaning_not_in_frustum_predicate>(
    &this->m_visible_objects,
    &predicate);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&predicate);
}
