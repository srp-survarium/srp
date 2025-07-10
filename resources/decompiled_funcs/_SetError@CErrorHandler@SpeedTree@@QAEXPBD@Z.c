void __thiscall SpeedTree::CErrorHandler::SetError(SpeedTree::CErrorHandler *this, char *buf)
{
  int v2; // eax
  _BYTE *v3; // edx
  void **v5; // [esp+18h] [ebp-414h] BYREF
  int v6; // [esp+428h] [ebp-4h]

  EnterCriticalSection((LPCRITICAL_SECTION)((char *)this + 20728));
  if ( buf )
  {
    strlen((unsigned __int8 *)buf);
    if ( v2 )
    {
      if ( *((_DWORD *)this + 5180) != -1 )
      {
        v5 = &SpeedTree::CBasicFixedString<1024>::`vftable';
        SpeedTree::CBasicFixedString<1024>::operator=((unsigned __int8 *)buf);
        v6 = 0;
        v3 = (char *)this + 1036 * *((_DWORD *)this + 5180);
        *v3 = 0;
        SpeedTree::CBasicFixedString<1024>::operator=((int)(v3 + 4), (int)&v5);
        v6 = -1;
        v5 = &SpeedTree::CBasicFixedString<1024>::`vftable';
        if ( *((_DWORD *)this + 5181) == -1 )
          *((_DWORD *)this + 5181) = *((_DWORD *)this + 5180);
        if ( ++*((_DWORD *)this + 5180) == 20 )
          *((_DWORD *)this + 5180) = 0;
        if ( *((_DWORD *)this + 5180) == *((_DWORD *)this + 5181) )
          *((_DWORD *)this + 5180) = -1;
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)((char *)this + 20728));
}
