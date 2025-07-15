void __thiscall survarium::object_environment::load(
        survarium::object_environment *this,
        vostok::configs::binary_config_value *t,
        const char *__formal,
        boost::function4<void,unsigned int,float,float,char const *> *cb)
{
  const char *pointer; // ebx
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v6; // ecx
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__thiscall *__ptr64 v8)(survarium::object_vegetation *, vostok::resources::queries_result *, boost::function<void __cdecl(survarium::game_object_ &)> *); // [esp-60h] [ebp-98h]
  boost::function<void __cdecl(survarium::game_object_ &)> v9; // [esp-50h] [ebp-88h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_environment,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_environment *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > v10; // [esp-30h] [ebp-68h] BYREF
  int v11; // [esp+0h] [ebp-38h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > *result; // [esp+Ch] [ebp-2Ch] BYREF
  vostok::resources::request requests; // [esp+10h] [ebp-28h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+18h] [ebp-20h] BYREF

  pointer = (const char *)vostok::configs::binary_config_value::operator[](t, "post_effect")->data.pointer;
  result = (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > *)&v10;
  boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(cb, (int)&v9);
  HIDWORD(v8) = (unsigned __int8)1_132;
  LODWORD(v8) = this;
  boost::bind<void,survarium::object_environment,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &,survarium::object_environment *,boost::arg<1>,boost::function<void __cdecl (survarium::game_object_ &)>>(
    (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_environment,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_environment *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > *)result,
    v8,
    (void (__thiscall *__ptr64)(survarium::object_vegetation *, vostok::resources::queries_result *, boost::function<void __cdecl(survarium::game_object_ &)> *))(unsigned int)survarium::object_environment::material_ready,
    v9);
  boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
    v6,
    v10,
    v11);
  requests.path = pointer;
  requests.id = material_class;
  result = 0;
  vostok::resources::query_resources(
    &requests,
    1u,
    &callback,
    (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
    (const vostok::variant<32> **)&result,
    0,
    assert_on_fail_true);
  if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
  {
    v7 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
    if ( v7 )
      v7(&callback.functor, &callback.functor, 2);
  }
}
