void __thiscall vostok::sound::composite_sound_cook::translate_query(
        vostok::sound::composite_sound_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  const char *requested_path; // eax
  vostok::buffer_string *v4; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+8h] [ebp-148h] BYREF
  __int64 v7; // [esp+28h] [ebp-128h]
  unsigned __int64 v8; // [esp+30h] [ebp-120h]
  char *request_path[3]; // [esp+38h] [ebp-118h] BYREF
  _BYTE v10[260]; // [esp+44h] [ebp-10Ch] BYREF
  char v11; // [esp+148h] [ebp-8h] BYREF

  request_path[0] = v10;
  request_path[1] = v10;
  request_path[2] = &v11;
  v10[0] = 0;
  v11 = 47;
  requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::fs_new::path_string_impl::assignf(
    (int)request_path,
    v4,
    (vostok::buffer_string *)&stru_7FF1F0,
    "resources/sounds/composite/",
    requested_path,
    ".composite_sound");
  callback.functor.obj_ptr = this;
  callback.vtable = (boost::detail::function::vtable_base *)vostok::sound::composite_sound_cook::on_sub_resources_loaded;
  (&callback.vtable)[1] = 0;
  LODWORD(v7) = vostok::sound::composite_sound_cook::on_sub_resources_loaded;
  HIDWORD(v7) = 0;
  v8 = __PAIR64__((unsigned int)callback.functor.vostok_pointer_size_alignment[1], (unsigned int)this);
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    callback.vtable = 0;
  }
  else
  {
    *(_QWORD *)&callback.functor.obj_ptr = v7;
    *((_QWORD *)&callback.functor.data + 1) = v8;
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::composite_sound_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::composite_sound_cook *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                             + 1);
  }
  vostok::resources::query_resource(
    request_path[0],
    &callback,
    (vostok::variant<32> *)0x20,
    &vostok::memory::g_resources_unmanaged_allocator,
    0,
    parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v5,
    (int *)&callback);
}
