void __userpurge vostok::render::stage_visibility::get_results_and_prepare_bounds_ambient_volumes(
        unsigned int *out_counter@<edi>,
        vostok::render::stage_visibility *this,
        vostok::math::float4 **out_bounds)
{
  vostok::render::base_scene_view *m_object; // eax
  int m_reconstruction_info_actuality_tick_high; // ebp
  int i; // esi
  int v6; // eax
  bool v7; // al
  int v8; // eax
  vostok::math::aabb *v9; // eax
  int v10; // eax
  const vostok::math::float4x4 *v11; // [esp+4h] [ebp-94h]
  __int64 v12; // [esp+14h] [ebp-84h]
  __int64 v13; // [esp+1Ch] [ebp-7Ch]
  __int64 v14; // [esp+3Ch] [ebp-5Ch]
  __int64 v15; // [esp+44h] [ebp-54h]
  __int64 v16; // [esp+4Ch] [ebp-4Ch]
  vostok::math::float4x4 v17; // [esp+54h] [ebp-44h] BYREF

  m_object = this->m_context->m_scene_view.m_object;
  m_reconstruction_info_actuality_tick_high = HIDWORD(m_object[5].m_reconstruction_info_actuality_tick);
  for ( i = m_object[5].m_reconstruction_info_actuality_tick;
        i != m_reconstruction_info_actuality_tick_high;
        *out_bounds = (vostok::math::float4 *)(v10 + 16) )
  {
    v6 = *(_DWORD *)(*(_DWORD *)i + 104);
    v7 = v6 != -1 && this->m_static_results_array[v6] == 0;
    *(_BYTE *)(*(_DWORD *)i + 108) = v7;
    v8 = *out_counter;
    *(_DWORD *)(*(_DWORD *)i + 104) = *out_counter;
    *out_counter = v8 + 1;
    v14 = *(_QWORD *)(*(_DWORD *)i + 76);
    v15 = *(_QWORD *)(*(_DWORD *)i + 84);
    v16 = *(_QWORD *)(*(_DWORD *)i + 92);
    v9 = (vostok::math::aabb *)vostok::math::float4x4::identity(&v17);
    vostok::math::aabb::modify(v9, v11);
    *(float *)&v12 = (float)(*((float *)&v15 + 1) + *(float *)&v14) * 0.5;
    *((float *)&v12 + 1) = (float)(*(float *)&v16 + *((float *)&v14 + 1)) * 0.5;
    *(float *)&v13 = (float)(*((float *)&v16 + 1) + *(float *)&v15) * 0.5;
    *((float *)&v13 + 1) = sqrtf(
                             (float)((float)((float)((float)(*((float *)&v16 + 1) - *(float *)&v15) * 0.5)
                                           * (float)((float)(*((float *)&v16 + 1) - *(float *)&v15) * 0.5))
                                   + (float)((float)((float)(*((float *)&v15 + 1) - *(float *)&v14) * 0.5)
                                           * (float)((float)(*((float *)&v15 + 1) - *(float *)&v14) * 0.5)))
                           + (float)((float)((float)(*(float *)&v16 - *((float *)&v14 + 1)) * 0.5)
                                   * (float)((float)(*(float *)&v16 - *((float *)&v14 + 1)) * 0.5)));
    v10 = (int)*out_bounds;
    *(_QWORD *)v10 = v12;
    *(_QWORD *)(v10 + 8) = v13;
    i += 4;
  }
}
