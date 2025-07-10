void __thiscall vostok::render::skeleton_render_model_instance::update(
        vostok::render::skeleton_render_model_instance *this)
{
  vostok::render::skeleton_render_model_instance *v1; // ebx
  vostok::render::render_surface_instance *v2; // ebp
  vostok::render::skeleton_render_model *m_object; // eax
  const vostok::math::float4x4 *M_start; // esi
  const vostok::math::float4x4 *M_finish; // ebx
  vostok::math::float4x4 *v6; // edi
  int p_m_aabbox; // eax
  const vostok::math::float4x4 *v8; // eax
  vostok::math::float4x4 *v9; // eax
  float x; // xmm1_4
  float *p_x; // eax
  int v12; // ecx
  int v13; // [esp+14h] [ebp-F0h]
  unsigned int i; // [esp+1Ch] [ebp-E8h]
  __int64 v16; // [esp+20h] [ebp-E4h]
  int v17; // [esp+28h] [ebp-DCh]
  __int64 v18; // [esp+2Ch] [ebp-D8h]
  float z; // [esp+34h] [ebp-D0h]
  vostok::math::float4x4 left; // [esp+44h] [ebp-C0h] BYREF
  vostok::math::float4x4 result; // [esp+84h] [ebp-80h] BYREF

  v1 = this;
  vostok::render::skeleton_render_model::update(this->m_original.m_object, &this->m_bones_matrices);
  i = 0;
  if ( v1->m_instances_count )
  {
    v13 = 0;
    do
    {
      v2 = &v1->m_surface_instances[v13];
      if ( (v2->m_flags & 1) != 0 )
      {
        m_object = v1->m_original.m_object;
        M_start = m_object->m_inverted_bones_matrices_in_bind_pose._M_impl._M_start;
        M_finish = m_object->m_inverted_bones_matrices_in_bind_pose._M_impl._M_finish;
        v6 = this->m_bones_matrices._M_impl._M_start;
        p_m_aabbox = (int)&v2->m_render_surface->m_aabbox;
        *(_QWORD *)(p_m_aabbox + 12) = 0;
        *(_QWORD *)p_m_aabbox = 0;
        *(_DWORD *)(p_m_aabbox + 20) = 0;
        for ( *(_DWORD *)(p_m_aabbox + 8) = 0; M_start != M_finish; *(_DWORD *)(v12 + 20) = v17 )
        {
          invert_impl(
            M_start,
            (float)((float)((float)((float)(M_start->j.y * M_start->k.z) - (float)(M_start->j.z * M_start->k.y))
                          * M_start->i.x)
                  - (float)((float)((float)(M_start->j.x * M_start->k.z) - (float)(M_start->k.x * M_start->j.z))
                          * M_start->i.y))
          + (float)((float)((float)(M_start->j.x * M_start->k.y) - (float)(M_start->k.x * M_start->j.y)) * M_start->i.z));
          v8 = vostok::math::transpose(&result, v6);
          v9 = vostok::math::mul4x4(&left, v8);
          x = v9->c.x;
          p_x = &v9->c.x;
          v12 = (int)&v2->m_render_surface->m_aabbox;
          if ( x <= *(float *)v12 )
            *(float *)&v18 = x;
          else
            *(float *)&v18 = v2->m_render_surface->m_aabbox.min.x;
          if ( p_x[1] <= v2->m_render_surface->m_aabbox.min.y )
            *((float *)&v18 + 1) = p_x[1];
          else
            HIDWORD(v18) = LODWORD(v2->m_render_surface->m_aabbox.min.y);
          if ( p_x[2] <= v2->m_render_surface->m_aabbox.min.z )
            z = p_x[2];
          else
            z = v2->m_render_surface->m_aabbox.min.z;
          *(_QWORD *)v12 = v18;
          *(float *)(v12 + 8) = z;
          if ( *(float *)(v12 + 12) <= *p_x )
            *(float *)&v16 = *p_x;
          else
            LODWORD(v16) = *(_DWORD *)(v12 + 12);
          if ( *(float *)(v12 + 16) <= p_x[1] )
            *((float *)&v16 + 1) = p_x[1];
          else
            HIDWORD(v16) = *(_DWORD *)(v12 + 16);
          if ( *(float *)(v12 + 20) <= p_x[2] )
            v17 = *((_DWORD *)p_x + 2);
          else
            v17 = *(_DWORD *)(v12 + 20);
          ++M_start;
          ++v6;
          *(_QWORD *)(v12 + 12) = v16;
        }
        v1 = this;
      }
      ++v13;
      ++i;
    }
    while ( i < v1->m_instances_count );
  }
}
