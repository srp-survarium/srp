stlp_std::pair<vostok::ai::game_object const *,enum vostok::ai::ignorance_types_enum> *__thiscall vostok::ai::pre_perceptors_filter::find_ignored_object(
        vostok::ai::pre_perceptors_filter *this,
        const vostok::ai::game_object *const object)
{
  unsigned __int16 i; // [esp+8h] [ebp-4h]

  for ( i = 0; i < (unsigned int)(this->m_ignorable_objects.m_end - this->m_ignorable_objects.m_begin); ++i )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    if ( this->m_ignorable_objects.m_begin[i].first == object )
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this->m_ignorable_objects.m_begin);
      return &this->m_ignorable_objects.m_begin[i];
    }
  }
  return 0;
}
