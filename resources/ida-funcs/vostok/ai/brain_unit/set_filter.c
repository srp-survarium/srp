void __thiscall vostok::ai::brain_unit::set_filter(
        vostok::ai::brain_unit *this,
        const stlp_std::pair<vostok::ai::game_object const *,enum vostok::ai::ignorance_types_enum> *begin,
        const stlp_std::pair<vostok::ai::game_object const *,enum vostok::ai::ignorance_types_enum> *end)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::ai::pre_perceptors_filter::ignore(&this->m_behaviour.m_object->m_ignorance_filter, begin, end);
}
