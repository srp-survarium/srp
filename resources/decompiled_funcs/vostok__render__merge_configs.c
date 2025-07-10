void __usercall vostok::render::merge_configs(
        const char *a1@<ebx>,
        const char *a2@<edi>,
        const vostok::render::custom_config_value **current,
        const vostok::render::custom_config_value **values,
        const vostok::render::custom_config_value *base,
        const vostok::render::custom_config_value *replace)
{
  const vostok::render::custom_config_value *v6; // ebp
  unsigned __int16 type; // ax
  int v8; // eax
  int v9; // esi
  const vostok::render::custom_config_value *v10; // eax
  _QWORD *i; // ebx
  int v12; // eax
  const vostok::render::custom_config_value *j; // esi
  vostok::render::custom_config_value *v14; // ecx
  const char *v15; // [esp-Ch] [ebp-10h]
  const vostok::render::custom_config_value *v16; // [esp-Ch] [ebp-10h]
  const char *v17; // [esp-8h] [ebp-Ch]

  v6 = base;
  type = base->type;
  if ( type == 3 || type == 4 )
  {
    v9 = (int)*current;
    *(_QWORD *)v9 = *(_QWORD *)&base->id;
    *(_QWORD *)(v9 + 8) = *(_QWORD *)&v6->id_crc;
    *(_DWORD *)(v9 + 16) = v6->destroyer;
    *(_WORD *)(v9 + 14) = (__int16)(20 * v6->count) / 20;
    v17 = a2;
    *(_DWORD *)(v9 + 4) = *values;
    base = *values;
    v10 = replace;
    *values = &base[*(unsigned __int16 *)(v9 + 14)];
    if ( v10 )
    {
      v15 = a1;
      for ( i = v10->data; i != (_QWORD *)((char *)v10->data + 20 * v10->count); i = (_QWORD *)((char *)i + 20) )
      {
        if ( !vostok::render::custom_config_value::value_exists(*(vostok::render::custom_config_value **)i, v15) )
        {
          ++*(_WORD *)(v9 + 14);
          v12 = (int)*values;
          *(_QWORD *)v12 = *i;
          *(_QWORD *)(v12 + 8) = i[1];
          *(_DWORD *)(v12 + 16) = *((_DWORD *)i + 4);
          ++*values;
        }
        v10 = replace;
      }
    }
    for ( j = (const vostok::render::custom_config_value *)v6->data;
          j != (const vostok::render::custom_config_value *)v6->data + v6->count;
          ++j )
    {
      if ( v10 && vostok::render::custom_config_value::value_exists((vostok::render::custom_config_value *)j->id, v17) )
      {
        v16 = vostok::render::custom_config_value::operator[](v14, j->id);
        vostok::render::merge_configs(&base, values, j, v16);
      }
      else
      {
        vostok::render::merge_configs(&base, values, j, 0);
      }
      ++base;
      v10 = replace;
    }
  }
  else
  {
    v8 = (int)*current;
    *(_QWORD *)v8 = *(_QWORD *)&base->id;
    *(_QWORD *)(v8 + 8) = *(_QWORD *)&v6->id_crc;
    *(_DWORD *)(v8 + 16) = v6->destroyer;
  }
}
