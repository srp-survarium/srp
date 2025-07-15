void __thiscall Scaleform::Thread::SetThreadName(Scaleform::Thread *this, const char *name)
{
  ULONG_PTR Arguments[4]; // [esp+Ch] [ebp-28h] BYREF
  CPPEH_RECORD ms_exc; // [esp+1Ch] [ebp-18h]

  Arguments[0] = 4096;
  Arguments[1] = (ULONG_PTR)name;
  Arguments[2] = (ULONG_PTR)this->IdValue;
  Arguments[3] = 0;
  ms_exc.registration.TryLevel = 0;
  RaiseException(0x406D1388u, 0, 4u, Arguments);
}
