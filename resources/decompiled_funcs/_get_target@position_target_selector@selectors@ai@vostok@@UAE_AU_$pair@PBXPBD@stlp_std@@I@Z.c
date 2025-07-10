stlp_std::pair<void const *,char const *> *__thiscall vostok::ai::selectors::position_target_selector::get_target(
        vostok::ai::selectors::position_target_selector *this,
        stlp_std::pair<void const *,char const *> *result,
        unsigned int target_index)
{
  const char *v3; // eax
  const vostok::ai::movement_target *instance; // [esp+14h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  instance = this->m_selected_positions.m_begin[target_index];
  v3 = type_info::name(&vostok::ai::movement_target const * `RTTI Type Descriptor', &__type_info_root_node);
  result->first = instance;
  result->second = v3;
  return result;
}
