void __thiscall vostok::animation::single_animation_cook::translate_query(
        vostok::animation::single_animation_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  const char *requested_path; // eax
  vostok::buffer_string *v4; // ecx
  const char *v5; // eax
  vostok::buffer_string *v6; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  vostok::resources::request v8; // [esp+8h] [ebp-260h] BYREF
  int v9; // [esp+10h] [ebp-258h]
  int v10; // [esp+14h] [ebp-254h]
  int v11[2]; // [esp+18h] [ebp-250h] BYREF
  vostok::animation::single_animation_cook *v12; // [esp+20h] [ebp-248h]
  int v13; // [esp+24h] [ebp-244h]
  vostok::animation::single_animation_cook *v14; // [esp+28h] [ebp-240h]
  int v15; // [esp+2Ch] [ebp-23Ch]
  void (__thiscall *v16)(vostok::animation::single_animation_cook *, vostok::resources::queries_result *); // [esp+38h] [ebp-230h]
  int v17; // [esp+3Ch] [ebp-22Ch]
  vostok::animation::single_animation_cook *v18; // [esp+40h] [ebp-228h]
  int v19; // [esp+44h] [ebp-224h]
  _DWORD v20[3]; // [esp+48h] [ebp-220h] BYREF
  _BYTE v21[260]; // [esp+54h] [ebp-214h] BYREF
  _DWORD v22[3]; // [esp+158h] [ebp-110h] BYREF
  _BYTE v23[260]; // [esp+164h] [ebp-104h] BYREF
  char vars0; // [esp+268h] [ebp+0h] BYREF

  v20[0] = v21;
  v20[1] = v21;
  v20[2] = v22;
  v21[0] = 0;
  requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::fs_new::path_string_impl::assignf(
    v20,
    v4,
    (vostok::buffer_string *)"resources/animations/single/%s",
    requested_path);
  v22[0] = v23;
  v22[1] = v23;
  v22[2] = &vars0;
  v23[0] = 0;
  v5 = vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::fs_new::path_string_impl::assignf(
    v22,
    v6,
    (vostok::buffer_string *)"resources/animations/single/%s%s",
    v5,
    ".options");
  v8.path = (const char *)v20[0];
  v12 = this;
  v9 = v22[0];
  v11[0] = (int)vostok::animation::single_animation_cook::on_sub_resources_loaded;
  v11[1] = 0;
  v16 = vostok::animation::single_animation_cook::on_sub_resources_loaded;
  v17 = 0;
  v18 = this;
  v8.id = animation_class;
  v10 = 32;
  v19 = v13;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    v11[0] = 0;
  }
  else
  {
    v12 = (vostok::animation::single_animation_cook *)v16;
    v13 = v17;
    v14 = v18;
    v15 = v19;
    v11[0] = (int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::animation::single_animation_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::animation::single_animation_cook *>,boost::arg<1>>>>'::`2'::stored_vtable
           + 1;
  }
  vostok::resources::query_resources(
    &v8,
    2u,
    &vostok::memory::g_resources_unmanaged_allocator,
    0,
    (const vostok::variant<32> **)parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v7, v11);
}
