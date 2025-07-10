void __usercall vostok::render::replace_value_data(
        const vostok::render::custom_config_value *to@<eax>,
        vostok::render::custom_config_value from)
{
  to->type = from.type;
  to->count = from.count;
  to->data = from.data;
}
