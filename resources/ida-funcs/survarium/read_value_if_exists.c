float __usercall survarium::read_value_if_exists<float>@<xmm0>(
        char *value_name@<eax>,
        vostok::configs::binary_config_value *a2@<ecx>,
        const vostok::configs::binary_config_value *cfg,
        float default_value)
{
  const vostok::configs::binary_config_value *v5; // eax

  if ( !vostok::configs::binary_config_value::value_exists(a2, (int)cfg, (unsigned int)value_name) )
    return default_value;
  v5 = vostok::configs::binary_config_value::operator[](cfg, value_name);
  if ( v5->type == 2 )
    return *(float *)&v5->data.pointer;
  else
    return (float)(int)v5->data.pointer;
}
