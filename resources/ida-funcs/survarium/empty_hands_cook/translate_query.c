void __thiscall survarium::empty_hands_cook::translate_query(
        survarium::empty_hands_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  const char *requested_path; // eax
  vostok::buffer_string *v4; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::empty_hands_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::empty_hands_cook *>,boost::arg<1> > > v6; // [esp-14h] [ebp-154h]
  int f[8]; // [esp+8h] [ebp-138h] BYREF
  const char *v8[3]; // [esp+28h] [ebp-118h] BYREF
  _BYTE v9[260]; // [esp+34h] [ebp-10Ch] BYREF
  char v10; // [esp+138h] [ebp-8h] BYREF

  v8[0] = v9;
  v8[1] = v9;
  v8[2] = &v10;
  v9[0] = 0;
  v10 = 47;
  requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::fs_new::path_string_impl::assignf(v8, v4, (vostok::buffer_string *)"resources/%s", requested_path);
  f[2] = (int)this;
  f[1] = 0;
  f[0] = (int)survarium::empty_hands_cook::on_empty_hands_config_loaded;
  HIDWORD(v6.f_.f_) = survarium::empty_hands_cook::on_empty_hands_config_loaded;
  v6.l_.a1_.t_ = 0;
  *((_DWORD *)&v6.l_ + 1) = this;
  LODWORD(v6.f_.f_) = f;
  boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
    0,
    v6,
    f[3]);
  vostok::resources::query_resource(
    v8[0],
    (vostok::variant<32> *)0x20,
    survarium::g_allocator,
    0,
    (const vostok::variant<32> **)parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v5, f);
}
