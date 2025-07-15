void __thiscall survarium::weapon_ammunition_cook::translate_query(
        survarium::weapon_ammunition_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  const char *requested_path; // eax
  vostok::buffer_string *v4; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  int v6[2]; // [esp+10h] [ebp-148h] BYREF
  survarium::weapon_ammunition_cook *v7; // [esp+18h] [ebp-140h]
  vostok::resources::query_result_for_cook *v8; // [esp+1Ch] [ebp-13Ch]
  unsigned __int64 v9; // [esp+20h] [ebp-138h]
  void (__thiscall *v10)(survarium::weapon_ammunition_cook *, vostok::resources::queries_result *, vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *); // [esp+30h] [ebp-128h]
  vostok::resources::query_result_for_cook *v11; // [esp+34h] [ebp-124h]
  unsigned __int64 v12; // [esp+38h] [ebp-120h]
  const char *v13[3]; // [esp+40h] [ebp-118h] BYREF
  _BYTE v14[260]; // [esp+4Ch] [ebp-10Ch] BYREF
  char v15; // [esp+150h] [ebp-8h] BYREF

  v13[0] = v14;
  v13[1] = v14;
  v13[2] = &v15;
  v14[0] = 0;
  v15 = 47;
  requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::fs_new::path_string_impl::assignf(v13, v4, (vostok::buffer_string *)"resources/%s", requested_path);
  v7 = this;
  v6[0] = (int)survarium::weapon_ammunition_cook::on_config_ready;
  v6[1] = 0;
  v8 = parent;
  v10 = survarium::weapon_ammunition_cook::on_config_ready;
  v11 = 0;
  v12 = __PAIR64__((unsigned int)parent, (unsigned int)this);
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    v6[0] = 0;
  }
  else
  {
    v7 = (survarium::weapon_ammunition_cook *)v10;
    v8 = v11;
    v9 = v12;
    v6[0] = (int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::weapon_ammunition_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *>,boost::_bi::list3<boost::_bi::value<survarium::weapon_ammunition_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>>>>'::`2'::stored_vtable
          + 1;
  }
  vostok::resources::query_resource(
    v13[0],
    (vostok::variant<32> *)0x20,
    survarium::g_allocator,
    0,
    (const vostok::variant<32> **)parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v5, v6);
}
