__int64 __thiscall btClock::getTimeMicroseconds(btClock *this)
{
  __int64 v1; // kr00_8
  int v2; // ebp
  DWORD TickCount; // eax
  btClockData *m_data; // esi
  int v5; // ecx
  __int64 v6; // rax
  __int64 v8; // [esp+10h] [ebp-10h]
  _LARGE_INTEGER currentTime; // [esp+18h] [ebp-8h] BYREF

  QueryPerformanceCounter(&currentTime);
  v1 = currentTime.QuadPart - gProfileClock.m_data->mStartTime.QuadPart;
  v2 = 1000 * v1 / gProfileClock.m_data->mClockFrequency.QuadPart;
  TickCount = GetTickCount();
  m_data = gProfileClock.m_data;
  v5 = v2 + gProfileClock.m_data->mStartTick - TickCount;
  if ( v5 < -100 || v5 > 100 )
  {
    v8 = (int)(v2 + gProfileClock.m_data->mStartTick - TickCount);
    if ( v8 * gProfileClock.m_data->mClockFrequency.QuadPart / 1000 <= v1 - gProfileClock.m_data->mPrevElapsedTime )
      v6 = v1 - gProfileClock.m_data->mPrevElapsedTime;
    else
      v6 = v8 * gProfileClock.m_data->mClockFrequency.QuadPart / 1000;
    gProfileClock.m_data->mStartTime.QuadPart += v6;
    m_data = gProfileClock.m_data;
    v1 -= v6;
  }
  LODWORD(m_data->mPrevElapsedTime) = v1;
  HIDWORD(gProfileClock.m_data->mPrevElapsedTime) = HIDWORD(v1);
  return v1 * (unsigned int)&off_F4240 / gProfileClock.m_data->mClockFrequency.QuadPart;
}
