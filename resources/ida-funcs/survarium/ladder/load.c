void __thiscall survarium::ladder::load(survarium::ladder *this, vostok::configs::binary_config_value *cfg_val)
{
  const vostok::configs::binary_config_value *v2; // eax
  bool v3; // al
  vostok::memory::doug_lea_allocator *v4; // eax
  const vostok::configs::binary_config_value *v5; // eax
  volatile int v6; // [esp+0h] [ebp-18h]
  void *_Where; // [esp+8h] [ebp-10h]
  survarium::usable_object *v9; // [esp+10h] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v2 = vostok::configs::binary_config_value::operator[](cfg_val, "collision_geometries");
  survarium::usable_object::load((survarium::usable_object *)this, v2);
  v3 = vostok::configs::binary_config_value::value_exists(cfg_val, "occlusion_geometries");
  if ( v3 )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v3);
    _Where = vostok::memory::doug_lea_allocator::malloc_impl(v4, 0x20u);
    v9 = (survarium::usable_object *)operator new(0x20u, _Where);
    if ( v9 )
    {
      survarium::usable_object::usable_object(v9);
      v9->survarium::collision_geometry_subscriber::__vftable = (survarium::usable_object_vtbl *)&survarium::ladder::ladder_occluder::`vftable'{for `survarium::collision_geometry_subscriber'};
      v9->survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::ladder::ladder_occluder::`vftable'{for `survarium::link_resolver'};
      v6 = (volatile int)v9;
    }
    else
    {
      v6 = 0;
    }
    this->m_parent_resources.m_thread_id = v6;
    v5 = vostok::configs::binary_config_value::operator[](cfg_val, "occlusion_geometries");
    (*(void (__thiscall **)(volatile int, const vostok::configs::binary_config_value *))(*(_DWORD *)this->m_parent_resources.m_thread_id
                                                                                       + 12))(
      this->m_parent_resources.m_thread_id,
      v5);
  }
}
