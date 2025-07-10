void __usercall survarium::base_game_scene::base_game_scene(
        survarium::base_game_scene *this@<esi>,
        survarium::game *g@<eax>)
{
  vostok::memory::doug_lea_allocator *f; // ecx
  survarium::camera_director *v3; // eax
  survarium::camera_director *v4; // eax

  f = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
  this->m_render_scene.m_object = 0;
  this->m_render_scene_view.m_object = 0;
  this->survarium::game_scene::__vftable = (survarium::base_game_scene_vtbl *)&survarium::base_game_scene::`vftable'{for `survarium::game_scene'};
  this->survarium::engine::__vftable = (survarium::engine_vtbl *)&survarium::base_game_scene::`vftable'{for `survarium::engine'};
  this->m_mouse_pos = 0;
  this->m_sound_scene.m_object = 0;
  this->m_text_manager = 0;
  this->m_game = g;
  this->m_is_ui_shown = 0;
  this->m_physics_world = 0;
  this->m_is_active = 0;
  v3 = (survarium::camera_director *)vostok::memory::doug_lea_allocator::malloc_impl(f, 0x8Cu);
  if ( v3 )
  {
    survarium::camera_director::camera_director(this, v3);
    this->m_camera_director = v4;
  }
  else
  {
    this->m_camera_director = 0;
  }
}
