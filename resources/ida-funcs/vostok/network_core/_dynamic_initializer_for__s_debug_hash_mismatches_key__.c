void __thiscall vostok::network_core::_dynamic_initializer_for__s_debug_hash_mismatches_key__(
        vostok::command_line::key *this)
{
  vostok::command_line::key::key(
    this,
    &s_debug_hash_mismatches_key,
    "debug_hash_mismatch",
    uri,
    "application",
    "turn debug hash mismatches on - may severely affect application performance!",
    uri);
}
