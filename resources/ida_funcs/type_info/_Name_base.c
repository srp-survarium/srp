const char *__cdecl type_info::_Name_base(const type_info *_This, __type_info_node *__ptype_info_node)
{
  unsigned __int8 *v2; // eax
  int v4; // eax
  int i; // esi
  __type_info_node *v6; // ebx
  unsigned int v7; // esi
  void *v8; // eax
  char *pTmpUndName; // [esp+10h] [ebp-1Ch]

  if ( !_This->_m_data )
  {
    v2 = (unsigned __int8 *)__unDName(0, &_This->_m_d_name[1], 0, malloc, free, 0x2800u);
    pTmpUndName = (char *)v2;
    if ( !v2 )
      return 0;
    strlen(v2);
    for ( i = v4; i; pTmpUndName[i] = 0 )
    {
      if ( pTmpUndName[--i] != 32 )
        goto LABEL_9;
    }
    i = -1;
LABEL_9:
    _lock(14);
    if ( !_This->_m_data )
    {
      v6 = (__type_info_node *)malloc(8u);
      if ( v6 )
      {
        v7 = i + 2;
        v8 = malloc(v7);
        _This->_m_data = v8;
        if ( v8 )
        {
          if ( strcpy_s((char *)v8, v7, pTmpUndName) )
            _invoke_watson((unsigned int)v6, (unsigned int)_This, v7);
          v6->memPtr = _This->_m_data;
          v6->next = __ptype_info_node->next;
          __ptype_info_node->next = v6;
        }
        else
        {
          free(v6);
        }
      }
    }
    free(pTmpUndName);
    _unlock(14);
  }
  return (const char *)_This->_m_data;
}
