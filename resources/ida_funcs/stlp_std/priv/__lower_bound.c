vostok::input::handler **__usercall stlp_std::priv::__lower_bound<vostok::input::handler * *,int,handler_prio_less,handler_prio_less,int>@<eax>(
        vostok::input::handler **__last@<eax>,
        vostok::input::handler **__first,
        int *__val)
{
  vostok::input::handler **v3; // ebx
  int v4; // edi
  int v5; // ebp
  int v6; // esi

  v3 = __first;
  v4 = __last - __first;
  while ( v4 > 0 )
  {
    v5 = *__val;
    v6 = v4 >> 1;
    if ( v3[v4 >> 1]->input_priority(v3[v4 >> 1]) >= v5 )
    {
      v4 >>= 1;
    }
    else
    {
      v3 += v6 + 1;
      v4 += -1 - v6;
    }
  }
  return v3;
}


vostok::ui::window **__cdecl stlp_std::priv::__lower_bound<vostok::ui::window * *,float,vostok::ui::pred_window_less_position,vostok::ui::pred_window_less_position,int>(
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
    if ( __firsta <= (float)(v6->get_position(v6)->y + *(float *)__lasta) )
    {
      v4 >>= 1;
    }
    else
    {
      v3 += v5 + 1;
      v4 += -1 - v5;
    }
  }
  return v3;
}
