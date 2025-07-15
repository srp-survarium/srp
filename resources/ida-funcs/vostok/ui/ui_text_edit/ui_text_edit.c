void __userpurge vostok::ui::ui_text_edit::ui_text_edit(
        vostok::ui::ui_text_edit *this@<ecx>,
        unsigned int a2@<esi>,
        vostok::ui::ui_world *w,
        vostok::ui::enum_text_edit_mode mode,
        vostok::memory::base_allocator *a)
{
  vostok::ui::ui_window *v5; // eax
  vostok::ui::ui_text_edit *v6; // ecx
  fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> v7; // [esp-8h] [ebp-10h]
  vostok::ui::enum_text_edit_mode v8; // [esp+0h] [ebp-8h]

  vostok::ui::ui_window::ui_window((vostok::ui::ui_window *)(a2 + 8), w->m_allocator);
  *(_DWORD *)(a2 + 4) = &vostok::ui::ui_text<vostok::ui::dynamic_text>::`vftable'{for `vostok::ui::text'};
  v5->__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_text<vostok::ui::dynamic_text>::`vftable'{for `vostok::ui::ui_window'};
  *(_DWORD *)(a2 + 72) = a2 + 84;
  *(_DWORD *)(a2 + 76) = a2 + 84;
  *(_BYTE *)(a2 + 84) = 0;
  *(_DWORD *)(a2 + 80) = a2 + 596;
  *(_DWORD *)(a2 + 608) = -1;
  *(_DWORD *)(a2 + 612) = w;
  *(_DWORD *)(a2 + 596) = 0;
  v7.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))survarium::game_world::on_mouse_key_action;
  v7.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)(a2 + 4);
  vostok::ui::ui_window::subscribe_event(v5, ev_text_changed, v7);
  *(_DWORD *)a2 = &vostok::ui::ui_text_edit::`vftable';
  *(_DWORD *)(a2 + 4) = &vostok::ui::ui_text_edit::`vftable'{for `vostok::ui::text'};
  *(_DWORD *)(a2 + 8) = &vostok::ui::ui_text_edit::`vftable'{for `vostok::ui::ui_window'};
  *(_DWORD *)(a2 + 616) = 0;
  *(_DWORD *)(a2 + 620) = 0;
  *(_DWORD *)(a2 + 624) = mode;
  *(_DWORD *)(a2 + 628) = 0;
  *(_DWORD *)(a2 + 632) = 0;
  *(_DWORD *)(a2 + 636) = 0;
  *(_DWORD *)(a2 + 640) = 0;
  *(_DWORD *)(a2 + 644) = 0;
  *(_DWORD *)(a2 + 648) = mode;
  *(_DWORD *)(a2 + 652) = 0;
  *(_DWORD *)(a2 + 656) = 0;
  *(_DWORD *)(a2 + 660) = 0;
  *(_DWORD *)(a2 + 664) = mode;
  *(_DWORD *)(a2 + 668) = 0;
  *(_DWORD *)(a2 + 672) = -1;
  *(_WORD *)(a2 + 676) = 255;
  *(_WORD *)(a2 + 678) = 0;
  *(_WORD *)(a2 + 680) = 0;
  *(_WORD *)(a2 + 682) = 0;
  *(_BYTE *)(a2 + 685) = 0;
  *(_BYTE *)(a2 + 686) = 0;
  *(_BYTE *)(a2 + 687) = 0;
  *(_BYTE *)(a2 + 684) = 0;
  vostok::ui::ui_window::subscribe_event(
    (vostok::ui::ui_window *)(a2 + 8),
    ev_focus,
    (fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)>)__PAIR64__(
                                                                              vostok::ui::ui_text_edit::on_focus,
                                                                              a2));
  *(_BYTE *)(a2 + 55) = 1;
  vostok::ui::ui_text_edit::init_internals(v6, (vostok::ui::ui_text_edit *)a2, v8);
}
