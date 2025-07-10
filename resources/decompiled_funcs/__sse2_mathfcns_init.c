int __cdecl _sse2_mathfcns_init()
{
  __use_sse2_mathfcns = 0;
  __use_sse2_mathfcns = _get_sse2_info();
  return 0;
}
