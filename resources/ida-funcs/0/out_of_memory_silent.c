char __stdcall out_of_memory_silent(void *const space, const void *parameter, int first_time)
{
  if ( first_time )
    return 0;
  vostok::memory::dump_statistics(0);
  return 1;
}
