char __userpurge survarium::object_track::evaluate@<al>(
        survarium::object_track *this@<ecx>,
        vostok::math::float4x4 *m@<eax>,
        float in_time)
{
  survarium::object_track *v3; // esi
  float m_max_time; // xmm1_4
  signed int v6; // eax
  float on_track_position; // [esp+0h] [ebp-5Ch]
  survarium::object_track *on_track_positiona; // [esp+0h] [ebp-5Ch]
  float v10; // [esp+14h] [ebp-48h]
  vostok::math::float4x4 v11; // [esp+1Ch] [ebp-40h] BYREF

  v3 = this;
  v10 = in_time;
  if ( this->m_cyclic )
  {
    m_max_time = this->m_max_time;
    if ( in_time > m_max_time )
    {
      on_track_position = in_time / m_max_time;
      if ( on_track_position <= 0.0 )
        v6 = vostok::math::ceil(on_track_position);
      else
        v6 = vostok::math::floor(on_track_position);
      this = on_track_positiona;
      v10 = in_time - (float)((float)v6 * m_max_time);
    }
  }
  vostok::animation::anm_track::evaluate((vostok::animation::anm_track *)this, &v3->m_track->m_channels, (int)m, m, v10);
  vostok::math::mul4x3(&v3->m_transform, m, &v11);
  qmemcpy(m, &v11, sizeof(vostok::math::float4x4));
  return 1;
}
