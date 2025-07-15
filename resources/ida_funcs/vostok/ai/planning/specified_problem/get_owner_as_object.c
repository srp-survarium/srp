stlp_std::pair<void const *,char const *> *__thiscall vostok::ai::planning::specified_problem::get_owner_as_object(
        vostok::ai::planning::specified_problem *this,
        stlp_std::pair<void const *,char const *> *result)
{
  const char *v2; // eax
  vostok::ai::brain_unit *instance; // [esp+14h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  instance = this->m_owner;
  v2 = type_info::name(&vostok::ai::brain_unit const * `RTTI Type Descriptor', &__type_info_root_node);
  result->first = instance;
  result->second = v2;
  return result;
}
