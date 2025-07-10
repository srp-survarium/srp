void __thiscall vostok::render::scene_cook::translate_query(
        vostok::render::scene_cook *this,
        vostok::resources::query_result_for_cook *in_out_query)
{
  vostok::variant<32> *m_user_data; // esi
  int *v3; // eax
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v4; // ecx
  vostok::configs::binary_config *v5; // eax
  vostok::configs::binary_config *v6; // esi
  vostok::render::scene_manager *v7; // edi
  void **M_finish; // eax
  int v9; // eax
  unsigned int v10; // edx
  void (__cdecl *v11)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::resources::query_result_for_cook *v12; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::scene_cook,vostok::resources::queries_result &,vostok::render::scene *,vostok::resources::query_result_for_cook *>,boost::_bi::list4<boost::_bi::value<vostok::render::scene_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::scene *>,boost::_bi::value<vostok::resources::query_result_for_cook *> > > v13; // [esp+92h] [ebp-A0h] BYREF
  bool v14; // [esp+AAh] [ebp-88h]
  vostok::render::scene_configuration out_value[13]; // [esp+B9h] [ebp-79h] BYREF
  vostok::variant<32> *user_data; // [esp+C6h] [ebp-6Ch] BYREF
  vostok::resources::creation_request requests; // [esp+CAh] [ebp-68h] BYREF
  __int64 v18; // [esp+DAh] [ebp-58h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+E2h] [ebp-50h] BYREF
  _DWORD v20[2]; // [esp+102h] [ebp-30h] BYREF
  vostok::resources::memory_type **p_m_memory_type_data; // [esp+10Ah] [ebp-28h] BYREF
  _DWORD *v22; // [esp+12Ah] [ebp-8h]
  int v23; // [esp+12Eh] [ebp-4h]

  *(_DWORD *)&out_value[1] = 0;
  m_user_data = in_out_query->m_user_data;
  *(_DWORD *)out_value = *(_BYTE *)out_value & 0x80;
  user_data = (vostok::variant<32> *)this;
  if ( m_user_data )
    vostok::variant<32>::try_get<vostok::render::scene_configuration>(
      (vostok::variant<32> *)this,
      (int)m_user_data,
      out_value);
  v3 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
         0x3D0u);
  if ( v3 )
  {
    vostok::render::scene::scene((vostok::render::scene *)out_value, (int)v3, out_value);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  v7 = vostok::quasi_singleton<vostok::render::scene_manager>::pinst;
  M_finish = vostok::quasi_singleton<vostok::render::scene_manager>::pinst->m_scenes._M_impl._M_finish;
  *(_DWORD *)&out_value[1] = v6;
  if ( M_finish == vostok::quasi_singleton<vostok::render::scene_manager>::pinst->m_scenes._M_impl._M_end_of_storage._M_data )
  {
    stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::_M_insert_overflow(
      v4,
      (int)vostok::quasi_singleton<vostok::render::scene_manager>::pinst,
      M_finish,
      (void *const *)&out_value[1],
      (const stlp_std::__true_type *)1,
      1,
      v14);
  }
  else
  {
    *M_finish = v6;
    ++v7->m_scenes._M_impl._M_finish;
  }
  if ( (*(_BYTE *)out_value & 2) != 0 )
  {
    v22 = 0;
    v23 = 0;
    v23 = vostok::detail::type_to_int<vostok::particle::engine *>::get();
    v22 = v20;
    requests.m_name = (const char *)vostok::render::scene_cook::on_particle_world_created;
    requests.m_data.m_data = 0;
    *(_QWORD *)&out_value[1] = __PAIR64__((unsigned int)v6, (unsigned int)user_data);
    v13.f_.f_ = *(void (__thiscall *__ptr64 *)(vostok::render::scene_cook *, vostok::resources::queries_result *, vostok::render::scene *, vostok::resources::query_result_for_cook *))&requests.m_name;
    v13.l_.boost::_bi::storage3<boost::_bi::value<vostok::render::scene_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::scene *> > = (boost::_bi::storage3<boost::_bi::value<vostok::render::scene_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::scene *> >)__PAIR64__((unsigned int)v6, (unsigned int)user_data);
    p_m_memory_type_data = &v6[2].m_memory_type_data;
    LODWORD(v18) = in_out_query;
    v20[0] = &vostok::detail::concrete_type_helper<vostok::particle::engine *>::`vftable';
    callback.vtable = 0;
    *(_QWORD *)&v13.l_.a4_.t_ = v18;
    boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::scene_cook,vostok::resources::queries_result &,vostok::render::scene *,vostok::resources::query_result_for_cook *>,boost::_bi::list4<boost::_bi::value<vostok::render::scene_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::scene *>,boost::_bi::value<vostok::resources::query_result_for_cook *>>>>(
      0,
      (int)&callback,
      (int)v6,
      v13);
    boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
      (vostok::mutable_buffer *)&out_value[1],
      (unsigned __int8 *)&buf,
      (unsigned int)&vostok::resources::g_resources_manager.m_static_memory[62144]);
    v10 = *(_DWORD *)(v9 + 4);
    requests.m_data.m_data = *(const char **)v9;
    requests.m_data.m_size = v10;
    user_data = (vostok::variant<32> *)v20;
    requests.m_name = (const char *)&buf;
    requests.m_id = particle_world_class;
    vostok::resources::query_create_resources(
      &requests,
      1u,
      (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
      (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
      (const vostok::variant<32> **)&user_data,
      in_out_query,
      assert_on_fail_true);
    if ( callback.vtable )
    {
      if ( ((int)callback.vtable & 1) == 0 )
      {
        v11 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
        if ( v11 )
          v11(&callback.functor, &callback.functor, 2);
      }
    }
    if ( v22 )
      (*(void (__thiscall **)(_DWORD *, vostok::resources::memory_type ***))(*v22 + 4))(v22, &p_m_memory_type_data);
  }
  else
  {
    *((_DWORD *)&v13.l_ + 3) = 976;
    v13.l_.a4_.t_ = (vostok::resources::query_result_for_cook *)&vostok::resources::nocache_memory;
    v13.l_.a3_.t_ = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v13.l_.a3_,
      v6);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      in_out_query,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v13.l_.a3_.t_,
      (const vostok::resources::memory_type *)v13.l_.a4_.t_,
      *((unsigned int *)&v13.l_ + 3));
    vostok::resources::query_result_for_cook::finish_query_impl(
      v12,
      (int)in_out_query,
      result_success,
      assert_on_fail_true,
      0);
  }
}
