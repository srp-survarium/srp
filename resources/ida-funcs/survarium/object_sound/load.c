void __thiscall survarium::object_sound::load(
        survarium::object_sound *this,
        const vostok::configs::binary_config_value *t,
        const char *__formal,
        boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *cb)
{
  boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *v5; // ecx
  vostok::variant<32> *pointer; // ebx
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v7; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  void (__thiscall *__ptr64 v9)(survarium::object_vegetation *, vostok::resources::queries_result *, boost::function<void __cdecl(survarium::game_object_ &)> *); // [esp-5Ch] [ebp-8Ch]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v10; // [esp-50h] [ebp-80h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_sound,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_sound *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > v11; // [esp-30h] [ebp-60h] BYREF
  int v12; // [esp+0h] [ebp-30h]
  int v13[8]; // [esp+10h] [ebp-20h] BYREF

  survarium::load_transform(t, &this->m_transform);
  this->m_sound_name = (const char *)vostok::configs::binary_config_value::operator[](t, "sound_name")->data.pointer;
  this->m_sound_emitter_type = (int)vostok::configs::binary_config_value::operator[](t, "sound_type")->data.pointer;
  if ( strlen(this->m_sound_name) )
  {
    pointer = (vostok::variant<32> *)vostok::configs::binary_config_value::operator[](t, "resource_id")->data.pointer;
    boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(cb, &v10);
    HIDWORD(v9) = survarium::object_sound::on_sound_resources_ready;
    LODWORD(v9) = (unsigned __int8)1_114;
    boost::bind<void,survarium::object_sound,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &,survarium::object_sound *,boost::arg<1>,boost::function<void __cdecl (survarium::game_object_ &)>>(
      (int)&v11,
      (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > *)this,
      v9,
      0,
      (int)v10.vtable);
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      v7,
      (int)v13,
      v11,
      v12);
    vostok::resources::query_resource(this->m_sound_name, pointer, survarium::g_allocator, 0, 0, assert_on_fail_true);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v8, v13);
  }
  else
  {
    boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
      v5,
      cb,
      (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)this);
  }
}
