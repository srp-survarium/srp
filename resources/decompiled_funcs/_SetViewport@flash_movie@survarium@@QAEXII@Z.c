void __usercall survarium::flash_movie::SetViewport(
        survarium::flash_movie *this@<esi>,
        unsigned int output_window_width@<edx>,
        unsigned int output_window_height@<ecx>)
{
  const vostok::math::float4x4 *v3; // xmm0_4
  Scaleform::GFx::Movie *m_movie; // ecx
  Scaleform::GFx::Viewport viewport; // [esp+0h] [ebp-34h] BYREF

  v3 = clear_value;
  this->m_output_height = output_window_height;
  viewport.BufferHeight = output_window_height;
  viewport.Height = output_window_height;
  m_movie = this->m_movie;
  this->m_output_width = output_window_width;
  viewport.BufferWidth = output_window_width;
  viewport.Left = 0;
  viewport.Top = 0;
  viewport.Width = output_window_width;
  memset(&viewport.ScissorLeft, 0, 20);
  LODWORD(viewport.AspectRatio) = v3;
  LODWORD(viewport.Scale) = v3;
  m_movie->SetViewport(m_movie, &viewport);
}
