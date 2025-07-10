void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::writeUTFBytes(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *value)
{
  if ( Scaleform::GFx::AS3::SocketThreadMgr::IsRunning(this->SockMgr.pObject) )
  {
    Scaleform::GFx::AS3::SocketThreadMgr::SendBytes(this->SockMgr.pObject, value->pNode->pData, value->pNode->Size);
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl_net::Socket::ExecuteIOErrorEvent(
      (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)this,
      "AS3 Net Socket: Attempting to write to closed socket");
    Scaleform::GFx::AS3::Instances::fl_net::Socket::ThrowIOError(this);
  }
}
