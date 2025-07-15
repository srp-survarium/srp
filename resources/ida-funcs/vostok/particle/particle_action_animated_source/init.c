void __thiscall vostok::particle::particle_action_animated_source::init(
        vostok::particle::particle_action_animated_source *this,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  vostok::collision::animated_object *m_object; // esi
  unsigned int m_seed; // edi
  unsigned int v6; // eax
  float v7; // xmm0_4
  vostok::math::curve_line_ranged_xyz_float *v8; // ecx
  vostok::particle::engine_vtbl *v9; // edi
  unsigned int surface_bone_index; // eax
  const vostok::resources::resource_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base> *v11; // edx
  float v12; // xmm1_4
  float y; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  unsigned int v19; // [esp+Ch] [ebp-F0h]
  vostok::math::float3 v20; // [esp+1Ch] [ebp-E0h] BYREF
  vostok::particle::particle_action_animated_source *v21; // [esp+28h] [ebp-D4h]
  vostok::math::float4x4 v22; // [esp+2Ch] [ebp-D0h] BYREF
  float v23[16]; // [esp+6Ch] [ebp-90h] BYREF
  vostok::math::float4x4 v24; // [esp+ACh] [ebp-50h] BYREF
  vostok::math::float3 v25; // [esp+F0h] [ebp-Ch] BYREF

  m_object = instance->m_particle_system_instance->m_damage_model.m_object;
  v21 = this;
  if ( m_object )
  {
    m_seed = P->m_seed;
    if ( this->m_use_random_permutation )
    {
      P->surface_id = this->m_random_permutation[this->m_random_permutation_index];
      this->m_random_permutation_index = (this->m_random_permutation_index + 1) % this->m_random_permutation_size;
    }
    else
    {
      m_seed = 134775813 * m_seed + 1;
      P->surface_id = vostok::physics::bt_animated_rigid_body::get_random_surface(
                        (vostok::physics::bt_animated_rigid_body *)0xFFFFFFFF,
                        (int)m_object->m_body,
                        COERCE_FLOAT((0xFFFFFFFF * (unsigned __int64)m_seed) >> 32),
                        this->m_mask);
    }
    vostok::physics::bt_animated_rigid_body::get_random_surface_point_by_id(
      instance->m_particle_system_instance->m_damage_model.m_object->m_body,
      P->surface_id,
      (unsigned int)&v20,
      (0xFFFFFFFF * (unsigned __int64)(134775813 * m_seed + 1)) >> 32);
    v6 = P->m_seed;
    v7 = s_bm_current_air_resistance;
    P->surface_position = v20;
    v20.x = v7;
    v20.y = v7;
    v20.z = v7;
    P->surface_scale = *vostok::math::curve_line_ranged_xyz_float::evaluate(
                          v8,
                          (int)&v21->m_scale,
                          v7,
                          &v25,
                          0.0,
                          &v20,
                          v6,
                          v19);
    if ( instance->m_world_space )
    {
      v9 = instance->m_engine->__vftable;
      surface_bone_index = vostok::collision::animated_object::get_surface_bone_index(
                             instance->m_particle_system_instance->m_damage_model.m_object,
                             P->surface_id);
      v9->get_bone_matrix(instance->m_engine, (vostok::math::float4x4 *)v23, v11 + 191, surface_bone_index);
      vostok::physics::bt_animated_rigid_body::get_surface_point_transform(
        instance->m_particle_system_instance->m_damage_model.m_object->m_body,
        P->surface_id,
        &v24);
      vostok::math::create_scale(&P->surface_scale, &v22);
      v12 = (float)((float)((float)(P->surface_position.x * v22.i.x) + (float)(P->surface_position.z * v22.k.x))
                  + (float)(P->surface_position.y * v22.j.x))
          + v22.c.x;
      y = P->surface_position.y;
      v14 = (float)((float)((float)(P->surface_position.x * v22.i.z) + (float)(y * v22.j.z))
                  + (float)(P->surface_position.z * v22.k.z))
          + v22.c.z;
      v15 = (float)((float)((float)(y * v22.j.y) + (float)(P->surface_position.z * v22.k.y))
                  + (float)(P->surface_position.x * v22.i.y))
          + v22.c.y;
      v16 = (float)((float)((float)(v24.k.x * v14) + (float)(v24.j.x * v15)) + (float)(v24.i.x * v12)) + v24.c.x;
      v17 = (float)((float)((float)(v24.k.y * v14) + (float)(v24.j.y * v15)) + (float)(v24.i.y * v12)) + v24.c.y;
      v18 = (float)((float)((float)(v24.k.z * v14) + (float)(v24.j.z * v15)) + (float)(v24.i.z * v12)) + v24.c.z;
      v20.x = (float)((float)((float)(v23[8] * v18) + (float)(v23[4] * v17)) + (float)(v23[0] * v16)) + v23[12];
      v20.y = (float)((float)((float)(v23[9] * v18) + (float)(v23[5] * v17)) + (float)(v23[1] * v16)) + v23[13];
      v20.z = (float)((float)((float)(v23[10] * v18) + (float)(v23[6] * v17)) + (float)(v23[2] * v16)) + v23[14];
      P->position = v20;
      P->spawn_position = v20;
    }
  }
}
