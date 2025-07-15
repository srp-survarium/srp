unsigned int __userpurge survarium::bullet::change_trajectory@<eax>(
        survarium::bullet *this@<ecx>,
        float a2@<xmm0>,
        survarium::bullet *const thisa,
        const struct vostok::math::float3 *new_velocity,
        float a5)
{
  unsigned int result; // eax

  ++thisa->m_change_trajectory_count;
  LODWORD(thisa->m_start_position.x) = this->m_id;
  *(_QWORD *)&thisa->m_start_position.elements[1] = *(_QWORD *)&this->m_position.x;
  thisa->m_start_velocity = *new_velocity;
  thisa->m_position = thisa->m_start_position;
  thisa->m_velocity = thisa->m_start_velocity;
  result = vostok::math::floor(a2 * 1000.0);
  thisa->m_born_time_in_ms += result;
  thisa->m_life_time = 0.0;
  return result;
}
