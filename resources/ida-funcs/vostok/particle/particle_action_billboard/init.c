void __userpurge vostok::particle::particle_action_billboard::init(
        vostok::particle::particle_action_billboard *this@<ecx>,
        float a2@<xmm0>,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time_delta)
{
  vostok::math::curve_line_ranged_float *p_m_movie_start_frame; // esi
  unsigned int v6; // edx
  float v7; // xmm2_4
  float v8; // xmm0_4
  float *p_subimage_index; // eax
  float v10; // [esp+18h] [ebp-4h]

  if ( this->m_use_sub_uv )
  {
    v10 = (float)(this->m_billboard_parameters.sub_image_horizontal * this->m_billboard_parameters.sub_image_vertical);
    if ( this->m_use_movie )
    {
      p_m_movie_start_frame = &this->m_movie_start_frame;
      vostok::particle::particle_emitter_instance::get_linear_emitter_time((vostok::particle::particle_emitter_instance *)this);
      vostok::math::curve_line_ranged_base::evaluate(
        &p_m_movie_start_frame->m_line,
        v6,
        a2,
        0.0,
        p_m_movie_start_frame->m_evaluate_type,
        range_time_type);
      v7 = s_bm_current_air_resistance;
      v8 = a2 - s_bm_current_air_resistance;
      if ( v8 > 0.0 )
      {
        if ( v10 < v8 )
          v8 = v10;
      }
      else
      {
        v8 = 0.0;
      }
      p_subimage_index = &P->subimage_index;
      P->subimage_index = v8;
      if ( v8 > v10 )
        *p_subimage_index = 0.0;
      P->next_subimage_index = *p_subimage_index + v7;
    }
  }
}
