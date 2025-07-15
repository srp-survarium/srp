BOOL __thiscall vostok::render::stage_postprocess::is_effects_ready(vostok::render::stage_postprocess *this)
{
  BOOL result; // eax

  result = 0;
  if ( this->m_sh_gather_bloom.m_object
    && this->m_sh_gather_luminance.m_object
    && this->m_sh_gather_luminance_histogram.m_object
    && this->m_sh_eye_adaptation.m_object
    && this->m_color_grading_lut_blending_effect.m_object
    && this->m_sh_blur[0].m_object
    && this->m_sh_blur[1].m_object
    && this->m_sh_blur[2].m_object
    && this->m_sh_blur[3].m_object
    && this->m_sh_blur[4].m_object
    && this->m_sh_blur[5].m_object
    && this->m_sh_blur[6].m_object
    && this->m_sh_blur[7].m_object
    && this->m_image_space_reflections_effect.m_object
    && this->m_sh_complex_blend[0][0].m_object
    && this->m_sh_complex_blend[1][0].m_object
    && this->m_sh_complex_blend[1][1].m_object
    && this->m_sh_effect_copy_image.m_object
    && this->m_lens_flares_effect.m_object
    && this->m_post_process_antialiasing_shader.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    && this->m_post_process_antialiasing_shader_fxaa.m_object
    && this->m_post_process_antialiasing_shader_sraa.m_object
    && this->m_post_process_shader_sharpen.m_object
    && this->m_god_rays_effect.m_object
    && this->m_post_process_downsample_frame_effect.m_object
    && this->m_motion_blur_effect.m_object
    && this->m_radial_motion_blur_effect.m_object
    && this->m_channel_blur_effect.m_object
    && this->m_aberration_sharpen_effect[0][0][0].m_object
    && this->m_aberration_sharpen_effect[0][0][1].m_object
    && this->m_aberration_sharpen_effect[0][1][0].m_object
    && this->m_aberration_sharpen_effect[0][1][1].m_object
    && this->m_aberration_sharpen_effect[1][0][0].m_object
    && this->m_aberration_sharpen_effect[1][0][1].m_object
    && this->m_aberration_sharpen_effect[1][1][0].m_object
    && this->m_aberration_sharpen_effect[1][1][1].m_object )
  {
    if ( this->m_temporal_antialiasing_effect.m_object )
      return this->m_motion_vectors_accumulation_effect.m_object != 0;
  }
  return result;
}
