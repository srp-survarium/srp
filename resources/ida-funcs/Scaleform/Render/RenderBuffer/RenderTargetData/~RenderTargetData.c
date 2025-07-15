void __thiscall Scaleform::Render::RenderBuffer::RenderTargetData::~RenderTargetData(
        Scaleform::Render::RenderBuffer::RenderTargetData *this)
{
  Scaleform::Render::DepthStencilBuffer *pObject; // ecx

  this->__vftable = (Scaleform::Render::RenderBuffer::RenderTargetData_vtbl *)&Scaleform::Render::RenderBuffer::RenderTargetData::`vftable';
  pObject = this->pDepthStencilBuffer.pObject;
  if ( pObject )
    pObject->Release(pObject);
}
