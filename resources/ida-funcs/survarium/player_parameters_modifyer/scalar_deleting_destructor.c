survarium::player_parameters_modifyer *__thiscall survarium::player_parameters_modifyer::`scalar deleting destructor'(
        survarium::player_parameters_modifyer *this,
        char a2)
{
  stlp_std::priv::_Rb_tree<vostok::fixed_string<16>,stlp_std::less<vostok::fixed_string<16>>,stlp_std::pair<vostok::fixed_string<16> const,survarium::body_part_parameters_modifyer>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<16> const,survarium::body_part_parameters_modifyer>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<16> const,survarium::body_part_parameters_modifyer>>,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<16>,survarium::body_part_parameters_modifyer>>>::clear(&this->body_part_parameters_modifyers._M_t);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->body_part_parameters_modifyers);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
