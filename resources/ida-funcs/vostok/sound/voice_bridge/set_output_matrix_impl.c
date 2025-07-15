void __userpurge vostok::sound::voice_bridge::set_output_matrix_impl(
        vostok::sound::voice_bridge *this@<esi>,
        const float *level_matrix@<edi>,
        bool force)
{
  unsigned __int8 channels_num; // bl
  unsigned int v4; // eax
  unsigned int m_master_channels_num; // [esp-8h] [ebp-10h]
  unsigned int v6; // [esp+0h] [ebp-8h]
  unsigned int v7; // [esp+0h] [ebp-8h]

  channels_num = this->m_params.channels_num;
  if ( channels_num == 1 )
  {
    if ( force
      || !vostok::math::is_similar<float>(this->m_output_level_matrix, level_matrix, 0.0000099999997)
      || !vostok::math::is_similar<float>(&this->m_output_level_matrix[1], level_matrix + 1, 0.0000099999997) )
    {
      v6 = vostok::sound::voice_bridge::operation_set;
      this->m_output_level_matrix[0] = *level_matrix;
      m_master_channels_num = this->m_master_channels_num;
      this->m_output_level_matrix[1] = level_matrix[1];
      this->m_output_level_matrix[2] = 0.0;
      this->m_output_level_matrix[3] = 0.0;
      this->m_source_voice->SetOutputMatrix(
        this->m_source_voice,
        this->m_output_voice,
        1u,
        m_master_channels_num,
        this->m_output_level_matrix,
        v6);
    }
  }
  else if ( force
         || !vostok::math::is_similar<float>(this->m_output_level_matrix, level_matrix, 0.0000099999997)
         || !vostok::math::is_similar<float>(&this->m_output_level_matrix[1], level_matrix + 1, 0.0000099999997)
         || !vostok::math::is_similar<float>(&this->m_output_level_matrix[2], level_matrix + 2, 0.0000099999997)
         || !vostok::math::is_similar<float>(&this->m_output_level_matrix[3], level_matrix + 3, 0.0000099999997) )
  {
    v7 = vostok::sound::voice_bridge::operation_set;
    this->m_output_level_matrix[0] = *level_matrix;
    v4 = this->m_master_channels_num;
    this->m_output_level_matrix[1] = level_matrix[1];
    this->m_output_level_matrix[2] = level_matrix[2];
    this->m_output_level_matrix[3] = level_matrix[3];
    this->m_source_voice->SetOutputMatrix(
      this->m_source_voice,
      this->m_output_voice,
      channels_num,
      v4,
      this->m_output_level_matrix,
      v7);
  }
}
