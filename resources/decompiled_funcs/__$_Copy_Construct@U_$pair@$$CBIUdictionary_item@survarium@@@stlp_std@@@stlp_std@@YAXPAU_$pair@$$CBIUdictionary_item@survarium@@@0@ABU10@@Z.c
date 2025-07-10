void __cdecl stlp_std::_Copy_Construct<stlp_std::pair<unsigned int const,survarium::dictionary_item>>(
        stlp_std::pair<unsigned int const ,survarium::dictionary_item> *__p,
        const stlp_std::pair<unsigned int const ,survarium::dictionary_item> *__val)
{
  char *v2; // [esp+28h] [ebp-8h]

  v2 = (char *)operator new(0x124u, __p);
  if ( v2 )
  {
    *(_DWORD *)v2 = __val->first;
    survarium::dictionary_item::dictionary_item((survarium::dictionary_item *)(v2 + 4), &__val->second);
  }
}
