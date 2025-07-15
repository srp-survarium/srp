const void *__cdecl vostok::particle::read_config_value<int,vostok::configs::binary_config_value>(
        const vostok::configs::binary_config_value *config_value,
        const vostok::configs::binary_config_value *name)
{
  vostok::configs::binary_config_value *v2; // ecx
  const vostok::configs::binary_config_value *v3; // eax

  if ( vostok::configs::binary_config_value::value_exists(v2, (int)config_value, (unsigned int)"CountVariance") )
    v3 = vostok::configs::binary_config_value::operator[](config_value, "CountVariance");
  else
    v3 = name;
  return v3->data.pointer;
}


int __usercall vostok::particle::read_config_value<float,vostok::configs::binary_config_value>@<xmm0>(
        char *name@<eax>,
        vostok::configs::binary_config_value *a2@<ecx>,
        const vostok::configs::binary_config_value *config_value,
        const vostok::configs::binary_config_value *default_value)
{
  const vostok::configs::binary_config_value *v5; // eax
  int result; // xmm0_4

  if ( vostok::configs::binary_config_value::value_exists(a2, (int)config_value, (unsigned int)name) )
  {
    v5 = vostok::configs::binary_config_value::operator[](config_value, name);
    if ( v5->type != 2 )
    {
      *(float *)&result = (float)(int)v5->data.pointer;
      return result;
    }
  }
  else
  {
    v5 = default_value;
  }
  return (int)v5->data.pointer;
}


const char *__usercall vostok::particle::read_config_value<char const *,vostok::configs::binary_config_value>@<eax>(
        char *name@<eax>,
        vostok::configs::binary_config_value *a2@<ecx>,
        const vostok::configs::binary_config_value *config_value,
        const vostok::configs::binary_config_value *default_value)
{
  const vostok::configs::binary_config_value *v5; // eax

  if ( vostok::configs::binary_config_value::value_exists(a2, (int)config_value, (unsigned int)name) )
    v5 = vostok::configs::binary_config_value::operator[](config_value, name);
  else
    v5 = default_value;
  return (const char *)v5->data.pointer;
}


const vostok::configs::binary_config_value *__usercall vostok::particle::read_config_value<vostok::math::float3,vostok::configs::binary_config_value>@<eax>(
        char *name@<eax>,
        vostok::configs::binary_config_value *a2@<ecx>,
        const vostok::configs::binary_config_value *config_value,
        vostok::configs::binary_config_value *default_value,
        const void **a5)
{
  const void **pointer; // esi
  const void **v7; // esi

  if ( vostok::configs::binary_config_value::value_exists(a2, (int)default_value, (unsigned int)name) )
    pointer = (const void **)vostok::configs::binary_config_value::operator[](default_value, name)->data.pointer;
  else
    pointer = a5;
  config_value->data.pointer = *pointer;
  v7 = pointer + 1;
  HIDWORD(config_value->data.max_storage) = *v7;
  config_value->id.pointer = (const char *)v7[1];
  return config_value;
}


bool __usercall vostok::particle::read_config_value<bool,vostok::configs::binary_config_value>@<al>(
        char *name@<eax>,
        vostok::configs::binary_config_value *a2@<ecx>,
        const vostok::configs::binary_config_value *config_value,
        const bool *default_value)
{
  if ( vostok::configs::binary_config_value::value_exists(a2, (int)config_value, (unsigned int)name) )
    return vostok::configs::binary_config_value::operator[](config_value, name)->data.pointer != 0;
  else
    return *default_value;
}
