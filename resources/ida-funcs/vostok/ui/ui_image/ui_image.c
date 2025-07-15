void __usercall vostok::ui::ui_image::ui_image(
        vostok::ui::ui_image *this@<esi>,
        vostok::memory::base_allocator *a@<edx>)
{
  _DWORD *v2; // eax
  float v3; // xmm0_4

  vostok::ui::ui_window::ui_window(&this->vostok::ui::ui_window, a);
  *v2 = &vostok::ui::ui_image::`vftable'{for `vostok::ui::ui_window'};
  this->vostok::ui::image::__vftable = (vostok::ui::ui_image_vtbl *)&vostok::ui::ui_image::`vftable'{for `vostok::ui::image'};
  *(_QWORD *)&this->m_tex_coords.x = 0;
  v3 = s_bm_current_air_resistance;
  this->m_tex_coords.z = s_bm_current_air_resistance;
  this->m_tex_coords.w = v3;
  this->m_color = -1;
  this->m_point_type = 1;
}
