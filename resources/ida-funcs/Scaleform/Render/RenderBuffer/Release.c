void __thiscall Scaleform::Render::RenderBuffer::Release(Scaleform::Render::RenderBuffer *this)
{
  if ( InterlockedExchangeAdd(&this->RefCount, -1) == 1 )
  {
    if ( this )
      ((void (__thiscall *)(Scaleform::Render::RenderBuffer *, int))this->~Scaleform::Render::RenderBuffer)(this, 1);
  }
}
