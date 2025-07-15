bool __thiscall vostok::particle::base_particle::is_dead(vostok::particle::base_particle *this)
{
  return this->duration > 0.001 && this->lifetime > this->duration;
}
