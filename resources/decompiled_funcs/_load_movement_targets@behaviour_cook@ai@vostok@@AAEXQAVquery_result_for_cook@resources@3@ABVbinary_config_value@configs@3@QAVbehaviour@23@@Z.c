void __thiscall vostok::ai::behaviour_cook::load_movement_targets(
        vostok::ai::behaviour_cook *this,
        vostok::resources::query_result_for_cook *const parent,
        vostok::configs::binary_config_value *behaviour_value,
        vostok::ai::behaviour *const new_behaviour)
{
  if ( new_behaviour->m_movement_targets_count )
    vostok::ai::behaviour_cook::fill_movement_targets(this, behaviour_value, new_behaviour);
  vostok::ai::behaviour_cook::finish_creation(this, parent, (vostok::configs::binary_config *)new_behaviour);
}
