BOOL __usercall is_table@<eax>(const vostok::configs::binary_config_value *value@<eax>)
{
  unsigned __int16 type; // ax

  type = value->type;
  return type == 3 || type == 4;
}
