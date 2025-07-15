char __userpurge vostok::ui::ui_window::process_event@<al>(
        vostok::ui::ui_window *this@<eax>,
        int p2@<ecx>,
        vostok::ui::ui_window *ev,
        int p1)
{
  return vostok::ui::ui_window::emit_event(ev, (int)this, (vostok::ui::enum_window_events)ev, this, p1, p2);
}
