void __thiscall vostok::particle::particle_emitter::load_binary(
        vostok::particle::particle_emitter *this,
        vostok::mutable_buffer *buffer)
{
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v2; // ecx
  vostok::particle::curve_line_ranged_base *p_m_line; // [esp+2Ch] [ebp-1Ch]

  p_m_line = &this->m_particle_lifetime_curve.m_line;
  vostok::particle::curve_line_points<float,0>::load_binary(&this->m_particle_lifetime_curve.m_line.m_upper, buffer);
  vostok::particle::curve_line_points<float,0>::load_binary(&p_m_line->m_lower, buffer);
  vostok::particle::curve_line_points<float,0>::load_binary(&this->m_particle_spawn_rate_curve.m_line.m_upper, buffer);
  vostok::particle::curve_line_points<float,0>::load_binary(&this->m_particle_spawn_rate_curve.m_line.m_lower, buffer);
  this->m_burst_entries.pointer = (vostok::particle::burst_entry *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                                     v2,
                                                                     (int)buffer);
  vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)(12 * this->m_num_burst_entries), buffer);
}
