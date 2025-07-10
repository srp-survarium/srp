void __fastcall vostok::input::input_world::input_world(
        vostok::input::engine *engine,
        HWND__ *window_handle,
        vostok::input::input_world *this)
{
  this->__vftable = (vostok::input::input_world_vtbl *)&vostok::input::input_world::`vftable';
  this->m_handlers._M_impl._M_start = 0;
  this->m_handlers._M_impl._M_finish = 0;
  this->m_handlers._M_impl._M_end_of_storage._M_data = 0;
  this->m_engine = engine;
  this->m_direct_input = 0;
  this->m_gamepad = 0;
  this->m_keyboard = 0;
  this->m_mouse = 0;
  this->m_target_state = 2;
  this->m_acquired = 0;
  vostok::input::input_world::create_devices((vostok::input::input_world *)engine, window_handle);
}
