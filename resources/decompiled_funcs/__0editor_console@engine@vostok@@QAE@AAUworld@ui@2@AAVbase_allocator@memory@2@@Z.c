void __userpurge vostok::engine::editor_console::editor_console(
        vostok::ui::world *uw@<ecx>,
        vostok::memory::base_allocator *a@<eax>,
        vostok::engine::editor_console *this)
{
  vostok::console_impl::console_impl(this, uw, a);
  this->vostok::engine::console::vostok::input::handler::__vftable = (vostok::engine::console_vtbl *)&vostok::engine::console::`vftable';
  this->vostok::console_impl::__vftable = (vostok::engine::editor_console_vtbl *)&vostok::engine::editor_console::`vftable'{for `vostok::console_impl'};
  this->vostok::engine::console::vostok::input::handler::__vftable = (vostok::engine::console_vtbl *)&vostok::engine::editor_console::`vftable'{for `vostok::engine::console'};
  this->m_self_deactivate = 0;
}
