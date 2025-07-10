unsigned __int64 __cdecl vostok::math::max(unsigned __int64 left, unsigned __int64 right)
{
  return left - (left < right ? left - right : 0);
}
