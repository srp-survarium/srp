void __thiscall survarium::animated_model_instance_cook::translate_query(
        survarium::animated_model_instance_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  const char *requested_path; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::animated_model_instance_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::animated_model_instance_cook *>,boost::arg<1> > > v4; // [esp-8h] [ebp-30h]
  int v5; // [esp+0h] [ebp-28h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::animated_model_instance_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::animated_model_instance_cook *>,boost::arg<1> > > v6[4]; // [esp+8h] [ebp-20h] BYREF

  v4.l_.a1_.t_ = this;
  v4.f_.f_ = survarium::animated_model_instance_cook::on_config_loaded;
  boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
    (boost::function<void __cdecl(vostok::resources::queries_result &)> *)this,
    v6,
    v4,
    v5);
  requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::resources::query_resource(
    requested_path,
    (vostok::variant<32> *)0x20,
    &vostok::memory::g_resources_unmanaged_allocator,
    0,
    (const vostok::variant<32> **)parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v3, (int *)v6);
}
