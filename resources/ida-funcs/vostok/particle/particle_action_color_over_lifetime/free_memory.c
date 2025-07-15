void __thiscall vostok::particle::particle_action_color_over_lifetime::free_memory(
        vostok::particle::particle_action_color_over_lifetime *this,
        vostok::particle::color_matrix *allocator)
{
  vostok::particle::color_matrix::free_memory(allocator, &this->m_color_over_life.m_points.pointer);
}
