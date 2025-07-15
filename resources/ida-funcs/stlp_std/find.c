char *__usercall stlp_std::find<vostok::render::render_output_window * *,vostok::render::render_output_window *>@<eax>(
        char *__first@<eax>,
        int *__val@<edi>,
        char *__last)
{
  int v3; // ecx
  int v4; // edx

  v3 = (__last - __first) >> 4;
  if ( v3 <= 0 )
  {
LABEL_8:
    if ( (__last - __first) >> 2 != 1 )
    {
      if ( (__last - __first) >> 2 != 2 )
      {
        if ( (__last - __first) >> 2 != 3 )
          return __last;
        if ( *(_DWORD *)__first == *__val )
          return __first;
        __first += 4;
      }
      if ( *(_DWORD *)__first == *__val )
        return __first;
      __first += 4;
    }
    if ( *(_DWORD *)__first == *__val )
      return __first;
    return __last;
  }
  v4 = *__val;
  while ( *(_DWORD *)__first != v4 )
  {
    __first += 4;
    if ( *(_DWORD *)__first == v4 )
      break;
    __first += 4;
    if ( *(_DWORD *)__first == v4 )
      break;
    __first += 4;
    if ( *(_DWORD *)__first == v4 )
      break;
    __first += 4;
    if ( --v3 <= 0 )
      goto LABEL_8;
  }
  return __first;
}


survarium::account_list_item *__usercall stlp_std::find<survarium::account_list_item *,unsigned int>@<eax>(
        survarium::account_list_item *__first@<ecx>,
        const unsigned int *__val@<edi>,
        survarium::account_list_item *__last)
{
  int v3; // eax
  int v4; // edx
  survarium::account_list_item *result; // eax

  v3 = (__last - __first) >> 2;
  if ( v3 > 0 )
  {
    v4 = *__val;
    while ( __first->account_id != v4 )
    {
      ++__first;
      if ( __first->account_id == v4 )
        break;
      ++__first;
      if ( __first->account_id == v4 )
        break;
      ++__first;
      if ( __first->account_id == v4 )
        break;
      ++__first;
      if ( --v3 <= 0 )
        goto LABEL_8;
    }
    return __first;
  }
LABEL_8:
  switch ( __last - __first )
  {
    case 1:
LABEL_15:
      result = __first;
      if ( __first->account_id == *__val )
        return result;
      return __last;
    case 2:
      goto LABEL_13;
    case 3:
      if ( __first->account_id == *__val )
        return __first;
      ++__first;
LABEL_13:
      if ( __first->account_id != *__val )
      {
        ++__first;
        goto LABEL_15;
      }
      return __first;
  }
  return __last;
}


vostok::render::light_data *__usercall stlp_std::find<vostok::render::light_data *,unsigned int>@<eax>(
        vostok::render::light_data *__first@<eax>,
        const unsigned int *__val@<edi>,
        vostok::render::light_data *__last)
{
  int v3; // ecx
  int v4; // edx

  v3 = ((char *)__last - (char *)__first) >> 5;
  if ( v3 <= 0 )
  {
LABEL_8:
    if ( __last - __first != 1 )
    {
      if ( __last - __first != 2 )
      {
        if ( __last - __first != 3 )
          return __last;
        if ( __first->id == *__val )
          return __first;
        ++__first;
      }
      if ( __first->id == *__val )
        return __first;
      ++__first;
    }
    if ( __first->id == *__val )
      return __first;
    return __last;
  }
  v4 = *__val;
  while ( __first->id != v4 )
  {
    ++__first;
    if ( __first->id == v4 )
      break;
    ++__first;
    if ( __first->id == v4 )
      break;
    ++__first;
    if ( __first->id == v4 )
      break;
    ++__first;
    if ( --v3 <= 0 )
      goto LABEL_8;
  }
  return __first;
}


vostok::render::texture_named_instance *__usercall stlp_std::find<vostok::render::texture_named_instance *,vostok::render::texture_named_instance>@<eax>(
        vostok::render::texture_named_instance *__first@<eax>,
        const vostok::render::texture_named_instance *__val@<edi>,
        vostok::render::texture_named_instance *__last)
{
  vostok::render::texture_named_instance *v3; // esi
  int v4; // eax
  vostok::render::res_texture *texture; // edx
  vostok::render::texture_named_instance *result; // eax

  v3 = __first;
  v4 = (__last - __first) >> 2;
  if ( v4 > 0 )
  {
    texture = __val->texture;
    while ( v3->texture != texture )
    {
      ++v3;
      if ( v3->texture == texture )
        break;
      ++v3;
      if ( v3->texture == texture )
        break;
      ++v3;
      if ( v3->texture == texture )
        break;
      ++v3;
      if ( --v4 <= 0 )
        goto LABEL_8;
    }
    return v3;
  }
LABEL_8:
  switch ( __last - v3 )
  {
    case 1:
LABEL_15:
      result = v3;
      if ( v3->texture == __val->texture )
        return result;
      return __last;
    case 2:
      goto LABEL_13;
    case 3:
      if ( v3->texture == __val->texture )
        return v3;
      ++v3;
LABEL_13:
      if ( v3->texture != __val->texture )
      {
        ++v3;
        goto LABEL_15;
      }
      return v3;
  }
  return __last;
}


vostok::ui::typed_handlers *__usercall stlp_std::find<vostok::ui::typed_handlers *,enum vostok::ui::enum_window_events>@<eax>(
        vostok::ui::typed_handlers *__first@<eax>,
        const vostok::ui::enum_window_events *__val@<edi>,
        vostok::ui::typed_handlers *__last)
{
  vostok::ui::typed_handlers *v3; // esi
  int v4; // eax
  int v5; // edx
  vostok::ui::typed_handlers *result; // eax

  v3 = __first;
  v4 = (__last - __first) >> 2;
  if ( v4 > 0 )
  {
    v5 = *__val;
    while ( v3->type != v5 )
    {
      ++v3;
      if ( v3->type == v5 )
        break;
      ++v3;
      if ( v3->type == v5 )
        break;
      ++v3;
      if ( v3->type == v5 )
        break;
      ++v3;
      if ( --v4 <= 0 )
        goto LABEL_8;
    }
    return v3;
  }
LABEL_8:
  switch ( __last - v3 )
  {
    case 1:
LABEL_15:
      result = v3;
      if ( v3->type == *__val )
        return result;
      return __last;
    case 2:
      goto LABEL_13;
    case 3:
      if ( v3->type == *__val )
        return v3;
      ++v3;
LABEL_13:
      if ( v3->type != *__val )
      {
        ++v3;
        goto LABEL_15;
      }
      return v3;
  }
  return __last;
}
