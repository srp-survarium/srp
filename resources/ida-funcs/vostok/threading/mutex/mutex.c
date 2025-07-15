void __thiscall vostok::threading::mutex::mutex(vostok::threading::mutex *this)
{
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)this, 0x2710u);
}
