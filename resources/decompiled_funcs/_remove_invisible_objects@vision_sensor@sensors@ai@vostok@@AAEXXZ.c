void __thiscall vostok::ai::sensors::vision_sensor::remove_invisible_objects(vostok::ai::sensors::vision_sensor *this)
{
  vostok::ai::sensors::cleansing_visible_objects_predicate predicate; // [esp+33h] [ebp-1h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&predicate);
  vostok::intrusive_list<vostok::ai::sensed_visual_object,vostok::ai::sensed_visual_object *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::remove_if<vostok::ai::sensors::cleansing_visible_objects_predicate>(
    &this->m_visible_objects,
    &predicate);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&predicate);
}
