void __usercall vostok::render::stage_apply_distortion::stage_apply_distortion(
        vostok::render::stage_apply_distortion *this@<esi>,
        vostok::render::renderer *in_renderer@<ecx>,
        vostok::render::renderer_context *context@<eax>)
{
  vostok::render::effect_manager *m_conflicted_action_to_bind; // ecx

  this->m_context = context;
  this->m_enabled = 1;
  this->m_prev_enabled = 1;
  this->m_renderer = in_renderer;
  m_conflicted_action_to_bind = (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind;
  this->__vftable = (vostok::render::stage_apply_distortion_vtbl *)&stru_965008.m_sh_res_view;
  this->m_sh_apply_distortion.m_object = 0;
  vostok::render::effect_manager::create_effect<vostok::render::effect_apply_distortion>(
    m_conflicted_action_to_bind,
    &this->m_sh_apply_distortion);
}
