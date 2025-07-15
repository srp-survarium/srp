void __thiscall vostok::sound::sound_collection_cook::translate_query(
        vostok::sound::sound_collection_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  const char *requested_path; // eax
  vostok::buffer_string *v4; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_collection_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_collection_cook *>,boost::arg<1> > > v6; // [esp-14h] [ebp-15Ch]
  boost::function<void __cdecl(vostok::resources::queries_result &)> f; // [esp+10h] [ebp-138h] BYREF
  char *request_path[3]; // [esp+30h] [ebp-118h] BYREF
  _BYTE v9[260]; // [esp+3Ch] [ebp-10Ch] BYREF
  char v10; // [esp+140h] [ebp-8h] BYREF

  if ( !parent->m_user_data )
  {
    request_path[0] = v9;
    request_path[1] = v9;
    request_path[2] = &v10;
    v9[0] = 0;
    v10 = 47;
    requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
    vostok::fs_new::path_string_impl::assignf(
      (int)request_path,
      v4,
      (vostok::buffer_string *)&stru_7FF1F0,
      "resources/sounds/collections/",
      requested_path,
      ".sound_collection");
    f.functor.obj_ptr = this;
    f.vtable = (boost::detail::function::vtable_base *)vostok::sound::sound_collection_cook::collection_config_loaded;
    (&f.vtable)[1] = 0;
    HIDWORD(v6.f_.f_) = vostok::sound::sound_collection_cook::collection_config_loaded;
    v6.l_.a1_.t_ = 0;
    *((_DWORD *)&v6.l_ + 1) = this;
    LODWORD(v6.f_.f_) = &f;
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      0,
      v6,
      (int)f.functor.vostok_pointer_size_alignment[1]);
    vostok::resources::query_resource(
      request_path[0],
      &f,
      (vostok::variant<32> *)0x20,
      &vostok::memory::g_resources_unmanaged_allocator,
      0,
      parent,
      assert_on_fail_true);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v5,
      (int *)&f);
  }
}
