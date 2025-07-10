void __thiscall vostok::ai::sensors::vision_sensor::update_perceptors(vostok::ai::sensors::vision_sensor *this)
{
  float visibility_threshold; // [esp+10h] [ebp-Ch]
  vostok::ai::sensors::update_perceptors_predicate pred; // [esp+14h] [ebp-8h] BYREF

  visibility_threshold = this->m_parameters.visibility_threshold;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&pred);
  pred.vision = this;
  pred.visibility_threashold = visibility_threshold;
  vostok::intrusive_list<vostok::ai::sensed_visual_object,vostok::ai::sensed_visual_object *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::ai::sensors::update_perceptors_predicate>(
    &this->m_visible_objects,
    &pred);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&pred);
}
