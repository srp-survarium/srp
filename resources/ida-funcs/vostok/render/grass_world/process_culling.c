void __userpurge vostok::render::grass_world::process_culling(
        vostok::render::grass_world *this@<ecx>,
        int a2@<edi>,
        vostok::render::renderer_context *context,
        const float first_lod_distance)
{
  void *v4; // esp
  int v5; // eax
  _DWORD *v6; // eax
  bool i; // zf
  vostok::render::grass_patch *v8; // eax
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm4_4
  float v12; // xmm0_4
  vostok::render::options *v13; // ecx
  float v14; // xmm0_4
  vostok::buffer_vector<vostok::render::grass_patch *> *m_num_avaliable_lods; // ecx
  bool v16; // cf
  _DWORD v17[2]; // [esp+0h] [ebp-9Ch] BYREF
  vostok::math::frustum v18; // [esp+8h] [ebp-94h] BYREF
  vostok::render::grass_patch *value; // [esp+80h] [ebp-1Ch] BYREF
  _DWORD *v20; // [esp+84h] [ebp-18h] BYREF
  _DWORD *v21; // [esp+88h] [ebp-14h]
  _DWORD *v22; // [esp+8Ch] [ebp-10h]
  _DWORD *v23; // [esp+90h] [ebp-Ch]
  _DWORD *v24; // [esp+94h] [ebp-8h]

  *(_DWORD *)(a2 + 344) = *(_DWORD *)(a2 + 340);
  vostok::quasi_singleton<vostok::render::statistics>::pinst->grass_stat_group.num_total_patches.value = (*(_DWORD *)(a2 + 332) - *(_DWORD *)(a2 + 328)) / 16568;
  v4 = alloca(4 * ((*(_DWORD *)(a2 + 332) - *(_DWORD *)(a2 + 328)) / 16568));
  v5 = (*(_DWORD *)(a2 + 332) - *(_DWORD *)(a2 + 328)) / 16568;
  v20 = v17;
  v21 = v17;
  v22 = &v17[v5];
  vostok::math::frustum::frustum(&v18, &context->m_vp);
  (*(void (__thiscall **)(_DWORD, int, vostok::math::frustum *, _DWORD **))(**(_DWORD **)(a2 + 448) + 28))(
    *(_DWORD *)(a2 + 448),
    -1,
    &v18,
    &v20);
  v6 = v20;
  v23 = v21;
  for ( i = v20 == v21; ; i = v24 + 1 == v23 )
  {
    v24 = v6;
    if ( i )
      break;
    v8 = *(vostok::render::grass_patch **)(*v6 + 36);
    v9 = (float)(v8->m_aabb.max.z + v8->m_aabb.min.z) * 0.5;
    v10 = context->m_view_pos.x - (float)((float)(v8->m_aabb.min.x + v8->m_aabb.max.x) * 0.5);
    v11 = context->m_view_pos.y - (float)((float)(v8->m_aabb.max.y + v8->m_aabb.min.y) * 0.5);
    v12 = (float)((float)((float)(context->m_view_pos.z - v9) * (float)(context->m_view_pos.z - v9)) + (float)(v11 * v11))
        + (float)(v10 * v10);
    value = v8;
    if ( v12 <= 10000.0 )
    {
      v13 = vostok::quasi_singleton<vostok::render::options>::pinst;
      v8->m_current_lod_index = 0;
      v14 = fsqrt(v12);
      if ( v14 <= v13->current.m_grass_lod1_distance )
      {
        if ( v14 > v13->current.m_grass_lod2_distance )
          v8->m_current_lod_index = 2;
      }
      else
      {
        v8->m_current_lod_index = 1;
      }
      m_num_avaliable_lods = (vostok::buffer_vector<vostok::render::grass_patch *> *)v8->m_num_avaliable_lods;
      if ( m_num_avaliable_lods )
      {
        v16 = v8->m_current_lod_index < (unsigned int)m_num_avaliable_lods;
        m_num_avaliable_lods = (vostok::buffer_vector<vostok::render::grass_patch *> *)((char *)m_num_avaliable_lods - 1);
        if ( v16 )
          m_num_avaliable_lods = (vostok::buffer_vector<vostok::render::grass_patch *> *)v8->m_current_lod_index;
      }
      v8->m_current_lod_index = (unsigned int)m_num_avaliable_lods;
      vostok::buffer_vector<vostok::render::grass_patch *>::push_back(m_num_avaliable_lods, a2 + 340, &value);
    }
    v6 = v24 + 1;
  }
  vostok::render::grass_world::process_sorting(
    (vostok::render::grass_world *)((*(int *)((char *)&dword_10DF8 + (unsigned int)context->m_scene_view.m_object) & 0x1F) == 0),
    (const vostok::math::float3 *)a2,
    (vostok::render::grass_patch *)&context->m_view_pos,
    (*(int *)((char *)&dword_10DF8 + (unsigned int)context->m_scene_view.m_object) & 0x1F) == 0);
}
