void __thiscall vostok::particle::base_particle::set_defaults(vostok::particle::base_particle *this)
{
  vostok::math::float3 *v1; // eax
  vostok::math::float3 *v2; // eax
  float *v3; // eax
  float *v4; // eax
  float *v5; // eax
  float *v6; // eax
  float *v7; // eax
  float *v8; // eax
  float *v9; // eax
  float *v10; // eax
  float *v11; // eax
  float *v12; // eax
  float *v13; // eax
  vostok::particle::base_particle *thisb; // [esp+Ch] [ebp-A4h]
  vostok::math::float3 v16; // [esp+10h] [ebp-A0h] BYREF
  vostok::math::float3 v17; // [esp+1Ch] [ebp-94h] BYREF
  vostok::math::float3 v18; // [esp+28h] [ebp-88h] BYREF
  vostok::math::float3 v19; // [esp+34h] [ebp-7Ch] BYREF
  vostok::math::float3 v20; // [esp+40h] [ebp-70h] BYREF
  vostok::math::float3 v21; // [esp+4Ch] [ebp-64h] BYREF
  vostok::math::float3 v22; // [esp+58h] [ebp-58h] BYREF
  vostok::math::float3 v23; // [esp+64h] [ebp-4Ch] BYREF
  vostok::math::float3 v24; // [esp+70h] [ebp-40h] BYREF
  vostok::math::float3 v25; // [esp+7Ch] [ebp-34h] BYREF
  _BYTE v26[16]; // [esp+88h] [ebp-28h] BYREF
  vostok::math::float3 v27; // [esp+98h] [ebp-18h] BYREF
  vostok::math::float3 v28; // [esp+A4h] [ebp-Ch] BYREF

  this->gravity_accumulation = *(float *)&FLOAT_0_0;
  vostok::math::float3::float3(&v28, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  this->render_position = *v1;
  vostok::math::float3::float3(&v27, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  this->render_old_position = *v2;
  v3 = (float *)vostok::math::float4::float4(
                  (vostok::math::float4 *)&this->render_old_position,
                  (int)v26,
                  (int)clear_value,
                  1.0,
                  1.0,
                  1.0,
                  *(float *)&this);
  thisb->color.x = *v3;
  thisb->color.y = v3[1];
  thisb->color.z = v3[2];
  thisb->color.w = v3[3];
  thisb->target_color_y_position = FLOAT_0_5;
  thisb->lifetime = *(float *)&FLOAT_0_0;
  thisb->duration = *(float *)&FLOAT_0_0;
  thisb->next = 0;
  vostok::math::float3::float3(&v25, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  thisb->position.x = *v4;
  thisb->position.y = v4[1];
  thisb->position.z = v4[2];
  vostok::math::float3::float3(&v24, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  thisb->spawn_position.x = *v5;
  thisb->spawn_position.y = v5[1];
  thisb->spawn_position.z = v5[2];
  vostok::math::float3::float3(&v23, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  thisb->old_position.x = *v6;
  thisb->old_position.y = v6[1];
  thisb->old_position.z = v6[2];
  thisb->rotation = *(float *)&FLOAT_0_0;
  vostok::math::float3::float3(&v22, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  thisb->rotation_rate.x = *v7;
  thisb->rotation_rate.y = v7[1];
  thisb->rotation_rate.z = v7[2];
  vostok::math::float3::float3(&v21, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  thisb->start_rotation_rate.x = *v8;
  thisb->start_rotation_rate.y = v8[1];
  thisb->start_rotation_rate.z = v8[2];
  thisb->rotationY = *(float *)&FLOAT_0_0;
  thisb->rotationZ = *(float *)&FLOAT_0_0;
  vostok::math::float3::float3(&v20, COERCE_UNSIGNED_INT(1.0), COERCE_UNSIGNED_INT(1.0), 1.0);
  thisb->size.x = *v9;
  thisb->size.y = v9[1];
  thisb->size.z = v9[2];
  vostok::math::float3::float3(&v19, COERCE_UNSIGNED_INT(1.0), COERCE_UNSIGNED_INT(1.0), 1.0);
  thisb->start_size.x = *v10;
  thisb->start_size.y = v10[1];
  thisb->start_size.z = v10[2];
  vostok::math::float3::float3(&v18, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  thisb->start_velocity.x = *v11;
  thisb->start_velocity.y = v11[1];
  thisb->start_velocity.z = v11[2];
  vostok::math::float3::float3(&v17, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  thisb->velocity.x = *v12;
  thisb->velocity.y = v12[1];
  thisb->velocity.z = v12[2];
  thisb->next = 0;
  thisb->subimage_index = *(float *)&FLOAT_0_0;
  thisb->next_subimage_index = *(float *)&FLOAT_0_0;
  vostok::math::float3::float3(&v16, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  thisb->prev_offset_position.x = *v13;
  thisb->prev_offset_position.y = v13[1];
  thisb->prev_offset_position.z = v13[2];
  thisb->m_seed = 0;
  thisb->gravity = *(float *)&FLOAT_0_0;
}
