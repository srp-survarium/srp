void __stdcall singletons_on_preinitialize::singletons_on_preinitialize(
        singletons_on_preinitialize *this,
        bool is_editor)
{
  const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *in_config; // eax
  vostok::render::device *v3; // ecx
  vostok::render::backend *v4; // ecx
  vostok::render::shader_macros *v5; // ecx
  vostok::render::effect_manager *v6; // ecx
  _DWORD *v7; // eax

  vostok::render::resource_manager::resource_manager(&this->resource_manager, in_config);
  `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game = (survarium::game *)&this->device;
  this->device.m_device = 0;
  this->device.m_context = 0;
  this->device.m_is_editor = is_editor;
  this->device.m_device_removed = 0;
  this->device.m_avaliable_video_memory = 0;
  vostok::render::device::create(v3);
  vostok::render::backend::backend(v4);
  this->scene_manager.m_scenes._M_impl._M_start = 0;
  this->scene_manager.m_scenes._M_impl._M_finish = 0;
  this->scene_manager.m_scenes._M_impl._M_end_of_storage._M_data = 0;
  this->scene_manager.m_views._M_impl._M_start = 0;
  this->scene_manager.m_views._M_impl._M_finish = 0;
  this->scene_manager.m_views._M_impl._M_end_of_storage._M_data = 0;
  this->scene_manager.m_output_windows._M_impl._M_start = 0;
  this->scene_manager.m_output_windows._M_impl._M_finish = 0;
  vostok::quasi_singleton<vostok::render::scene_manager>::pinst = &this->scene_manager;
  this->scene_manager.m_output_windows._M_impl._M_end_of_storage._M_data = 0;
  `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[2] = (survarium::options_tab *)&this->shader_macros;
  vostok::buffer_vector<void const *>::buffer_vector<void const *>(
    (vostok::buffer_vector<void const *> *)&this->shader_macros,
    this->shader_macros.m_available_macros.m_buffer,
    0x80u,
    0);
  this->shader_macros.m_working_macro_list.m_begin = (vostok::render::shader_macro *)this->shader_macros.m_working_macro_list.m_buffer;
  this->shader_macros.m_working_macro_list.m_end = (vostok::render::shader_macro *)this->shader_macros.m_working_macro_list.m_buffer;
  vostok::render::shader_macros::register_available_macros(v5);
  vostok::render::effect_manager::effect_manager(v6);
  v7 = (_DWORD *)((char *)stlp_std::swap<vostok::size_policy> + (_DWORD)this);
  *v7 = 0;
  v7[1] = 0;
  v7[2] = 0;
  v7[3] = 0;
  vostok::quasi_singleton<vostok::render::effect_constant_storage>::pinst = (vostok::render::effect_constant_storage *)((char *)stlp_std::swap<vostok::size_policy> + (_DWORD)this);
}
