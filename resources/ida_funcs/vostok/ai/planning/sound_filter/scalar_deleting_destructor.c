vostok::ai::planning::sound_filter *__thiscall vostok::ai::planning::sound_filter::`scalar deleting destructor'(
        vostok::ai::planning::sound_filter *this,
        char a2)
{
  vostok::ai::planning::sound_filter::~sound_filter(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
