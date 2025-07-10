void __usercall vostok::render::grass_render_surface::grass_render_surface(
        vostok::render::grass_render_surface *this@<ecx>,
        _DWORD *a2@<esi>)
{
  vostok::render::render_surface::render_surface(this, (int)a2);
  a2[39] = 0;
  a2[40] = 0;
  a2[41] = 0;
  a2[42] = 0;
  *a2 = &stru_966A14.m_name.m_string.m_buffer[8];
  a2[1] = 11;
}
