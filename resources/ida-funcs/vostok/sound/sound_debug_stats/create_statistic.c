void __thiscall vostok::sound::sound_debug_stats::create_statistic(vostok::sound::sound_debug_stats *this)
{
  vostok::sound::sound_scene *v2; // ecx

  this->m_statistic[0] = vostok::sound::sound_scene::create_statistic((vostok::sound::sound_scene *)this);
  this->m_statistic[1] = vostok::sound::sound_scene::create_statistic(v2);
}
