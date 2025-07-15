void __thiscall vostok::sound::encoded_sound_with_qualities::increase_quality_to_target(
        vostok::sound::encoded_sound_with_qualities *this,
        vostok::variant<32> **parent_query)
{
  int v3; // edx
  char *v4; // eax
  vostok::fixed_string<260> *p_m_req_path; // edi
  char *requested_path; // eax
  char *m_begin; // ecx
  vostok::buffer_string *v8; // ecx
  char *m_end; // esi
  _DWORD *v10; // eax
  char v11; // dl
  unsigned int j; // esi
  const char *v13; // eax
  vostok::resources::class_id_enum m_sound_interface_type; // eax
  vostok::resources::resource_quality *m_parent_query; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v16; // ecx
  vostok::resources::resources_manager *v17; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v18; // ecx
  const bool *v19; // [esp+0h] [ebp-1E8h]
  const unsigned int *v20; // [esp+4h] [ebp-1E4h]
  const char *v21; // [esp+8h] [ebp-1E0h]
  unsigned int v22; // [esp+Ch] [ebp-1DCh]
  char *query_type; // [esp+10h] [ebp-1D8h]
  float query_typea; // [esp+10h] [ebp-1D8h]
  unsigned int *i; // [esp+14h] [ebp-1D4h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+18h] [ebp-1D0h] BYREF
  float target_satisfactions[2]; // [esp+38h] [ebp-1B0h] BYREF
  _DWORD v28[2]; // [esp+40h] [ebp-1A8h] BYREF
  __int64 v29; // [esp+48h] [ebp-1A0h]
  unsigned __int64 v30; // [esp+50h] [ebp-198h]
  vostok::resources::request requests[2]; // [esp+58h] [ebp-190h] BYREF
  vostok::resources::query_resource_params params; // [esp+68h] [ebp-180h] BYREF
  _DWORD v33[3]; // [esp+D0h] [ebp-118h] BYREF
  char v34; // [esp+DCh] [ebp-10Ch] BYREF
  char v35[140]; // [esp+15Ch] [ebp-8Ch] BYREF

  this->m_parent_query = (vostok::resources::query_result_for_cook *)parent_query;
  v3 = 1;
  v4 = &v34;
  do
  {
    *((_DWORD *)v4 - 3) = v4;
    *((_DWORD *)v4 - 2) = v4;
    *((_DWORD *)v4 - 1) = v4 + 128;
    *v4 = 0;
    *v4 = 0;
    v4 += 140;
    --v3;
  }
  while ( v3 >= 0 );
  p_m_req_path = &this->m_req_path;
  if ( this->m_req_path.m_begin == this->m_req_path.m_end )
  {
    requested_path = (char *)vostok::resources::query_result_for_user::get_requested_path((vostok::resources::query_result_for_user *)parent_query);
    m_begin = p_m_req_path->m_begin;
    if ( p_m_req_path->m_begin != requested_path )
    {
      this->m_req_path.m_end = m_begin;
      *m_begin = 0;
      vostok::buffer_string::operator+=(&this->m_req_path, requested_path);
    }
  }
  if ( this->m_sound_interface_type == unknown_data_class )
    this->m_sound_interface_type = encoded_sound_class;
  for ( i = 0; (unsigned int)i < 2; i = (unsigned int *)((char *)i + 1) )
  {
    v8 = (vostok::buffer_string *)p_m_req_path->m_begin;
    m_end = this->m_req_path.m_end;
    v10 = &v33[35 * (_DWORD)i];
    for ( query_type = p_m_req_path->m_begin; query_type != m_end; ++v10[1] )
    {
      v8 = (vostok::buffer_string *)v10[1];
      v11 = *query_type++;
      LOBYTE(v8->m_begin) = v11;
    }
    *(_BYTE *)v10[1] = 0;
    if ( this->m_sound_interface_type == encoded_sound_class )
    {
      if ( i )
        vostok::buffer_string::append(v8, (int)v35, ".medium");
      else
        vostok::buffer_string::append(v8, (int)v33, ".high");
    }
  }
  for ( j = 0; j < 2; ++j )
  {
    v13 = (const char *)v33[35 * j];
    v28[j] = j;
    requests[j].path = v13;
    if ( j )
      m_sound_interface_type = unknown_data_class;
    else
      m_sound_interface_type = this->m_sound_interface_type;
    m_parent_query = this->m_parent_query;
    requests[j].id = m_sound_interface_type;
    if ( !m_parent_query )
      m_parent_query = this;
    query_typea = vostok::resources::resource_quality::satisfaction(m_parent_query, j, 0, 0);
    target_satisfactions[j] = query_typea;
  }
  callback.vtable = (boost::detail::function::vtable_base *)vostok::sound::encoded_sound_with_qualities::on_quality_loaded;
  (&callback.vtable)[1] = 0;
  callback.functor.obj_ptr = this;
  LODWORD(v29) = vostok::sound::encoded_sound_with_qualities::on_quality_loaded;
  HIDWORD(v29) = 0;
  v30 = __PAIR64__((unsigned int)callback.functor.vostok_pointer_size_alignment[1], (unsigned int)this);
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    callback.vtable = 0;
  }
  else
  {
    *(_QWORD *)&callback.functor.obj_ptr = v29;
    *((_QWORD *)&callback.functor.data + 1) = v30;
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::encoded_sound_with_qualities,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::encoded_sound_with_qualities *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                             + 1);
  }
  vostok::resources::query_resource_params::query_resource_params(
    &params,
    requests,
    (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&callback,
    0,
    2u,
    &vostok::memory::g_resources_unmanaged_allocator,
    target_satisfactions,
    0,
    (const vostok::variant<32> **)parent_query,
    (vostok::resources::query_result_for_cook *)v28,
    v19,
    v20,
    v21,
    v22,
    SLODWORD(query_typea),
    i,
    (vostok::resources::autoselect_quality_bool *)callback.vtable,
    (assert_on_fail_bool)(&callback.vtable)[1]);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v16,
    (int *)&callback);
  this->m_increasing_quality = 1;
  vostok::resources::resources_manager::query_resources_impl(v17, &params);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v18,
    (int *)&params.callback);
}
