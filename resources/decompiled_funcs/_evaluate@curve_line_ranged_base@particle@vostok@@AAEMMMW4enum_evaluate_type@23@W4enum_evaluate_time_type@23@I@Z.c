double __thiscall vostok::particle::curve_line_ranged_base::evaluate(
        vostok::particle::curve_line_ranged_base *this,
        float time,
        float default_value,
        vostok::particle::enum_evaluate_type evaluate_type,
        vostok::particle::enum_evaluate_time_type time_type,
        boost::_bi::list1<vostok::network_core::packet_reader &> *seed)
{
  float curve_time_max; // xmm0_4
  float curve_time_min; // xmm0_4
  float a; // [esp+10h] [ebp-6Ch]
  float left_range_alpha; // [esp+14h] [ebp-68h]
  float left_range_alphaa; // [esp+14h] [ebp-68h]
  float range; // [esp+18h] [ebp-64h]
  float rangea; // [esp+18h] [ebp-64h]
  unsigned int random_index; // [esp+68h] [ebp-14h]
  float alpha1; // [esp+6Ch] [ebp-10h]
  vostok::math::random32 rnd; // [esp+70h] [ebp-Ch] BYREF
  unsigned int index; // [esp+74h] [ebp-8h]
  float alpha0; // [esp+78h] [ebp-4h]
  float timea; // [esp+84h] [ebp+8h]

  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    0,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&rnd);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    seed,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&rnd);
  index = vostok::particle::curve_line_points<float,0>::get_left_point_index(&this->m_upper, time);
  for ( random_index = 0; random_index < index; ++random_index )
    vostok::math::random32::random(&rnd, 0xFFFFu);
  alpha0 = vostok::math::random32::random_f(&rnd, 1.0);
  alpha1 = vostok::math::random32::random_f(&rnd, 1.0);
  if ( evaluate_type != random_evaluate_type )
    return vostok::particle::curve_line_points<float,0>::evaluate(
             &this->m_upper,
             time,
             default_value,
             time_type,
             alpha0,
             alpha1);
  range = vostok::particle::random_float(0.0, 1.0);
  curve_time_max = this->m_upper.curve_time_max;
  vostok::math::max();
  left_range_alpha = curve_time_max;
  curve_time_min = this->m_lower.curve_time_min;
  vostok::math::min();
  timea = vostok::particle::linear_interpolation<float>(curve_time_min, left_range_alpha, range);
  rangea = vostok::particle::random_float(0.0, 1.0);
  left_range_alphaa = vostok::particle::curve_line_points<float,0>::evaluate(
                        &this->m_lower,
                        timea,
                        default_value,
                        range_time_type,
                        0.0,
                        0.0);
  a = vostok::particle::curve_line_points<float,0>::evaluate(
        &this->m_upper,
        timea,
        default_value,
        range_time_type,
        0.0,
        0.0);
  return vostok::particle::linear_interpolation<float>(a, left_range_alphaa, rangea);
}
