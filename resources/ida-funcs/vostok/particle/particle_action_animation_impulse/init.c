void __thiscall vostok::particle::particle_action_animation_impulse::init(
        vostok::particle::particle_action_animation_impulse *this,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  unsigned __int16 surface_id; // ax
  vostok::particle::engine **p_m_engine; // edi
  const vostok::resources::resource_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base> *v6; // edx
  vostok::particle::particle_emitter_instance *v7; // ecx
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm5_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float z; // xmm5_4
  float v19; // xmm2_4
  float x; // xmm6_4
  float v21; // xmm7_4
  float v22; // xmm3_4
  float v23; // xmm4_4
  float v24; // xmm5_4
  float v25; // [esp+18h] [ebp-150h]
  float v26; // [esp+1Ch] [ebp-14Ch]
  __int64 v27; // [esp+1Ch] [ebp-14Ch]
  unsigned int surface_bone_index; // [esp+24h] [ebp-144h]
  vostok::math::float4x4 v29; // [esp+28h] [ebp-140h] BYREF
  float v30[16]; // [esp+68h] [ebp-100h] BYREF
  float v31[16]; // [esp+A8h] [ebp-C0h] BYREF
  vostok::math::float4x4 v32; // [esp+E8h] [ebp-80h] BYREF
  float v33[16]; // [esp+128h] [ebp-40h] BYREF

  surface_id = P->surface_id;
  if ( surface_id != 0xFFFF )
  {
    surface_bone_index = vostok::collision::animated_object::get_surface_bone_index(
                           instance->m_particle_system_instance->m_damage_model.m_object,
                           surface_id);
    p_m_engine = &instance->m_engine;
    (*p_m_engine)->get_bone_matrix(*p_m_engine, (vostok::math::float4x4 *)v30, v6 + 191, surface_bone_index);
    (*p_m_engine)->get_old_bone_matrix(
      *p_m_engine,
      (vostok::math::float4x4 *)v31,
      &instance->m_particle_system_instance->m_skeleton_model,
      surface_bone_index);
    vostok::physics::bt_animated_rigid_body::get_surface_point_transform(
      instance->m_particle_system_instance->m_damage_model.m_object->m_body,
      P->surface_id,
      &v29);
    vostok::particle::particle_emitter_instance::get_transform(v7, instance, &v32);
    v8 = (float)((float)((float)(P->surface_position.x * v29.i.x) + (float)(P->surface_position.z * v29.k.x))
               + (float)(P->surface_position.y * v29.j.x))
       + v29.c.x;
    v9 = (float)((float)((float)(P->surface_position.x * v29.i.z) + (float)(P->surface_position.y * v29.j.z))
               + (float)(P->surface_position.z * v29.k.z))
       + v29.c.z;
    v10 = (float)((float)((float)(P->surface_position.y * v29.j.y) + (float)(P->surface_position.z * v29.k.y))
                + (float)(P->surface_position.x * v29.i.y))
        + v29.c.y;
    v11 = (float)((float)((float)(v30[0] * v8) + (float)(v30[8] * v9)) + (float)(v30[4] * v10)) + v30[12];
    qmemcpy(v33, &instance->m_old_transform, sizeof(v33));
    v12 = (float)((float)((float)(v30[1] * v8) + (float)(v30[9] * v9)) + (float)(v30[5] * v10)) + v30[13];
    v13 = (float)((float)((float)(v30[2] * v8) + (float)(v30[10] * v9)) + (float)(v30[6] * v10)) + v30[14];
    v14 = (float)((float)(v32.i.x * v11) + (float)(v32.k.x * v13)) + (float)(v32.j.x * v12);
    v15 = (float)((float)(v32.i.y * v11) + (float)(v32.k.y * v13)) + (float)(v32.j.y * v12);
    v16 = v32.i.z * v11;
    v17 = v32.k.z * v13;
    z = P->surface_position.z;
    v19 = (float)((float)(v16 + v17) + (float)(v32.j.z * v12)) + v32.c.z;
    v25 = (float)((float)((float)(v29.i.x * P->surface_position.x) + (float)(v29.k.x * z))
                + (float)(P->surface_position.y * v29.j.x))
        + v29.c.x;
    x = P->surface_position.x;
    v26 = (float)((float)((float)(v29.j.y * P->surface_position.y) + (float)(v29.k.y * z)) + (float)(v29.i.y * x))
        + v29.c.y;
    v21 = (float)((float)((float)(v29.i.z * x) + (float)(v29.j.z * P->surface_position.y)) + (float)(v29.k.z * z))
        + v29.c.z;
    v22 = (float)((float)((float)(v31[0] * v25) + (float)(v31[8] * v21)) + (float)(v31[4] * v26)) + v31[12];
    v23 = (float)((float)((float)(v31[1] * v25) + (float)(v31[9] * v21)) + (float)(v31[5] * v26)) + v31[13];
    v24 = (float)((float)((float)(v31[2] * v25) + (float)(v31[10] * v21)) + (float)(v31[6] * v26)) + v31[14];
    *(float *)&v27 = (float)((float)(v15 + v32.c.y)
                           - (float)((float)((float)((float)(v33[9] * v24) + (float)(v33[5] * v23))
                                           + (float)(v33[1] * v22))
                                   + v33[13]))
                   * -100.0;
    *((float *)&v27 + 1) = (float)(v19
                                 - (float)((float)((float)((float)(v33[10] * v24) + (float)(v33[6] * v23))
                                                 + (float)(v33[2] * v22))
                                         + v33[14]))
                         * -100.0;
    P->animation_direction.x = (float)((float)(v14 + v32.c.x)
                                     - (float)((float)((float)((float)(v33[8] * v24) + (float)(v33[4] * v23))
                                                     + (float)(v33[0] * v22))
                                             + v33[12]))
                             * -100.0;
    *(_QWORD *)&P->animation_direction.elements[1] = v27;
  }
}
