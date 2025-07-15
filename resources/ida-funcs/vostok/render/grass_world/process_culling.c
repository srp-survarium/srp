void __userpurge vostok::render::grass_world::process_culling(
        vostok::render::grass_world *this@<ecx>,
        int a2@<edi>,
        vostok::render::renderer_context *context,
        float first_lod_distance)
{
  void **v4; // eax
  void **v5; // ecx
  void **v6; // esi
  vostok::render::renderer_context *v7; // ebx
  unsigned __int8 *M_finish; // ecx
  const vostok::collision::object *const *M_start; // edx
  float v10; // xmm4_4
  void *m_user_data; // esi
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  long double v15; // st7
  unsigned int v16; // eax
  unsigned int v17; // eax
  char *v18; // ebp
  unsigned int v19; // eax
  int *v20; // ecx
  unsigned int v21; // ebx
  unsigned __int8 *v22; // eax
  unsigned int v23; // ebp
  int v24; // eax
  unsigned __int8 *v25; // eax
  _DWORD *v26; // ebp
  void *v27; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  unsigned __int8 *v29; // edx
  unsigned int _X; // [esp+Ch] [ebp-B4h]
  float _Xa; // [esp+Ch] [ebp-B4h]
  stlp_std::priv::_STLP_alloc_proxy<unsigned int *,unsigned int,vostok::render::std_allocator<unsigned int> > *v32; // [esp+10h] [ebp-B0h]
  float v33; // [esp+24h] [ebp-9Ch] BYREF
  const vostok::collision::object *const *it; // [esp+28h] [ebp-98h]
  vostok::vectora<vostok::collision::object const *> objects; // [esp+2Ch] [ebp-94h] BYREF
  float to_aabb_center_squared; // [esp+3Ch] [ebp-84h]
  int v37; // [esp+40h] [ebp-80h] BYREF
  const vostok::collision::object *const *end; // [esp+44h] [ebp-7Ch]
  vostok::math::frustum view_frustum; // [esp+48h] [ebp-78h] BYREF

  v4 = *(void ***)(a2 + 304);
  v5 = *(void ***)(a2 + 300);
  if ( v5 != v4 )
  {
    v6 = stlp_std::priv::__copy_ptrs<void * *,void * *>(v4, v4, v5);
    stlp_std::_Destroy<vostok::fs_new::virtual_path_string>();
    *(_DWORD *)(a2 + 304) = v6;
  }
  vostok::quasi_singleton<vostok::render::statistics>::pinst->grass_stat_group.num_total_patches.value = (*(_DWORD *)(a2 + 292) - *(_DWORD *)(a2 + 288)) >> 2;
  _X = (*(_DWORD *)(a2 + 292) - *(_DWORD *)(a2 + 288)) >> 2;
  objects._M_impl._M_start = 0;
  objects._M_impl._M_finish = 0;
  objects._M_impl._M_end_of_storage.m_allocator = (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object;
  objects._M_impl._M_end_of_storage._M_data = 0;
  stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::reserve(
    (stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *> > *)_X,
    &objects._M_impl,
    _X);
  v7 = context;
  vostok::math::frustum::frustum(&view_frustum, &context->m_vp);
  (*(void (__thiscall **)(_DWORD, int, vostok::math::frustum *, vostok::vectora<vostok::collision::object const *> *))(**(_DWORD **)(a2 + 312) + 28))(
    *(_DWORD *)(a2 + 312),
    -1,
    &view_frustum,
    &objects);
  M_finish = (unsigned __int8 *)objects._M_impl._M_finish;
  M_start = (const vostok::collision::object *const *)objects._M_impl._M_start;
  it = (const vostok::collision::object *const *)objects._M_impl._M_start;
  end = (const vostok::collision::object *const *)objects._M_impl._M_finish;
  if ( objects._M_impl._M_start != objects._M_impl._M_finish )
  {
    v10 = FLOAT_0_5;
    do
    {
      m_user_data = (*M_start)->m_user_data;
      v12 = v7->m_view_pos.x - (float)((float)(*((float *)m_user_data + 4101) + *((float *)m_user_data + 4104)) * v10);
      v13 = v7->m_view_pos.y - (float)((float)(*((float *)m_user_data + 4105) + *((float *)m_user_data + 4102)) * v10);
      v14 = v7->m_view_pos.z - (float)((float)(*((float *)m_user_data + 4106) + *((float *)m_user_data + 4103)) * v10);
      to_aabb_center_squared = (float)((float)(v12 * v12) + (float)(v14 * v14)) + (float)(v13 * v13);
      if ( to_aabb_center_squared <= 10000.0 )
      {
        _Xa = to_aabb_center_squared;
        *((_DWORD *)m_user_data + 4112) = 0;
        v15 = sqrtf(_Xa);
        v33 = v15;
        if ( v15 <= *((float *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                    + 20) )
        {
          if ( v33 > *((float *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                     + 21) )
            *((_DWORD *)m_user_data + 4112) = 2;
        }
        else
        {
          *((_DWORD *)m_user_data + 4112) = 1;
        }
        v16 = *((_DWORD *)m_user_data + 4113);
        M_finish = (unsigned __int8 *)*((_DWORD *)m_user_data + 4112);
        if ( v16 )
        {
          if ( (unsigned int)M_finish < v16 )
            v17 = *((_DWORD *)m_user_data + 4112);
          else
            v17 = v16 - 1;
        }
        else
        {
          v17 = 0;
        }
        *((_DWORD *)m_user_data + 4112) = v17;
        v18 = *(char **)(a2 + 304);
        if ( v18 == *(char **)(a2 + 308) )
        {
          v19 = (int)&v18[-*(_DWORD *)(a2 + 300)] >> 2;
          v37 = 1;
          v33 = *(float *)&v19;
          if ( v19 == 0x3FFFFFFF )
            stlp_std::__stl_throw_length_error("vector");
          v20 = (int *)&v33;
          if ( v19 <= 1 )
            v20 = &v37;
          v21 = v19 + *v20;
          if ( v21 > 0x3FFFFFFF || v21 < v19 )
            v21 = 0x3FFFFFFF;
          M_finish = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>>>::allocate(
                                          v21,
                                          v32);
          v22 = *(unsigned __int8 **)(a2 + 300);
          v23 = v18 - (char *)v22;
          v33 = *(float *)&M_finish;
          if ( v23 )
          {
            memmove(M_finish, v22, v23);
            M_finish = (unsigned __int8 *)LODWORD(v33);
            v25 = (unsigned __int8 *)(v23 + v24);
          }
          else
          {
            v25 = M_finish;
          }
          *(_DWORD *)v25 = m_user_data;
          v26 = v25 + 4;
          v27 = *(void **)(a2 + 300);
          if ( v27 )
          {
            m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
            BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
            vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v27);
            M_finish = (unsigned __int8 *)LODWORD(v33);
          }
          v29 = &M_finish[4 * v21];
          v7 = context;
          *(_DWORD *)(a2 + 300) = M_finish;
          *(_DWORD *)(a2 + 304) = v26;
          *(_DWORD *)(a2 + 308) = v29;
        }
        else
        {
          *(_DWORD *)v18 = m_user_data;
          *(_DWORD *)(a2 + 304) += 4;
        }
        v10 = FLOAT_0_5;
      }
      M_start = it + 1;
      it = M_start;
    }
    while ( M_start != end );
  }
  LOBYTE(M_finish) = (v7->m_scene_view.m_object[4].m_current_satisfaction_update_tick & 0x1F) == 0;
  vostok::render::grass_world::process_sorting(
    (vostok::render::grass_world *)M_finish,
    a2,
    (vostok::render::sort_grass_patch_predicate *)&v7->m_view_pos,
    (bool)M_finish);
  if ( objects._M_impl._M_start )
    objects._M_impl._M_end_of_storage.m_allocator->call_free(
      objects._M_impl._M_end_of_storage.m_allocator,
      objects._M_impl._M_start);
}
