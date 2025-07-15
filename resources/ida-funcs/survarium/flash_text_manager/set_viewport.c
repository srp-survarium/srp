void __usercall survarium::flash_text_manager::set_viewport(
        survarium::flash_text_manager *this@<esi>,
        unsigned int output_window_width@<ecx>,
        unsigned int output_window_height@<eax>)
{
  Scaleform::GFx::Viewport v3; // [esp+0h] [ebp-34h] BYREF

  this->m_output_width = output_window_width;
  this->m_output_height = output_window_height;
  Scaleform::GFx::Viewport::Viewport(
    &v3,
    output_window_width,
    output_window_height,
    0,
    0,
    output_window_width,
    output_window_height,
    0);
  Scaleform::GFx::DrawTextManager::SetViewport(this->text_manager_impl, &v3);
  this->need_capture = 1;
}
