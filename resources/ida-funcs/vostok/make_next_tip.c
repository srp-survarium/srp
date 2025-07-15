const char *__usercall vostok::make_next_tip@<eax>(
        const vostok::vectora<char const *> *v@<eax>,
        unsigned __int16 *tip_index@<esi>,
        char *text,
        bool b_next,
        vostok::enum_tips_mode mode)
{
  int v6; // eax
  const void **M_start; // ebx
  int v8; // eax
  const void **v9; // eax
  const char *result; // eax
  const void **v11; // ebx
  const void **v12; // eax
  const void **v13; // eax
  const void **v14; // ebx
  const void **v15; // edi
  int v16; // ecx
  const void **v17; // [esp+8h] [ebp-Ch]
  const void **M_finish; // [esp+Ch] [ebp-8h]
  char *right; // [esp+10h] [ebp-4h]

  *tip_index = 0;
  if ( !strlen(text) )
    goto LABEL_9;
  if ( mode == tm_arg_list )
  {
    strchr(text, 0x20u);
    right = (char *)(v6 + 1);
  }
  else
  {
    right = text;
  }
  if ( b_next )
  {
    M_start = v->_M_impl._M_start;
    M_finish = v->_M_impl._M_finish;
    if ( v->_M_impl._M_start != M_finish )
    {
      while ( 1 )
      {
        v8 = vostok::strings::compare((const char *)*M_start++, right);
        ++*tip_index;
        if ( !v8 )
          break;
        if ( M_start == M_finish )
          goto LABEL_9;
      }
      if ( M_start != M_finish )
        return (const char *)*M_start;
      *tip_index = 0;
      v9 = v->_M_impl._M_start;
      return (const char *)*v9;
    }
LABEL_9:
    v9 = v->_M_impl._M_start;
    if ( v->_M_impl._M_start == v->_M_impl._M_finish )
    {
      *tip_index = 255;
      return uri;
    }
    *tip_index = 0;
    return (const char *)*v9;
  }
  v11 = v->_M_impl._M_finish;
  v12 = v->_M_impl._M_start;
  *tip_index = v11 - v->_M_impl._M_start - 1;
  if ( v11 == v12 )
    goto LABEL_9;
  while ( 1 )
  {
    v17 = v11 - 1;
    if ( !vostok::strings::compare((const char *)*(v11 - 1), right) )
      break;
    --v11;
    --*tip_index;
    if ( v17 == v->_M_impl._M_start )
      goto LABEL_9;
  }
  --*tip_index;
  v13 = v->_M_impl._M_start;
  v14 = v11 - 1;
  if ( v14 != v->_M_impl._M_start )
    return (const char *)*(v14 - 1);
  v15 = v->_M_impl._M_finish;
  v16 = (char *)v15 - (char *)v13;
  result = (const char *)*(v15 - 1);
  *tip_index = (v16 >> 2) - 1;
  return result;
}
