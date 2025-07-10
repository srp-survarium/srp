void __thiscall btClock::reset(btClock *this)
{
  QueryPerformanceCounter(&gProfileClock.m_data->mStartTime);
  gProfileClock.m_data->mStartTick = GetTickCount();
  LODWORD(gProfileClock.m_data->mPrevElapsedTime) = 0;
  HIDWORD(gProfileClock.m_data->mPrevElapsedTime) = 0;
}
