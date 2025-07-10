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
