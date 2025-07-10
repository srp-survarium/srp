void __thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_reserve(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *this,
        unsigned int __n)
{
  btBroadphasePair *Length; // [esp+Ch] [ebp-30h]
  btPersistentManifold **v4; // [esp+14h] [ebp-28h]
  int i; // [esp+1Ch] [ebp-20h]
  char *v6; // [esp+20h] [ebp-1Ch]
  char *__new_start; // [esp+38h] [ebp-4h]

  __new_start = stlp_std::priv::_STLP_alloc_proxy<char *,char,stlp_std::allocator<char>>::allocate(
                  &this->_M_start_of_storage,
                  __n,
                  &__n);
  Length = Scaleform::MemoryFile::GetLength((btNullPairCache *)this);
  v4 = stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_Start((btCollisionDispatcher *)this);
  v6 = __new_start;
  for ( i = (char *)Length - (char *)v4; i > 0; --i )
  {
    survarium::generate_shaders_world::is_loading();
    survarium::generate_shaders_world::is_loading();
    *v6 = *(_BYTE *)v4;
    v4 = (btPersistentManifold **)((char *)v4 + 1);
    ++v6;
  }
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_construct_null(this, v6);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(this);
  this->_M_buffers._M_end_of_storage = &__new_start[__n];
  this->_M_finish = v6;
  this->_M_start_of_storage._M_data = __new_start;
}
