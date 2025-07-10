void __thiscall survarium::object_vegetation::load(
        survarium::object_vegetation *this,
        const vostok::configs::binary_config_value *t,
        const char *project_resources_path,
        boost::function4<void,unsigned int,float,float,char const *> *cb)
{
  int *v4; // eax
  int *v5; // esi
  const char *v6; // eax
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v7; // ecx
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__thiscall *__ptr64 v9)(survarium::object_vegetation *, vostok::resources::queries_result *, boost::function<void __cdecl(survarium::game_object_ &)> *); // [esp-30h] [ebp-C8h]
  boost::function<void __cdecl(survarium::game_object_ &)> v10; // [esp-20h] [ebp-B8h] BYREF
  vostok::variant<32> ud; // [esp+0h] [ebp-98h] BYREF
  int v12; // [esp+30h] [ebp-68h]
  void (__thiscall *__ptr64 f)(survarium::object_vegetation *, vostok::resources::queries_result *, boost::function<void __cdecl(survarium::game_object_ &)> *); // [esp+3Ch] [ebp-5Ch] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > *result; // [esp+44h] [ebp-54h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+48h] [ebp-50h] BYREF
  _DWORD v16[2]; // [esp+68h] [ebp-30h] BYREF
  int *v17; // [esp+70h] [ebp-28h] BYREF
  _DWORD *v18; // [esp+90h] [ebp-8h]
  int v19; // [esp+94h] [ebp-4h]

  LODWORD(f) = this;
  v4 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
         0x114u);
  if ( v4 )
  {
    v4[1] = (int)(v4 + 4);
    v4[2] = (int)(v4 + 4);
    v4[3] = (int)(v4 + 69);
    *((_BYTE *)v4 + 16) = 0;
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  *v5 = (int)t;
  v6 = (const char *)v5[1];
  if ( v6 != project_resources_path )
  {
    v5[2] = (int)v6;
    ud.m_type_id = (unsigned int)project_resources_path;
    *v6 = 0;
    vostok::buffer_string::operator+=((vostok::buffer_string *)(v5 + 1), (const char *)ud.m_type_id);
  }
  v19 = vostok::detail::type_to_int<vostok::render::grass_loading_data *>::get();
  v17 = v5;
  v18 = v16;
  v16[0] = &vostok::detail::concrete_type_helper<vostok::render::grass_loading_data *>::`vftable';
  result = (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > *)&ud;
  boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(cb, (int)&v10);
  HIDWORD(v9) = (unsigned __int8)1_146;
  LODWORD(v9) = (_DWORD)f;
  boost::bind<void,survarium::object_environment,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &,survarium::object_environment *,boost::arg<1>,boost::function<void __cdecl (survarium::game_object_ &)>>(
    (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_environment,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_environment *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > *)result,
    v9,
    (void (__thiscall *__ptr64)(survarium::object_vegetation *, vostok::resources::queries_result *, boost::function<void __cdecl(survarium::game_object_ &)> *))(unsigned int)survarium::object_vegetation::on_grass_loaded,
    v10);
  boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
    v7,
    (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > >)ud,
    v12);
  result = (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > *)v16;
  LODWORD(f) = "grass";
  HIDWORD(f) = 109;
  vostok::resources::query_resources(
    (const vostok::resources::request *)&f,
    1u,
    (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
    (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
    (const vostok::variant<32> **)&result,
    0,
    assert_on_fail_true);
  if ( callback.vtable )
  {
    if ( ((int)callback.vtable & 1) == 0 )
    {
      v8 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
      if ( v8 )
        v8(&callback.functor, &callback.functor, 2);
    }
  }
  if ( v18 )
    (*(void (__thiscall **)(_DWORD *, int **))(*v18 + 4))(v18, &v17);
}
