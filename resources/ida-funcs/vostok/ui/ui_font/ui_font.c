void __usercall vostok::ui::ui_font::ui_font(vostok::ui::ui_font *this@<ecx>, float *a2@<eax>)
{
  float v2; // xmm0_4

  v2 = SNaN;
  *((_DWORD *)a2 + 1) = this;
  *(_DWORD *)a2 = &vostok::ui::ui_font::`vftable';
  a2[3] = v2;
  a2[4] = v2;
  a2[6] = 0.0;
}
