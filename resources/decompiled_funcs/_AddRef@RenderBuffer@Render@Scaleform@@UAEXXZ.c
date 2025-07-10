void __thiscall Scaleform::Render::RenderBuffer::AddRef(Scaleform::Render::RenderBuffer *this)
{
  InterlockedExchangeAdd(&this->RefCount, 1);
}
