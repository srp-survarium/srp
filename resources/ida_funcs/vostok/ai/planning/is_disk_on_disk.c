BOOL __cdecl vostok::ai::planning::is_disk_on_disk(
        const vostok::ai::planning::disk *const upper_disk,
        const vostok::ai::planning::disk *const lower_disk)
{
  return lower_disk->disk_above == upper_disk;
}
