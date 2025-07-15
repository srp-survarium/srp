void __userpurge vostok::render::stage_visibility::get_results_and_prepare_bounds_decals(
        vostok::fixed_string<512> *(__thiscall **out_counter)(struct vostok::resources::resource_base *this, vostok::fixed_string<512> *result)@<edi>,
        vostok::render::stage_visibility *this,
        vostok::math::float4 **out_bounds)
{
  vostok::render::base_scene_view *m_object; // eax
  vostok::resources::unmanaged_resource *m_prev_in_global_delay_delete_list; // ebp
  vostok::resources::unmanaged_resource *i; // esi
  vostok::fixed_string<512> *(__thiscall *log_string)(struct vostok::resources::resource_base *, vostok::fixed_string<512> *); // eax
  bool v7; // al
  vostok::fixed_string<512> *(__thiscall *v8)(struct vostok::resources::resource_base *, vostok::fixed_string<512> *); // eax
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
  m_prev_in_global_delay_delete_list = m_object[4].m_prev_in_global_delay_delete_list;
  for ( i = m_object[4].m_next_in_global_delay_delete_list;
        i != m_prev_in_global_delay_delete_list;
        *out_bounds = (vostok::math::float4 *)(v10 + 16) )
  {
    log_string = i->__vftable[5].log_string;
    v7 = log_string != (vostok::fixed_string<512> *(__thiscall *)(struct vostok::resources::resource_base *, vostok::fixed_string<512> *))-1
      && *((_BYTE *)log_string + (unsigned int)this->m_static_results_array) == 0;
    LOBYTE(i->__vftable[5].unlink_child_resource) = v7;
    v8 = *out_counter;
    i->__vftable[5].log_string = *out_counter;
    *out_counter = (vostok::fixed_string<512> *(__thiscall *)(struct vostok::resources::resource_base *, vostok::fixed_string<512> *))((char *)v8 + 1);
    v14 = *(_QWORD *)&i->__vftable[3].increase_quality_to_target;
    v15 = *(_QWORD *)&i->__vftable[4].~vostok::resources::resource_base;
    v16 = *(_QWORD *)&i->__vftable[4].link_child_resource;
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
    i = (vostok::resources::unmanaged_resource *)((char *)i + 4);
  }
}
