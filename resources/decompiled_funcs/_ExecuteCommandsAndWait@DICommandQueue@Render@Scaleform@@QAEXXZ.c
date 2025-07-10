void __thiscall Scaleform::Render::DICommandQueue::ExecuteCommandsAndWait(Scaleform::Render::DICommandQueue *this)
{
  Scaleform::Event *p_ExecuteDone; // esi

  Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)this);
  Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)this->ExecuteCmd.pObject);
  this->pRTCommandQueue->PushThreadCommand(this->pRTCommandQueue, this->ExecuteCmd.pObject);
  p_ExecuteDone = &this->ExecuteCmd.pObject->ExecuteDone;
  Scaleform::Event::Wait(p_ExecuteDone, 0xFFFFFFFF);
  Scaleform::Event::ResetEvent(p_ExecuteDone);
}
