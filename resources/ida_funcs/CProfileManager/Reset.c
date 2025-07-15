void __cdecl CProfileManager::Reset()
{
  btClock *v0; // ecx

  QueryPerformanceCounter(&gProfileClock.m_data->mStartTime);
  gProfileClock.m_data->mStartTick = GetTickCount();
  LODWORD(gProfileClock.m_data->mPrevElapsedTime) = 0;
  HIDWORD(gProfileClock.m_data->mPrevElapsedTime) = 0;
  CProfileNode::Reset(&CProfileManager::Root);
  ++CProfileManager::Root.TotalCalls;
  v0 = (btClock *)CProfileManager::Root.RecursionCounter++;
  if ( !v0 )
    CProfileManager::Root.StartTime = btClock::getTimeMicroseconds(0);
  CProfileManager::FrameCounter = 0;
  CProfileManager::ResetTime = btClock::getTimeMicroseconds(v0);
}
