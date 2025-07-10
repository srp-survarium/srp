vostok::sound::sound_instance_proxy_internal *__thiscall vostok::sound::sound_instance_proxy_internal::`scalar deleting destructor'(
        vostok::sound::sound_instance_proxy_internal *this,
        char a2)
{
  vostok::sound::sound_instance_proxy_internal::~sound_instance_proxy_internal(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
