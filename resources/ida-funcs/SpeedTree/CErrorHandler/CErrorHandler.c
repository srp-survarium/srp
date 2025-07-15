SpeedTree::CErrorHandler *__thiscall SpeedTree::CErrorHandler::CErrorHandler(SpeedTree::CErrorHandler *this)
{
  `eh vector constructor iterator'(
    (char *)this,
    0x40Cu,
    20,
    SpeedTree::CErrorHandler::SErrorString::SErrorString,
    (void (__thiscall *)(void *))SpeedTree::CErrorHandler::SErrorString::~SErrorString);
  *((_DWORD *)this + 5180) = 0;
  *((_DWORD *)this + 5181) = -1;
  InitializeCriticalSection((LPCRITICAL_SECTION)((char *)this + 20728));
  return this;
}
