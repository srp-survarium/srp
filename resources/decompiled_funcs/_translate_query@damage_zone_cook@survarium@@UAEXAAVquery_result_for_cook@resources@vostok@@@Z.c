void __thiscall survarium::damage_zone_cook::translate_query(
        survarium::damage_zone_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::variant<32> *m_user_data; // esi
  stlp_std::priv::_Impl_vector<vostok::resources::request,survarium::std_allocator<vostok::resources::request> > *v3; // ecx
  boost::detail::function::vtable_base *v4; // ecx
  bool v5; // al
  vostok::resources::request *M_start; // esi
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::resources::request *v8; // eax
  void *v9; // esi
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::damage_zone_cook,vostok::resources::queries_result &,vostok::configs::binary_config_value const &>,boost::_bi::list3<boost::_bi::value<survarium::damage_zone_cook *>,boost::arg<1>,boost::_bi::value<vostok::configs::binary_config_value> > > v10; // [esp-28h] [ebp-B0h]
  bool v11; // [esp+0h] [ebp-88h]
  boost::detail::function::function_obj_tag v12; // [esp+0h] [ebp-88h]
  vostok::resources::request __x; // [esp+14h] [ebp-74h] BYREF
  survarium::vector<vostok::resources::request> requests; // [esp+1Ch] [ebp-6Ch] BYREF
  vostok::configs::binary_config_value cfg_val; // [esp+28h] [ebp-60h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+40h] [ebp-48h] BYREF
  void (__userpurge *v18)(survarium::damage_zone_cook *@<ecx>, float@<xmm0>, vostok::resources::queries_result *, vostok::configs::binary_config_value *); // [esp+60h] [ebp-28h]
  int v19; // [esp+64h] [ebp-24h]

  m_user_data = parent->m_user_data;
  cfg_val.data.max_storage = 0;
  vostok::platform_pointer_selector<char const,1>::helper::helper(&cfg_val.id, 0);
  cfg_val.id_crc = 0;
  cfg_val.type = 0;
  cfg_val.count = 0;
  vostok::variant<32>::try_get<vostok::configs::binary_config_value>(m_user_data, &cfg_val, 0);
  __x.path = (const char *)&buf;
  memset(&requests, 0, sizeof(requests));
  __x.id = unknown_data_class;
  stlp_std::priv::_Impl_vector<vostok::resources::request,survarium::std_allocator<vostok::resources::request>>::_M_insert_overflow(
    v3,
    (int)&requests,
    (stlp_std::priv::_STLP_alloc_proxy<vostok::resources::request *,vostok::resources::request,survarium::std_allocator<vostok::resources::request> > *)m_user_data,
    0,
    &__x,
    (vostok::resources::request *)1,
    1,
    v11);
  v4 = (boost::detail::function::vtable_base *)this;
  LOBYTE(this) = 0;
  *(_DWORD *)&v10.l_.a3_.t_.type = this;
  v18 = survarium::damage_zone_cook::on_sub_resources_loaded;
  callback.vtable = v4;
  v19 = 0;
  LODWORD(v10.f_.f_) = 0;
  *(void (__thiscall *__ptr64 *)(survarium::damage_zone_cook *, vostok::resources::queries_result *, const vostok::configs::binary_config_value *))((char *)&v10.f_.f_ + 4) = *(void (__thiscall *__ptr64 *)(survarium::damage_zone_cook *, vostok::resources::queries_result *, const vostok::configs::binary_config_value *))&callback.vtable;
  *(_QWORD *)(&v10.l_.boost::_bi::storage2<boost::_bi::value<survarium::damage_zone_cook *>,boost::arg<1> > + 1) = cfg_val.data.max_storage;
  *(unsigned __int64 *)((char *)&v10.l_.a3_.t_.data.max_storage + 4) = cfg_val.id.max_storage;
  callback.vtable = 0;
  *(unsigned __int64 *)((char *)&v10.l_.a3_.t_.id.max_storage + 4) = *(_QWORD *)&cfg_val.id_crc;
  v5 = boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::damage_zone_cook,vostok::resources::queries_result &,vostok::configs::binary_config_value const &>,boost::_bi::list3<boost::_bi::value<survarium::damage_zone_cook *>,boost::arg<1>,boost::_bi::value<vostok::configs::binary_config_value>>>>(
         &callback.functor,
         (int)v4,
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)survarium::damage_zone_cook::on_sub_resources_loaded,
         v10,
         v12);
  M_start = requests._M_impl._M_start;
  callback.vtable = v5
                  ? (boost::detail::function::vtable_base *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::damage_zone_cook,vostok::resources::queries_result &,vostok::configs::binary_config_value const &>,boost::_bi::list3<boost::_bi::value<survarium::damage_zone_cook *>,boost::arg<1>,boost::_bi::value<vostok::configs::binary_config_value>>>>'::`2'::stored_vtable
                  : 0;
  vostok::resources::query_resources(
    requests._M_impl._M_start,
    requests._M_impl._M_finish - requests._M_impl._M_start,
    &callback,
    (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
    0,
    parent,
    assert_on_fail_true);
  if ( callback.vtable )
  {
    if ( ((int)callback.vtable & 1) == 0 )
    {
      v7 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
      if ( v7 )
        v7(&callback.functor, &callback.functor, 2);
    }
    callback.vtable = 0;
  }
  if ( M_start )
  {
    v8 = M_start;
    v9 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v9, (void *)v8);
  }
}
