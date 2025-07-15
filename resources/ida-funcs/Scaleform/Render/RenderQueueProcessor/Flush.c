void __thiscall Scaleform::Render::RenderQueueProcessor::Flush(Scaleform::Render::RenderQueueProcessor *this)
{
  Scaleform::Render::RenderQueueProcessor::ProcessQueue(this, QPM_All);
  this->PrepareItemBuffer.pItem = 0;
  this->EmitItemBuffer.pItem = 0;
}
