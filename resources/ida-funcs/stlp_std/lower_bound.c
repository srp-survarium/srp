float *__usercall stlp_std::lower_bound<float *,float,stlp_std::less<float>>@<eax>(
        float *__first@<eax>,
        float *__last@<ecx>,
        float *__val)
{
  int v3; // ecx
  float *v4; // esi

  v3 = __last - __first;
  while ( v3 > 0 )
  {
    v4 = &__first[v3 >> 1];
    if ( *__val <= *v4 )
    {
      v3 >>= 1;
    }
    else
    {
      __first = v4 + 1;
      v3 += -1 - (v3 >> 1);
    }
  }
  return __first;
}


vostok::ui::window **__usercall stlp_std::lower_bound<vostok::ui::window * *,float,vostok::ui::pred_window_less_position>@<eax>(
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
    if ( v6 <= (float)(v4->get_position(v4)->y + *p_y) )
    {
      v9 >>= 1;
    }
    else
    {
      v9 += -1 - (v9 >> 1);
      v8 = v3 + 1;
    }
  }
  return v8;
}


vostok::render::data_indexer *__usercall stlp_std::lower_bound<vostok::render::data_indexer *,vostok::render::data_indexer,bool (__cdecl *)(vostok::render::data_indexer const &,vostok::render::data_indexer const &)>@<eax>(
        vostok::render::data_indexer *__first@<ecx>,
        vostok::render::data_indexer *__last@<eax>,
        const vostok::render::data_indexer *__val)
{
  vostok::render::data_indexer *v3; // edi
  int v4; // ebx
  int v5; // edx

  v3 = __first;
  v4 = __last - __first;
  while ( v4 > 0 )
  {
    if ( vostok::render::constant_data_predicate(&v3[v4 >> 1], __val) )
    {
      v3 += (v4 >> 1) + 1;
      v4 += -1 - v5;
    }
    else
    {
      v4 = v5;
    }
  }
  return v3;
}


vostok::memory::platform::region *__fastcall stlp_std::lower_bound<vostok::memory::platform::region *,vostok::memory::platform::region>(
        vostok::memory::platform::region *__last,
        const vostok::memory::platform::region *__val,
        vostok::memory::platform::region *__first)
{
  vostok::memory::platform::region *result; // eax
  int v4; // esi
  vostok::memory::platform::region *v5; // ecx

  result = __first;
  v4 = __last - __first;
  while ( v4 > 0 )
  {
    v5 = &result[v4 >> 1];
    if ( v5->size >= __val->size )
    {
      v4 >>= 1;
    }
    else
    {
      result = v5 + 1;
      v4 += -1 - (v4 >> 1);
    }
  }
  return result;
}


const vostok::configs::binary_config_value *__usercall stlp_std::lower_bound<vostok::configs::binary_config_value const *,unsigned int>@<eax>(
        const vostok::configs::binary_config_value *__first@<ecx>,
        const vostok::configs::binary_config_value *__last@<eax>,
        unsigned int *__val)
{
  const vostok::configs::binary_config_value *v3; // esi
  int v4; // eax
  const vostok::configs::binary_config_value *v5; // ecx

  v3 = __first;
  v4 = __last - __first;
  while ( v4 > 0 )
  {
    v5 = &v3[v4 >> 1];
    if ( v5->id_crc >= *__val )
    {
      v4 >>= 1;
    }
    else
    {
      v3 = v5 + 1;
      v4 += -1 - (v4 >> 1);
    }
  }
  return v3;
}
