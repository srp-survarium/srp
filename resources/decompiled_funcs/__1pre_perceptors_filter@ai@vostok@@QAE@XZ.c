void __thiscall vostok::ai::pre_perceptors_filter::~pre_perceptors_filter(vostok::ai::pre_perceptors_filter *this)
{
  stlp_std::pair<vostok::ai::game_object const *,enum vostok::ai::ignorance_types_enum> *i; // [esp+4h] [ebp-4h]

  vostok::threading::mutex::~mutex(
    (vostok::threading::mutex *)this,
    (_RTL_CRITICAL_SECTION *)&this->m_aux_filters.vostok::threading::mutex);
  for ( i = this->m_ignorable_objects.m_begin; i != this->m_ignorable_objects.m_end; ++i )
    ;
  this->m_ignorable_objects.m_end = this->m_ignorable_objects.m_begin;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
