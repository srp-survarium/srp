BOOL __cdecl vostok::ai::planning::is_disk_on_peg(
        const vostok::ai::planning::disk *const disk_to_check,
        const vostok::ai::planning::peg *const some_peg)
{
  return some_peg->lower_disk == disk_to_check;
}
