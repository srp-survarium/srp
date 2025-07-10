void __thiscall survarium::victory_item_core::load(
        survarium::victory_item_core *this,
        vostok::configs::binary_config_value *cfg)
{
  survarium::game_camera *v2; // ecx
  vostok::memory::doug_lea_allocator *v3; // eax
  void *v4; // eax
  survarium::collision_geometry *v5; // eax
  vostok::configs::binary_config_value *v6; // eax
  const vostok::configs::binary_config_value *v7; // eax
  survarium::collision_geometry *v8; // [esp+0h] [ebp-20h]
  survarium::collision_geometry *v10; // [esp+1Ch] [ebp-4h]

  survarium::usable_object::load(this, cfg);
  survarium::weapon_user_dead_state::finalize(v2);
  v4 = vostok::memory::new_helper<survarium::collision_geometry>::call<vostok::memory::doug_lea_allocator>(v3);
  v10 = (survarium::collision_geometry *)operator new(0x130u, v4);
  if ( v10 )
  {
    survarium::collision_geometry::collision_geometry(v10);
    v8 = v5;
  }
  else
  {
    v8 = 0;
  }
  *this->m_collision_geometries = v8;
  v6 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                 cfg,
                                                 "collision_geometries");
  v7 = vostok::configs::binary_config_value::operator[](v6, 0);
  survarium::collision_geometry::load(*this->m_collision_geometries, v7);
}
