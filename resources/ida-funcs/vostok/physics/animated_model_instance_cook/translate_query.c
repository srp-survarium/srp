void __thiscall vostok::physics::animated_model_instance_cook::translate_query(
        vostok::physics::animated_model_instance_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  const char *requested_path; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  vostok::memory::base_allocator *m_allocator; // [esp-10h] [ebp-38h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::physics::animated_model_instance_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::physics::animated_model_instance_cook *>,boost::arg<1> > > v6; // [esp-8h] [ebp-30h]
  int v7; // [esp+0h] [ebp-28h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+8h] [ebp-20h] BYREF

  v6.l_.a1_.t_ = this;
  v6.f_.f_ = vostok::physics::animated_model_instance_cook::on_config_loaded;
  boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
    (boost::function<void __cdecl(vostok::resources::queries_result &)> *)this,
    (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::physics::animated_model_instance_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::physics::animated_model_instance_cook *>,boost::arg<1> > > *)&callback,
    v6,
    v7);
  m_allocator = this->m_allocator;
  requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::resources::query_resource(
    requested_path,
    &callback,
    (vostok::variant<32> *)0x20,
    m_allocator,
    0,
    parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v4,
    (int *)&callback);
}
