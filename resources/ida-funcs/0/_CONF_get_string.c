char *__cdecl _CONF_get_string(const conf_st *conf, const char *section, char *name)
{
  char *result; // eax
  void ***v4; // eax
  lhash_st *data; // [esp-10h] [ebp-20h]
  lhash_st *v6; // [esp-10h] [ebp-20h]
  const char *v7; // [esp+4h] [ebp-Ch] BYREF
  char *v8; // [esp+8h] [ebp-8h]

  if ( !name )
    return 0;
  if ( !conf )
    return getenv(0, (int)name, name);
  if ( !section )
    goto LABEL_8;
  data = (lhash_st *)conf->data;
  v8 = name;
  v7 = section;
  v4 = lh_retrieve(data, &v7);
  if ( v4 )
    return (char *)v4[2];
  if ( strcmp(section, "ENV") || (result = getenv((int)conf, (int)name, name)) == 0 )
  {
LABEL_8:
    v6 = (lhash_st *)conf->data;
    v7 = "default";
    v8 = name;
    v4 = lh_retrieve(v6, &v7);
    if ( !v4 )
      return 0;
    return (char *)v4[2];
  }
  return result;
}
