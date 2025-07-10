void __thiscall Scaleform::Render::HAL::Flush(Scaleform::Render::HAL *this)
{
  Scaleform::Render::RenderQueueProcessor *v1; // eax

  v1 = this->GetRQProcessor(this);
  Scaleform::Render::RenderQueueProcessor::Flush(v1);
}
