void __thiscall survarium::base_project::base_project(survarium::base_project *this)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_objects_registry);
  this->__vftable = (survarium::base_project_vtbl *)&survarium::base_project::`vftable';
  stlp_std::map<vostok::fixed_string<260>,survarium::base_game_object *,stlp_std::less<vostok::fixed_string<260>>,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<260>,survarium::base_game_object *>>>::map<vostok::fixed_string<260>,survarium::base_game_object *,stlp_std::less<vostok::fixed_string<260>>,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<260>,survarium::base_game_object *>>>(&this->m_objects_registry);
  this->m_objects_to_resolve._M_impl._M_start = 0;
  this->m_objects_to_resolve._M_impl._M_finish = 0;
  this->m_objects_to_resolve._M_impl._M_end_of_storage._M_data = 0;
  this->m_static_collision_objects = 0;
  this->m_static_collision_objects_count = 0;
}
