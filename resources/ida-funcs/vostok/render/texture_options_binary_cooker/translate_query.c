void __thiscall vostok::render::texture_options_binary_cooker::translate_query(
        vostok::render::texture_options_binary_cooker *this,
        vostok::resources::query_result_for_cook *parent)
{
  const char *requested_path; // edi
  vostok::render::texture_options_binary_cooker *v3; // edx
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v4; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::texture_options_binary_cooker,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::render::texture_options_binary_cooker *>,boost::arg<1> > > v6; // [esp-8h] [ebp-30h]
  int v7; // [esp+0h] [ebp-28h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::texture_options_binary_cooker,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::render::texture_options_binary_cooker *>,boost::arg<1> > > v8[4]; // [esp+8h] [ebp-20h] BYREF

  requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
  v6.l_.a1_.t_ = v3;
  v6.f_.f_ = vostok::render::texture_options_binary_cooker::on_binary_config_loaded;
  boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
    v4,
    v8,
    v6,
    v7);
  vostok::resources::query_resource(
    requested_path,
    (vostok::variant<32> *)0x20,
    &vostok::memory::g_resources_unmanaged_allocator,
    0,
    (const vostok::variant<32> **)parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v5, (int *)v8);
}
