void __thiscall vostok::animation::mixing::n_ary_tree_deserializer::process_interpolators(
        vostok::animation::mixing::n_ary_tree_deserializer *this,
        unsigned int interpolators_mask)
{
  const vostok::animation::base_interpolator **m_interpolators; // edx
  int v3; // ebx
  char *v4; // eax
  float v5; // xmm0_4
  vostok::mutable_buffer *v6; // eax
  char *m_data; // eax
  vostok::mutable_buffer *m_buffer; // eax

  m_interpolators = this->m_interpolators;
  v3 = 0;
  if ( interpolators_mask )
  {
    while ( (interpolators_mask & 1) == 0 )
    {
LABEL_19:
      interpolators_mask >>= 1;
      ++v3;
      if ( !interpolators_mask )
        return;
    }
    if ( !v3 )
    {
      m_data = this->m_buffer->m_data;
      if ( m_data )
        *(_DWORD *)m_data = &vostok::animation::instant_interpolator::`vftable';
      else
        m_data = 0;
      *m_interpolators = (const vostok::animation::base_interpolator *)m_data;
      m_buffer = this->m_buffer;
      m_buffer->m_data += 4;
      ++m_interpolators;
      m_buffer->m_size -= 4;
      goto LABEL_19;
    }
    if ( v3 == 1 )
    {
      v4 = this->m_buffer->m_data;
      if ( v4 )
      {
        v5 = g_jump_prepare_interval_length;
        goto LABEL_12;
      }
    }
    else
    {
      v4 = this->m_buffer->m_data;
      if ( v3 == 2 )
      {
        if ( v4 )
        {
          v5 = g_short_jump_transition_time;
          goto LABEL_12;
        }
      }
      else if ( v4 )
      {
        v5 = s_aim_transition_time;
LABEL_12:
        *(_DWORD *)v4 = &vostok::animation::linear_interpolator::`vftable';
        *((float *)v4 + 1) = v5;
LABEL_14:
        *m_interpolators = (const vostok::animation::base_interpolator *)v4;
        v6 = this->m_buffer;
        v6->m_data += 8;
        ++m_interpolators;
        v6->m_size -= 8;
        goto LABEL_19;
      }
    }
    v4 = 0;
    goto LABEL_14;
  }
}
