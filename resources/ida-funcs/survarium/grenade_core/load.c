void __thiscall survarium::grenade_core::load(
        survarium::grenade_core *this,
        const vostok::configs::binary_config_value *config)
{
  vostok::configs::binary_config_value *v4; // eax
  vostok::configs::binary_config_value *v5; // eax
  unsigned __int16 pointer; // ax
  const vostok::physics::bt_rigid_body_construction_info *v7; // eax
  vostok::physics::bt_collision_shape *v8; // edx
  vostok::physics::bt_dynamic_rigid_body *dynamic_rigid_body; // eax
  btRigidBody *m_bt_body; // eax
  vostok::physics::bt_rigid_body_construction_info *v11; // [esp-4h] [ebp-7Ch]
  vostok::math::float3 v12; // [esp+10h] [ebp-68h] BYREF
  vostok::math::float3 v13; // [esp+1Ch] [ebp-5Ch] BYREF
  float v14; // [esp+28h] [ebp-50h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v15; // [esp+2Ch] [ebp-4Ch] BYREF
  float v16; // [esp+5Ch] [ebp-1Ch]
  float v17; // [esp+60h] [ebp-18h]
  float v18; // [esp+64h] [ebp-14h]
  float v19; // [esp+68h] [ebp-10h]
  float v20; // [esp+6Ch] [ebp-Ch]
  float v21; // [esp+70h] [ebp-8h]
  char v22[4]; // [esp+74h] [ebp-4h] BYREF

  v4 = vostok::configs::binary_config_value::operator[](config, "game_material_settings");
  v5 = vostok::configs::binary_config_value::operator[](v4, "default");
  pointer = (unsigned __int16)vostok::configs::binary_config_value::operator[](v5, "game_material_id")->data.pointer;
  v12.x = s_bm_current_air_resistance;
  v12.y = s_bm_current_air_resistance;
  v12.z = s_bm_current_air_resistance;
  this->m_game_material_id = pointer;
  *(_QWORD *)&v13.x = __PAIR64__(LODWORD(FLOAT_0_1), LODWORD(satisfaction_equality_tolerance));
  v13.z = FLOAT_0_1;
  vostok::physics::create_primitive_shape(&v13, primitive_sphere, &v12);
  vostok::physics::bt_rigid_body_construction_info::bt_rigid_body_construction_info(v11, (int)&v14);
  v14 = s_aim_transition_time;
  v16 = s_bm_current_air_resistance;
  v17 = s_bm_current_air_resistance;
  v18 = s_bm_current_air_resistance;
  v13.x = s_bm_current_air_resistance;
  v13.y = s_bm_current_air_resistance;
  v13.z = s_bm_current_air_resistance;
  v19 = s_bm_current_air_resistance;
  v20 = s_bm_current_air_resistance;
  v21 = s_bm_current_air_resistance;
  v22[0] = 1;
  dynamic_rigid_body = vostok::physics::create_dynamic_rigid_body((int)this, (int)v22, (int)&v14, v7, v8);
  this->m_rigid_body = dynamic_rigid_body;
  m_bt_body = dynamic_rigid_body->m_bt_body;
  m_bt_body->m_ccdMotionThreshold = FLOAT_0_029999999;
  m_bt_body->m_ccdSweptSphereRadius = FLOAT_0_0099999998;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v15);
}
