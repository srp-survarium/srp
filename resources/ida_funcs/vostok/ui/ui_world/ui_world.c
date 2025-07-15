void __userpurge vostok::ui::ui_world::ui_world(
        vostok::ui::ui_world *this@<edi>,
        vostok::memory::base_allocator *allocator@<eax>,
        vostok::input::world *input_world@<ecx>,
        vostok::ui::engine *engine,
        vostok::render::ui::renderer *renderer)
{
  float v5; // xmm0_4
  unsigned __int64 QuadPart; // rax
  LARGE_INTEGER PerformanceCount; // [esp+0h] [ebp-8h] BYREF

  this->m_input_world = input_world;
  this->m_base_screen_size.x = 1024.0;
  this->__vftable = (vostok::ui::ui_world_vtbl *)&vostok::ui::ui_world::`vftable';
  this->m_engine = engine;
  this->m_renderer = renderer;
  this->m_allocator = allocator;
  this->m_base_screen_size.y = 768.0;
  v5 = SNaN;
  this->m_font_manager.m_allocator = allocator;
  this->m_font_manager.m_font.m_allocator = allocator;
  this->m_font_manager.m_font.__vftable = (vostok::ui::ui_font_vtbl *)&vostok::ui::ui_font::`vftable';
  this->m_font_manager.m_font.m_ts_size.x = v5;
  this->m_font_manager.m_font.m_ts_size.y = v5;
  this->m_font_manager.m_font.m_char_map = 0;
  vostok::ui::ui_font::init_font((vostok::ui::ui_font *)renderer, &this->m_font_manager.m_font.__vftable);
  vostok::timing::timer::timer(&this->m_timer);
  if ( vostok::timing::g_cpu_supports_time_stamp )
  {
    QuadPart = __rdtsc();
  }
  else
  {
    QueryPerformanceCounter(&PerformanceCount);
    QuadPart = PerformanceCount.QuadPart;
  }
  this->m_timer.m_start_time = QuadPart;
  this->m_timer.m_current_time = 0;
}
