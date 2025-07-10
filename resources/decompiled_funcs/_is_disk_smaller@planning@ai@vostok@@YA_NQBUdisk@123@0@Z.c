bool __cdecl vostok::ai::planning::is_disk_smaller(
        const vostok::ai::planning::disk *const disk1,
        const vostok::ai::planning::disk *const disk2)
{
  return disk2->radius > disk1->radius;
}
