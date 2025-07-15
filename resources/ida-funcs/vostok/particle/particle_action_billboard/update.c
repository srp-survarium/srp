void __userpurge vostok::particle::particle_action_billboard::update(
        vostok::particle::particle_action_billboard *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        vostok::particle::base_particle *a4@<xmm0>,
        vostok::particle::particle_emitter_instance *instance,
        float P,
        float time_delta)
{
  int v8; // edi
  float v9; // xmm0_4
  signed int v10; // eax
  vostok::particle::enum_particle_subuv_method subuv_method; // eax
  int v12; // edi
  unsigned int v13; // ebx
  int v14; // edi
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // [esp+0h] [ebp-28h]
  double min_value; // [esp+Ch] [ebp-1Ch]
  double max_value; // [esp+10h] [ebp-18h]
  float sub_image_changes; // [esp+20h] [ebp-8h]
  float v21; // [esp+24h] [ebp-4h]

  if ( this->m_use_sub_uv )
  {
    HIDWORD(max_value) = a3;
    v21 = (float)(this->m_billboard_parameters.sub_image_horizontal * this->m_billboard_parameters.sub_image_vertical);
    if ( this->m_use_movie )
    {
      v8 = LODWORD(P);
      v9 = (float)(this->m_movie_frame_rate * time_delta) + *(float *)(LODWORD(P) + 264);
      P = v9;
      *(float *)(v8 + 264) = v9;
      if ( v21 > 0.001 )
      {
        v10 = vostok::math::floor(v9 / v21);
        *(float *)(v8 + 264) = P - (float)((float)v10 * v21);
      }
      *(float *)(v8 + 268) = *(float *)(v8 + 264) + s_bm_current_air_resistance;
    }
    else
    {
      subuv_method = this->m_billboard_parameters.subuv_method;
      if ( subuv_method == particle_subuv_method_random || subuv_method == particle_subuv_method_random_smooth )
      {
        v14 = LODWORD(P);
        *(float *)(LODWORD(P) + 268) = *(float *)(LODWORD(P) + 264);
        sub_image_changes = (float)this->m_billboard_parameters.sub_image_changes;
        vostok::particle::base_particle::get_linear_lifetime_impl(
          (vostok::particle::base_particle *)this,
          v14,
          *(float *)(v14 + 248));
        LODWORD(max_value) = &P;
        P = *(float *)&a4;
        P = modf(*(float *)&a4, max_value);
        if ( COERCE_FLOAT(LODWORD(P) & 0x7FFFFFFF) < 0.001
          && COERCE_FLOAT(LODWORD(sub_image_changes) & 0x7FFFFFFF) < 0.001
          || (P = P * sub_image_changes, v15 = P, v16 = (float)(int)vostok::math::floor(P), v15 >= v16)
          && (float)((float)(sub_image_changes * time_delta) + v16) > v15 )
        {
          *(float *)(v14 + 264) = vostok::particle::random_float(0.0, v21);
        }
      }
      else
      {
        v12 = LODWORD(P);
        HIDWORD(min_value) = a2;
        v13 = *(_DWORD *)(LODWORD(P) + 284);
        vostok::particle::base_particle::get_linear_lifetime_impl(
          (vostok::particle::base_particle *)this,
          SLODWORD(P),
          *(float *)(LODWORD(P) + 248));
        LODWORD(min_value) = &P;
        P = *(float *)&a4;
        v17 = modf(*(float *)&a4, min_value);
        vostok::math::curve_line_ranged_base::evaluate(
          &this->m_subimage_index.m_line,
          v13,
          v17,
          0.0,
          this->m_subimage_index.m_evaluate_type,
          range_time_type);
        *(float *)(v12 + 264) = *(float *)&a4;
        *(float *)(v12 + 268) = *(float *)&a4 + s_bm_current_air_resistance;
      }
    }
  }
}
