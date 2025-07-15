void __thiscall survarium::body_part_parameters_modifyer::body_part_parameters_modifyer(
        survarium::body_part_parameters_modifyer *this,
        const survarium::body_part_parameters_modifyer *__that)
{
  this->health = __that->health;
  this->health_regeneration = __that->health_regeneration;
  stlp_std::priv::_Rb_tree<vostok::fixed_string<16>,stlp_std::less<vostok::fixed_string<16>>,stlp_std::pair<vostok::fixed_string<16> const,survarium::hit_type_parameters_modifyer>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<16> const,survarium::hit_type_parameters_modifyer>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<16> const,survarium::hit_type_parameters_modifyer>>,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<16>,survarium::hit_type_parameters_modifyer>>>::_Rb_tree<vostok::fixed_string<16>,stlp_std::less<vostok::fixed_string<16>>,stlp_std::pair<vostok::fixed_string<16> const,survarium::hit_type_parameters_modifyer>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<16> const,survarium::hit_type_parameters_modifyer>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<16> const,survarium::hit_type_parameters_modifyer>>,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<16>,survarium::hit_type_parameters_modifyer>>>(
    &this->hit_type_modifyers._M_t,
    &__that->hit_type_modifyers._M_t);
}
