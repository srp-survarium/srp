void __usercall vostok::render::skeleton_render_model::load_bones(
        vostok::render::skeleton_render_model *this@<ecx>,
        vostok::memory::reader *bones_chunk@<edi>)
{
  const unsigned __int8 *m_pointer; // eax
  unsigned __int16 v3; // bp
  int v4; // esi
  const unsigned __int8 *v5; // ebx
  const unsigned __int8 *v6; // ecx
  const unsigned __int8 *i; // eax
  _BYTE *v8; // eax
  __int64 v9; // xmm0_8
  float v10; // ecx
  float v11; // ecx
  __int64 v12; // xmm0_8
  float v13; // ecx
  __int64 v14; // xmm0_8
  void (__cdecl *v15)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // ebp
  void (__cdecl *v16)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  int v17; // [esp+24h] [ebp-A8h]
  int v18; // [esp+28h] [ebp-A4h]
  vostok::render::vector<vostok::math::float4x4> *p_m_inverted_bones_matrices_in_bind_pose; // [esp+2Ch] [ebp-A0h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+30h] [ebp-9Ch] BYREF
  vostok::animation::frame frm; // [esp+54h] [ebp-78h] BYREF
  vostok::math::float4x4 frm_matrix; // [esp+78h] [ebp-54h] BYREF
  vostok::math::float3 scale_; // [esp+BCh] [ebp-10h] BYREF

  m_pointer = bones_chunk->m_pointer;
  v3 = *(_WORD *)m_pointer;
  bones_chunk->m_pointer = m_pointer + 2;
  v17 = 0;
  p_m_inverted_bones_matrices_in_bind_pose = &this->m_inverted_bones_matrices_in_bind_pose;
  stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>::resize(
    &this->m_inverted_bones_matrices_in_bind_pose._M_impl,
    v3,
    &frm_matrix);
  if ( v3 )
  {
    v4 = 0;
    v18 = v3;
    do
    {
      v5 = bones_chunk->m_pointer;
      v6 = &bones_chunk->m_data[bones_chunk->m_size];
      for ( i = v5; i != v6; ++i )
      {
        if ( !*i )
          break;
      }
      v8 = i + 1;
      bones_chunk->m_pointer = v8;
      v9 = *(_QWORD *)v8;
      v10 = *((float *)v8 + 2);
      v8 += 12;
      bones_chunk->m_pointer = v8;
      frm.translation.z = v10;
      v11 = *((float *)v8 + 2);
      v8 += 12;
      *(_QWORD *)&frm.translation.x = v9;
      v12 = *(_QWORD *)(v8 - 12);
      bones_chunk->m_pointer = v8;
      frm.rotation.z = v11;
      v13 = *((float *)v8 + 2);
      *(_QWORD *)&frm.channels[3] = v12;
      v14 = *(_QWORD *)v8;
      bones_chunk->m_pointer = v8 + 12;
      frm.scale.z = v13;
      *(_QWORD *)&frm.channels[6] = v14;
      vostok::animation::frame_matrix(&frm, &scale_, &frm_matrix);
      vostok::math::float4x4::try_invert(&p_m_inverted_bones_matrices_in_bind_pose->_M_impl._M_start[v4], &frm_matrix);
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render_pc_dx11:", info) )
      {
        v15 = vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
        if ( v15 )
        {
          log_callback.functor.obj_ptr = v15;
          log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                       + 1);
        }
        else
        {
          log_callback.vtable = 0;
        }
        v17 |= 1u;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\render_model_skeleton.cpp",
          0x3Cu,
          (const char *)&stru_962594.m_compile_error_handler.m_Closure.m_pFunction,
          "render_pc_dx11:",
          info,
          (const char *)&stru_962594.m_texture_storage,
          v5,
          frm_matrix.c.x,
          frm_matrix.c.y,
          frm_matrix.c.z);
      }
      if ( (v17 & 1) != 0 )
      {
        v17 &= ~1u;
        if ( log_callback.vtable )
        {
          if ( ((int)log_callback.vtable & 1) == 0 )
          {
            v16 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
            if ( v16 )
              v16(&log_callback.functor, &log_callback.functor, 2);
          }
        }
      }
      ++v4;
      --v18;
    }
    while ( v18 );
  }
}
