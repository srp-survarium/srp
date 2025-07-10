BOOL __thiscall vostok::configs::binary_config_value::operator bool(vostok::configs::binary_config_value *this)
{
  return this->data.pointer != 0;
}
