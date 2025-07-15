char __userpurge survarium::bullet::try_pierce@<al>(
        survarium::hit_receiver *const hit_target@<ecx>,
        float a2@<edi>,
        survarium::bullet *this,
        const vostok::physics::closest_ray_result *ray_result,
        const vostok::math::float3 *direction,
        survarium::triangle_orientation orientation)
{
  __m128i v6; // xmm1
  float m_armor; // xmm3_4
  float m_pierce; // xmm2_4
  float v10; // xmm2_4
  float v11; // xmm5_4
  survarium::bullet_manager *m_bullet_manager; // ecx
  float v14; // xmm3_4
  float z; // xmm2_4
  float v16; // xmm5_4
  float v17; // xmm4_4
  float v18; // xmm2_4
  __m128i v19; // xmm0
  vostok::math::float4x4 *rotation; // eax
  float v21; // xmm1_4
  float v22; // xmm1_4
  survarium::bullet_manager *v23; // ecx
  float m_pierce_dispersion_angle; // xmm1_4
  const survarium::game_material *m_collided_material; // eax
  __m128i m_pierce_dispersion_koef_low; // xmm0
  vostok::math::float4x4 *v27; // eax
  float v28; // xmm4_4
  float y; // xmm5_4
  float x; // xmm3_4
  unsigned int v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm5_4
  float v34; // xmm4_4
  float v35; // xmm3_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // [esp+14h] [ebp-6Ch]
  float v39; // [esp+14h] [ebp-6Ch]
  _BYTE v40[64]; // [esp+24h] [ebp-5Ch] BYREF
  vostok::math::float3 v41; // [esp+64h] [ebp-1Ch] BYREF
  float v42; // [esp+70h] [ebp-10h] BYREF
  float v43; // [esp+74h] [ebp-Ch]
  float v44; // [esp+78h] [ebp-8h]
  float v45; // [esp+7Ch] [ebp-4h]
  float m_damage; // [esp+88h] [ebp+8h]
  float v47; // [esp+88h] [ebp+8h]

  v6 = (__m128i)LODWORD(s_bm_current_air_resistance);
  m_armor = this->m_collided_material->m_armor;
  m_pierce = this->m_pierce;
  m_damage = this->m_damage;
  v45 = m_pierce;
  if ( m_armor == 0.0 )
    goto LABEL_5;
  v10 = (float)(m_pierce - m_armor) / m_armor;
  if ( v10 <= 0.0 )
  {
    v10 = 0.0;
    goto LABEL_6;
  }
  if ( s_bm_current_air_resistance < v10 )
LABEL_5:
    v10 = s_bm_current_air_resistance;
LABEL_6:
  v11 = s_bm_current_air_resistance
      - (float)((float)(s_bm_current_air_resistance - v10) * (float)(s_bm_current_air_resistance - v10));
  if ( hit_target )
  {
    if ( hit_target == this->m_ignorable_object )
    {
      v11 = s_bm_current_air_resistance;
    }
    else
    {
      ((void (__stdcall *)(unsigned int, const survarium::hit_initiator *, int, _DWORD, _DWORD, _DWORD, survarium::bullet *, vostok::math::float3 *, survarium::triangle_orientation, _DWORD))hit_target->hit)(
        this->m_current_time_in_ms,
        this->m_initiator,
        ray_result->triangle_index,
        0,
        LODWORD(m_damage),
        LODWORD(v45),
        this,
        &ray_result->hit_point_world,
        orientation,
        this->m_weapon->m_dict_id);
      v11 = this->m_damage / m_damage;
      v6 = (__m128i)LODWORD(s_bm_current_air_resistance);
    }
  }
  if ( v11 <= 0.0 )
    return 0;
  this->m_damage = v11 * m_damage;
  m_bullet_manager = this->m_bullet_manager;
  this->m_pierce = v11 * v45;
  v14 = direction->y * 0.0;
  v47 = fsqrt(
          (float)((float)(this->m_velocity.z * this->m_velocity.z) + (float)(this->m_velocity.x * this->m_velocity.x))
        + (float)(this->m_velocity.y * this->m_velocity.y))
      * v11;
  z = direction->z;
  v16 = v14 - z;
  v17 = direction->x - v14;
  v18 = (float)(z * 0.0) - (float)(direction->x * 0.0);
  *(float *)v6.m128i_i32 = *(float *)v6.m128i_i32
                         / fsqrt((float)((float)(v17 * v17) + (float)(v18 * v18)) + (float)(v16 * v16));
  v42 = *(float *)v6.m128i_i32 * v16;
  v19 = v6;
  *(float *)v19.m128i_i32 = *(float *)v6.m128i_i32 * v18;
  v43 = *(float *)v6.m128i_i32 * v18;
  v44 = *(float *)v6.m128i_i32 * v17;
  v38 = vostok::math::random32::random_f(&m_bullet_manager->m_random, 6.2831855);
  rotation = vostok::math::create_rotation(direction, (int)v40, v19, v38);
  v21 = rotation->j.y * v43;
  v41.x = (float)((float)(rotation->k.x * v44) + (float)(rotation->j.x * v43)) + (float)(rotation->i.x * v42);
  *(float *)v19.m128i_i32 = (float)((float)(rotation->k.y * v44) + v21) + (float)(rotation->i.y * v42);
  v22 = rotation->j.z * v43;
  LODWORD(v41.y) = v19.m128i_i32[0];
  v23 = this->m_bullet_manager;
  *(float *)v19.m128i_i32 = (float)((float)(rotation->k.z * v44) + v22) + (float)(rotation->i.z * v42);
  m_pierce_dispersion_angle = this->m_weapon_ammunition->m_pierce_dispersion_angle;
  m_collided_material = this->m_collided_material;
  LODWORD(v41.z) = v19.m128i_i32[0];
  m_pierce_dispersion_koef_low = (__m128i)LODWORD(m_collided_material->m_pierce_dispersion_koef);
  *(float *)m_pierce_dispersion_koef_low.m128i_i32 = *(float *)m_pierce_dispersion_koef_low.m128i_i32
                                                   * m_pierce_dispersion_angle;
  v39 = vostok::math::random32::random_f(&v23->m_random, *(const float *)m_pierce_dispersion_koef_low.m128i_i32);
  v27 = vostok::math::create_rotation(&v41, (int)v40, m_pierce_dispersion_koef_low, v39);
  v28 = direction->z;
  y = direction->y;
  x = direction->x;
  *(float *)m_pierce_dispersion_koef_low.m128i_i32 = (float)((float)((float)(v27->j.x * y) + (float)(v27->k.x * v28))
                                                           + (float)(direction->x * v27->i.x))
                                                   * v47;
  *(float *)&v31 = (float)((float)((float)(v27->j.y * y) + (float)(v27->k.y * v28)) + (float)(v27->i.y * direction->x))
                 * v47;
  v32 = v27->j.z * y;
  v33 = v27->k.z * v28;
  v34 = v27->i.z * direction->x;
  *(_QWORD *)&v41.x = __PAIR64__(v31, m_pierce_dispersion_koef_low.m128i_u32[0]);
  v35 = (float)(x * 0.001) + ray_result->hit_point_world.x;
  v36 = direction->y * 0.001;
  v41.z = (float)((float)(v32 + v33) + v34) * v47;
  v37 = direction->z * 0.001;
  v43 = ray_result->hit_point_world.y + v36;
  v44 = ray_result->hit_point_world.z + v37;
  m_pierce_dispersion_koef_low.m128i_i32[0] = LODWORD(this->m_life_time);
  v42 = v35;
  survarium::bullet::change_trajectory(
    (survarium::bullet *)&v42,
    *(float *)m_pierce_dispersion_koef_low.m128i_i32,
    this,
    &v41,
    a2);
  return 1;
}
