void __thiscall survarium::object_particle_visual::load(
        survarium::object_particle_visual *this,
        vostok::configs::binary_config_value *t,
        const char *project_resources_path,
        boost::function4<void,unsigned int,float,float,char const *> *cb)
{
  survarium::base_game_scene *m_game_scene; // ecx
  vostok::render::base_scene *v6; // edx
  vostok::render::base_scene *m_object; // eax
  unsigned int m_quality_levels_count; // esi
  const char *pointer; // ebx
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v10; // ecx
  void (__cdecl *v11)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__thiscall *__ptr64 v12)(survarium::object_vegetation *, vostok::resources::queries_result *, boost::function<void __cdecl(survarium::game_object_ &)> *); // [esp-30h] [ebp-C8h]
  boost::function<void __cdecl(survarium::game_object_ &)> v13; // [esp-20h] [ebp-B8h] BYREF
  vostok::variant<32> ud; // [esp+0h] [ebp-98h] BYREF
  int v15; // [esp+30h] [ebp-68h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > *result; // [esp+3Ch] [ebp-5Ch] BYREF
  vostok::resources::request requests; // [esp+40h] [ebp-58h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+48h] [ebp-50h] BYREF
  _DWORD v19[2]; // [esp+68h] [ebp-30h] BYREF
  unsigned int v20[8]; // [esp+70h] [ebp-28h] BYREF
  _DWORD *v21; // [esp+90h] [ebp-8h]
  int v22; // [esp+94h] [ebp-4h]

  survarium::load_transform(t, &this->m_transform);
  m_game_scene = this->m_game_scene;
  v6 = 0;
  v21 = 0;
  v22 = 0;
  m_object = m_game_scene->m_render_scene.m_object;
  if ( m_object )
  {
    v6 = m_game_scene->m_render_scene.m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  m_quality_levels_count = v6[3].m_quality_levels_count;
  result = (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > *)&v6->vostok::resources::unmanaged_intrusive_base;
  if ( !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v6->vostok::resources::unmanaged_intrusive_base, v6);
  v22 = vostok::detail::type_to_int<vostok::particle::world *>::get();
  v20[0] = m_quality_levels_count;
  v19[0] = &vostok::detail::concrete_type_helper<vostok::particle::world *>::`vftable';
  v21 = v19;
  pointer = (const char *)vostok::configs::binary_config_value::operator[](t, "lib_name")->data.pointer;
  result = (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > *)&ud;
  boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(cb, (int)&v13);
  HIDWORD(v12) = (unsigned __int8)1_141;
  LODWORD(v12) = this;
  boost::bind<void,survarium::object_environment,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &,survarium::object_environment *,boost::arg<1>,boost::function<void __cdecl (survarium::game_object_ &)>>(
    (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_environment,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_environment *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > *)result,
    v12,
    (void (__thiscall *__ptr64)(survarium::object_vegetation *, vostok::resources::queries_result *, boost::function<void __cdecl(survarium::game_object_ &)> *))(unsigned int)survarium::object_particle_visual::on_visual_ready,
    v13);
  boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
    v10,
    (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_particle_visual,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_particle_visual *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > >)ud,
    v15);
  result = (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > *)v19;
  requests.path = pointer;
  requests.id = particle_system_instance_class;
  vostok::resources::query_resources(
    &requests,
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
      v11 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
      if ( v11 )
        v11(&callback.functor, &callback.functor, 2);
    }
  }
  if ( v21 )
    (*(void (__thiscall **)(_DWORD *, unsigned int *))(*v21 + 4))(v21, v20);
}
