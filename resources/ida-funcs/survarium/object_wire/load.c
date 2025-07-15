void __thiscall survarium::object_wire::load(
        survarium::object_wire *this,
        const vostok::configs::binary_config_value *t,
        const char *__formal,
        boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *cb)
{
  const vostok::configs::binary_config_value *v5; // eax
  float pointer; // xmm0_4
  const void *v7; // eax
  vostok::memory::doug_lea_allocator *v8; // esi
  char *v9; // eax
  char *v10; // eax
  bool v11; // zf
  _DWORD *v12; // esi
  char *v13; // edi
  unsigned int v14; // eax
  vostok::math::float3 *m_points; // ecx
  vostok::memory::writer *m_points_count; // eax
  const vostok::variant<32> *m_data; // esi
  vostok::buffer_string *v18; // ecx
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v19; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v20; // ecx
  bool has_passed_filters; // al
  void (__thiscall *__ptr64 v22)(survarium::object_vegetation *, vostok::resources::queries_result *, boost::function<void __cdecl(survarium::game_object_ &)> *); // [esp-58h] [ebp-FCh]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v23; // [esp-4Ch] [ebp-F0h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_wire,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_wire *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > v24; // [esp-2Ch] [ebp-D0h] BYREF
  const char *v25; // [esp+4h] [ebp-A0h]
  const char *v26; // [esp+8h] [ebp-9Ch]
  unsigned int v27; // [esp+Ch] [ebp-98h]
  int v28; // [esp+14h] [ebp-90h]
  char *v29; // [esp+18h] [ebp-8Ch]
  int v30; // [esp+1Ch] [ebp-88h]
  int v31; // [esp+20h] [ebp-84h]
  vostok::resources::query_result_for_cook *m_file_size; // [esp+24h] [ebp-80h]
  const char *v33[3]; // [esp+28h] [ebp-7Ch] BYREF
  _BYTE v34[32]; // [esp+34h] [ebp-70h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v35; // [esp+54h] [ebp-50h] BYREF
  vostok::memory::writer v36; // [esp+78h] [ebp-2Ch] BYREF

  v31 = 0;
  survarium::load_transform(t, &this->m_transform);
  v5 = vostok::configs::binary_config_value::operator[](t, "wire_width");
  if ( v5->type == 2 )
    pointer = *(float *)&v5->data.pointer;
  else
    pointer = (float)(int)v5->data.pointer;
  this->m_wire_width = pointer;
  v7 = vostok::configs::binary_config_value::operator[](t, "points_count")->data.pointer;
  this->m_points_count = (unsigned int)v7;
  if ( v7 )
  {
    v8 = survarium::g_allocator;
    v9 = type_info::raw_name(&vostok::math::float3 `RTTI Type Descriptor');
    v10 = vostok::memory::doug_lea_allocator::malloc_impl(
            (vostok::memory::doug_lea_allocator *)(12 * this->m_points_count),
            (int)v8,
            12 * this->m_points_count,
            v9,
            v25,
            v26,
            v27);
    v30 = 0;
    v11 = this->m_points_count == 0;
    this->m_points = (vostok::math::float3 *)v10;
    v29 = v10;
    if ( !v11 )
    {
      v28 = 0;
      do
      {
        v12 = *(_DWORD **)((char *)vostok::configs::binary_config_value::operator[](t, "points")->data.pointer + v28);
        v13 = v29;
        v29 += 12;
        v14 = ++v30;
        v28 += 24;
        *(_DWORD *)v13 = *v12++;
        v13 += 4;
        *(_DWORD *)v13 = *v12;
        *((_DWORD *)v13 + 1) = v12[1];
      }
      while ( v14 < this->m_points_count );
    }
  }
  vostok::memory::writer::writer(&v36, survarium::g_allocator);
  m_points_count = (vostok::memory::writer *)this->m_points_count;
  v36.external_data = 1;
  if ( m_points_count && (m_points = this->m_points) != 0 )
  {
    survarium::create_wire_visual_source(
      &v36,
      m_points,
      m_points_count,
      COERCE_VOSTOK_MEMORY_WRITER_(this->m_wire_width));
    m_data = (const vostok::variant<32> *)v36.m_data;
    m_file_size = (vostok::resources::query_result_for_cook *)v36.m_file_size;
    v33[0] = v34;
    v33[1] = v34;
    v33[2] = (const char *)&v35;
    v34[0] = 0;
    vostok::fs_new::path_string_impl::assignf(v33, v18, (vostok::buffer_string *)"wire_%X", (const char *)this);
    boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(cb, &v23);
    HIDWORD(v22) = survarium::object_wire::resources_ready;
    LODWORD(v22) = (unsigned __int8)1_113;
    boost::bind<void,survarium::object_sound,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &,survarium::object_sound *,boost::arg<1>,boost::function<void __cdecl (survarium::game_object_ &)>>(
      (int)&v24,
      (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > *)this,
      v22,
      0,
      (int)v23.vtable);
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      v19,
      (int)&v35,
      v24,
      (int)v25);
    v24.l_.a3_.t_.functor.vostok_pointer_size_alignment[1] = survarium::g_allocator;
    v24.l_.a3_.t_.functor.obj_ptr = (void *)25;
    vostok::resources::query_create_resource(
      v33[0],
      *(vostok::const_buffer *)&v24.l_.a3_.t_.functor.obj_ptr,
      0,
      0,
      m_data,
      m_file_size);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v20,
      (int *)&v35);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"game",
                                 (const char *)3),
          m_points = (vostok::math::float3 *)v24.l_.a3_.t_.functor.vostok_pointer_size_alignment[5],
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)m_points,
        &v35);
      v31 = 1;
      vostok::logging::append(
        &v35,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\object_wire.cpp",
        0x68u,
        "void __thiscall survarium::object_wire::load(const class vostok::configs::binary_config_value &,const char *,cla"
        "ss boost::function<void __cdecl(class survarium::game_object_ &)> &)",
        "game",
        warning,
        "empty wire");
    }
    if ( (v31 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)m_points,
        (int *)&v35);
    boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
      (boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *)m_points,
      cb,
      (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)this);
  }
  vostok::memory::writer::~writer(&v36);
}
