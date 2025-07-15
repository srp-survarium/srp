void __userpurge vostok::ui::ui_world::ui_world(
        vostok::ui::ui_world *this@<edi>,
        vostok::memory::base_allocator *allocator@<eax>,
        vostok::input::world *input_world@<ecx>,
        vostok::ui::engine *engine,
        vostok::render::ui::renderer *renderer)
{
  float v6; // xmm0_4
  vostok::timing::timer *v7; // ecx
  vostok::timing::timer *v8; // ecx

  this->m_input_world = input_world;
  this->m_engine = engine;
  this->m_base_screen_size.x = FLOAT_1024_0;
  this->__vftable = (vostok::ui::ui_world_vtbl *)&vostok::ui::ui_world::`vftable';
  this->m_renderer = (struct vostok::ui::render::ui::renderer *)renderer;
  this->m_allocator = allocator;
  this->m_base_screen_size.y = FLOAT_768_0;
  v6 = SNaN;
  this->m_font_manager.m_allocator = allocator;
  this->m_font_manager.m_font.m_allocator = allocator;
  this->m_font_manager.m_font.m_char_map = 0;
  this->m_font_manager.m_font.__vftable = (vostok::ui::ui_font_vtbl *)&vostok::ui::ui_font::`vftable';
  this->m_font_manager.m_font.m_ts_size.x = v6;
  this->m_font_manager.m_font.m_ts_size.y = v6;
  vostok::ui::ui_font::init_font((vostok::ui::ui_font *)renderer, (int)&this->m_font_manager.m_font);
  vostok::timing::timer::timer(v7, (LARGE_INTEGER *)&this->m_timer);
  vostok::timing::timer::start(v8, (LARGE_INTEGER *)&this->m_timer);
}
