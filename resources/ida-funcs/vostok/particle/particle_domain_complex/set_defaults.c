void __thiscall vostok::particle::particle_domain_complex::set_defaults(
        vostok::particle::particle_domain_complex *this)
{
  vostok::math::float3_pod *v1; // eax
  vostok::math::float3_pod *v2; // eax
  vostok::math::float3_pod *v3; // eax
  vostok::math::float4x4 *v4; // eax
  vostok::math::float4x4 *v5; // eax
  $03587BACB216BA0890FE706AD1985887 *v6; // eax
  vostok::math::float3_pod *v7; // eax
  vostok::math::float3_pod *v8; // eax
  vostok::math::float3 v10; // [esp+98h] [ebp-C8h] BYREF
  vostok::math::float3 v11; // [esp+A4h] [ebp-BCh] BYREF
  vostok::math::float3 v12; // [esp+B0h] [ebp-B0h] BYREF
  survarium::game_options v13; // [esp+BCh] [ebp-A4h] BYREF
  vostok::math::float3 v14; // [esp+13Ch] [ebp-24h] BYREF
  vostok::math::float3 v15; // [esp+148h] [ebp-18h] BYREF
  vostok::math::float3 v16; // [esp+154h] [ebp-Ch] BYREF

  this->m_affect_velocity = 0;
  vostok::math::float3::float3(&v16, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  this->m_translate = *v1;
  vostok::math::float3::float3(&v15, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  this->m_rotate = *v2;
  vostok::math::float3::float3(&v14, COERCE_UNSIGNED_INT(1.0), COERCE_UNSIGNED_INT(1.0), 1.0);
  this->m_scale = *v3;
  v4 = (vostok::math::float4x4 *)survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v13.m_conflicted_action_to_bind);
  qmemcpy(this, vostok::math::float4x4::identity(v4), 0x40u);
  v5 = (vostok::math::float4x4 *)survarium::weapon_core::cast_weapon_core(&v13);
  qmemcpy((void *)&this->m_inv_transform, vostok::math::float4x4::identity(v5), sizeof(this->m_inv_transform));
  vostok::math::float3::float3(&v12, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  this->164 = *v6;
  LODWORD(this->m_line_width) = clear_value;
  LODWORD(this->m_box_width) = clear_value;
  LODWORD(this->m_box_height) = clear_value;
  LODWORD(this->m_box_depth) = clear_value;
  this->m_inner_radius = *(float *)&FLOAT_0_0;
  LODWORD(this->m_outer_radius) = clear_value;
  LODWORD(this->m_cylinder_height) = clear_value;
  this->m_domain_type = 0;
  vostok::math::float3::float3(&v11, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  this->m_triangle_b = *v7;
  vostok::math::float3::float3(&v10, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  this->m_triangle_c = *v8;
}
