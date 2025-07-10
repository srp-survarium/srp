vostok::detail::concrete_type_helper<survarium::booby_trap_set_cook_data> *__thiscall vostok::detail::concrete_type_helper<survarium::booby_trap_set_cook_data>::`vector deleting destructor'(
        vostok::detail::concrete_type_helper<survarium::booby_trap_set_cook_data> *this,
        char a2)
{
  vostok::detail::abstract_type_helper::~abstract_type_helper(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
