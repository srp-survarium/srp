int __cdecl __timet_from_ft(_FILETIME *pft)
{
  _SYSTEMTIME SystemTime; // [esp+0h] [ebp-18h] BYREF
  _FILETIME LocalFileTime; // [esp+10h] [ebp-8h] BYREF

  if ( (pft->dwLowDateTime || pft->dwHighDateTime)
    && FileTimeToLocalFileTime(pft, &LocalFileTime)
    && FileTimeToSystemTime(&LocalFileTime, &SystemTime) )
  {
    return __loctotime32_t(
             SystemTime.wYear,
             SystemTime.wMonth,
             SystemTime.wDay,
             SystemTime.wHour,
             SystemTime.wMinute,
             SystemTime.wSecond,
             0);
  }
  else
  {
    return -1;
  }
}
