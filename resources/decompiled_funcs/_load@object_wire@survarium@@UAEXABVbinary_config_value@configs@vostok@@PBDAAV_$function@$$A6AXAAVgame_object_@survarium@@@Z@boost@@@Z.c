void __thiscall survarium::object_wire::load(
        survarium::object_wire *this,
        vostok::configs::binary_config_value *t,
        const char *__formal,
        boost::function4<void,unsigned int,float,float,char const *> *cb)
{
  vostok::configs::binary_config_value *v4; // esi
  unsigned int v6; // ebx
  const vostok::configs::binary_config_value *v7; // eax
  float pointer; // xmm0_4
  unsigned int v9; // eax
  int *v10; // eax
  const vostok::configs::binary_config_value *v11; // eax
  const char *m_data; // ecx
  int v13; // eoff
  unsigned int m_points_count; // eax
  vostok::math::float3 *m_points; // ecx
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v16; // ecx
  void (__cdecl *v17)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v18)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v19)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  survarium::game_camera *v20; // eax
  void (__thiscall *__ptr64 v21)(survarium::object_vegetation *, vostok::resources::queries_result *, boost::function<void __cdecl(survarium::game_object_ &)> *); // [esp-5Ch] [ebp-228h]
  boost::function<void __cdecl(survarium::game_object_ &)> v22; // [esp-4Ch] [ebp-218h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_wire,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_wire *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > v23; // [esp-2Ch] [ebp-1F8h] BYREF
  unsigned int v24; // [esp+4h] [ebp-1C8h]
  unsigned int v25; // [esp+8h] [ebp-1C4h]
  unsigned int v26; // [esp+Ch] [ebp-1C0h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > *result; // [esp+14h] [ebp-1B8h] BYREF
  vostok::const_buffer creation_buffer; // [esp+18h] [ebp-1B4h] BYREF
  vostok::memory::writer writer; // [esp+20h] [ebp-1ACh] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> requests; // [esp+4Ch] [ebp-180h] BYREF
  vostok::fixed_string<32> wire_name; // [esp+70h] [ebp-15Ch] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+9Ch] [ebp-130h] BYREF
  boost::bad_function_call v33; // [esp+BCh] [ebp-110h] BYREF

  v4 = t;
  v6 = 0;
  result = 0;
  survarium::load_transform(t, &this->m_transform);
  v7 = vostok::configs::binary_config_value::operator[](t, "wire_width");
  if ( v7->type == 2 )
    pointer = *(float *)&v7->data.pointer;
  else
    pointer = (float)(int)v7->data.pointer;
  v23.l_.a3_.t_.functor.vostok_pointer_size_alignment[5] = (void *)"points_count";
  this->m_wire_width = pointer;
  v9 = (unsigned int)vostok::configs::binary_config_value::operator[](
                       t,
                       (char *)v23.l_.a3_.t_.functor.vostok_pointer_size_alignment[5])->data.pointer;
  this->m_points_count = v9;
  if ( v9 )
  {
    v10 = vostok::memory::doug_lea_allocator::malloc_impl(
            (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
            12 * v9);
    this->m_points = (vostok::math::float3 *)v10;
    v4 = (vostok::configs::binary_config_value *)v10;
    if ( this->m_points_count )
    {
      creation_buffer.m_data = 0;
      do
      {
        v11 = vostok::configs::binary_config_value::operator[](t, "points");
        m_data = creation_buffer.m_data;
        v13 = *(_DWORD *)&creation_buffer.m_data[(unsigned int)v11->data.pointer];
        v4->data.max_storage = *(_QWORD *)v13;
        v4->id.pointer = *(const char **)(v13 + 8);
        ++v6;
        v4 = (vostok::configs::binary_config_value *)((char *)v4 + 12);
        creation_buffer.m_data = m_data + 24;
      }
      while ( v6 < this->m_points_count );
    }
  }
  writer.m_allocator = (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_;
  writer.m_chunk_pos._M_impl._M_end_of_storage.m_allocator = (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_;
  m_points_count = this->m_points_count;
  writer.m_chunk_pos._M_impl._M_start = 0;
  writer.m_chunk_pos._M_impl._M_finish = 0;
  writer.m_chunk_pos._M_impl._M_end_of_storage._M_data = 0;
  writer.__vftable = (vostok::memory::writer_vtbl *)&vostok::memory::writer::`vftable';
  memset(&writer.m_data, 0, 16);
  writer.external_data = 1;
  if ( m_points_count && (m_points = this->m_points) != 0 )
  {
    survarium::create_wire_visual_source(
      &writer,
      0,
      (int)this,
      (int)v4,
      m_points,
      m_points_count,
      COERCE_CONST_CHAR_(this->m_wire_width),
      v24,
      v25,
      v26);
    boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
      (vostok::mutable_buffer *)&creation_buffer,
      writer.m_data,
      writer.m_file_size);
    wire_name.m_begin = wire_name.m_buffer;
    wire_name.m_end = wire_name.m_buffer;
    wire_name.m_max_end = (char *)&callback;
    wire_name.m_buffer[0] = 0;
    vostok::buffer_string::assignf(&wire_name, "wire_%X", this);
    result = (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > *)&v23;
    boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(cb, (int)&v22);
    HIDWORD(v21) = (unsigned __int8)1_143;
    LODWORD(v21) = this;
    boost::bind<void,survarium::object_environment,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &,survarium::object_environment *,boost::arg<1>,boost::function<void __cdecl (survarium::game_object_ &)>>(
      (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_environment,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_environment *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > *)result,
      v21,
      (void (__thiscall *__ptr64)(survarium::object_vegetation *, vostok::resources::queries_result *, boost::function<void __cdecl(survarium::game_object_ &)> *))(unsigned int)survarium::object_wire::resources_ready,
      v22);
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      v16,
      v23,
      v24);
    requests.vtable = (boost::detail::function::vtable_base *)wire_name.m_begin;
    (&requests.vtable)[1] = (boost::detail::function::vtable_base *)creation_buffer.m_data;
    *(_QWORD *)&requests.functor.obj_ptr = creation_buffer.m_size | 0x1C00000000LL;
    result = 0;
    vostok::resources::query_create_resources(
      (const vostok::resources::creation_request *)&requests,
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
        v17 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
        if ( v17 )
          v17(&callback.functor, &callback.functor, 2);
      }
    }
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", warning) )
    {
      v18 = vostok::core::g_log_callback;
      requests.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &requests.functor,
          &requests.functor,
          destroy_functor_tag);
      if ( v18 )
      {
        requests.functor.obj_ptr = v18;
        requests.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                 + 1);
      }
      else
      {
        requests.vtable = 0;
      }
      result = (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > *)1;
      vostok::logging::append(
        &requests,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\object_wire.cpp",
        0x68u,
        "void __thiscall survarium::object_wire::load(const class vostok::configs::binary_config_value &,const char *,cla"
        "ss boost::function<void __cdecl(class survarium::game_object_ &)> &)",
        "game:",
        warning,
        "empty wire");
    }
    if ( ((unsigned __int8)result & 1) != 0 )
    {
      if ( requests.vtable )
      {
        if ( ((int)requests.vtable & 1) == 0 )
        {
          v19 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)requests.vtable & 0xFFFFFFFE);
          if ( v19 )
            v19(&requests.functor, &requests.functor, 2);
        }
      }
    }
    if ( !cb->vtable )
    {
      boost::bad_function_call::bad_function_call(&v33);
      boost::throw_exception(v20);
      stlp_std::__Named_exception::~__Named_exception((stlp_std::out_of_range *)&v33);
    }
    (*(void (__cdecl **)(boost::detail::function::function_buffer *, survarium::object_wire *))(((int)cb->vtable
                                                                                               & 0xFFFFFFFE)
                                                                                              + 4))(
      &cb->functor,
      this);
  }
  writer.__vftable = (vostok::memory::writer_vtbl *)&vostok::memory::writer::`vftable';
  memset(&writer.m_position, 0, 12);
  if ( !writer.external_data && writer.m_data )
  {
    writer.m_allocator->call_free(writer.m_allocator, writer.m_data);
    writer.m_data = 0;
  }
  writer.__vftable = (vostok::memory::writer_vtbl *)&vostok::memory::writer_base::`vftable';
  if ( writer.m_chunk_pos._M_impl._M_start )
    writer.m_chunk_pos._M_impl._M_end_of_storage.m_allocator->call_free(
      writer.m_chunk_pos._M_impl._M_end_of_storage.m_allocator,
      writer.m_chunk_pos._M_impl._M_start);
}
