void __usercall vostok::ui::client_to_screen(
        const vostok::ui::ui_window *w@<ecx>,
        vostok::math::float2 *src_and_dest@<edi>)
{
  vostok::ui::ui_window_vtbl *v2; // eax
  float *v3; // eax
  float v4; // xmm0_4
  const vostok::ui::ui_window *v5; // esi

  v2 = w->__vftable;
  while ( 1 )
  {
    v5 = (const vostok::ui::ui_window *)((int (__fastcall *)(const vostok::ui::ui_window *))v2->get_parent)(w);
    if ( !v5 )
      break;
    v3 = (float *)v5->get_position(v5);
    src_and_dest->x = *v3 + src_and_dest->x;
    v4 = v3[1] + src_and_dest->y;
    v2 = v5->__vftable;
    src_and_dest->y = v4;
    w = v5;
  }
}
