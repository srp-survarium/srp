void __thiscall vostok::particle::particle_action_billboard::update(
        vostok::particle::particle_action_billboard *this,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time_delta)
{
  _BYTE *v4; // eax
  float time; // [esp+2Ch] [ebp-78h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *seed; // [esp+58h] [ebp-4Ch]
  float v8; // [esp+84h] [ebp-20h] BYREF
  float right; // [esp+88h] [ebp-1Ch] BYREF
  char v10; // [esp+8Fh] [ebp-15h]
  float f_position; // [esp+90h] [ebp-14h]
  float num_images_per_lifetime; // [esp+94h] [ebp-10h] BYREF
  float particle_time; // [esp+98h] [ebp-Ch] BYREF
  float i_position; // [esp+9Ch] [ebp-8h]
  float num_images; // [esp+A0h] [ebp-4h]

  v10 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v4 )
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)instance);
  if ( this->m_use_sub_uv )
  {
    num_images = (float)(this->m_billboard_parameters.sub_image_vertical
                       * this->m_billboard_parameters.sub_image_horizontal);
    if ( this->m_use_movie )
    {
      P->subimage_index = (float)(time_delta * this->m_movie_frame_rate) + P->subimage_index;
      if ( P->subimage_index > num_images )
        P->subimage_index = *(float *)&FLOAT_0_0;
      P->next_subimage_index = P->subimage_index + *(float *)&clear_value;
    }
    else if ( this->m_billboard_parameters.subuv_method == particle_subuv_method_random
           || this->m_billboard_parameters.subuv_method == particle_subuv_method_random_smooth )
    {
      P->next_subimage_index = P->subimage_index;
      num_images_per_lifetime = (float)this->m_billboard_parameters.sub_image_changes;
      particle_time = vostok::particle::frac(P->lifetime);
      right = *(float *)&FLOAT_0_0;
      if ( vostok::math::is_similar<float>(&particle_time, &right, 0.001)
        && (v8 = *(float *)&FLOAT_0_0, vostok::math::is_similar<float>(&num_images_per_lifetime, &v8, 0.001)) )
      {
        P->subimage_index = vostok::particle::random_float(0.0, num_images);
      }
      else
      {
        f_position = particle_time * num_images_per_lifetime;
        i_position = (float)(int)vostok::math::floor(particle_time * num_images_per_lifetime);
        if ( f_position >= i_position
          && (float)((float)(time_delta * num_images_per_lifetime) + i_position) > f_position )
        {
          P->subimage_index = vostok::particle::random_float(0.0, num_images);
        }
      }
    }
    else
    {
      seed = (boost::_bi::list1<vostok::network_core::packet_reader &> *)P->m_seed;
      time = vostok::particle::frac(P->lifetime);
      P->subimage_index = vostok::particle::curve_line_ranged_base::evaluate(
                            &this->m_subimage_index.m_line,
                            time,
                            0.0,
                            this->m_subimage_index.m_evaluate_type,
                            range_time_type,
                            seed);
      P->next_subimage_index = P->subimage_index + *(float *)&clear_value;
    }
  }
}
