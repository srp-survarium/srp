void __thiscall vostok::render::render_texture_cook::translate_query(
        vostok::render::render_texture_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  unsigned int num_last_mips_used; // edi
  vostok::resources::query_result_for_cook *requested_path; // eax
  vostok::render::resource_manager *v5; // ecx
  const char *v6; // eax
  vostok::buffer_string *v7; // ecx
  vostok::particle::particle_action *v8; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  unsigned int mip_level_cut; // [esp-20h] [ebp-170h]
  bool use_pool; // [esp-1Ch] [ebp-16Ch]
  bool load_async; // [esp-18h] [ebp-168h]
  bool use_converter; // [esp-14h] [ebp-164h]
  unsigned int v14; // [esp-10h] [ebp-160h]
  bool streamed; // [esp-8h] [ebp-158h]
  char force_query; // [esp-4h] [ebp-154h]
  vostok::render::render_texture_cook_parameters out_value; // [esp+Ch] [ebp-144h] BYREF
  vostok::render::res_texture *texture; // [esp+1Ch] [ebp-134h]
  int v19[2]; // [esp+20h] [ebp-130h] BYREF
  vostok::render::render_texture_cook_parameters v20; // [esp+28h] [ebp-128h]
  const char *v21[3]; // [esp+40h] [ebp-110h] BYREF
  _BYTE v22[260]; // [esp+4Ch] [ebp-104h] BYREF
  char vars0; // [esp+150h] [ebp+0h] BYREF

  vostok::variant<32>::try_get<vostok::render::render_texture_cook_parameters>(
    (vostok::variant<32> *)this,
    (int)parent->m_user_data->m_helper_storage,
    &out_value);
  force_query = out_value.force_query;
  num_last_mips_used = out_value.num_last_mips_used;
  streamed = out_value.streamed;
  v14 = out_value.num_last_mips_used;
  use_converter = out_value.use_converter;
  load_async = out_value.load_async;
  use_pool = out_value.use_pool;
  mip_level_cut = out_value.mip_level_cut;
  requested_path = (vostok::resources::query_result_for_cook *)vostok::resources::query_result_for_user::get_requested_path(parent);
  texture = vostok::render::resource_manager::create_texture(
              v5,
              vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
              requested_path,
              parent,
              mip_level_cut,
              use_pool,
              load_async,
              use_converter,
              v14,
              0,
              streamed,
              force_query);
  v21[0] = v22;
  v21[1] = v22;
  v21[2] = &vars0;
  v22[0] = 0;
  v6 = vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::fs_new::path_string_impl::assignf(v21, v7, (vostok::buffer_string *)&stru_80B1B4, v6);
  v19[0] = (int)vostok::render::render_texture_cook::on_texture_loaded;
  v19[1] = (int)this;
  *(_QWORD *)&v20.mip_level_cut = __PAIR64__(num_last_mips_used, (unsigned int)texture);
  out_value.mip_level_cut = (unsigned int)vostok::render::render_texture_cook::on_texture_loaded;
  out_value.num_last_mips_used = (unsigned int)this;
  *(_DWORD *)&out_value.use_pool = texture;
  *(_DWORD *)&out_value.force_query = num_last_mips_used;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(v8) )
  {
    v19[0] = 0;
  }
  else
  {
    v20 = out_value;
    v19[0] = (int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::render_texture_cook,vostok::resources::queries_result &,vostok::render::res_texture *,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::render::render_texture_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::res_texture *>,boost::_bi::value<unsigned int>>>>'::`2'::stored_vtable
           + 1;
  }
  vostok::resources::query_resource(
    v21[0],
    (vostok::variant<32> *)7,
    vostok::render::g_allocator,
    0,
    (const vostok::variant<32> **)parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v9, v19);
}
