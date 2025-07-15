stlp_std::priv::_List_node<unsigned int> *__thiscall stlp_std::priv::_Impl_list<unsigned int,vostok::ai::std_allocator<unsigned int>>::_M_create_node(
        stlp_std::priv::_Impl_list<unsigned int,vostok::ai::std_allocator<unsigned int> > *this,
        unsigned int *__x)
{
  const unsigned int *v2; // eax
  unsigned int __a; // [esp+8h] [ebp-10h] BYREF
  unsigned int __b; // [esp+10h] [ebp-8h] BYREF
  stlp_std::priv::_List_node<unsigned int> *__p; // [esp+14h] [ebp-4h]

  __a = 1;
  __b = 1;
  v2 = stlp_std::max<unsigned int>(&__a, &__b);
  __p = (stlp_std::priv::_List_node<unsigned int> *)vostok::memory::doug_lea_allocator::realloc_impl(
                                                      vostok::ai::g_allocator,
                                                      0,
                                                      12 * *v2);
  stlp_std::_Copy_Construct<unsigned int>(&__p->_M_data, __x);
  return __p;
}
