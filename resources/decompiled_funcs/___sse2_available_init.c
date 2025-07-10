int __sse2_available_init()
{
  __sse2_available = _get_sse2_info();
  return 0;
}
