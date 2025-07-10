void __userpurge vostok::render::scene::select_models(
        vostok::render::vector<vostok::render::render_surface_instance *> *selection@<eax>,
        vostok::render::scene *this,
        const vostok::math::float4x4 *mat_vp,
        vostok::render::culling::portal_sector_system *view_pos,
        unsigned int surface_flags,
        bool moved_only)
{
  vostok::render::culling::portal_sector_system *m_portal_system; // eax
  void **M_finish; // eax
  void **v9; // esi
  void (__cdecl *v10)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  const void **M_start; // ebp
  int v12; // esi
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::moved_object_predicate_helper,vostok::collision::object const &>,boost::_bi::list2<boost::_bi::value<vostok::render::moved_object_predicate_helper *>,boost::arg<1> > > v13; // [esp+8h] [ebp-E8h]
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v14; // [esp+Ch] [ebp-E4h]
  const vostok::math::float4x4 *v15; // [esp+10h] [ebp-E0h]
  unsigned __int8 lod_id; // [esp+24h] [ebp-CCh]
  vostok::vectora<vostok::collision::object const *> query_result; // [esp+28h] [ebp-C8h] BYREF
  const vostok::collision::object *const *end; // [esp+38h] [ebp-B8h]
  vostok::render::moved_object_predicate_helper helper; // [esp+3Ch] [ebp-B4h] BYREF
  boost::function<void __cdecl(vostok::collision::object const &)> callback; // [esp+40h] [ebp-B0h] BYREF
  _BYTE v21[24]; // [esp+60h] [ebp-90h] BYREF
  vostok::math::frustum view_frustum; // [esp+78h] [ebp-78h] BYREF

  if ( *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
       + 284) )
  {
    m_portal_system = this->m_portal_system;
    if ( !m_portal_system
      || !s_use_poral_culling_value
      || (vostok::render::culling::portal_sector_system::select_models(
            view_pos,
            m_portal_system,
            this->m_models_tree,
            (vostok::math::float3 *)view_pos,
            mat_vp,
            selection),
          selection->_M_impl._M_start == selection->_M_impl._M_finish) )
    {
      vostok::math::frustum::frustum(&view_frustum, mat_vp);
      M_finish = selection->_M_impl._M_finish;
      if ( selection->_M_impl._M_start != M_finish )
      {
        v9 = stlp_std::priv::__copy_ptrs<void * *,void * *>(M_finish, M_finish, selection->_M_impl._M_start);
        stlp_std::_Destroy<vostok::fs_new::virtual_path_string>();
        selection->_M_impl._M_finish = v9;
      }
      query_result._M_impl._M_start = 0;
      query_result._M_impl._M_finish = 0;
      query_result._M_impl._M_end_of_storage.m_allocator = (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object;
      query_result._M_impl._M_end_of_storage._M_data = 0;
      if ( moved_only )
      {
        v13.l_.a1_.t_ = &helper;
        v13.f_.f_ = vostok::render::moved_object_predicate_helper::check_object;
        helper.m_array = &query_result;
        callback.vtable = 0;
        boost::function1<void,vostok::collision::object const &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::moved_object_predicate_helper,vostok::collision::object const &>,boost::_bi::list2<boost::_bi::value<vostok::render::moved_object_predicate_helper *>,boost::arg<1>>>>(
          (boost::function1<void,vostok::collision::object const &> *)&helper,
          (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::moved_object_predicate_helper,vostok::collision::object const &>,boost::_bi::list2<boost::_bi::value<vostok::render::moved_object_predicate_helper *>,boost::arg<1> > > *)&callback,
          v13);
        this->m_models_tree->cuboid_query(this->m_models_tree, -1u, &view_frustum, &callback);
        if ( callback.vtable )
        {
          if ( ((int)callback.vtable & 1) == 0 )
          {
            v10 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
            if ( v10 )
              v10(&callback.functor, &callback.functor, 2);
          }
        }
      }
      else
      {
        this->m_models_tree->cuboid_query(this->m_models_tree, -1u, &view_frustum, &query_result);
      }
      v14 = (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)(selection->_M_impl._M_finish
                                                                                          - selection->_M_impl._M_start
                                                                                          + query_result._M_impl._M_finish
                                                                                          - query_result._M_impl._M_start);
      stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::reserve(
        v14,
        (int)selection,
        (unsigned int)v14);
      M_start = query_result._M_impl._M_start;
      end = (const vostok::collision::object *const *)query_result._M_impl._M_finish;
      if ( query_result._M_impl._M_start != query_result._M_impl._M_finish )
      {
        do
        {
          v12 = *((_DWORD *)*M_start + 12);
          (*(void (__thiscall **)(int, _BYTE *))(*(_DWORD *)v12 + 60))(v12, v21);
          vostok::math::aabb::modify((vostok::math::aabb *)(v12 + 324), v15);
          if ( this->fixed_lod_value == -1 )
            lod_id = -1;
          else
            lod_id = this->fixed_lod_value;
          (*(void (__thiscall **)(int, const vostok::math::float4x4 *, vostok::render::culling::portal_sector_system *, vostok::render::vector<vostok::render::render_surface_instance *> *, int, unsigned __int8, unsigned int))(*(_DWORD *)v12 + 64))(
            v12,
            mat_vp,
            view_pos,
            selection,
            1,
            lod_id,
            surface_flags);
          ++M_start;
        }
        while ( M_start != (const void **)end );
        M_start = query_result._M_impl._M_start;
      }
      if ( M_start )
        query_result._M_impl._M_end_of_storage.m_allocator->call_free(
          query_result._M_impl._M_end_of_storage.m_allocator,
          M_start);
    }
  }
}
