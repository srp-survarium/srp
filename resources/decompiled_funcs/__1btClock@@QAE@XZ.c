void __thiscall btClock::~btClock(btClock *this)
{
  operator delete(gProfileClock.m_data);
}
