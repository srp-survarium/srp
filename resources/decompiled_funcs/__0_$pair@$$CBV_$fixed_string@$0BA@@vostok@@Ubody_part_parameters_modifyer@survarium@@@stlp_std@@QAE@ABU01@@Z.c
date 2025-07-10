void __thiscall stlp_std::pair<vostok::fixed_string<16> const,survarium::body_part_parameters_modifyer>::pair<vostok::fixed_string<16> const,survarium::body_part_parameters_modifyer>(
        stlp_std::pair<vostok::fixed_string<16> const ,survarium::body_part_parameters_modifyer> *this,
        const stlp_std::pair<vostok::fixed_string<16> const ,survarium::body_part_parameters_modifyer> *__o)
{
  vostok::fixed_string<16>::fixed_string<16>(&this->first, &__o->first);
  this->second.health = __o->second.health;
  this->second.health_regeneration = __o->second.health_regeneration;
  stlp_std::priv::_Rb_tree<vostok::fixed_string<16>,stlp_std::less<vostok::fixed_string<16>>,stlp_std::pair<vostok::fixed_string<16> const,survarium::hit_type_parameters_modifyer>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<16> const,survarium::hit_type_parameters_modifyer>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<16> const,survarium::hit_type_parameters_modifyer>>,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<16>,survarium::hit_type_parameters_modifyer>>>::_Rb_tree<vostok::fixed_string<16>,stlp_std::less<vostok::fixed_string<16>>,stlp_std::pair<vostok::fixed_string<16> const,survarium::hit_type_parameters_modifyer>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<16> const,survarium::hit_type_parameters_modifyer>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<16> const,survarium::hit_type_parameters_modifyer>>,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<16>,survarium::hit_type_parameters_modifyer>>>(
    &this->second.hit_type_modifyers._M_t,
    &__o->second.hit_type_modifyers._M_t);
}
