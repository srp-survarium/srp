vostok::ui::window **__usercall stlp_std::upper_bound<vostok::ui::window * *,float,vostok::ui::pred_window_less_position>@<eax>(
        vostok::ui::window **__first@<ecx>,
        vostok::ui::window **__last@<eax>,
        float *__val)
{
  vostok::ui::window **v3; // ebx
  vostok::ui::window *v4; // esi
  float v6; // [esp+0h] [ebp-10h]
  float *p_y; // [esp+4h] [ebp-Ch]
  vostok::ui::window **v8; // [esp+8h] [ebp-8h]
  int v9; // [esp+Ch] [ebp-4h]

  v8 = __first;
  v9 = __last - __first;
  while ( v9 > 0 )
  {
    v3 = &v8[v9 >> 1];
    v4 = *v3;
    v6 = *__val;
    p_y = &(*v3)->get_size(*v3)->y;
    if ( (float)(v4->get_position(v4)->y + *p_y) <= v6 )
    {
      v9 += -1 - (v9 >> 1);
      v8 = v3 + 1;
    }
    else
    {
      v9 >>= 1;
    }
  }
  return v8;
}
