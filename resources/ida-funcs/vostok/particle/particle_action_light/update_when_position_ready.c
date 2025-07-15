void __userpurge vostok::particle::particle_action_light::update_when_position_ready(
        vostok::particle::particle_action_light *this@<ecx>,
        float a2@<xmm0>,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  unsigned int m_seed; // esi
  unsigned int v8; // esi
  vostok::particle::base_particle *v9; // ecx
  unsigned int v10; // esi
  vostok::particle::base_particle *v11; // ecx
  unsigned int v12; // esi
  vostok::particle::base_particle *v13; // ecx
  unsigned int v14; // esi
  vostok::particle::base_particle *v15; // ecx
  vostok::particle::base_particle *v16; // ecx
  bool v17; // zf
  double lifetime; // st7
  float v19; // xmm0_4
  vostok::math::curve_line_color *v20; // ecx
  vostok::particle::base_particle *v21; // esi
  vostok::particle::engine *m_engine; // eax
  int *p_y; // esi
  vostok::particle::engine_vtbl *v24; // eax
  vostok::math::float4x4 *v25; // eax
  BOOL m_static_shadows; // edx
  double m_shadow_transparency; // st7
  BOOL m_enable_shadows; // ecx
  _DWORD v29[16]; // [esp+14h] [ebp-F0h] BYREF
  vostok::math::enum_evaluate_type m_evaluate_type; // [esp+6Ch] [ebp-98h]
  int lifetime_low; // [esp+70h] [ebp-94h]
  vostok::particle::particle_action_light *v32; // [esp+84h] [ebp-80h]
  float v33; // [esp+88h] [ebp-7Ch]
  float v34; // [esp+8Ch] [ebp-78h]
  float v35; // [esp+90h] [ebp-74h]
  float v36; // [esp+94h] [ebp-70h]
  float v37; // [esp+98h] [ebp-6Ch]
  vostok::particle::engine *v38; // [esp+9Ch] [ebp-68h]
  void (__thiscall **p_update_light)(_DWORD, unsigned int, float, _DWORD, _DWORD, _DWORD, unsigned int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, float, float, float, float, _DWORD, _DWORD, vostok::math::enum_evaluate_type, int); // [esp+A0h] [ebp-64h]
  float x; // [esp+A4h] [ebp-60h]
  int v41; // [esp+A8h] [ebp-5Ch]
  int v42; // [esp+ACh] [ebp-58h]
  unsigned int v43; // [esp+B0h] [ebp-54h]
  vostok::math::float4 v44; // [esp+B4h] [ebp-50h] BYREF
  vostok::math::float4x4 v45; // [esp+C4h] [ebp-40h] BYREF

  m_seed = P->m_seed;
  lifetime_low = SLODWORD(P->lifetime);
  v32 = this;
  vostok::particle::base_particle::get_linear_lifetime_impl(
    (vostok::particle::base_particle *)this,
    (int)P,
    *(float *)&lifetime_low);
  lifetime_low = 1;
  m_evaluate_type = this->m_radius.m_evaluate_type;
  v33 = a2;
  vostok::math::curve_line_ranged_base::evaluate(
    &this->m_radius.m_line,
    m_seed,
    a2,
    0.0,
    m_evaluate_type,
    range_time_type);
  v8 = P->m_seed;
  lifetime_low = SLODWORD(P->lifetime);
  v37 = a2;
  vostok::particle::base_particle::get_linear_lifetime_impl(v9, (int)P, *(float *)&lifetime_low);
  lifetime_low = 1;
  m_evaluate_type = this->m_attenuation.m_evaluate_type;
  v33 = a2;
  vostok::math::curve_line_ranged_base::evaluate(
    &this->m_attenuation.m_line,
    v8,
    a2,
    0.0,
    m_evaluate_type,
    range_time_type);
  v10 = P->m_seed;
  lifetime_low = SLODWORD(P->lifetime);
  v36 = a2;
  vostok::particle::base_particle::get_linear_lifetime_impl(v11, (int)P, *(float *)&lifetime_low);
  lifetime_low = 1;
  m_evaluate_type = this->m_intensity.m_evaluate_type;
  v33 = a2;
  vostok::math::curve_line_ranged_base::evaluate(
    &this->m_intensity.m_line,
    v10,
    a2,
    0.0,
    m_evaluate_type,
    range_time_type);
  v12 = P->m_seed;
  lifetime_low = SLODWORD(P->lifetime);
  v35 = a2;
  vostok::particle::base_particle::get_linear_lifetime_impl(v13, (int)P, *(float *)&lifetime_low);
  lifetime_low = 1;
  m_evaluate_type = this->m_diffuse_factor.m_evaluate_type;
  v33 = a2;
  vostok::math::curve_line_ranged_base::evaluate(
    &this->m_diffuse_factor.m_line,
    v12,
    a2,
    0.0,
    m_evaluate_type,
    range_time_type);
  v14 = P->m_seed;
  lifetime_low = SLODWORD(P->lifetime);
  v34 = a2;
  vostok::particle::base_particle::get_linear_lifetime_impl(v15, (int)P, *(float *)&lifetime_low);
  lifetime_low = 1;
  m_evaluate_type = this->m_specular_factor.m_evaluate_type;
  v33 = a2;
  vostok::math::curve_line_ranged_base::evaluate(
    &this->m_specular_factor.m_line,
    v14,
    a2,
    0.0,
    m_evaluate_type,
    range_time_type);
  v17 = !this->m_enable_color;
  v33 = a2;
  if ( v17 )
  {
    v21 = P;
  }
  else
  {
    lifetime = P->lifetime;
    x = 0.0;
    v41 = 0;
    v42 = 0;
    v19 = s_bm_current_air_resistance;
    *(float *)&lifetime_low = lifetime;
    v43 = LODWORD(s_bm_current_air_resistance);
    vostok::particle::base_particle::get_linear_lifetime_impl(v16, (int)P, *(float *)&lifetime_low);
    v21 = (vostok::particle::base_particle *)vostok::math::curve_line_color::evaluate(
                                               v20,
                                               (vostok::math::float4 *)&v32->m_color,
                                               &v44,
                                               (vostok::math::float4)COERCE_UNSIGNED_INT(v19 * s_spot_max_distance),
                                               v43);
  }
  m_engine = instance->m_engine;
  x = v21->color.x;
  p_y = (int *)&v21->color.y;
  v41 = *p_y++;
  v38 = m_engine;
  v24 = m_engine->__vftable;
  v42 = *p_y;
  p_update_light = (void (__thiscall **)(_DWORD, unsigned int, float, _DWORD, _DWORD, _DWORD, unsigned int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, float, float, float, float, _DWORD, _DWORD, vostok::math::enum_evaluate_type, int))&v24->update_light;
  v43 = p_y[1];
  v25 = vostok::math::create_translation(&P->render_position, &v45);
  lifetime_low = v32->m_shadow_map_size_index;
  m_static_shadows = v32->m_static_shadows;
  m_shadow_transparency = v32->m_shadow_transparency;
  m_evaluate_type = (vostok::math::enum_evaluate_type)v32;
  m_enable_shadows = v32->m_enable_shadows;
  *(float *)&m_evaluate_type = m_shadow_transparency;
  qmemcpy(v29, v25, sizeof(v29));
  (*p_update_light)(
    v38,
    P->particle_light_id,
    COERCE_FLOAT(LODWORD(v37)),
    LODWORD(x),
    v41,
    v42,
    v43,
    v29[0],
    v29[1],
    v29[2],
    v29[3],
    v29[4],
    v29[5],
    v29[6],
    v29[7],
    v29[8],
    v29[9],
    v29[10],
    v29[11],
    v29[12],
    v29[13],
    v29[14],
    v29[15],
    COERCE_FLOAT(LODWORD(v36)),
    COERCE_FLOAT(LODWORD(v35)),
    COERCE_FLOAT(LODWORD(v34)),
    COERCE_FLOAT(LODWORD(v33)),
    m_enable_shadows,
    m_static_shadows,
    m_evaluate_type,
    lifetime_low);
}
