void __thiscall survarium::game_world::load(
        survarium::game_world *this,
        boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::game_world,vostok::resources::queries_result &,unsigned int,boost::function<void __cdecl(vostok::resources::queries_result &)> const &>,boost::_bi::list4<boost::_bi::value<survarium::game_world *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl(vostok::resources::queries_result &)> > > > *project_resource_name,
        vostok::resources::request *requests_begin,
        vostok::resources::request *requests_end,
        const vostok::variant<32> **user_datas_begin,
        boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *callback)
{
  int v6; // edi
  int v7; // edi
  void *v8; // esp
  unsigned int v9; // esi
  void *v10; // esp
  void *v11; // esp
  vostok::resources::request *i; // edi
  vostok::buffer_vector<vostok::variant<32> const *> *v13; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::game_world,vostok::resources::queries_result &,unsigned int,boost::function<void __cdecl(vostok::resources::queries_result &)> const &>,boost::_bi::list4<boost::_bi::value<survarium::game_world *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl(vostok::resources::queries_result &)> > > > *v14; // edi
  vostok::memory::doug_lea_allocator *v15; // esi
  char *v16; // eax
  vostok::memory::doug_lea_allocator *v17; // ecx
  vostok::buffer_vector<vostok::variant<32> > *v18; // ecx
  char *v19; // esi
  int v20; // eax
  int v21; // eax
  void (__thiscall ***v22)(_DWORD, _DWORD *); // ecx
  int v23; // ecx
  vostok::variant<32> *v24; // ecx
  vostok::variant<32> *v25; // ecx
  vostok::buffer_vector<vostok::variant<32> > *v26; // ecx
  vostok::variant<32> *v27; // ecx
  vostok::variant<32> *v28; // ecx
  vostok::buffer_vector<vostok::variant<32> const *> *v29; // ecx
  vostok::buffer_vector<vostok::variant<32> const *> *v30; // ecx
  vostok::buffer_vector<vostok::variant<32> const *> *v31; // ecx
  vostok::buffer_vector<vostok::variant<32> const *> *v32; // ecx
  vostok::buffer_vector<vostok::variant<32> const *> *v33; // ecx
  vostok::buffer_vector<vostok::variant<32> const *> *v34; // ecx
  vostok::buffer_vector<vostok::variant<32> const *> *v35; // ecx
  boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *v36; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v37; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v38; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v39; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v40; // ecx
  vostok::buffer_vector<vostok::variant<32> > *v41; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::game_world,vostok::resources::queries_result &,unsigned int,boost::function<void __cdecl(vostok::resources::queries_result &)> const &>,boost::_bi::list4<boost::_bi::value<survarium::game_world *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl(vostok::resources::queries_result &)> > > > v42; // [esp-34h] [ebp-140h] BYREF
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v43; // [esp-4h] [ebp-110h]
  const char *v44[2]; // [esp+0h] [ebp-10Ch] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::game_world,vostok::resources::queries_result &,unsigned int,boost::function<void __cdecl(vostok::resources::queries_result &)> const &>,boost::_bi::list4<boost::_bi::value<survarium::game_world *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl(vostok::resources::queries_result &)> > > > __that; // [esp+8h] [ebp-104h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::game_world,vostok::resources::queries_result &,unsigned int,boost::function<void __cdecl(vostok::resources::queries_result &)> const &>,boost::_bi::list4<boost::_bi::value<survarium::game_world *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl(vostok::resources::queries_result &)> > > > v46; // [esp+38h] [ebp-D4h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::game_world,vostok::resources::queries_result &,unsigned int,boost::function<void __cdecl(vostok::resources::queries_result &)> const &>,boost::_bi::list4<boost::_bi::value<survarium::game_world *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl(vostok::resources::queries_result &)> > > > v47; // [esp+68h] [ebp-A4h] BYREF
  vostok::variant<32> value; // [esp+98h] [ebp-74h] BYREF
  _DWORD v49[2]; // [esp+CCh] [ebp-40h] BYREF
  int v50; // [esp+D4h] [ebp-38h]
  const vostok::variant<32> **v51; // [esp+D8h] [ebp-34h] BYREF
  const char **v52; // [esp+DCh] [ebp-30h]
  const char **v53; // [esp+E0h] [ebp-2Ch]
  const vostok::variant<32> *const *v54[3]; // [esp+E4h] [ebp-28h] BYREF
  vostok::buffer_vector<vostok::resources::request> v55; // [esp+F0h] [ebp-1Ch] BYREF
  unsigned int v56; // [esp+FCh] [ebp-10h] BYREF
  vostok::resources::request v57; // [esp+100h] [ebp-Ch] BYREF

  v6 = (char *)requests_end - (char *)requests_begin;
  LOBYTE(project_resource_name[284].l_.a1_.t_) = 1;
  v50 = v6 >> 3;
  v7 = s_max_tracers_count + 8 + (v6 >> 3);
  v8 = alloca(8 * v7);
  v9 = 12 * (s_max_tracers_count + 8);
  v55.m_begin = (vostok::resources::request *)v44;
  v55.m_end = (vostok::resources::request *)v44;
  v55.m_max_end = (vostok::resources::request *)&v44[2 * v7];
  v10 = alloca(v9 * 4);
  v51 = (const vostok::variant<32> **)v44;
  v52 = v44;
  v7 *= 4;
  v53 = &v44[v9];
  v11 = alloca(v7);
  v54[0] = (const vostok::variant<32> *const *)v44;
  v54[1] = (const vostok::variant<32> *const *)v44;
  v54[2] = (const vostok::variant<32> *const *)((char *)v44 + v7);
  for ( i = requests_begin; i != requests_end; ++i )
  {
    vostok::buffer_vector<vostok::resources::request>::push_back(&v55, i);
    vostok::buffer_vector<vostok::variant<32> const *>::push_back(v13, (int)v54, user_datas_begin++);
  }
  v14 = project_resource_name;
  HIBYTE(user_datas_begin) &= 0xC0u;
  if ( !HIDWORD(project_resource_name->f_.f_) )
  {
    v15 = survarium::g_allocator;
    v16 = type_info::raw_name(&survarium::damage_model_stats `RTTI Type Descriptor');
    v19 = vostok::memory::doug_lea_allocator::malloc_impl(
            v17,
            (int)v15,
            0x1Cu,
            v16,
            v44[0],
            v44[1],
            (const unsigned int)__that.f_.f_);
    if ( v19 )
    {
      v20 = (*((int (__thiscall **)(boost::detail::function::vtable_base *))project_resource_name[3].l_.a4_.t_.vtable->manager
             + 11))(project_resource_name[3].l_.a4_.t_.vtable);
      *((float *)v19 + 4) = FLOAT_20_0;
      *((float *)v19 + 5) = FLOAT_180_0;
      *(_DWORD *)v19 = v20;
      *((_DWORD *)v19 + 2) = -8323073;
      *((_DWORD *)v19 + 3) = -128;
      *((float *)v19 + 6) = FLOAT_360_0;
      v21 = (*(int (__thiscall **)(int))(*(_DWORD *)v20 + 8))(v20);
      *((_DWORD *)v19 + 1) = v21;
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v21 + 16))(v21, 1);
      v22 = (void (__thiscall ***)(_DWORD, _DWORD *))*((_DWORD *)v19 + 1);
      v49[0] = 0;
      v49[1] = 0;
      (**v22)(v22, v49);
      v23 = *((_DWORD *)v19 + 1);
      *(float *)&v57.path = FLOAT_1280_0;
      *(float *)&v57.id = FLOAT_720_0;
      (*(void (__thiscall **)(int, vostok::resources::request *))(*(_DWORD *)v23 + 8))(v23, &v57);
    }
    else
    {
      v19 = 0;
    }
    value.m_helper = 0;
    value.m_type_id = 0;
    HIBYTE(user_datas_begin) = HIBYTE(user_datas_begin) & 0xE4 | 0x1A;
    HIDWORD(project_resource_name[284].f_.f_) = v19;
    v56 = 128;
    v57.path = (const char *)196;
    v57.id = fs_iterator_class;
    vostok::buffer_vector<vostok::variant<32>>::push_back(v18, (int)&v51, &value);
    vostok::variant<32>::destroy_previous_variable_if_needed(v24, (int)&value);
    vostok::variant<32>::set<vostok::render::scene_configuration>(
      v25,
      (int)(v52 - 12),
      (const vostok::render::scene_configuration *)&user_datas_begin + 3);
    value.m_helper = 0;
    value.m_type_id = 0;
    vostok::buffer_vector<vostok::variant<32>>::push_back(v26, (int)&v51, &value);
    vostok::variant<32>::destroy_previous_variable_if_needed(v27, (int)&value);
    vostok::variant<32>::set<vostok::sound::sound_scene_creation_params>(
      v28,
      (const vostok::sound::sound_scene_creation_params *)v52 - 4,
      &v56);
    v57.path = "game_scene";
    v57.id = scene_class;
    vostok::buffer_vector<vostok::resources::request>::push_back(&v55, &v57);
    user_datas_begin = v51;
    vostok::buffer_vector<vostok::variant<32> const *>::push_back(
      v29,
      (int)v54,
      (const vostok::variant<32> **)&user_datas_begin);
    v57.path = "game_scene_view";
    v57.id = scene_view_class;
    vostok::buffer_vector<vostok::resources::request>::push_back(&v55, &v57);
    user_datas_begin = 0;
    vostok::buffer_vector<vostok::variant<32> const *>::push_back(
      v30,
      (int)v54,
      (const vostok::variant<32> **)&user_datas_begin);
    v57.path = "game_sound_scene";
    v57.id = sound_scene_class;
    vostok::buffer_vector<vostok::resources::request>::push_back(&v55, &v57);
    user_datas_begin = v51 + 12;
    vostok::buffer_vector<vostok::variant<32> const *>::push_back(
      v31,
      (int)v54,
      (const vostok::variant<32> **)&user_datas_begin);
    v57.path = "resources/flash_movies/hud.swf";
    v57.id = flash_movie_class;
    vostok::buffer_vector<vostok::resources::request>::push_back(&v55, &v57);
    user_datas_begin = 0;
    vostok::buffer_vector<vostok::variant<32> const *>::push_back(
      v32,
      (int)v54,
      (const vostok::variant<32> **)&user_datas_begin);
    v57.path = "resources/flash_movies/cursor.swf";
    v57.id = flash_movie_class;
    vostok::buffer_vector<vostok::resources::request>::push_back(&v55, &v57);
    user_datas_begin = 0;
    vostok::buffer_vector<vostok::variant<32> const *>::push_back(
      v33,
      (int)v54,
      (const vostok::variant<32> **)&user_datas_begin);
    v57.path = "resources/flash_movies/player_icons.swf";
    v57.id = flash_movie_class;
    vostok::buffer_vector<vostok::resources::request>::push_back(&v55, &v57);
    user_datas_begin = 0;
    vostok::buffer_vector<vostok::variant<32> const *>::push_back(
      v34,
      (int)v54,
      (const vostok::variant<32> **)&user_datas_begin);
    user_datas_begin = 0;
    if ( s_max_tracers_count )
    {
      v57.path = "weapons/trace";
      v57.id = tracer_model_instance_class;
      requests_end = 0;
      do
      {
        vostok::buffer_vector<vostok::resources::request>::push_back(&v55, &v57);
        vostok::buffer_vector<vostok::variant<32> const *>::push_back(
          v35,
          (int)v54,
          (const vostok::variant<32> **)&requests_end);
        user_datas_begin = (const vostok::variant<32> **)((char *)user_datas_begin + 1);
      }
      while ( (unsigned int)user_datas_begin < s_max_tracers_count );
    }
    v14 = project_resource_name;
  }
  if ( v14[23].l_.a4_.t_.functor.obj_ptr )
    survarium::game_world::unload(
      this,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v14);
  v57.id = unknown_data_class;
  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
    callback,
    (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&(&v42.l_.a4_.t_.vtable)[1]);
  v42.l_.a1_.t_ = (survarium::game_world *)v50;
  HIDWORD(v42.f_.f_) = (unsigned __int8)1_77;
  boost::bind<void,survarium::object_decal,vostok::resources::queries_result &,vostok::render::material_effects_instance_cook_data *,boost::function<void __cdecl (survarium::game_object_ &)> &,survarium::object_decal *,boost::arg<1>,vostok::render::material_effects_instance_cook_data *,boost::function<void __cdecl (survarium::game_object_ &)>>(
    (int)&__that,
    v14,
    *(void (__thiscall *__ptr64 *)(survarium::game_world *, vostok::resources::queries_result *, unsigned int, const boost::function<void __cdecl(vostok::resources::queries_result &)> *))((char *)&v42.f_.f_ + 4),
    (survarium::game_world *)survarium::game_world::on_project_loaded,
    v57.id,
    (unsigned int)(&v42.l_.a4_.t_.vtable)[1]);
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::game_world,vostok::resources::queries_result &,unsigned int,boost::function<void __cdecl (vostok::resources::queries_result &)> const &>,boost::_bi::list4<boost::_bi::value<survarium::game_world *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl (vostok::resources::queries_result &)>>>>::bind_t<void,boost::_mfi::mf3<void,survarium::game_world,vostok::resources::queries_result &,unsigned int,boost::function<void __cdecl (vostok::resources::queries_result &)> const &>,boost::_bi::list4<boost::_bi::value<survarium::game_world *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl (vostok::resources::queries_result &)>>>>(
    &v47,
    &__that);
  *(_DWORD *)&value.m_storage[8] = 0;
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::game_world,vostok::resources::queries_result &,unsigned int,boost::function<void __cdecl (vostok::resources::queries_result &)> const &>,boost::_bi::list4<boost::_bi::value<survarium::game_world *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl (vostok::resources::queries_result &)>>>>::bind_t<void,boost::_mfi::mf3<void,survarium::game_world,vostok::resources::queries_result &,unsigned int,boost::function<void __cdecl (vostok::resources::queries_result &)> const &>,boost::_bi::list4<boost::_bi::value<survarium::game_world *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl (vostok::resources::queries_result &)>>>>(
    &v46,
    &v47);
  v43 = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)&value.m_storage[16];
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::game_world,vostok::resources::queries_result &,unsigned int,boost::function<void __cdecl (vostok::resources::queries_result &)> const &>,boost::_bi::list4<boost::_bi::value<survarium::game_world *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl (vostok::resources::queries_result &)>>>>::bind_t<void,boost::_mfi::mf3<void,survarium::game_world,vostok::resources::queries_result &,unsigned int,boost::function<void __cdecl (vostok::resources::queries_result &)> const &>,boost::_bi::list4<boost::_bi::value<survarium::game_world *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl (vostok::resources::queries_result &)>>>>(
    &v42,
    &v46);
  *(_DWORD *)&value.m_storage[8] = boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::game_world,vostok::resources::queries_result &,unsigned int,boost::function<void __cdecl (vostok::resources::queries_result &)> const &>,boost::_bi::list4<boost::_bi::value<survarium::game_world *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl (vostok::resources::queries_result &)>>>>>(
                                     v36,
                                     v42,
                                     v43) != 0
                                 ? &`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::game_world,vostok::resources::queries_result &,unsigned int,boost::function<void __cdecl (vostok::resources::queries_result &)> const &>,boost::_bi::list4<boost::_bi::value<survarium::game_world *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl (vostok::resources::queries_result &)>>>>>'::`2'::stored_vtable
                                 : 0;
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v37,
    (int *)&v46.l_.a4_);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v38,
    (int *)&v47.l_.a4_);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v39,
    (int *)&__that.l_.a4_);
  vostok::resources::query_resources(
    v55.m_begin,
    v55.m_end - v55.m_begin,
    survarium::g_allocator,
    v54[0],
    0,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v40,
    (int *)&value.m_storage[8]);
  vostok::buffer_vector<vostok::variant<32>>::~buffer_vector<vostok::variant<32>>(v41, (int *)&v51);
}
