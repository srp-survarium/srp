// attributes: thunk
void __thiscall vostok::engine::editor_console::on_deactivate(vostok::engine::editor_console *this)
{
  vostok::console_impl::on_deactivate(this);
}


void __thiscall vostok::engine::editor_console::on_deactivate(char *this)
{
  vostok::engine::editor_console::on_deactivate((vostok::engine::editor_console *)(this - 616));
}
