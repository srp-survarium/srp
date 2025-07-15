void __usercall boost::asio::detail::deadline_timer_service<boost::asio::time_traits<boost::posix_time::ptime>>::~deadline_timer_service<boost::asio::time_traits<boost::posix_time::ptime>>(
        boost::asio::detail::deadline_timer_service<boost::asio::time_traits<boost::posix_time::ptime> > *this@<ecx>,
        _RTL_CRITICAL_SECTION *a2@<eax>)
{
  _RTL_CRITICAL_SECTION *DebugInfo; // edi
  _RTL_CRITICAL_SECTION_DEBUG *v4; // eax
  boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> > *v5; // ecx

  DebugInfo = (_RTL_CRITICAL_SECTION *)a2[1].DebugInfo;
  EnterCriticalSection(DebugInfo + 2);
  v4 = DebugInfo[3].DebugInfo;
  if ( v4 )
  {
    if ( a2 == (_RTL_CRITICAL_SECTION *)v4 )
    {
      DebugInfo[3].DebugInfo = (_RTL_CRITICAL_SECTION_DEBUG *)a2->LockCount;
LABEL_9:
      a2->LockCount = 0;
    }
    else
    {
      while ( v4->CriticalSection )
      {
        if ( v4->CriticalSection == a2 )
        {
          v4->CriticalSection = (_RTL_CRITICAL_SECTION *)a2->LockCount;
          goto LABEL_9;
        }
        v4 = (_RTL_CRITICAL_SECTION_DEBUG *)v4->CriticalSection;
      }
    }
  }
  LeaveCriticalSection(DebugInfo + 2);
  boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::~timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>(
    v5,
    a2);
}
