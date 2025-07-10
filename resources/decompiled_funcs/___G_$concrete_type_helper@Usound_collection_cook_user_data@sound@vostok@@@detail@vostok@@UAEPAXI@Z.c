vostok::detail::concrete_type_helper<vostok::sound::sound_collection_cook_user_data> *__thiscall vostok::detail::concrete_type_helper<vostok::sound::sound_collection_cook_user_data>::`scalar deleting destructor'(
        vostok::detail::concrete_type_helper<vostok::sound::sound_collection_cook_user_data> *this,
        char a2)
{
  this->__vftable = (vostok::detail::concrete_type_helper<vostok::sound::sound_collection_cook_user_data>_vtbl *)&vostok::detail::abstract_type_helper::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
