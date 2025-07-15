bool __cdecl vostok::ai::planning::is_peg_clear(const vostok::ai::planning::peg *const parameter)
{
  return parameter->lower_disk == 0;
}
