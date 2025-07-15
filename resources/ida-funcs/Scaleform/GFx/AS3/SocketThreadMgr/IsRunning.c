bool __thiscall Scaleform::GFx::AS3::SocketThreadMgr::IsRunning(Scaleform::GFx::AS3::SocketThreadMgr *this)
{
  Scaleform::Thread *pObject; // ecx

  pObject = this->SocketThread.pObject;
  return pObject && !(unsigned __int8)Scaleform::Thread::IsSignaled(pObject);
}
