char *__usercall stlp_std::priv::__find<unsigned short *,unsigned short>@<eax>(
        char *__first@<eax>,
        char *__last@<esi>,
        const unsigned __int16 *__val@<edi>)
{
  int v3; // ecx
  __int16 v4; // dx

  v3 = (__last - __first) >> 3;
  if ( v3 <= 0 )
  {
LABEL_8:
    if ( (__last - __first) >> 1 != 1 )
    {
      if ( (__last - __first) >> 1 != 2 )
      {
        if ( (__last - __first) >> 1 != 3 )
          return __last;
        if ( *(_WORD *)__first == *__val )
          return __first;
        __first += 2;
      }
      if ( *(_WORD *)__first == *__val )
        return __first;
      __first += 2;
    }
    if ( *(_WORD *)__first == *__val )
      return __first;
    return __last;
  }
  v4 = *__val;
  while ( *(_WORD *)__first != v4 )
  {
    __first += 2;
    if ( *(_WORD *)__first == v4 )
      break;
    __first += 2;
    if ( *(_WORD *)__first == v4 )
      break;
    __first += 2;
    if ( *(_WORD *)__first == v4 )
      break;
    --v3;
    __first += 2;
    if ( v3 <= 0 )
      goto LABEL_8;
  }
  return __first;
}


survarium::account_list_item *__usercall stlp_std::priv::__find<survarium::account_list_item *,unsigned int>@<eax>(
        survarium::account_list_item *__first@<ecx>,
        survarium::account_list_item *__last@<esi>,
        const unsigned int *__val@<edi>)
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
      --v3;
      ++__first;
      if ( v3 <= 0 )
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


survarium::hit_receiver_info *__cdecl stlp_std::priv::__find<survarium::hit_receiver_info *,survarium::hit_receiver_info>(
        survarium::hit_receiver_info *__first,
        survarium::hit_receiver_info *__last,
        const survarium::hit_receiver_info *__val)
{
  int v4; // [esp+0h] [ebp-8h]
  int __trip_count; // [esp+4h] [ebp-4h]
  survarium::hit_receiver_info *__firsta; // [esp+10h] [ebp+8h]
  survarium::hit_receiver_info *__firstb; // [esp+10h] [ebp+8h]
  survarium::hit_receiver_info *__firstc; // [esp+10h] [ebp+8h]

  for ( __trip_count = (__last - __first) >> 2; __trip_count > 0; --__trip_count )
  {
    if ( survarium::hit_receiver_info::operator==(__first, __val) )
      return __first;
    __firsta = __first + 1;
    if ( survarium::hit_receiver_info::operator==(__firsta, __val) )
      return __firsta;
    __firstb = __firsta + 1;
    if ( survarium::hit_receiver_info::operator==(__firstb, __val) )
      return __firstb;
    __firstc = __firstb + 1;
    if ( survarium::hit_receiver_info::operator==(__firstc, __val) )
      return __firstc;
    __first = __firstc + 1;
  }
  v4 = __last - __first;
  if ( v4 != 1 )
  {
    if ( v4 != 2 )
    {
      if ( v4 != 3 )
        return __last;
      if ( survarium::hit_receiver_info::operator==(__first, __val) )
        return __first;
      ++__first;
    }
    if ( survarium::hit_receiver_info::operator==(__first, __val) )
      return __first;
    ++__first;
  }
  if ( survarium::hit_receiver_info::operator==(__first, __val) )
    return __first;
  return __last;
}


vostok::render::light_data *__usercall stlp_std::priv::__find<vostok::render::light_data *,unsigned int>@<eax>(
        vostok::render::light_data *__first@<eax>,
        vostok::render::light_data *__last@<esi>,
        const unsigned int *__val@<edi>)
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
    --v3;
    ++__first;
    if ( v3 <= 0 )
      goto LABEL_8;
  }
  return __first;
}


vostok::render::streaming_texture_instance *__usercall stlp_std::priv::__find<vostok::render::streaming_texture_instance *,vostok::render::streaming_texture_instance>@<eax>(
        vostok::render::streaming_texture_instance *__first@<ecx>,
        vostok::render::streaming_texture_instance *__last@<edi>,
        const vostok::render::streaming_texture_instance *__val@<esi>)
{
  int v3; // edx
  float texel_factor; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm1_4
  float v7; // xmm1_4
  vostok::render::streaming_texture_instance *result; // eax

  v3 = (__last - __first) >> 2;
  if ( v3 > 0 )
  {
    texel_factor = __val->texel_factor;
    while ( __first->texel_factor != texel_factor || __first->surface_instance != __val->surface_instance )
    {
      v5 = __first[1].texel_factor;
      ++__first;
      if ( v5 == texel_factor && __first->surface_instance == __val->surface_instance )
        break;
      v6 = __first[1].texel_factor;
      ++__first;
      if ( v6 == texel_factor && __first->surface_instance == __val->surface_instance )
        break;
      v7 = __first[1].texel_factor;
      ++__first;
      if ( v7 == texel_factor && __first->surface_instance == __val->surface_instance )
        break;
      --v3;
      ++__first;
      if ( v3 <= 0 )
        goto LABEL_12;
    }
    return __first;
  }
LABEL_12:
  if ( __last - __first != 1 )
  {
    if ( __last - __first != 2 )
    {
      if ( __last - __first != 3 )
        return __last;
      if ( __first->texel_factor == __val->texel_factor && __first->surface_instance == __val->surface_instance )
        return __first;
      ++__first;
    }
    if ( __first->texel_factor != __val->texel_factor || __first->surface_instance != __val->surface_instance )
    {
      ++__first;
      goto LABEL_21;
    }
    return __first;
  }
LABEL_21:
  if ( __first->texel_factor != __val->texel_factor )
    return __last;
  result = __first;
  if ( __first->surface_instance != __val->surface_instance )
    return __last;
  return result;
}


vostok::ui::typed_handlers *__usercall stlp_std::priv::__find<vostok::ui::typed_handlers *,enum vostok::ui::enum_window_events>@<eax>(
        vostok::ui::typed_handlers *__first@<ecx>,
        vostok::ui::typed_handlers *__last@<esi>,
        const vostok::ui::enum_window_events *__val@<edi>)
{
  int v3; // eax
  int v4; // edx
  vostok::ui::typed_handlers *result; // eax

  v3 = (__last - __first) >> 2;
  if ( v3 > 0 )
  {
    v4 = *__val;
    while ( __first->type != v4 )
    {
      ++__first;
      if ( __first->type == v4 )
        break;
      ++__first;
      if ( __first->type == v4 )
        break;
      ++__first;
      if ( __first->type == v4 )
        break;
      --v3;
      ++__first;
      if ( v3 <= 0 )
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
      if ( __first->type == *__val )
        return result;
      return __last;
    case 2:
      goto LABEL_13;
    case 3:
      if ( __first->type == *__val )
        return __first;
      ++__first;
LABEL_13:
      if ( __first->type != *__val )
      {
        ++__first;
        goto LABEL_15;
      }
      return __first;
  }
  return __last;
}


vostok::animation::mixing::animated_object_holder *__usercall stlp_std::priv::__find<vostok::animation::mixing::animated_object_holder *,void const *>@<eax>(
        vostok::animation::mixing::animated_object_holder *__first@<ecx>,
        vostok::animation::mixing::animated_object_holder *__last@<esi>,
        const void *const *__val@<edi>)
{
  int v3; // eax
  const void *v4; // edx
  vostok::animation::mixing::animated_object_holder *result; // eax

  v3 = (__last - __first) >> 2;
  if ( v3 > 0 )
  {
    v4 = *__val;
    while ( __first->animated_object != v4 )
    {
      ++__first;
      if ( __first->animated_object == v4 )
        break;
      ++__first;
      if ( __first->animated_object == v4 )
        break;
      ++__first;
      if ( __first->animated_object == v4 )
        break;
      --v3;
      ++__first;
      if ( v3 <= 0 )
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
      if ( __first->animated_object == *__val )
        return result;
      return __last;
    case 2:
      goto LABEL_13;
    case 3:
      if ( __first->animated_object == *__val )
        return __first;
      ++__first;
LABEL_13:
      if ( __first->animated_object != *__val )
      {
        ++__first;
        goto LABEL_15;
      }
      return __first;
  }
  return __last;
}


vostok::render::shader_constant_binding *__usercall stlp_std::priv::__find<vostok::render::shader_constant_binding *,vostok::render::shader_constant_binding>@<eax>(
        vostok::render::shader_constant_binding *__first@<ecx>,
        vostok::render::shader_constant_binding *__last@<esi>,
        const vostok::render::shader_constant_binding *__val@<edi>)
{
  int v3; // eax
  vostok::strings::shared::profile *m_object; // edx
  vostok::render::shader_constant_binding *result; // eax

  v3 = (__last - __first) >> 2;
  if ( v3 > 0 )
  {
    m_object = __val->m_name.m_pointer.m_object;
    while ( __first->m_name.m_pointer.m_object != m_object )
    {
      ++__first;
      if ( __first->m_name.m_pointer.m_object == m_object )
        break;
      ++__first;
      if ( __first->m_name.m_pointer.m_object == m_object )
        break;
      ++__first;
      if ( __first->m_name.m_pointer.m_object == m_object )
        break;
      --v3;
      ++__first;
      if ( v3 <= 0 )
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
      if ( __first->m_name.m_pointer.m_object == __val->m_name.m_pointer.m_object )
        return result;
      return __last;
    case 2:
      goto LABEL_13;
    case 3:
      if ( __first->m_name.m_pointer.m_object == __val->m_name.m_pointer.m_object )
        return __first;
      ++__first;
LABEL_13:
      if ( __first->m_name.m_pointer.m_object != __val->m_name.m_pointer.m_object )
      {
        ++__first;
        goto LABEL_15;
      }
      return __first;
  }
  return __last;
}


vostok::fs_new::virtual_path_string *__usercall stlp_std::priv::__find<vostok::fs_new::virtual_path_string *,vostok::fs_new::virtual_path_string>@<eax>(
        vostok::fs_new::virtual_path_string *__first@<eax>,
        vostok::fs_new::virtual_path_string *__last,
        const vostok::fs_new::virtual_path_string *__val)
{
  vostok::fs_new::virtual_path_string *v3; // esi
  int v4; // edi
  bool v5; // zf
  vostok::fs_new::virtual_path_string *result; // eax

  v3 = __first;
  v4 = (__last - __first) >> 2;
  if ( v4 > 0 )
  {
    while ( !vostok::fs_new::path_string_impl::operator==(v3, &__val->vostok::fs_new::path_string_impl) )
    {
      if ( vostok::fs_new::path_string_impl::operator==(++v3, &__val->vostok::fs_new::path_string_impl) )
        break;
      if ( vostok::fs_new::path_string_impl::operator==(++v3, &__val->vostok::fs_new::path_string_impl) )
        break;
      if ( vostok::fs_new::path_string_impl::operator==(++v3, &__val->vostok::fs_new::path_string_impl) )
        break;
      --v4;
      ++v3;
      if ( v4 <= 0 )
        goto LABEL_7;
    }
    return v3;
  }
LABEL_7:
  switch ( __last - v3 )
  {
    case 1:
LABEL_14:
      v5 = vostok::fs_new::path_string_impl::operator==(v3, &__val->vostok::fs_new::path_string_impl) == 0;
      result = v3;
      if ( !v5 )
        return result;
      return __last;
    case 2:
      goto LABEL_12;
    case 3:
      if ( vostok::fs_new::path_string_impl::operator==(v3, &__val->vostok::fs_new::path_string_impl) )
        return v3;
      ++v3;
LABEL_12:
      if ( !vostok::fs_new::path_string_impl::operator==(v3, &__val->vostok::fs_new::path_string_impl) )
      {
        ++v3;
        goto LABEL_14;
      }
      return v3;
  }
  return __last;
}


vostok::fs_new::path_string_impl *__usercall stlp_std::priv::__find<vostok::fixed_string<260> *,vostok::fixed_string<260>>@<eax>(
        vostok::fs_new::path_string_impl *__first@<eax>,
        vostok::fixed_string<260> *__last,
        vostok::fs_new::path_string_impl *__val)
{
  vostok::fs_new::path_string_impl *v3; // esi
  int v4; // edi
  bool v5; // zf
  vostok::fs_new::path_string_impl *result; // eax

  v3 = __first;
  v4 = (((char *)__last - (char *)__first) / 272) >> 2;
  if ( v4 > 0 )
  {
    while ( !vostok::operator==(v3, __val) )
    {
      v3 = (vostok::fs_new::path_string_impl *)((char *)v3 + 272);
      if ( vostok::operator==(v3, __val) )
        break;
      v3 = (vostok::fs_new::path_string_impl *)((char *)v3 + 272);
      if ( vostok::operator==(v3, __val) )
        break;
      v3 = (vostok::fs_new::path_string_impl *)((char *)v3 + 272);
      if ( vostok::operator==(v3, __val) )
        break;
      --v4;
      v3 = (vostok::fs_new::path_string_impl *)((char *)v3 + 272);
      if ( v4 <= 0 )
        goto LABEL_7;
    }
    return v3;
  }
LABEL_7:
  switch ( ((char *)__last - (char *)v3) / 272 )
  {
    case 1:
LABEL_14:
      v5 = vostok::operator==(v3, __val) == 0;
      result = v3;
      if ( !v5 )
        return result;
      return (vostok::fs_new::path_string_impl *)__last;
    case 2:
      goto LABEL_12;
    case 3:
      if ( vostok::operator==(v3, __val) )
        return v3;
      v3 = (vostok::fs_new::path_string_impl *)((char *)v3 + 272);
LABEL_12:
      if ( !vostok::operator==(v3, __val) )
      {
        v3 = (vostok::fs_new::path_string_impl *)((char *)v3 + 272);
        goto LABEL_14;
      }
      return v3;
  }
  return (vostok::fs_new::path_string_impl *)__last;
}


unsigned __int64 *__cdecl stlp_std::priv::__find<unsigned __int64 *,unsigned __int64>(
        unsigned __int64 *__first,
        unsigned __int64 *__last,
        const unsigned __int64 *__val)
{
  int v4; // [esp+18h] [ebp-28h]
  int __trip_count; // [esp+3Ch] [ebp-4h]
  unsigned __int64 *__firsta; // [esp+48h] [ebp+8h]
  unsigned __int64 *__firstb; // [esp+48h] [ebp+8h]
  unsigned __int64 *__firstc; // [esp+48h] [ebp+8h]

  for ( __trip_count = ((char *)__last - (char *)__first) >> 5; __trip_count > 0; --__trip_count )
  {
    if ( *(_DWORD *)__first == *(_DWORD *)__val && *((_DWORD *)__first + 1) == *((_DWORD *)__val + 1) )
      return __first;
    __firsta = __first + 1;
    if ( *(_DWORD *)__firsta == *(_DWORD *)__val && *((_DWORD *)__firsta + 1) == *((_DWORD *)__val + 1) )
      return __firsta;
    __firstb = __firsta + 1;
    if ( *(_DWORD *)__firstb == *(_DWORD *)__val && *((_DWORD *)__firstb + 1) == *((_DWORD *)__val + 1) )
      return __firstb;
    __firstc = __firstb + 1;
    if ( *(_DWORD *)__firstc == *(_DWORD *)__val && *((_DWORD *)__firstc + 1) == *((_DWORD *)__val + 1) )
      return __firstc;
    __first = __firstc + 1;
  }
  v4 = __last - __first;
  if ( v4 != 1 )
  {
    if ( v4 != 2 )
    {
      if ( v4 != 3 )
        return __last;
      if ( *(_DWORD *)__first == *(_DWORD *)__val && *((_DWORD *)__first + 1) == *((_DWORD *)__val + 1) )
        return __first;
      ++__first;
    }
    if ( *(_DWORD *)__first == *(_DWORD *)__val && *((_DWORD *)__first + 1) == *((_DWORD *)__val + 1) )
      return __first;
    ++__first;
  }
  if ( *(_DWORD *)__first == *(_DWORD *)__val && *((_DWORD *)__first + 1) == *((_DWORD *)__val + 1) )
    return __first;
  return __last;
}


const vostok::fs_new::virtual_path_string *__usercall stlp_std::priv::__find<vostok::fs_new::virtual_path_string const *,char const [23]>@<eax>(
        vostok::fs_new::virtual_path_string *__first@<eax>,
        const vostok::fs_new::virtual_path_string *__last)
{
  vostok::fs_new::virtual_path_string *v2; // esi
  int v3; // edi
  bool v4; // zf
  const vostok::fs_new::virtual_path_string *result; // eax

  v2 = __first;
  v3 = (__last - __first) >> 2;
  if ( v3 > 0 )
  {
    while ( !vostok::fs_new::path_string_impl::operator==(v2, "GLOBAL_SHADING_QUALITY") )
    {
      if ( vostok::fs_new::path_string_impl::operator==(++v2, "GLOBAL_SHADING_QUALITY") )
        break;
      if ( vostok::fs_new::path_string_impl::operator==(++v2, "GLOBAL_SHADING_QUALITY") )
        break;
      if ( vostok::fs_new::path_string_impl::operator==(++v2, "GLOBAL_SHADING_QUALITY") )
        break;
      --v3;
      ++v2;
      if ( v3 <= 0 )
        goto LABEL_7;
    }
    return v2;
  }
LABEL_7:
  switch ( __last - v2 )
  {
    case 1:
LABEL_14:
      v4 = !vostok::fs_new::path_string_impl::operator==(v2, "GLOBAL_SHADING_QUALITY");
      result = v2;
      if ( !v4 )
        return result;
      return __last;
    case 2:
      goto LABEL_12;
    case 3:
      if ( vostok::fs_new::path_string_impl::operator==(v2, "GLOBAL_SHADING_QUALITY") )
        return v2;
      ++v2;
LABEL_12:
      if ( !vostok::fs_new::path_string_impl::operator==(v2, "GLOBAL_SHADING_QUALITY") )
      {
        ++v2;
        goto LABEL_14;
      }
      return v2;
  }
  return __last;
}


const vostok::fs_new::virtual_path_string *__usercall stlp_std::priv::__find<vostok::fs_new::virtual_path_string const *,char const [38]>@<eax>(
        vostok::fs_new::virtual_path_string *__first@<eax>,
        const vostok::fs_new::virtual_path_string *__last)
{
  vostok::fs_new::virtual_path_string *v2; // esi
  int v3; // edi
  bool v4; // zf
  const vostok::fs_new::virtual_path_string *result; // eax

  v2 = __first;
  v3 = (__last - __first) >> 2;
  if ( v3 > 0 )
  {
    while ( !vostok::fs_new::path_string_impl::operator==(v2, "GLOBAL_USE_POISSON_DISC_SHADOW_FILTER") )
    {
      if ( vostok::fs_new::path_string_impl::operator==(++v2, "GLOBAL_USE_POISSON_DISC_SHADOW_FILTER") )
        break;
      if ( vostok::fs_new::path_string_impl::operator==(++v2, "GLOBAL_USE_POISSON_DISC_SHADOW_FILTER") )
        break;
      if ( vostok::fs_new::path_string_impl::operator==(++v2, "GLOBAL_USE_POISSON_DISC_SHADOW_FILTER") )
        break;
      --v3;
      ++v2;
      if ( v3 <= 0 )
        goto LABEL_7;
    }
    return v2;
  }
LABEL_7:
  switch ( __last - v2 )
  {
    case 1:
LABEL_14:
      v4 = !vostok::fs_new::path_string_impl::operator==(v2, "GLOBAL_USE_POISSON_DISC_SHADOW_FILTER");
      result = v2;
      if ( !v4 )
        return result;
      return __last;
    case 2:
      goto LABEL_12;
    case 3:
      if ( vostok::fs_new::path_string_impl::operator==(v2, "GLOBAL_USE_POISSON_DISC_SHADOW_FILTER") )
        return v2;
      ++v2;
LABEL_12:
      if ( !vostok::fs_new::path_string_impl::operator==(v2, "GLOBAL_USE_POISSON_DISC_SHADOW_FILTER") )
      {
        ++v2;
        goto LABEL_14;
      }
      return v2;
  }
  return __last;
}


survarium::collision_geometry_subscriber **__cdecl stlp_std::priv::__find<enum survarium::profile_slot_enum const *,enum survarium::profile_slot_enum>(
        survarium::collision_geometry_subscriber **__first,
        survarium::collision_geometry_subscriber **__last,
        survarium::collision_geometry_subscriber **__val)
{
  int v4; // [esp+0h] [ebp-8h]
  int __trip_count; // [esp+4h] [ebp-4h]
  survarium::collision_geometry_subscriber **__firsta; // [esp+10h] [ebp+8h]
  survarium::collision_geometry_subscriber **__firstb; // [esp+10h] [ebp+8h]
  survarium::collision_geometry_subscriber **__firstc; // [esp+10h] [ebp+8h]

  for ( __trip_count = ((char *)__last - (char *)__first) >> 4; __trip_count > 0; --__trip_count )
  {
    if ( *__first == *__val )
      return __first;
    __firsta = __first + 1;
    if ( *__firsta == *__val )
      return __firsta;
    __firstb = __firsta + 1;
    if ( *__firstb == *__val )
      return __firstb;
    __firstc = __firstb + 1;
    if ( *__firstc == *__val )
      return __firstc;
    __first = __firstc + 1;
  }
  v4 = __last - __first;
  if ( v4 != 1 )
  {
    if ( v4 != 2 )
    {
      if ( v4 != 3 )
        return __last;
      if ( *__first == *__val )
        return __first;
      ++__first;
    }
    if ( *__first == *__val )
      return __first;
    ++__first;
  }
  if ( *__first == *__val )
    return __first;
  return __last;
}


const wchar_t *__cdecl stlp_std::priv::__find<wchar_t const *,wchar_t>(
        const wchar_t *__first,
        const wchar_t *__last,
        const wchar_t *__val)
{
  const wchar_t *result; // eax
  int v4; // ecx
  __int16 v5; // dx

  result = __first;
  v4 = ((char *)__last - (char *)__first) >> 3;
  if ( v4 <= 0 )
  {
LABEL_8:
    if ( __last - result != 1 )
    {
      if ( __last - result != 2 )
      {
        if ( __last - result != 3 )
          return __last;
        if ( *result == *__val )
          return result;
        ++result;
      }
      if ( *result == *__val )
        return result;
      ++result;
    }
    if ( *result == *__val )
      return result;
    return __last;
  }
  v5 = *__val;
  while ( *result != v5 )
  {
    if ( *++result == v5 )
      break;
    if ( *++result == v5 )
      break;
    if ( *++result == v5 )
      break;
    --v4;
    ++result;
    if ( v4 <= 0 )
      goto LABEL_8;
  }
  return result;
}
