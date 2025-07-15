void __thiscall vostok::ui::ui_image::init_texture(vostok::ui::ui_image *this, char *texture_name)
{
  float v3; // xmm0_4
  float v4; // xmm0_4

  if ( !_stricmp(texture_name, "ui_scull") )
  {
    this->m_tex_coords.x = 0.0;
    this->m_tex_coords.y = 0.0;
    v3 = s_bm_current_air_resistance;
    this->m_tex_coords.z = s_bm_current_air_resistance;
    this->m_tex_coords.w = v3;
    this->m_point_type = 1;
  }
  else
  {
    _stricmp(texture_name, "ui_rect");
    this->m_tex_coords.x = 0.0;
    this->m_tex_coords.y = 0.0;
    v4 = s_bm_current_air_resistance;
    this->m_tex_coords.z = s_bm_current_air_resistance;
    this->m_tex_coords.w = v4;
    this->m_point_type = 2;
  }
}
