void __cdecl stlp_std::_Copy_Construct<stlp_std::pair<char const * const,unsigned int>>(
        stlp_std::pair<unsigned int const ,vostok::ai::planning::oracle *> *__p,
        const stlp_std::pair<unsigned int const ,vostok::ai::planning::oracle *> *__val)
{
  stlp_std::pair<unsigned int const ,vostok::ai::planning::oracle *> *v2; // [esp+4h] [ebp-8h]

  v2 = (stlp_std::pair<unsigned int const ,vostok::ai::planning::oracle *> *)operator new(8u, __p);
  if ( v2 )
    *v2 = *__val;
}
