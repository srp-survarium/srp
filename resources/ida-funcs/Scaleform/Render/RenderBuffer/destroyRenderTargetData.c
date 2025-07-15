void __thiscall Scaleform::Render::RenderBuffer::destroyRenderTargetData(Scaleform::Render::RenderBuffer *this)
{
  Scaleform::Render::RenderBuffer::RenderTargetData *pRenderTargetData; // ecx

  pRenderTargetData = this->pRenderTargetData;
  if ( pRenderTargetData )
  {
    ((void (__thiscall *)(Scaleform::Render::RenderBuffer::RenderTargetData *, int))pRenderTargetData->~Scaleform::Render::RenderBuffer::RenderTargetData)(
      pRenderTargetData,
      1);
    this->pRenderTargetData = 0;
  }
}
