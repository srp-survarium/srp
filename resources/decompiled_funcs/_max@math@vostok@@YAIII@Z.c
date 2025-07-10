unsigned int __cdecl vostok::math::max(unsigned int left, unsigned int right)
{
  return left - (left < right ? left - right : 0);
}
