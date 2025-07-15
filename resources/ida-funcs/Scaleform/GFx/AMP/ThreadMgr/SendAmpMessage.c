void __thiscall Scaleform::GFx::AMP::ThreadMgr::SendAmpMessage(
        Scaleform::GFx::AMP::ThreadMgr *this,
        Scaleform::RefCountVImpl *msg)
{
  if ( this->ValidConnection.Value )
    Scaleform::GFx::AMP::ThreadMgr::MsgQueue::PushBack(&this->MsgSendQueue, (Scaleform::GFx::AMP::Message *)msg);
  else
    Scaleform::RefCountImpl::Release(msg);
}
