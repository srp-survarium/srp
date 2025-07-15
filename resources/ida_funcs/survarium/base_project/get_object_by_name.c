survarium::base_game_object *__thiscall survarium::base_project::get_object_by_name(
        survarium::base_project *this,
        const char *name)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  return *stlp_std::map<vostok::fixed_string<260>,survarium::base_game_object *,stlp_std::less<vostok::fixed_string<260>>,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<260>,survarium::base_game_object *>>>::operator[]<char const *>(
            &name,
            &this->m_objects_registry);
}
