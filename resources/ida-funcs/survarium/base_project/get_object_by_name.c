survarium::base_game_object *__thiscall survarium::base_project::get_object_by_name(
        survarium::base_project *this,
        const char *name)
{
  return *(survarium::base_game_object **)&stlp_std::priv::_Rb_tree<vostok::fixed_string<260>,stlp_std::less<vostok::fixed_string<260>>,stlp_std::pair<vostok::fixed_string<260> const,survarium::base_game_object *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<260> const,survarium::base_game_object *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<260> const,survarium::base_game_object *>>,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<260>,survarium::base_game_object *>>>::_M_find<char const *>(
                                             &this->m_objects_registry._M_t,
                                             (const char *const *)&this->m_objects_registry,
                                             &name)[18]._M_color;
}
