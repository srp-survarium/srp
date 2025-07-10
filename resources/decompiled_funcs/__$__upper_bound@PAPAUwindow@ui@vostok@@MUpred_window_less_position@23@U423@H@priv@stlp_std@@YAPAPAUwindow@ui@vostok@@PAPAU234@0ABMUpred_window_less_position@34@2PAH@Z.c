vostok::ui::window **__cdecl stlp_std::priv::__upper_bound<vostok::ui::window * *,float,vostok::ui::pred_window_less_position,vostok::ui::pred_window_less_position,int>(
        vostok::ui::window **__first,
        vostok::ui::window **__last,
        float *__val)
{
  vostok::ui::window **v3; // ebp
  int v4; // ebx
  int v5; // esi
  vostok::ui::window *v6; // edi
  float __firsta; // [esp+Ch] [ebp+4h]
  vostok::ui::window **__lasta; // [esp+10h] [ebp+8h]

  v3 = __first;
  v4 = __last - __first;
  while ( v4 > 0 )
  {
    v5 = v4 >> 1;
    v6 = v3[v4 >> 1];
    __firsta = *__val;
    __lasta = (vostok::ui::window **)&v6->get_size(v6)->y;
    if ( (float)(v6->get_position(v6)->y + *(float *)__lasta) <= __firsta )
    {
      v3 += v5 + 1;
      v4 += -1 - v5;
    }
    else
    {
      v4 >>= 1;
    }
  }
  return v3;
}
