void __thiscall survarium::usable_object::load(
        survarium::usable_object *this,
        vostok::configs::binary_config_value *cfg)
{
  unsigned int v2; // esi
  survarium::game_camera *v3; // ecx
  vostok::memory::doug_lea_allocator *v4; // eax
  vostok::configs::binary_config_value collision_table; // [esp+18h] [ebp-18h] BYREF

  collision_table = *vostok::configs::binary_config_value::operator[](cfg, "collision_geometries");
  this->m_collision_geometries_count = vostok::configs::binary_config_value::size(&collision_table);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v2 = 4 * this->m_collision_geometries_count;
  survarium::weapon_user_dead_state::finalize(v3);
  this->m_collision_geometries = (survarium::collision_geometry **)vostok::memory::malloc_helper<vostok::memory::doug_lea_allocator>(
                                                                     v4,
                                                                     v2);
}
