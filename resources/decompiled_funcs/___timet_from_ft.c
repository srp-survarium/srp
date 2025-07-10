int __cdecl __timet_from_ft(_FILETIME *pft)
{
  _SYSTEMTIME st; // [esp+0h] [ebp-18h] BYREF
  _FILETIME lft; // [esp+10h] [ebp-8h] BYREF

  if ( (pft->dwLowDateTime || pft->dwHighDateTime)
    && FileTimeToLocalFileTime(pft, &lft)
    && FileTimeToSystemTime(&lft, &st) )
  {
    return __loctotime32_t(st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, 0);
  }
  else
  {
    return -1;
  }
}
