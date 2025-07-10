void __cdecl stlp_std::_Destroy<stlp_std::pair<unsigned int const,survarium::dictionary_item>>(
        stlp_std::pair<unsigned int const ,survarium::dictionary_item> *__pointer)
{
  survarium::dictionary_item::~dictionary_item(&__pointer->second);
}
