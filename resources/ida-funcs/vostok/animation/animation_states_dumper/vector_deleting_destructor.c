vostok::animation::animation_states_dumper *__thiscall vostok::animation::animation_states_dumper::`vector deleting destructor'(
        vostok::animation::animation_states_dumper *this,
        char a2)
{
  this->__vftable = (vostok::animation::animation_states_dumper_vtbl *)&vostok::animation::animation_states_dumper::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
