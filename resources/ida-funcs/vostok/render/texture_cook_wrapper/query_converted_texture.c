void __thiscall vostok::render::texture_cook_wrapper::query_converted_texture(
        vostok::render::texture_cook_wrapper *this,
        vostok::resources::query_result_for_cook *parent,
        vostok::resources::query_result_for_cook *a3)
{
  char *requested_path; // eax
  vostok::fixed_string<260> *v4; // ecx
  vostok::particle::particle_action *v5; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  int v7[8]; // [esp+10h] [ebp-138h] BYREF
  vostok::fs_new::virtual_path_string in_out_result; // [esp+30h] [ebp-118h] BYREF

  requested_path = (char *)vostok::resources::query_result_for_user::get_requested_path(a3);
  vostok::fixed_string<260>::fixed_string<260>(v4, &in_out_result.m_string, requested_path);
  in_out_result.m_separator = 47;
  vostok::fs_new::set_extension_for_path<vostok::fs_new::virtual_path_string>(&in_out_result);
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(v5) )
  {
    v7[0] = 0;
  }
  else
  {
    v7[2] = (int)vostok::render::texture_cook_wrapper::on_texture_loaded;
    v7[3] = (int)parent;
    v7[0] = (int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::texture_cook_wrapper,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::render::texture_cook_wrapper *>,boost::arg<1>>>>'::`2'::stored_vtable
          + 1;
  }
  vostok::resources::query_resource(
    in_out_result.m_string.m_begin,
    (vostok::variant<32> *)8,
    &vostok::memory::g_mt_allocator,
    0,
    (const vostok::variant<32> **)a3,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v6, v7);
}
