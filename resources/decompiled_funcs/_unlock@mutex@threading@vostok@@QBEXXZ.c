void __thiscall vostok::threading::mutex::unlock(vostok::threading::mutex *this)
{
  LeaveCriticalSection((LPCRITICAL_SECTION)this);
}
