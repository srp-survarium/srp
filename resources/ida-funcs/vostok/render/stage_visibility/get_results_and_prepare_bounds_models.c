void __userpurge vostok::render::stage_visibility::get_results_and_prepare_bounds_models(
        unsigned int *out_counter@<edi>,
        vostok::render::stage_visibility *this,
        vostok::math::float4 **out_bounds)
{
  vostok::render::base_scene_view *m_object; // eax
  volatile int m_flags; // ebp
  volatile int i; // esi
  int v6; // ecx
  int v7; // eax
  bool v8; // al
  int v9; // eax
  __int64 v10; // xmm0_8
  int v11; // eax
  const vostok::math::float4x4 *v12; // [esp+4h] [ebp-3Ch]
  __int64 v13; // [esp+14h] [ebp-2Ch]
  __int64 v14; // [esp+1Ch] [ebp-24h]
  __int64 v15; // [esp+2Ch] [ebp-14h]
  float v16[3]; // [esp+34h] [ebp-Ch]

  m_object = this->m_context->m_scene_view.m_object;
  m_flags = m_object[4].vostok::resources::unmanaged_resource::vostok::resources::unmanaged_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags.vostok::resources::unmanaged_resource::vostok::resources::unmanaged_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags;
  for ( i = m_object[4].m_reference_count; i != m_flags; *out_bounds = (vostok::math::float4 *)(v11 + 16) )
  {
    v6 = *(_DWORD *)i;
    v7 = *(_DWORD *)(*(_DWORD *)i + 12);
    v8 = v7 != -1 && this->m_static_results_array[v7] == 0;
    *(_BYTE *)(v6 + 25) = v8;
    v9 = *out_counter;
    *(_DWORD *)(v6 + 12) = *out_counter;
    *out_counter = v9 + 1;
    v10 = *(_QWORD *)(*(_DWORD *)v6 + 8);
    v15 = *(_QWORD *)(*(_DWORD *)v6 + 16);
    *(_QWORD *)v16 = *(_QWORD *)(*(_DWORD *)v6 + 24);
    vostok::math::aabb::modify(*(vostok::math::aabb **)(v6 + 4), v12);
    *(float *)&v13 = (float)(*((float *)&v15 + 1) + *(float *)&v10) * 0.5;
    *((float *)&v13 + 1) = (float)(v16[0] + *((float *)&v10 + 1)) * 0.5;
    *(float *)&v14 = (float)(v16[1] + *(float *)&v15) * 0.5;
    *((float *)&v14 + 1) = sqrtf(
                             (float)((float)((float)((float)(v16[1] - *(float *)&v15) * 0.5)
                                           * (float)((float)(v16[1] - *(float *)&v15) * 0.5))
                                   + (float)((float)((float)(v16[0] - *((float *)&v10 + 1)) * 0.5)
                                           * (float)((float)(v16[0] - *((float *)&v10 + 1)) * 0.5)))
                           + (float)((float)((float)(*((float *)&v15 + 1) - *(float *)&v10) * 0.5)
                                   * (float)((float)(*((float *)&v15 + 1) - *(float *)&v10) * 0.5)));
    v11 = (int)*out_bounds;
    *(_QWORD *)v11 = v13;
    *(_QWORD *)(v11 + 8) = v14;
    i += 4;
  }
}
