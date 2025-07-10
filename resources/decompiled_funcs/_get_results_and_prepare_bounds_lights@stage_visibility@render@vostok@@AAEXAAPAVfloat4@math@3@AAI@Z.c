void __thiscall vostok::render::stage_visibility::get_results_and_prepare_bounds_lights(
        vostok::render::stage_visibility *this,
        vostok::math::float4 **out_bounds,
        vostok::math::float4 **out_counter,
        vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *end)
{
  float z; // eax
  vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v6; // esi
  unsigned int m_occlusion_info_index; // eax
  bool v8; // al
  vostok::render::light *m_object; // eax
  vostok::render::light *v10; // edi
  vostok::math::aabb *v11; // eax
  vostok::math::float4 *v12; // eax
  const vostok::math::float4x4 *v13; // [esp+4h] [ebp-78h]
  __int64 v14; // [esp+14h] [ebp-68h]
  __int64 v15; // [esp+1Ch] [ebp-60h]
  __int64 v16; // [esp+24h] [ebp-58h]
  __int64 v17; // [esp+2Ch] [ebp-50h]
  __int64 v18; // [esp+34h] [ebp-48h]
  vostok::math::float4x4 v19; // [esp+3Ch] [ebp-40h] BYREF
  vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *enda; // [esp+88h] [ebp+Ch]

  z = out_bounds[1][774].z;
  v6 = *(vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(LODWORD(z) + 1352);
  for ( enda = *(vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(LODWORD(z) + 1356);
        v6 != enda;
        *out_counter = v12 + 1 )
  {
    m_occlusion_info_index = v6->m_object->m_occlusion_info_index;
    v8 = m_occlusion_info_index != -1 && *((_BYTE *)&out_bounds[7]->x + m_occlusion_info_index) == 0;
    v6->m_object->m_occluded = v8;
    m_object = end->m_object;
    v6->m_object->m_occlusion_info_index = (unsigned int)end->m_object;
    v10 = v6->m_object;
    end->m_object = (vostok::render::light *)((char *)&m_object->m_reference_count + 1);
    v11 = (vostok::math::aabb *)vostok::math::float4x4::identity(&v19);
    v16 = *(_QWORD *)&v10->m_aabb.min.x;
    v17 = *(_QWORD *)&v10->m_aabb.min.elements[2];
    v18 = *(_QWORD *)&v10->m_aabb.max.elements[1];
    vostok::math::aabb::modify(v11, v13);
    *(float *)&v14 = (float)(*((float *)&v17 + 1) + *(float *)&v16) * 0.5;
    *((float *)&v14 + 1) = (float)(*(float *)&v18 + *((float *)&v16 + 1)) * 0.5;
    *(float *)&v15 = (float)(*((float *)&v18 + 1) + *(float *)&v17) * 0.5;
    *((float *)&v15 + 1) = sqrtf(
                             (float)((float)((float)((float)(*((float *)&v18 + 1) - *(float *)&v17) * 0.5)
                                           * (float)((float)(*((float *)&v18 + 1) - *(float *)&v17) * 0.5))
                                   + (float)((float)((float)(*((float *)&v17 + 1) - *(float *)&v16) * 0.5)
                                           * (float)((float)(*((float *)&v17 + 1) - *(float *)&v16) * 0.5)))
                           + (float)((float)((float)(*(float *)&v18 - *((float *)&v16 + 1)) * 0.5)
                                   * (float)((float)(*(float *)&v18 - *((float *)&v16 + 1)) * 0.5)));
    v12 = *out_counter;
    *(_QWORD *)&v12->x = v14;
    *(_QWORD *)&v12->elements[2] = v15;
    ++v6;
  }
}
