int __thiscall dynamic_initializer_for__gProfileClock__(btClock *this)
{
  btClock::btClock(this);
  return atexit(dynamic_atexit_destructor_for__gProfileClock__);
}
