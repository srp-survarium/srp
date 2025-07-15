void __usercall vostok::ui::ui_scroll_bar::move_end(vostok::ui::ui_scroll_bar *this@<ecx>, int a2@<eax>)
{
  vostok::ui::ui_scroll_bar *v3; // ecx
  float size; // [esp+0h] [ebp-8h]

  size = -((double (__thiscall *)(_DWORD))***(_DWORD ***)(a2 + 184))(*(_DWORD *)(a2 + 184));
  vostok::ui::ui_scroll_bar::move(v3, a2, size);
}
