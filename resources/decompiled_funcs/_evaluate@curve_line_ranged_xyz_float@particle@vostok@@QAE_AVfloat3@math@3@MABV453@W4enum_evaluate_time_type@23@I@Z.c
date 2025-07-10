vostok::math::float3 *__thiscall vostok::particle::curve_line_ranged_xyz_float::evaluate(
        vostok::particle::curve_line_ranged_xyz_float *this,
        vostok::math::float3 *result,
        float time,
        const vostok::math::float3 *default_value,
        vostok::particle::enum_evaluate_time_type time_type,
        boost::_bi::list1<vostok::network_core::packet_reader &> *seed)
{
  float z; // [esp+60h] [ebp-Ch]
  unsigned int x; // [esp+64h] [ebp-8h]
  unsigned int y; // [esp+68h] [ebp-4h]

  *(float *)&x = vostok::particle::curve_line_ranged_base::evaluate(
                   &this->m_line_x,
                   time,
                   default_value->x,
                   this->m_evaluate_type,
                   time_type,
                   seed);
  *(float *)&y = vostok::particle::curve_line_ranged_base::evaluate(
                   &this->m_line_y,
                   time,
                   default_value->y,
                   this->m_evaluate_type,
                   time_type,
                   seed);
  z = vostok::particle::curve_line_ranged_base::evaluate(
        &this->m_line_z,
        time,
        default_value->z,
        this->m_evaluate_type,
        time_type,
        seed);
  vostok::math::float3::float3(result, x, y, z);
  return result;
}
