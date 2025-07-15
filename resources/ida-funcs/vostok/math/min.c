unsigned __int64 __cdecl vostok::math::min(unsigned __int64 left, unsigned __int64 right)
{
  return right + (left < right ? left - right : 0);
}
