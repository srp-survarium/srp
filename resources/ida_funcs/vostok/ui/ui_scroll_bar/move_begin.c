void __usercall vostok::ui::ui_scroll_bar::move_begin(
        vostok::ui::ui_scroll_bar *this@<ecx>,
        int a2@<eax>,
        int a3@<edi>)
{
  vostok::ui::ui_scroll_bar *v4; // ecx
  float size; // [esp+0h] [ebp-8h]
  float v6; // [esp+4h] [ebp-4h]

  size = ((double (__thiscall *)(_DWORD))***(_DWORD ***)(a2 + 184))(*(_DWORD *)(a2 + 184));
  vostok::ui::ui_scroll_bar::move(v4, a3, a2, size, v6);
}
