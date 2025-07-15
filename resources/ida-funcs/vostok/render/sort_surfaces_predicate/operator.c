bool __userpurge vostok::render::sort_surfaces_predicate::operator()@<al>(
        const vostok::render::sort_surfaces_predicate_entry *right@<edi>,
        vostok::render::sort_surfaces_predicate *this,
        const vostok::render::sort_surfaces_predicate_entry *left)
{
  float v3; // xmm2_4
  bool result; // al
  float distance; // xmm1_4
  bool v6; // cc
  vostok::render::sort_surfaces_predicate v7; // al
  unsigned __int8 alpha_test; // cl
  vostok::render::sort_surfaces_predicate v9; // al
  unsigned __int8 two_sided; // cl
  unsigned int v11; // eax
  const void *vs; // ecx
  unsigned int v13; // eax
  const void *ps; // ecx
  int v15; // eax

  if ( s_by_dist )
    goto LABEL_23;
  if ( s_sort2 )
  {
    v3 = *(float *)&this[16];
    if ( v3 <= 3.0 && right->distance > 3.0 )
      return 1;
    if ( v3 >= 3.0 && right->distance < 3.0 )
      return 0;
    if ( v3 < 3.0 )
    {
      distance = right->distance;
      if ( distance < 3.0 )
      {
        result = 0;
        v6 = distance <= v3;
        goto LABEL_24;
      }
    }
  }
  if ( s_sort0 )
  {
    v7 = this[21];
    alpha_test = right->alpha_test;
    if ( *(unsigned __int8 *)&v7 >= alpha_test )
    {
      if ( *(unsigned __int8 *)&v7 > alpha_test )
        return 0;
      v9 = this[20];
      two_sided = right->two_sided;
      if ( *(unsigned __int8 *)&v9 <= two_sided )
      {
        if ( *(unsigned __int8 *)&v9 < two_sided )
          return 0;
        v11 = *(_DWORD *)&this[8];
        vs = right->vs;
        if ( v11 >= (unsigned int)vs )
        {
          if ( v11 <= (unsigned int)vs )
            goto LABEL_19;
          return 0;
        }
      }
    }
    return 1;
  }
LABEL_19:
  v13 = *(_DWORD *)&this[12];
  ps = right->ps;
  if ( v13 < (unsigned int)ps )
    return 1;
  if ( v13 > (unsigned int)ps )
    return 0;
  v15 = vostok::render::res_texture_list::compare(
          *(vostok::render::res_buffer_list **)(*(_DWORD *)this + 12),
          (const vostok::render::res_buffer_list *)right->ps_ref.m_object->m_textures.m_object);
  if ( v15 < 0 )
    return 1;
  if ( v15 > 0 )
    return 0;
LABEL_23:
  result = 0;
  v6 = right->distance <= *(float *)&this[16];
LABEL_24:
  if ( !v6 )
    return 1;
  return result;
}
