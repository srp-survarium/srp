void __userpurge vostok::engine::game_console::game_console(
        vostok::ui::world *uw@<ecx>,
        vostok::memory::base_allocator *a@<eax>,
        vostok::engine::game_console *this,
        vostok::input::world *iw)
{
  vostok::console_impl::console_impl(this, uw, a);
  this->vostok::engine::console::vostok::input::handler::__vftable = (vostok::engine::console_vtbl *)&vostok::engine::console::`vftable';
  this->m_input_world = iw;
  this->vostok::console_impl::__vftable = (vostok::engine::game_console_vtbl *)&vostok::engine::game_console::`vftable'{for `vostok::console_impl'};
  this->vostok::engine::console::vostok::input::handler::__vftable = (vostok::engine::console_vtbl *)&vostok::engine::game_console::`vftable'{for `vostok::engine::console'};
  this->m_self_deactivate = 1;
}
