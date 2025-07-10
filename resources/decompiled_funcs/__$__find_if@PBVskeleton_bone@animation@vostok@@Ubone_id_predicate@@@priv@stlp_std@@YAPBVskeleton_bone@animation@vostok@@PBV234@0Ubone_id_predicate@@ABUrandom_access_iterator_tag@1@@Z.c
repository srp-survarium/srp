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
