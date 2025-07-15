unsigned __int64 __cdecl vostok::math::align_down<unsigned __int64>(unsigned __int64 value, unsigned __int64 align_on)
{
  return value - value % align_on;
}
