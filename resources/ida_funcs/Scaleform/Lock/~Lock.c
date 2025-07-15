void __thiscall Scaleform::Lock::~Lock(Scaleform::Lock *this)
{
  DeleteCriticalSection(&this->cs);
}
