vostok::sound::sound_response *__thiscall vostok::sound::sound_response::`scalar deleting destructor'(
        vostok::sound::sound_response *this,
        char a2)
{
  this->__vftable = (vostok::sound::sound_response_vtbl *)&vostok::sound::sound_response::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
