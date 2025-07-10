void __thiscall vostok::sound::encoded_sound_with_qualities::increase_quality_to_target(
        vostok::sound::encoded_sound_with_qualities *this,
        vostok::resources::query_result_for_cook *parent_query)
{
  vostok::memory::base_allocator *v2; // eax
  float v3; // [esp+0h] [ebp-270h]
  vostok::resources::class_id_enum m_sound_interface_type; // [esp+4h] [ebp-26Ch]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v6; // [esp+18h] [ebp-258h]
  char *s; // [esp+54h] [ebp-21Ch]
  int v8; // [esp+68h] [ebp-208h]
  vostok::fixed_string<128> *j; // [esp+6Ch] [ebp-204h]
  unsigned int max_count; // [esp+74h] [ebp-1FCh] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+78h] [ebp-1F8h] BYREF
  void (__thiscall *f)(vostok::sound::encoded_sound_with_qualities *, vostok::resources::queries_result *); // [esp+88h] [ebp-1E8h]
  int f_4; // [esp+8Ch] [ebp-1E4h]
  boost::function1<void,vostok::resources::queries_result &> v14; // [esp+90h] [ebp-1E0h] BYREF
  char *begin_src; // [esp+B4h] [ebp-1BCh] BYREF
  char *end_src; // [esp+B8h] [ebp-1B8h] BYREF
  unsigned int quality_level; // [esp+BCh] [ebp-1B4h]
  unsigned int i; // [esp+C0h] [ebp-1B0h]
  unsigned int requests_count; // [esp+C4h] [ebp-1ACh]
  vostok::resources::request all_requests[2]; // [esp+C8h] [ebp-1A8h] BYREF
  float satisfactions[2]; // [esp+D8h] [ebp-198h] BYREF
  vostok::fixed_string<128> names[2]; // [esp+E0h] [ebp-190h] BYREF
  unsigned int quality_indexes[2]; // [esp+1F8h] [ebp-78h] BYREF
  vostok::resources::query_resource_params params; // [esp+200h] [ebp-70h] BYREF
  vostok::resources::request *requests; // [esp+26Ch] [ebp-4h]

  this->m_parent_query = parent_query;
  v8 = 2;
  for ( j = names; --v8 >= 0; ++j )
  {
    max_count = 128;
    vostok::buffer_string::buffer_string(j, j->m_buffer, &max_count);
    j->m_buffer[0] = 0;
  }
  if ( this->m_req_path.m_begin == this->m_req_path.m_end )
  {
    s = (char *)vostok::resources::query_result_for_user::get_requested_path(parent_query);
    if ( this->m_req_path.m_begin != s )
    {
      this->m_req_path.m_end = this->m_req_path.m_begin;
      *this->m_req_path.m_end = 0;
      vostok::buffer_string::operator+=(&this->m_req_path, s);
    }
  }
  if ( this->m_sound_interface_type == unknown_data_class )
    this->m_sound_interface_type = ogg_encoded_sound_interface_class;
  for ( i = 0; i < 2; ++i )
  {
    end_src = this->m_req_path.m_end;
    begin_src = this->m_req_path.m_begin;
    vostok::buffer_string::append<char *>(&names[i], &begin_src, &end_src);
    if ( this->m_sound_interface_type == ogg_encoded_sound_interface_class )
    {
      switch ( i )
      {
        case 0u:
          goto LABEL_16;
        case 1u:
          vostok::buffer_string::append(&names[1], ".medium");
          break;
        case 2u:
          vostok::buffer_string::append((vostok::buffer_string *)quality_indexes, ".low");
          break;
        default:
LABEL_16:
          vostok::buffer_string::append(&names[i], ".high");
          continue;
      }
    }
  }
  for ( quality_level = 0; quality_level < 2; ++quality_level )
  {
    quality_indexes[quality_level] = quality_level;
    all_requests[quality_level].path = names[quality_level].m_begin;
    if ( quality_level )
      m_sound_interface_type = unknown_data_class;
    else
      m_sound_interface_type = this->m_sound_interface_type;
    all_requests[quality_level].id = m_sound_interface_type;
    if ( this->m_parent_query )
      v3 = vostok::resources::resource_quality::satisfaction(this->m_parent_query, quality_level, 0, 0);
    else
      v3 = vostok::resources::resource_quality::satisfaction(this, quality_level, 0, 0);
    satisfactions[quality_level] = v3;
  }
  requests = all_requests;
  requests_count = 2;
  f = vostok::sound::encoded_sound_with_qualities::on_quality_loaded;
  f_4 = 0;
  v6 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
          (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result,
          (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)vostok::sound::encoded_sound_with_qualities::on_quality_loaded,
          (survarium::weapon_core_animation_end_aware_state *)this);
  v14.vtable = 0;
  boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::encoded_sound_with_qualities,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::encoded_sound_with_qualities *>,boost::arg<1>>>>(
    &v14,
    (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::encoded_sound_with_qualities,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::encoded_sound_with_qualities *>,boost::arg<1> > >)v6);
  v2 = vostok::resources::unmanaged_allocator();
  vostok::resources::query_resource_params::query_resource_params(
    &params,
    requests,
    0,
    2u,
    (const boost::function<void __cdecl(vostok::resources::queries_result &)> *)&v14,
    v2,
    satisfactions,
    0,
    0,
    parent_query,
    0,
    quality_indexes,
    0,
    0,
    query_type_normal,
    0,
    0,
    assert_on_fail_true);
  if ( v14.vtable )
  {
    if ( ((int)v14.vtable & 1) == 0 )
      boost::detail::function::basic_vtable9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::clear(
        (boost::detail::function::basic_vtable9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)((int)v14.vtable & 0xFFFFFFFE),
        &v14.functor);
    v14.vtable = 0;
  }
  this->m_increasing_quality = 1;
  vostok::resources::query_resources(&params);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&params.callback);
}
