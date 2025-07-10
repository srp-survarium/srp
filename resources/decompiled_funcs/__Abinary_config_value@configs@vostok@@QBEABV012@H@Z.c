const vostok::configs::binary_config_value *__usercall vostok::configs::binary_config_value::operator[]@<eax>(
        vostok::configs::binary_config_value *this@<ecx>,
        const int index@<eax>)
{
  return (const vostok::configs::binary_config_value *)((char *)this->data.pointer + 24 * index);
}
