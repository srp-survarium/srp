void __usercall survarium::flash_text_manager::set_viewport(
        survarium::flash_text_manager *this@<esi>,
        unsigned int output_window_width@<edx>,
        unsigned int output_window_height@<ecx>)
{
  const vostok::math::float4x4 *v3; // xmm0_4
  Scaleform::GFx::DrawTextManager *text_manager_impl; // ecx
  Scaleform::GFx::Viewport viewport; // [esp+0h] [ebp-34h] BYREF

  v3 = clear_value;
  viewport.Left = 0;
  viewport.Top = 0;
  memset(&viewport.ScissorLeft, 0, 20);
  this->m_output_height = output_window_height;
  viewport.BufferHeight = output_window_height;
  viewport.Height = output_window_height;
  text_manager_impl = this->text_manager_impl;
  this->m_output_width = output_window_width;
  viewport.BufferWidth = output_window_width;
  viewport.Width = output_window_width;
  LODWORD(viewport.AspectRatio) = v3;
  LODWORD(viewport.Scale) = v3;
  Scaleform::GFx::DrawTextManager::SetViewport(text_manager_impl, &viewport);
  this->need_capture = 1;
}
