void __thiscall vostok::sound::ogg_encoded_sound_interface_cook::query_converted_resources(
        vostok::sound::ogg_encoded_sound_interface_cook *this,
        __int64 parent)
{
  const char *requested_path; // eax
  vostok::buffer_string *v3; // ecx
  const char *v4; // eax
  vostok::buffer_string *v5; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+10h] [ebp-270h] BYREF
  vostok::resources::request requests; // [esp+30h] [ebp-250h] BYREF
  int v9; // [esp+38h] [ebp-248h]
  int v10; // [esp+3Ch] [ebp-244h]
  __int64 v11; // [esp+40h] [ebp-240h]
  __int64 v12; // [esp+48h] [ebp-238h]
  _DWORD v13[3]; // [esp+50h] [ebp-230h] BYREF
  _BYTE v14[260]; // [esp+5Ch] [ebp-224h] BYREF
  char v15; // [esp+160h] [ebp-120h] BYREF
  _DWORD v16[3]; // [esp+168h] [ebp-118h] BYREF
  _BYTE v17[260]; // [esp+174h] [ebp-10Ch] BYREF
  char v18; // [esp+278h] [ebp-8h] BYREF

  v13[0] = v14;
  v13[1] = v14;
  v13[2] = &v15;
  v14[0] = 0;
  v15 = 47;
  requested_path = vostok::resources::query_result_for_user::get_requested_path((vostok::resources::query_result_for_user *)HIDWORD(parent));
  vostok::fs_new::path_string_impl::assignf(
    (int)v13,
    v3,
    (vostok::buffer_string *)&stru_7FF1F0,
    "resources/sounds/single/",
    requested_path,
    ".ogg");
  v16[0] = v17;
  v16[1] = v17;
  v16[2] = &v18;
  v17[0] = 0;
  v18 = 47;
  v4 = vostok::resources::query_result_for_user::get_requested_path((vostok::resources::query_result_for_user *)HIDWORD(parent));
  vostok::fs_new::path_string_impl::assignf(
    (int)v16,
    v5,
    (vostok::buffer_string *)&stru_7FF1F0,
    "resources/sounds/single/",
    v4,
    ".rms");
  requests.path = (const char *)v13[0];
  requests.id = raw_data_class;
  v10 = 3;
  callback.vtable = (boost::detail::function::vtable_base *)vostok::sound::ogg_encoded_sound_interface_cook::on_ogg_resources_loaded;
  *(_QWORD *)&callback.functor.obj_ptr = parent;
  v9 = v16[0];
  (&callback.vtable)[1] = 0;
  LODWORD(v11) = vostok::sound::ogg_encoded_sound_interface_cook::on_ogg_resources_loaded;
  HIDWORD(v11) = 0;
  v12 = parent;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    callback.vtable = 0;
  }
  else
  {
    *(_QWORD *)&callback.functor.obj_ptr = v11;
    *((_QWORD *)&callback.functor.data + 1) = v12;
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::ogg_encoded_sound_interface_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *>,boost::_bi::list3<boost::_bi::value<vostok::sound::ogg_encoded_sound_interface_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>>>>'::`2'::stored_vtable
                                                             + 1);
  }
  vostok::resources::query_resources(
    &requests,
    2u,
    &vostok::memory::g_mt_allocator,
    0,
    (const vostok::variant<32> **)HIDWORD(parent),
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v6,
    (int *)&callback);
}
