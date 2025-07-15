void __thiscall vostok::collision::collision_cook::query_triangle_mesh(
        vostok::collision::collision_cook *this,
        vostok::resources::query_result_for_cook *parent_query,
        vostok::resources::query_result_for_cook *a3)
{
  char *requested_path; // eax
  vostok::buffer_string *v4; // ecx
  vostok::buffer_string *v5; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  vostok::resources::request requests; // [esp+1Ch] [ebp-26Ch] BYREF
  char *m_begin; // [esp+24h] [ebp-264h]
  int v9; // [esp+28h] [ebp-260h]
  __int64 v10; // [esp+2Ch] [ebp-25Ch]
  vostok::resources::query_result_for_cook *v11; // [esp+34h] [ebp-254h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+38h] [ebp-250h] BYREF
  vostok::fixed_string<260> v13; // [esp+58h] [ebp-230h] BYREF
  char v14; // [esp+168h] [ebp-120h] BYREF
  vostok::fixed_string<260> v15; // [esp+170h] [ebp-118h] BYREF
  char v16; // [esp+280h] [ebp-8h]

  v13.m_begin = v13.m_buffer;
  v13.m_end = v13.m_buffer;
  v13.m_max_end = &v14;
  v13.m_buffer[0] = 0;
  v14 = 47;
  requested_path = (char *)vostok::resources::query_result_for_user::get_requested_path(a3);
  if ( v13.m_buffer != requested_path )
  {
    v13.m_end = v13.m_buffer;
    v13.m_buffer[0] = 0;
    vostok::buffer_string::operator+=(&v13, requested_path);
  }
  vostok::fixed_string<260>::fixed_string<260>(&v15, &v13);
  v16 = 47;
  vostok::buffer_string::append(v4, (int)&v13, "/vertices");
  vostok::buffer_string::append(v5, (int)&v15, "/indices");
  requests.path = v13.m_begin;
  requests.id = raw_data_class;
  v9 = 3;
  LODWORD(v10) = vostok::collision::collision_cook::on_triangle_mesh_collision_loaded;
  HIDWORD(v10) = parent_query;
  m_begin = v15.m_begin;
  v11 = a3;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus((vostok::particle::particle_action *)v15.m_begin) )
  {
    callback.vtable = 0;
  }
  else
  {
    *(_QWORD *)&callback.functor.obj_ptr = v10;
    callback.functor.vostok_pointer_size_alignment[2] = v11;
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::collision::collision_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *>,boost::_bi::list3<boost::_bi::value<vostok::collision::collision_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>>>>'::`2'::stored_vtable
                                                             + 1);
  }
  vostok::resources::query_resources(
    &requests,
    2u,
    &vostok::memory::g_resources_unmanaged_allocator,
    0,
    (const vostok::variant<32> **)a3,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v6,
    (int *)&callback);
}
