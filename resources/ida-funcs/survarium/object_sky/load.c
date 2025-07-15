void __thiscall survarium::object_sky::load(
        survarium::object_sky *this,
        vostok::configs::binary_config_value *t,
        const char *__formal,
        boost::function4<void,unsigned int,float,float,char const *> *cb)
{
  int *v4; // esi
  survarium::game_world *v5; // eax
  survarium::game_world *v6; // edi
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v7; // ecx
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__thiscall *__ptr64 v9)(survarium::game_world *, vostok::resources::queries_result *, unsigned int, const boost::function<void __cdecl(vostok::resources::queries_result &)> *); // [esp+20h] [ebp-D4h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> v10; // [esp+34h] [ebp-C0h] BYREF
  vostok::variant<32> user_data; // [esp+54h] [ebp-A0h] BYREF
  int v12; // [esp+84h] [ebp-70h]
  survarium::object_sky *f; // [esp+94h] [ebp-60h]
  void (__thiscall *__ptr64 f_4)(survarium::game_world *, vostok::resources::queries_result *, unsigned int, const boost::function<void __cdecl(vostok::resources::queries_result &)> *); // [esp+98h] [ebp-5Ch] BYREF
  vostok::variant<32> *pointer; // [esp+A0h] [ebp-54h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+A4h] [ebp-50h] BYREF
  _DWORD v17[2]; // [esp+C4h] [ebp-30h] BYREF
  survarium::game_world *v18; // [esp+CCh] [ebp-28h] BYREF
  _DWORD *v19; // [esp+ECh] [ebp-8h]
  int v20; // [esp+F0h] [ebp-4h]

  f = this;
  pointer = (vostok::variant<32> *)vostok::configs::binary_config_value::operator[](t, "material_name")->data.pointer;
  v4 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
         0x10u);
  if ( v4 )
  {
    vostok::render::material_effects_instance_cook_data::material_effects_instance_cook_data(
      (vostok::render::material_effects_instance_cook_data *)v4,
      post_process_vertex_input_type,
      0,
      0,
      cull_mode_back);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  v20 = vostok::detail::type_to_int<vostok::render::material_effects_instance_cook_data *>::get();
  v19 = v17;
  v18 = v6;
  v17[0] = &vostok::detail::concrete_type_helper<vostok::render::material_effects_instance_cook_data *>::`vftable';
  LODWORD(f_4) = &user_data;
  boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(cb, (int)&v10);
  HIDWORD(v9) = (unsigned __int8)1_133;
  LODWORD(v9) = f;
  boost::bind<void,survarium::object_sky,vostok::resources::queries_result &,vostok::render::material_effects_instance_cook_data *,boost::function<void __cdecl (survarium::game_object_ &)> &,survarium::object_sky *,boost::arg<1>,vostok::render::material_effects_instance_cook_data *,boost::function<void __cdecl (survarium::game_object_ &)>>(
    (boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::object_sky,vostok::resources::queries_result &,vostok::render::material_effects_instance_cook_data *,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list4<boost::_bi::value<survarium::object_sky *>,boost::arg<1>,boost::_bi::value<vostok::render::material_effects_instance_cook_data *>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > *)f_4,
    v9,
    v6,
    (void (__thiscall *__ptr64)(survarium::game_world *, vostok::resources::queries_result *, unsigned int, const boost::function<void __cdecl(vostok::resources::queries_result &)> *))(unsigned int)survarium::object_sky::material_ready,
    v10);
  boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
    v7,
    (boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::object_sky,vostok::resources::queries_result &,vostok::render::material_effects_instance_cook_data *,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list4<boost::_bi::value<survarium::object_sky *>,boost::arg<1>,boost::_bi::value<vostok::render::material_effects_instance_cook_data *>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > >)user_data,
    v12);
  LODWORD(f_4) = pointer;
  pointer = (vostok::variant<32> *)v17;
  HIDWORD(f_4) = 15;
  vostok::resources::query_resources(
    (const vostok::resources::request *)&f_4,
    1u,
    (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
    (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
    (const vostok::variant<32> **)&pointer,
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
  if ( v19 )
    (*(void (__thiscall **)(_DWORD *, survarium::game_world **))(*v19 + 4))(v19, &v18);
}
