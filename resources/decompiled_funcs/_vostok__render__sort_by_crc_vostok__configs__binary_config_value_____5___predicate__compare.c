BOOL __cdecl vostok::render::sort_by_crc_vostok::configs::binary_config_value__::_5_::predicate::compare(
        const vostok::configs::binary_config_value *left,
        const vostok::configs::binary_config_value *right)
{
  return left->id_crc < right->id_crc;
}
