void __thiscall vostok::particle::particle_action_billboard::init(
        vostok::particle::particle_action_billboard *this,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time_delta)
{
  _BYTE *v4; // eax
  float right; // [esp+1Ch] [ebp-Ch] BYREF
  char v7; // [esp+23h] [ebp-5h]
  float num_images; // [esp+24h] [ebp-4h]

  v7 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v4 )
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)instance);
  if ( this->m_use_sub_uv )
  {
    num_images = (float)(this->m_billboard_parameters.sub_image_vertical
                       * this->m_billboard_parameters.sub_image_horizontal);
    if ( this->m_use_movie )
    {
      right = *(float *)&FLOAT_0_0;
      if ( vostok::math::is_similar<float>(&this->m_movie_start_frame, &right, 0.001) )
      {
        this->m_movie_start_frame = vostok::particle::random_float(0.0, num_images);
      }
      else
      {
        this->m_movie_start_frame = this->m_movie_start_frame - *(float *)&clear_value;
        vostok::math::clamp<float>(&this->m_movie_start_frame, 0.0, num_images);
      }
      P->subimage_index = this->m_movie_start_frame;
      if ( P->subimage_index > num_images )
        P->subimage_index = *(float *)&FLOAT_0_0;
      P->next_subimage_index = P->subimage_index + *(float *)&clear_value;
    }
  }
}
