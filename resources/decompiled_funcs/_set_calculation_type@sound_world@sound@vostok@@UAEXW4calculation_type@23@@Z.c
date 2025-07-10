void __thiscall vostok::sound::sound_world::set_calculation_type(
        vostok::sound::sound_world *this,
        vostok::sound::calculation_type type)
{
  _InterlockedExchange(&this->m_calc_type, type);
}
