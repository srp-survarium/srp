vostok::engine::editor_console *__thiscall vostok::engine::editor_console::`scalar deleting destructor'(
        vostok::engine::editor_console *this,
        char a2)
{
  this->vostok::engine::console::vostok::input::handler::__vftable = (vostok::engine::console_vtbl *)&vostok::engine::console::`vftable';
  vostok::console_impl::~console_impl(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
