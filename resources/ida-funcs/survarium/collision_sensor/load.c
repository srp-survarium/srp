void __thiscall survarium::collision_sensor::load(
        survarium::collision_sensor *this,
        const vostok::configs::binary_config_value *cfg)
{
  vostok::memory::doug_lea_allocator *v3; // esi
  char *v4; // eax
  const char *v5; // [esp+0h] [ebp-28h]
  const char *v6; // [esp+4h] [ebp-24h]
  unsigned int v7; // [esp+8h] [ebp-20h]
  _DWORD v8[6]; // [esp+10h] [ebp-18h] BYREF

  qmemcpy(v8, vostok::configs::binary_config_value::operator[](cfg, "collision_geometries"), sizeof(v8));
  v3 = survarium::g_allocator;
  this->m_collision_geometries_count = 24 * HIWORD(v8[5]) / 24;
  v4 = type_info::raw_name(&survarium::collision_geometry * `RTTI Type Descriptor');
  this->m_collision_geometries = (survarium::collision_geometry **)vostok::memory::doug_lea_allocator::malloc_impl(
                                                                     (vostok::memory::doug_lea_allocator *)(4 * this->m_collision_geometries_count),
                                                                     (int)v3,
                                                                     4 * this->m_collision_geometries_count,
                                                                     v4,
                                                                     v5,
                                                                     v6,
                                                                     v7);
}
