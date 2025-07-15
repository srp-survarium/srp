vostok::sound::destroy_sound_instance_proxy_order *__thiscall vostok::sound::destroy_sound_instance_proxy_order::`scalar deleting destructor'(
        vostok::sound::destroy_sound_instance_proxy_order *this,
        char a2)
{
  vostok::sound::destroy_sound_instance_proxy_order::~destroy_sound_instance_proxy_order(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
