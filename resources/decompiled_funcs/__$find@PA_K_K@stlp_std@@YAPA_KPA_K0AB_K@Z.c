unsigned __int64 *__cdecl stlp_std::find<unsigned __int64 *,unsigned __int64>(
        unsigned __int64 *__first,
        unsigned __int64 *__last,
        const unsigned __int64 *__val)
{
  stlp_std::random_access_iterator_tag __formal; // [esp+7h] [ebp-1h] BYREF

  return stlp_std::priv::__find<unsigned __int64 *,unsigned __int64>(__first, __last, __val, &__formal);
}
