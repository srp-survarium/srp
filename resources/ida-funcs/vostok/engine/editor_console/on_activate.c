// attributes: thunk
void __thiscall vostok::engine::editor_console::on_activate(vostok::engine::editor_console *this)
{
  vostok::console_impl::on_activate(this);
}


void __thiscall vostok::engine::editor_console::on_activate(char *this)
{
  vostok::engine::editor_console::on_activate((vostok::engine::editor_console *)(this - 616));
}
