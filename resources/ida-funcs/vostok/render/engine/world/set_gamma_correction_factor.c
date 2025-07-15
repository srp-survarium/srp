void __thiscall vostok::render::engine::world::set_gamma_correction_factor(
        vostok::render::engine::world *this,
        float value)
{
  vostok::quasi_singleton<vostok::render::options>::pinst->current.m_gamma_correction_factor = value;
}
