bool __thiscall Scaleform::GFx::AMP::ThreadMgr::IsRunning(Scaleform::GFx::AMP::ThreadMgr *this)
{
  Scaleform::Thread *pObject; // ecx

  pObject = this->SocketThread.pObject;
  return pObject && !(unsigned __int8)Scaleform::Thread::IsSignaled(pObject);
}
