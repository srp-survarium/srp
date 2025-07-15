const vostok::configs::binary_config_value *__thiscall vostok::configs::binary_config_value::end(
        vostok::configs::binary_config_value *this)
{
  return (const vostok::configs::binary_config_value *)((char *)this->data.pointer + 24 * this->count);
}
