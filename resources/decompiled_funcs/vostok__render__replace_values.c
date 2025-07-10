void __usercall vostok::render::replace_values(const char *a1@<edi>, const vostok::render::custom_config_value *in_v)
{
  unsigned __int16 type; // ax
  vostok::render::custom_config_value *v3; // ecx
  const vostok::render::custom_config_value *v4; // eax
  const void *data; // eax
  vostok::render::custom_config_value *v6; // ecx
  const vostok::render::custom_config_value *v7; // eax
  const vostok::render::custom_config_value *i; // edi
  const vostok::render::custom_config_value *j; // edi
  const char *v10; // [esp-4h] [ebp-1Ch]
  __int64 v11; // [esp+4h] [ebp-14h]
  __int64 v12; // [esp+Ch] [ebp-Ch]

  type = in_v->type;
  if ( type == 4 || type == 3 )
  {
    if ( vostok::render::custom_config_value::value_exists(&stru_960860, a1) )
    {
      v4 = vostok::render::custom_config_value::operator[](v3, (const char *)&stru_960860);
      v12 = *(_QWORD *)&v4->id_crc;
      data = v4->data;
      *(_DWORD *)&in_v->type = HIDWORD(v12);
      in_v->data = data;
    }
    else
    {
      for ( i = (const vostok::render::custom_config_value *)in_v->data;
            i != (const vostok::render::custom_config_value *)in_v->data + in_v->count;
            ++i )
      {
        vostok::render::replace_values(i);
      }
    }
    if ( vostok::render::custom_config_value::value_exists(&stru_955964, v10) )
    {
      v7 = vostok::render::custom_config_value::operator[](v6, (const char *)&stru_955964);
      v11 = *(_QWORD *)&v7->id;
      *(_DWORD *)&in_v->type = *(_DWORD *)&v7->type;
      in_v->data = (const void *)HIDWORD(v11);
    }
    else
    {
      for ( j = (const vostok::render::custom_config_value *)in_v->data;
            j != (const vostok::render::custom_config_value *)in_v->data + in_v->count;
            ++j )
      {
        vostok::render::replace_values(j);
      }
    }
  }
}
