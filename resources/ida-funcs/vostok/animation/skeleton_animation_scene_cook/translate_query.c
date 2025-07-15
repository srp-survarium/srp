void __thiscall vostok::animation::skeleton_animation_scene_cook::translate_query(
        vostok::animation::skeleton_animation_scene_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  const char *requested_path; // eax
  vostok::buffer_string *v4; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  int v6[2]; // [esp+8h] [ebp-148h] BYREF
  __int64 v7; // [esp+10h] [ebp-140h]
  unsigned __int64 v8; // [esp+18h] [ebp-138h]
  __int64 v9; // [esp+28h] [ebp-128h]
  unsigned __int64 v10; // [esp+30h] [ebp-120h]
  const char *v11[3]; // [esp+38h] [ebp-118h] BYREF
  _BYTE v12[260]; // [esp+44h] [ebp-10Ch] BYREF
  char v13; // [esp+148h] [ebp-8h] BYREF

  v11[0] = v12;
  v11[1] = v12;
  v11[2] = &v13;
  v12[0] = 0;
  v13 = 47;
  requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::fs_new::path_string_impl::assignf(v11, v4, (vostok::buffer_string *)"%s.avs", requested_path);
  LODWORD(v7) = this;
  v6[0] = (int)vostok::animation::skeleton_animation_scene_cook::on_scene_config_loaded;
  v6[1] = 0;
  LODWORD(v9) = vostok::animation::skeleton_animation_scene_cook::on_scene_config_loaded;
  HIDWORD(v9) = 0;
  v10 = __PAIR64__(HIDWORD(v7), (unsigned int)this);
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    v6[0] = 0;
  }
  else
  {
    v7 = v9;
    v8 = v10;
    v6[0] = (int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::animation::skeleton_animation_scene_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::animation::skeleton_animation_scene_cook *>,boost::arg<1>>>>'::`2'::stored_vtable
          + 1;
  }
  vostok::resources::query_resource(
    v11[0],
    (vostok::variant<32> *)0x20,
    &vostok::memory::g_resources_helper_allocator,
    0,
    (const vostok::variant<32> **)parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v5, v6);
}
