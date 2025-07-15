double __thiscall CProfileManager::Get_Time_Since_Reset(btClock *this)
{
  return (double)((unsigned int)btClock::getTimeMicroseconds(this) - CProfileManager::ResetTime) * 0.001;
}
