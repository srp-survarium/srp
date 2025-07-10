vostok::math::float4x4 *__userpurge vostok::render::speedtree_forest::get_instance_transform@<eax>(
        vostok::render::speedtree_forest *this@<ecx>,
        int a2@<eax>,
        vostok::math::float4x4 *result,
        const SpeedTree::CInstance *in_instance)
{
  int v4; // edx
  int v5; // ebx
  vostok::render::shader_constant_host *m_wind_dir_parameter; // xmm0_4
  float *v8; // ecx
  vostok::math::float4x4 *v9; // esi
  vostok::math::float4x4 v11; // [esp+10h] [ebp-40h] BYREF

  v4 = *(_DWORD *)(a2 + 4364);
  v5 = *(_DWORD *)(a2 + 4368);
  if ( v4 == v5 )
  {
LABEL_7:
    v9 = vostok::math::float4x4::identity(&v11);
  }
  else
  {
    m_wind_dir_parameter = this->m_speedtree_wind_parameters.m_wind_dir_parameter;
    while ( 1 )
    {
      v8 = *(float **)(*(_DWORD *)v4 + 336);
      if ( *(float *)&m_wind_dir_parameter == *v8
        && *(float *)&this->m_speedtree_wind_parameters.m_wind_times_parameter == v8[1]
        && *(float *)&this->m_speedtree_wind_parameters.m_wind_distances_parameter == v8[2] )
      {
        break;
      }
      v4 += 4;
      if ( v4 == v5 )
        goto LABEL_7;
    }
    v9 = (vostok::math::float4x4 *)(*(_DWORD *)v4 + 264);
  }
  qmemcpy((void *)result, v9, sizeof(vostok::math::float4x4));
  return result;
}
