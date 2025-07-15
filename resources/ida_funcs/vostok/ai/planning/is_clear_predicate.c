bool __cdecl vostok::ai::planning::is_clear_predicate(const vostok::ai::planning::block *const parameter)
{
  return parameter->block_above == 0;
}
