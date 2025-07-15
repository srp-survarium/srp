void __thiscall vostok::animation::skeleton_animation_cook::translate_query(
        vostok::animation::skeleton_animation_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  const char *requested_path; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::resources::queries_result &),boost::_bi::list1<boost::arg<1> > > v4; // [esp-8h] [ebp-38h]
  int v5; // [esp+0h] [ebp-30h]
  int v6; // [esp+Ch] [ebp-24h]
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::resources::queries_result &),boost::_bi::list1<boost::arg<1> > > v7[4]; // [esp+10h] [ebp-20h] BYREF

  *(_DWORD *)&v4.l_.boost::_bi::storage1<boost::arg<1> > = v6;
  v4.f_ = vostok::animation::skeleton_animation_cook::on_bi_spline_animation_arrived;
  boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
    (boost::function<void __cdecl(vostok::resources::queries_result &)> *)this,
    v7,
    v4,
    v5);
  requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::resources::query_resource(
    requested_path,
    (vostok::variant<32> *)0x30,
    &vostok::memory::g_resources_helper_allocator,
    0,
    (const vostok::variant<32> **)parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v3, (int *)v7);
}
