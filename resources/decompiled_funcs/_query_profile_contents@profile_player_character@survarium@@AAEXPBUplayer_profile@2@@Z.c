void __userpurge survarium::profile_player_character::query_profile_contents(
        survarium::profile_player_character *this@<ecx>,
        __int64 a2@<esi:edi>,
        survarium::player_profile *profile)
{
  survarium::player_profile *v3; // eax
  int v4; // eax
  int v5; // ecx
  void (__cdecl *v6)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::animated_model_instance_cook,vostok::resources::queries_result &,survarium::animated_model_instance *>,boost::_bi::list3<boost::_bi::value<survarium::animated_model_instance_cook *>,boost::arg<1>,boost::_bi::value<survarium::animated_model_instance *> > > v7; // [esp+88h] [ebp-78h]
  vostok::variant<32> *user_data; // [esp+9Ch] [ebp-64h] BYREF
  vostok::resources::request requests; // [esp+A0h] [ebp-60h] BYREF
  __int64 v10; // [esp+A8h] [ebp-58h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+B0h] [ebp-50h] BYREF
  _DWORD v12[2]; // [esp+D0h] [ebp-30h] BYREF
  _QWORD v13[4]; // [esp+D8h] [ebp-28h] BYREF
  _DWORD *v14; // [esp+F8h] [ebp-8h]
  int v15; // [esp+FCh] [ebp-4h]

  v3 = (survarium::player_profile *)vostok::memory::doug_lea_allocator::malloc_impl(
                                      (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                                      0x1B8u);
  if ( v3 )
  {
    survarium::player_profile::player_profile(v3);
    HIDWORD(a2) = v4;
  }
  else
  {
    HIDWORD(a2) = 0;
  }
  memcpy((unsigned __int8 *)HIDWORD(a2), (unsigned __int8 *)profile, 0x1B8u);
  v5 = *(_DWORD *)(a2 + 4);
  LOBYTE(requests.id) = 0;
  BYTE4(v10) = 1;
  LODWORD(v10) = v5;
  requests.path = (const char *)HIDWORD(a2);
  v14 = 0;
  v13[0] = requests;
  v15 = vostok::detail::type_to_int<survarium::player_initial_info>::get();
  v13[1] = v10;
  requests.path = (const char *)survarium::profile_player_character::on_player_ready;
  requests.id = a2;
  *(_QWORD *)&v7.f_.f_ = a2;
  v12[0] = &vostok::detail::concrete_type_helper<survarium::player_initial_info>::`vftable';
  v14 = v12;
  callback.vtable = 0;
  if ( boost::detail::function::basic_vtable1<void,bool>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::resources::device_manager,vostok::resources::query_result *,bool>,boost::_bi::list3<boost::_bi::value<vostok::resources::device_manager *>,boost::_bi::value<vostok::resources::query_result *>,boost::arg<1>>>>(
         &callback.functor,
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)survarium::profile_player_character::on_player_ready,
         v7) )
  {
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&off_971E3C + 1);
  }
  else
  {
    callback.vtable = 0;
  }
  user_data = (vostok::variant<32> *)v12;
  requests.path = "gameplay/players/default.player";
  requests.id = player_class;
  vostok::resources::query_resources(
    &requests,
    1u,
    (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
    (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
    (const vostok::variant<32> **)&user_data,
    0,
    assert_on_fail_true);
  if ( callback.vtable )
  {
    if ( ((int)callback.vtable & 1) == 0 )
    {
      v6 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
      if ( v6 )
        v6(&callback.functor, &callback.functor, 2);
    }
  }
  if ( v14 )
    (*(void (__thiscall **)(_DWORD *, _QWORD *))(*v14 + 4))(v14, v13);
}
