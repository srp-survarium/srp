bool __thiscall Scaleform::Mutex::TryAcquire(Scaleform::Mutex *this)
{
  volatile int RefCount; // esi
  bool result; // al

  RefCount = this->RefCount;
  if ( WaitForSingleObject(*(HANDLE *)RefCount, 0) )
    return 0;
  result = 1;
  ++*(_DWORD *)(RefCount + 8);
  return result;
}
