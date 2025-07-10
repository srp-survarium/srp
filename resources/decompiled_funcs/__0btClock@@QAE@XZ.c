btClock *__thiscall btClock::btClock(btClock *this)
{
  gProfileClock.m_data = (btClockData *)operator new(0x20u);
  QueryPerformanceFrequency(&gProfileClock.m_data->mClockFrequency);
  QueryPerformanceCounter(&gProfileClock.m_data->mStartTime);
  gProfileClock.m_data->mStartTick = GetTickCount();
  LODWORD(gProfileClock.m_data->mPrevElapsedTime) = 0;
  HIDWORD(gProfileClock.m_data->mPrevElapsedTime) = 0;
  return &gProfileClock;
}
