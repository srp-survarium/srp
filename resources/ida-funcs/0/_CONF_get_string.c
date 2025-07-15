char *__cdecl _CONF_get_string(const conf_st *conf, char *section, char *name)
{
  char *result; // eax
  void **v4; // eax
  lhash_st *v5; // [esp-10h] [ebp-20h]
  lhash_st *v6; // [esp-10h] [ebp-20h]
  char *data; // [esp+4h] [ebp-Ch] BYREF
  char *v8; // [esp+8h] [ebp-8h]

  if ( !name )
    return 0;
  if ( !conf )
    return getenv(0, (unsigned int)name, name);
  if ( !section )
    goto LABEL_8;
  v5 = (lhash_st *)conf->data;
  v8 = name;
  data = section;
  v4 = lh_retrieve(v5, &data);
  if ( v4 )
    return (char *)v4[2];
  if ( strcmp(section, "ENV") || (result = getenv((unsigned int)conf, (unsigned int)name, name)) == 0 )
  {
LABEL_8:
    v6 = (lhash_st *)conf->data;
    data = &::result.m_buffer[40];
    v8 = name;
    v4 = lh_retrieve(v6, &data);
    if ( !v4 )
      return 0;
    return (char *)v4[2];
  }
  return result;
}
