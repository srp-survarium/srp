void __usercall vostok::ui::ui_image::ui_image(
        vostok::ui::ui_image *this@<eax>,
        vostok::memory::base_allocator *a@<edx>)
{
  const vostok::math::float4x4 *v2; // xmm0_4

  this->m_allocator = a;
  this->vostok::ui::ui_window::vostok::ui::window::__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_window::`vftable';
  this->m_position = 0;
  this->m_size = 0;
  this->m_parent = 0;
  this->m_event_manager._M_impl._M_start = 0;
  this->m_event_manager._M_impl._M_finish = 0;
  this->m_event_manager._M_impl._M_end_of_storage.m_allocator = a;
  this->m_event_manager._M_impl._M_end_of_storage._M_data = 0;
  this->m_b_visible = 0;
  this->m_b_orphan = 1;
  this->m_b_focused = 0;
  this->m_b_tab_stop = 0;
  this->m_children._M_impl._M_start = 0;
  this->m_children._M_impl._M_finish = 0;
  this->m_children._M_impl._M_end_of_storage.m_allocator = a;
  this->m_children._M_impl._M_end_of_storage._M_data = 0;
  this->vostok::ui::image::__vftable = (vostok::ui::ui_image_vtbl *)&vostok::ui::ui_image::`vftable'{for `vostok::ui::image'};
  this->vostok::ui::ui_window::vostok::ui::window::__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_image::`vftable'{for `vostok::ui::ui_window'};
  *(_QWORD *)&this->m_tex_coords.x = 0;
  v2 = clear_value;
  LODWORD(this->m_tex_coords.z) = clear_value;
  LODWORD(this->m_tex_coords.w) = v2;
  this->m_color = -1;
  this->m_point_type = 1;
}
