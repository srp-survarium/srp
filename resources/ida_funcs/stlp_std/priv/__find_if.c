vostok::physics::base_physics_object **__cdecl stlp_std::priv::__find_if<vostok::physics::base_physics_object * *,bool (__cdecl *)(vostok::physics::base_physics_object *)>(
        vostok::physics::base_physics_object **__first,
        vostok::physics::base_physics_object **__last,
        bool (__cdecl *__pred)(vostok::physics::base_physics_object *))
{
  int v4; // [esp+0h] [ebp-8h]
  int __trip_count; // [esp+4h] [ebp-4h]
  vostok::physics::base_physics_object **__firsta; // [esp+10h] [ebp+8h]
  vostok::physics::base_physics_object **__firstb; // [esp+10h] [ebp+8h]
  vostok::physics::base_physics_object **__firstc; // [esp+10h] [ebp+8h]

  for ( __trip_count = ((char *)__last - (char *)__first) >> 4; __trip_count > 0; --__trip_count )
  {
    if ( __pred(*__first) )
      return __first;
    __firsta = __first + 1;
    if ( __pred(*__firsta) )
      return __firsta;
    __firstb = __firsta + 1;
    if ( __pred(*__firstb) )
      return __firstb;
    __firstc = __firstb + 1;
    if ( __pred(*__firstc) )
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
      if ( __pred(*__first) )
        return __first;
      ++__first;
    }
    if ( __pred(*__first) )
      return __first;
    ++__first;
  }
  if ( __pred(*__first) )
    return __first;
  return __last;
}


survarium::bullet **__cdecl stlp_std::priv::__find_if<survarium::bullet * *,survarium::redundant_bullet_predicate>(
        survarium::bullet **__first,
        survarium::bullet **__last,
        survarium::redundant_bullet_predicate __pred)
{
  int v4; // [esp+0h] [ebp-5Ch]
  int __trip_count; // [esp+58h] [ebp-4h]
  survarium::bullet **__firsta; // [esp+64h] [ebp+8h]
  survarium::bullet **__firstb; // [esp+64h] [ebp+8h]
  survarium::bullet **__firstc; // [esp+64h] [ebp+8h]

  for ( __trip_count = ((char *)__last - (char *)__first) >> 4; __trip_count > 0; --__trip_count )
  {
    if ( survarium::redundant_bullet_predicate::operator()(&__pred, *__first) )
      return __first;
    __firsta = __first + 1;
    if ( survarium::redundant_bullet_predicate::operator()(&__pred, *__firsta) )
      return __firsta;
    __firstb = __firsta + 1;
    if ( survarium::redundant_bullet_predicate::operator()(&__pred, *__firstb) )
      return __firstb;
    __firstc = __firstb + 1;
    if ( survarium::redundant_bullet_predicate::operator()(&__pred, *__firstc) )
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
      if ( survarium::redundant_bullet_predicate::operator()(&__pred, *__first) )
        return __first;
      ++__first;
    }
    if ( survarium::redundant_bullet_predicate::operator()(&__pred, *__first) )
      return __first;
    ++__first;
  }
  if ( survarium::redundant_bullet_predicate::operator()(&__pred, *__first) )
    return __first;
  return __last;
}


const char **__usercall stlp_std::priv::__find_if<char const * *,vostok::compare_pcstr_pred>@<eax>(
        const char **__first@<eax>,
        const char **__last,
        vostok::compare_pcstr_pred __pred)
{
  int v3; // esi
  const char *v4; // edx
  const char *v5; // edx
  const char *v6; // edx

  v3 = ((char *)__last - (char *)__first) >> 4;
  if ( v3 <= 0 )
  {
LABEL_7:
    if ( __last - __first != 1 )
    {
      if ( __last - __first != 2 )
      {
        if ( __last - __first != 3 )
          return __last;
        if ( !strcmp(__pred.str, *__first) )
          return __first;
        ++__first;
      }
      if ( !strcmp(__pred.str, *__first) )
        return __first;
      ++__first;
    }
    if ( !strcmp(__pred.str, *__first) )
      return __first;
    return __last;
  }
  while ( strcmp(__pred.str, *__first) )
  {
    v4 = __first[1];
    ++__first;
    if ( !strcmp(__pred.str, v4) )
      break;
    v5 = __first[1];
    ++__first;
    if ( !strcmp(__pred.str, v5) )
      break;
    v6 = __first[1];
    ++__first;
    if ( !strcmp(__pred.str, v6) )
      break;
    --v3;
    ++__first;
    if ( v3 <= 0 )
      goto LABEL_7;
  }
  return __first;
}


vostok::logging::initiator_filter *__cdecl stlp_std::priv::__find_if<vostok::logging::initiator_filter *,vostok::logging::filter_name_eq>(
        vostok::logging::initiator_filter *__first,
        vostok::logging::initiator_filter *__last,
        vostok::logging::filter_name_eq __pred)
{
  int v4; // [esp+0h] [ebp-14h]
  int __trip_count; // [esp+10h] [ebp-4h]
  vostok::logging::initiator_filter *__firsta; // [esp+1Ch] [ebp+8h]
  vostok::logging::initiator_filter *__firstb; // [esp+1Ch] [ebp+8h]
  vostok::logging::initiator_filter *__firstc; // [esp+1Ch] [ebp+8h]

  for ( __trip_count = (__last - __first) >> 2; __trip_count > 0; --__trip_count )
  {
    if ( vostok::operator==(&__first->initiator, __pred.name) )
      return __first;
    __firsta = __first + 1;
    if ( vostok::operator==(&__firsta->initiator, __pred.name) )
      return __firsta;
    __firstb = __firsta + 1;
    if ( vostok::operator==(&__firstb->initiator, __pred.name) )
      return __firstb;
    __firstc = __firstb + 1;
    if ( vostok::operator==(&__firstc->initiator, __pred.name) )
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
      if ( vostok::operator==(&__first->initiator, __pred.name) )
        return __first;
      ++__first;
    }
    if ( vostok::operator==(&__first->initiator, __pred.name) )
      return __first;
    ++__first;
  }
  if ( vostok::operator==(&__first->initiator, __pred.name) )
    return __first;
  return __last;
}


const char *__cdecl stlp_std::priv::__find_if<char const *,stlp_std::_Ctype_not_mask>(
        const char *__first,
        const char *__last,
        stlp_std::_Ctype_not_mask __pred)
{
  const char *result; // eax
  int v4; // ecx
  int v5; // ebx
  int v6; // ebx
  int v7; // ebx

  result = __first;
  v4 = (__last - __first) >> 2;
  if ( v4 <= 0 )
  {
LABEL_7:
    if ( __last - result != 1 )
    {
      if ( __last - result != 2 )
      {
        if ( __last - result != 3 )
          return __last;
        if ( (__pred._Mask & __pred._M_table[*(unsigned __int8 *)result]) == 0 )
          return result;
        ++result;
      }
      if ( (__pred._Mask & __pred._M_table[*(unsigned __int8 *)result]) == 0 )
        return result;
      ++result;
    }
    if ( (__pred._Mask & __pred._M_table[*(unsigned __int8 *)result]) == 0 )
      return result;
    return __last;
  }
  while ( (__pred._Mask & __pred._M_table[*(unsigned __int8 *)result]) != 0 )
  {
    v5 = *(unsigned __int8 *)++result;
    if ( (__pred._Mask & __pred._M_table[v5]) == 0 )
      break;
    v6 = *(unsigned __int8 *)++result;
    if ( (__pred._Mask & __pred._M_table[v6]) == 0 )
      break;
    v7 = *(unsigned __int8 *)++result;
    if ( (__pred._Mask & __pred._M_table[v7]) == 0 )
      break;
    --v4;
    ++result;
    if ( v4 <= 0 )
      goto LABEL_7;
  }
  return result;
}


const vostok::animation::event_channel *__usercall stlp_std::priv::__find_if<vostok::animation::event_channel const *,vostok::animation::find_predicate>@<eax>(
        const vostok::animation::event_channel *__first@<eax>,
        const vostok::animation::event_channel *__last,
        vostok::animation::find_predicate __pred)
{
  const vostok::animation::event_channel *v3; // esi
  int v4; // edi
  const vostok::animation::event_channel *result; // eax
  bool v6; // zf

  v3 = __first;
  v4 = (__last - __first) >> 2;
  if ( v4 > 0 )
  {
    while ( strcmp(v3->m_name, __pred.m_name) )
    {
      ++v3;
      if ( !strcmp(v3->m_name, __pred.m_name) )
        break;
      ++v3;
      if ( !strcmp(v3->m_name, __pred.m_name) )
        break;
      ++v3;
      if ( !strcmp(v3->m_name, __pred.m_name) )
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
LABEL_16:
      v6 = strcmp(v3->m_name, __pred.m_name) == 0;
      result = v3;
      if ( v6 )
        return result;
      return __last;
    case 2:
      goto LABEL_14;
    case 3:
      if ( !strcmp(v3->m_name, __pred.m_name) )
        return v3;
      ++v3;
LABEL_14:
      if ( strcmp(v3->m_name, __pred.m_name) )
      {
        ++v3;
        goto LABEL_16;
      }
      return v3;
  }
  return __last;
}


const vostok::animation::skeleton_bone *__usercall stlp_std::priv::__find_if<vostok::animation::skeleton_bone const *,bone_id_predicate>@<eax>(
        const vostok::animation::skeleton_bone *__first@<eax>,
        const vostok::animation::skeleton_bone *__last,
        bone_id_predicate __pred)
{
  const vostok::animation::skeleton_bone *v3; // esi
  int v4; // edi
  const char *m_id; // eax
  const char *v6; // eax
  const char *v7; // eax
  const vostok::animation::skeleton_bone *result; // eax
  bool v9; // zf

  v3 = __first;
  v4 = (__last - __first) >> 2;
  if ( v4 > 0 )
  {
    while ( strcmp(v3->m_id, __pred.m_bone_name) )
    {
      m_id = v3[1].m_id;
      ++v3;
      if ( !strcmp(m_id, __pred.m_bone_name) )
        break;
      v6 = v3[1].m_id;
      ++v3;
      if ( !strcmp(v6, __pred.m_bone_name) )
        break;
      v7 = v3[1].m_id;
      ++v3;
      if ( !strcmp(v7, __pred.m_bone_name) )
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
LABEL_16:
      v9 = strcmp(v3->m_id, __pred.m_bone_name) == 0;
      result = v3;
      if ( v9 )
        return result;
      return __last;
    case 2:
      goto LABEL_14;
    case 3:
      if ( !strcmp(v3->m_id, __pred.m_bone_name) )
        return v3;
      ++v3;
LABEL_14:
      if ( strcmp(v3->m_id, __pred.m_bone_name) )
      {
        ++v3;
        goto LABEL_16;
      }
      return v3;
  }
  return __last;
}


const wchar_t *__cdecl stlp_std::priv::__find_if<wchar_t const *,stlp_std::_Ctype_w_is_mask>(
        const wchar_t *__first,
        const wchar_t *__last,
        stlp_std::_Ctype_w_is_mask __pred)
{
  const wchar_t *result; // eax
  int v4; // ecx
  wchar_t v5; // dx
  wchar_t v6; // dx
  wchar_t v7; // dx

  result = __first;
  v4 = ((char *)__last - (char *)__first) >> 3;
  if ( v4 <= 0 )
  {
LABEL_11:
    if ( __last - result != 1 )
    {
      if ( __last - result != 2 )
      {
        if ( __last - result != 3 )
          return __last;
        if ( *result < 0x100u && (__pred.M & __pred.table[*result]) != 0 )
          return result;
        ++result;
      }
      if ( *result < 0x100u && (__pred.M & __pred.table[*result]) != 0 )
        return result;
      ++result;
    }
    if ( *result < 0x100u && (__pred.M & __pred.table[*result]) != 0 )
      return result;
    return __last;
  }
  while ( *result >= 0x100u || (__pred.M & __pred.table[*result]) == 0 )
  {
    v5 = result[1];
    ++result;
    if ( v5 < 0x100u && (__pred.M & __pred.table[v5]) != 0 )
      break;
    v6 = result[1];
    ++result;
    if ( v6 < 0x100u && (__pred.M & __pred.table[v6]) != 0 )
      break;
    v7 = result[1];
    ++result;
    if ( v7 < 0x100u && (__pred.M & __pred.table[v7]) != 0 )
      break;
    --v4;
    ++result;
    if ( v4 <= 0 )
      goto LABEL_11;
  }
  return result;
}


const wchar_t *__cdecl stlp_std::priv::__find_if<wchar_t const *,stlp_std::unary_negate<stlp_std::_Ctype_w_is_mask>>(
        const wchar_t *__first,
        const wchar_t *__last,
        stlp_std::unary_negate<stlp_std::_Ctype_w_is_mask> __pred)
{
  const wchar_t *result; // eax
  int v4; // ecx
  wchar_t v5; // dx
  wchar_t v6; // dx
  wchar_t v7; // dx

  result = __first;
  v4 = ((char *)__last - (char *)__first) >> 3;
  if ( v4 <= 0 )
  {
LABEL_11:
    if ( __last - result != 1 )
    {
      if ( __last - result != 2 )
      {
        if ( __last - result != 3 )
          return __last;
        if ( *result >= 0x100u || (__pred._M_pred.M & __pred._M_pred.table[*result]) == 0 )
          return result;
        ++result;
      }
      if ( *result >= 0x100u || (__pred._M_pred.M & __pred._M_pred.table[*result]) == 0 )
        return result;
      ++result;
    }
    if ( *result >= 0x100u || (__pred._M_pred.M & __pred._M_pred.table[*result]) == 0 )
      return result;
    return __last;
  }
  while ( *result < 0x100u )
  {
    if ( (__pred._M_pred.M & __pred._M_pred.table[*result]) == 0 )
      break;
    v5 = result[1];
    ++result;
    if ( v5 >= 0x100u )
      break;
    if ( (__pred._M_pred.M & __pred._M_pred.table[v5]) == 0 )
      break;
    v6 = result[1];
    ++result;
    if ( v6 >= 0x100u )
      break;
    if ( (__pred._M_pred.M & __pred._M_pred.table[v6]) == 0 )
      break;
    v7 = result[1];
    ++result;
    if ( v7 >= 0x100u || (__pred._M_pred.M & __pred._M_pred.table[v7]) == 0 )
      break;
    --v4;
    ++result;
    if ( v4 <= 0 )
      goto LABEL_11;
  }
  return result;
}
