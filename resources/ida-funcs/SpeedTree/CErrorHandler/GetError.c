char *__thiscall SpeedTree::CErrorHandler::GetError(SpeedTree::CErrorHandler *this)
{
  char *v3; // [esp+4h] [ebp-4h]

  v3 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)((char *)this + 20728));
  if ( *((_DWORD *)this + 5181) != -1 )
  {
    v3 = (char *)this + 1036 * *((_DWORD *)this + 5181) + 12;
    *((_BYTE *)this + 1036 * (*((_DWORD *)this + 5181))++) = 1;
    if ( *((_DWORD *)this + 5181) == 20 )
      *((_DWORD *)this + 5181) = 0;
    if ( *((_DWORD *)this + 5181) == *((_DWORD *)this + 5180) )
      *((_DWORD *)this + 5181) = -1;
    if ( *((_DWORD *)this + 5181) != -1 && *((_BYTE *)this + 1036 * *((_DWORD *)this + 5181)) )
      *((_DWORD *)this + 5181) = -1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)((char *)this + 20728));
  return v3;
}
