vostok::network::network_world *__thiscall vostok::network::network_world::`scalar deleting destructor'(
        vostok::network::network_world *this,
        char a2)
{
  vostok::network::network_world::~network_world(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
