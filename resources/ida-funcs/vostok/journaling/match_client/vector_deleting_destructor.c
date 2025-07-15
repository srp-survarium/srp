vostok::journaling::match_client *__thiscall vostok::journaling::match_client::`vector deleting destructor'(
        vostok::journaling::match_client *this,
        char a2)
{
  vostok::journaling::match_client::~match_client(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
