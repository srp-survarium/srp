void __usercall vostok::ui::ui_progress_bar::ui_progress_bar(vostok::ui::ui_progress_bar *this@<ecx>, int a2@<eax>)
{
  float y; // edx

  y = this->m_position.y;
  *(float *)(a2 + 8) = y;
  *(_DWORD *)(a2 + 4) = &vostok::ui::ui_window::`vftable';
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 20) = 0;
  *(_DWORD *)(a2 + 24) = 0;
  *(_DWORD *)(a2 + 28) = 0;
  *(_DWORD *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 36) = 0;
  *(float *)(a2 + 40) = y;
  *(_DWORD *)(a2 + 44) = 0;
  *(_BYTE *)(a2 + 48) = 0;
  *(_BYTE *)(a2 + 49) = 1;
  *(_BYTE *)(a2 + 50) = 0;
  *(_BYTE *)(a2 + 51) = 0;
  *(_DWORD *)(a2 + 52) = 0;
  *(_DWORD *)(a2 + 56) = 0;
  *(float *)(a2 + 60) = y;
  *(_DWORD *)(a2 + 64) = 0;
  *(_DWORD *)(a2 + 68) = this;
  *(_DWORD *)a2 = &vostok::ui::ui_progress_bar::`vftable'{for `vostok::ui::progress_bar'};
  *(_DWORD *)(a2 + 4) = &vostok::ui::ui_progress_bar::`vftable'{for `vostok::ui::ui_window'};
  *(_DWORD *)(a2 + 72) = -7401961;
  *(_DWORD *)(a2 + 76) = -1284079;
  *(_DWORD *)(a2 + 80) = -13905202;
  *(_DWORD *)(a2 + 84) = 1;
  *(_DWORD *)(a2 + 88) = 1;
  *(_DWORD *)(a2 + 92) = 0;
  *(_DWORD *)(a2 + 96) = 100;
  *(_DWORD *)(a2 + 100) = 0;
  *(_DWORD *)(a2 + 112) = a2 + 148;
  *(_DWORD *)(a2 + 104) = a2 + 116;
  *(_DWORD *)(a2 + 108) = a2 + 116;
  *(_BYTE *)(a2 + 116) = 0;
  *(_BYTE *)(a2 + 148) = 0;
}
