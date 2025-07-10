void __thiscall survarium::object_sound::load(
        survarium::object_sound *this,
        vostok::configs::binary_config_value *t,
        const char *__formal,
        boost::function4<void,unsigned int,float,float,char const *> *cb)
{
  const void *pointer; // edx
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v6; // ecx
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__thiscall *__ptr64 v8)(survarium::object_vegetation *, vostok::resources::queries_result *, boost::function<void __cdecl(survarium::game_object_ &)> *); // [esp-60h] [ebp-98h]
  boost::function<void __cdecl(survarium::game_object_ &)> v9; // [esp-50h] [ebp-88h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_sound,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_sound *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > v10; // [esp-30h] [ebp-68h] BYREF
  int v11; // [esp+0h] [ebp-38h]
  vostok::resources::request result; // [esp+Ch] [ebp-2Ch] BYREF
  vostok::resources::class_id_enum resource_id; // [esp+14h] [ebp-24h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+18h] [ebp-20h] BYREF

  survarium::load_transform(t, &this->m_transform);
  this->m_sound_name = (const char *)vostok::configs::binary_config_value::operator[](t, "sound_name")->data.pointer;
  pointer = vostok::configs::binary_config_value::operator[](t, "sound_type")->data.pointer;
  v10.l_.a3_.t_.functor.vostok_pointer_size_alignment[5] = (void *)"resource_id";
  this->m_sound_emitter_type = (int)pointer;
  resource_id = (vostok::resources::class_id_enum)vostok::configs::binary_config_value::operator[](
                                                    t,
                                                    (char *)v10.l_.a3_.t_.functor.vostok_pointer_size_alignment[5])->data.pointer;
  result.path = (const char *)&v10;
  boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(cb, (int)&v9);
  HIDWORD(v8) = (unsigned __int8)1_144;
  LODWORD(v8) = this;
  boost::bind<void,survarium::object_environment,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &,survarium::object_environment *,boost::arg<1>,boost::function<void __cdecl (survarium::game_object_ &)>>(
    (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_environment,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_environment *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > *)result.path,
    v8,
    (void (__thiscall *__ptr64)(survarium::object_vegetation *, vostok::resources::queries_result *, boost::function<void __cdecl(survarium::game_object_ &)> *))(unsigned int)survarium::object_sound::on_sound_resources_ready,
    v9);
  boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
    v6,
    v10,
    v11);
  result.path = this->m_sound_name;
  result.id = resource_id;
  resource_id = unknown_data_class;
  vostok::resources::query_resources(
    &result,
    1u,
    (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
    (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
    (const vostok::variant<32> **)&resource_id,
    0,
    assert_on_fail_true);
  if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
  {
    v7 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
    if ( v7 )
      v7(&callback.functor, &callback.functor, 2);
  }
}
