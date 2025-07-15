void __usercall vostok::ui::ui_scroll_bar::~ui_scroll_bar(vostok::ui::ui_scroll_bar *this@<ecx>, int a2@<esi>)
{
  vostok::ui::ui_window::~ui_window((vostok::ui::ui_window *)(a2 + 252));
  vostok::ui::ui_window::~ui_window((vostok::ui::ui_window *)(a2 + 188));
  vostok::ui::ui_image::~ui_image((vostok::ui::ui_image *)(a2 + 92));
  vostok::ui::ui_image::~ui_image((vostok::ui::ui_image *)a2);
}
