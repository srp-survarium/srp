int __cdecl vostok::math::max(int left, int right)
{
  return left - (left < right ? left - right : 0);
}
