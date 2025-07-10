unsigned int __fastcall vostok::math::min(unsigned int left, unsigned int right)
{
  return right + (left < right ? left - right : 0);
}
