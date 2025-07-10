void __usercall vostok::render::res_render_output::resize(
        vostok::render::res_render_output *this@<ecx>,
        HWND force_resize@<eax>)
{
  vostok::render::res_render_output::resize(this, 0, 0, this->m_windowed, force_resize);
}
