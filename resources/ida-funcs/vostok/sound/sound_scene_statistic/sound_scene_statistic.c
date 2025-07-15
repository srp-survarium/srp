void __thiscall vostok::sound::sound_scene_statistic::sound_scene_statistic(vostok::sound::sound_scene_statistic *this)
{
  this->m_proxies_statistic.m_size = 0;
  this->m_proxies_statistic.m_first = 0;
  this->m_proxies_statistic.m_last = 0;
  vostok::memory::zero(this, 0x24u);
}
