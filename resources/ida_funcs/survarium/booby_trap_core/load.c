void __userpurge survarium::booby_trap_core::load(
        survarium::booby_trap_core *this@<ecx>,
        btRigidBody *a2@<ebx>,
        vostok::configs::binary_config_value *config)
{
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  survarium::game_camera *v6; // ecx
  vostok::configs::binary_config_value *v7; // eax
  survarium::game_camera *v8; // ecx
  vostok::memory::doug_lea_allocator *v9; // eax
  void *v10; // eax
  int v11; // eax
  vostok::configs::binary_config_value *v12; // eax
  vostok::configs::binary_config_value *v13; // eax
  const vostok::configs::binary_config_value *v14; // eax
  const vostok::configs::binary_config_value *v15; // eax
  survarium::game_camera *v16; // ecx
  vostok::memory::doug_lea_allocator *v17; // eax
  void *v18; // eax
  int v19; // eax
  vostok::configs::binary_config_value *v20; // eax
  vostok::configs::binary_config_value *v21; // eax
  const vostok::configs::binary_config_value *v22; // eax
  vostok::configs::binary_config_value *v23; // eax
  int v24; // [esp+0h] [ebp-40h]
  int v25; // [esp+4h] [ebp-3Ch]
  survarium::collision_geometry *v27; // [esp+30h] [ebp-10h]
  survarium::collision_geometry *v28; // [esp+34h] [ebp-Ch]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v3);
  survarium::weapon_user_dead_state::finalize(v4);
  survarium::weapon_user_dead_state::finalize(v5);
  survarium::weapon_user_dead_state::finalize(v6);
  v7 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                 config,
                                                 "collision_sensor");
  survarium::collision_sensor::load((survarium::collision_sensor *)this, v7);
  survarium::weapon_user_dead_state::finalize(v8);
  v10 = vostok::memory::new_helper<survarium::collision_geometry>::call<vostok::memory::doug_lea_allocator>(v9);
  v28 = (survarium::collision_geometry *)operator new(0x130u, v10);
  if ( v28 )
  {
    survarium::collision_geometry::collision_geometry(v28);
    v25 = v11;
  }
  else
  {
    v25 = 0;
  }
  *(_DWORD *)HIDWORD(this->m_reconstruction_info_actuality_tick) = v25;
  v12 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                  config,
                                                  "collision_sensor");
  v13 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                  v12,
                                                  "collision_geometries");
  v14 = vostok::configs::binary_config_value::operator[](v13, 0);
  survarium::collision_geometry::load(
    *(survarium::collision_geometry **)HIDWORD(this->m_reconstruction_info_actuality_tick),
    v14);
  v15 = vostok::configs::binary_config_value::operator[](config, "usable_object");
  survarium::usable_object::load((survarium::usable_object *)&this->m_children_resources, v15);
  survarium::weapon_user_dead_state::finalize(v16);
  v18 = vostok::memory::new_helper<survarium::collision_geometry>::call<vostok::memory::doug_lea_allocator>(v17);
  v27 = (survarium::collision_geometry *)operator new(0x130u, v18);
  if ( v27 )
  {
    survarium::collision_geometry::collision_geometry(v27);
    v24 = v19;
  }
  else
  {
    v24 = 0;
  }
  *(_DWORD *)this->m_parent_resources.m_size = v24;
  v20 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                  config,
                                                  "usable_object");
  v21 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                  v20,
                                                  "collision_geometries");
  v22 = vostok::configs::binary_config_value::operator[](v21, 0);
  survarium::collision_geometry::load(*(survarium::collision_geometry **)this->m_parent_resources.m_size, v22);
  if ( vostok::configs::binary_config_value::value_exists(config, "hittable_object") )
  {
    v23 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    config,
                                                    "hittable_object");
    survarium::hittable_object::load((survarium::hittable_object *)&this[-1].m_transform.lines[3], a2, v23);
  }
}


void __thiscall survarium::booby_trap_core::load(char *this, const vostok::configs::binary_config_value *a2)
{
  survarium::booby_trap_core::load((survarium::booby_trap_core *)(this - 36), a2);
}
