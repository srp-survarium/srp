const survarium::flash_text *__usercall vostok::make_next_tip@<eax>(
        char *text@<edx>,
        const vostok::vectora<char const *> *v,
        char *tip_index,
        bool b_next,
        vostok::enum_tips_mode mode)
{
  int v6; // eax
  const void **M_start; // eax
  const void **M_finish; // edi
  const void **v9; // esi
  const survarium::flash_text *result; // eax
  int v11; // ecx
  const void **v12; // esi
  const void **v13; // edi
  const void **v14; // esi
  const void **v15; // ecx
  const char *tip; // [esp+18h] [ebp+8h]

  *(_WORD *)tip_index = 0;
  if ( !strlen(text) )
    goto LABEL_6;
  if ( mode == tm_arg_list )
  {
    strchr(text, 0x20u);
    text = (char *)(v6 + 1);
  }
  tip = text;
  if ( b_next )
  {
    M_start = v->_M_impl._M_start;
    M_finish = v->_M_impl._M_finish;
    v9 = v->_M_impl._M_start;
    if ( v->_M_impl._M_start != M_finish )
    {
      while ( 1 )
      {
        v11 = strcmp((const char *)*v9, text);
        ++*(_WORD *)tip_index;
        ++v9;
        if ( !v11 )
          break;
        if ( v9 == M_finish )
          goto LABEL_6;
        text = (char *)tip;
      }
      if ( v9 != M_finish )
        return (const survarium::flash_text *)*v9;
      goto LABEL_23;
    }
LABEL_6:
    M_start = v->_M_impl._M_start;
    if ( v->_M_impl._M_start == v->_M_impl._M_finish )
    {
      *(_WORD *)tip_index = 255;
      return &buf;
    }
LABEL_23:
    result = (const survarium::flash_text *)*M_start;
    *(_WORD *)tip_index = 0;
    return result;
  }
  v12 = v->_M_impl._M_finish;
  v13 = v->_M_impl._M_start;
  *(_WORD *)tip_index = v12 - v->_M_impl._M_start - 1;
  if ( v12 == v13 )
    goto LABEL_6;
  while ( strcmp((const char *)*(v12 - 1), text) )
  {
    --*(_WORD *)tip_index;
    if ( --v12 == v13 )
      goto LABEL_6;
    text = (char *)tip;
  }
  --*(_WORD *)tip_index;
  v14 = v12 - 1;
  if ( v14 != v13 )
    return (const survarium::flash_text *)*(v14 - 1);
  v15 = v->_M_impl._M_finish;
  result = (const survarium::flash_text *)*(v15 - 1);
  *(_WORD *)tip_index = v15 - v13 - 1;
  return result;
}
