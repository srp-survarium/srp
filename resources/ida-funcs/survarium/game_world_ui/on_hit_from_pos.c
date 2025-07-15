void __userpurge survarium::game_world_ui::on_hit_from_pos(
        const vostok::math::float3 *position@<eax>,
        unsigned int bullet_id@<ecx>,
        survarium::game_world_ui *this)
{
  unsigned int m_enemy_last_bullet; // edi
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm4_4
  vostok::math::float4x4 *v11; // eax
  vostok::math::float4x4 *v12; // ecx
  float *p_y; // ebx
  vostok::math::float4x4 *v14; // ecx
  float v15; // xmm0_4
  int v16; // edi
  survarium::flash_value *v17; // ecx
  survarium::flash_value *v18; // ecx
  int v19; // edx
  survarium::flash_value *v20; // ecx
  Scaleform::GFx::Value *v21; // esi
  vostok::math::float3 *v22; // [esp+4h] [ebp-11Ch]
  vostok::math::float3 *v23; // [esp+4h] [ebp-11Ch]
  vostok::math::axis_rotation_order v24; // [esp+8h] [ebp-118h]
  vostok::math::axis_rotation_order v25; // [esp+8h] [ebp-118h]
  vostok::math::float4x4 v26; // [esp+14h] [ebp-10Ch] BYREF
  vostok::math::float4x4 v27; // [esp+54h] [ebp-CCh] BYREF
  float v28[16]; // [esp+94h] [ebp-8Ch] BYREF
  survarium::flash_value v29; // [esp+D4h] [ebp-4Ch] BYREF
  _BYTE v30[24]; // [esp+ECh] [ebp-34h] BYREF
  vostok::math::float3 v31; // [esp+104h] [ebp-1Ch] BYREF
  vostok::math::float3 v32; // [esp+110h] [ebp-10h] BYREF

  m_enemy_last_bullet = this->m_enemy_last_bullet;
  if ( bullet_id > m_enemy_last_bullet || m_enemy_last_bullet == -1 )
  {
    this->m_enemy_last_bullet = bullet_id;
    x = position->x;
    y = position->y;
    z = position->z;
    qmemcpy(v28, &this->m_game_world->m_camera_director->m_inverted_view, sizeof(v28));
    LODWORD(v7) = COERCE_UNSIGNED_INT(x - v28[12]) ^ _mask__NegFloat_;
    LODWORD(v8) = COERCE_UNSIGNED_INT(y - v28[13]) ^ _mask__NegFloat_;
    LODWORD(v9) = COERCE_UNSIGNED_INT(z - v28[14]) ^ _mask__NegFloat_;
    v10 = s_bm_current_air_resistance / fsqrt((float)((float)(v9 * v9) + (float)(v8 * v8)) + (float)(v7 * v7));
    v31.x = v10 * v7;
    v31.y = v8 * v10;
    v31.z = v9 * v10;
    v32.x = 0.0;
    *(_QWORD *)&v32.elements[1] = LODWORD(s_bm_current_air_resistance);
    v11 = vostok::math::create_camera_direction(&v31, &v32, &v26, &position->x);
    vostok::math::invert4x3(v11, &v27);
    p_y = &vostok::math::float4x4::get_angles(v12, v22, v24)->y;
    v15 = *p_y - vostok::math::float4x4::get_angles(v14, v23, v25)->y;
    v16 = 1;
    v17 = &v29;
    do
    {
      survarium::flash_value::flash_value(v17);
      v17 = v18 + 1;
    }
    while ( v19 - 1 >= 0 );
    survarium::flash_value::SetNumber(v17, (int)&v29, COERCE_FLOAT(LODWORD(v15) ^ _mask__NegFloat_) - 1.5707964);
    survarium::flash_value::SetNumber(v20, (int)v30, 50.0);
    Scaleform::GFx::Movie::Invoke(
      this->m_game_hud_ui.m_object->movie->m_movie,
      "root.hit_player",
      0,
      (const Scaleform::GFx::Value *)&v29,
      2u);
    v21 = (Scaleform::GFx::Value *)&v31;
    do
    {
      Scaleform::GFx::Value::~Value(--v21);
      --v16;
    }
    while ( v16 >= 0 );
  }
}
