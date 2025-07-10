void __thiscall vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this,
        const vostok::collision::capsule_geometry_instance *bounding_volume,
        const vostok::collision::truncated_sphere_geometry_instance *testee)
{
  const vostok::collision::geometry_instance *m_testee; // eax

  m_testee = this->m_testee;
  this->m_testee = this->m_bounding_volume;
  this->m_bounding_volume = m_testee;
  this->dispatch(this, testee, bounding_volume);
}
