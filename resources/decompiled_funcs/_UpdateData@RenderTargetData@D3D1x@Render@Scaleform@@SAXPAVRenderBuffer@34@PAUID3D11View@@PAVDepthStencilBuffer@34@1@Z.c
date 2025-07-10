void __usercall Scaleform::Render::D3D1x::RenderTargetData::UpdateData(
        Scaleform::Render::DepthStencilBuffer *pdsb@<eax>,
        Scaleform::Render::RenderBuffer *buffer,
        ID3D11View *prt,
        ID3D11View *pdss)
{
  Scaleform::Render::RenderBuffer::RenderTargetData *pRenderTargetData; // esi
  Scaleform::Render::D3D1x::RenderTargetData *v6; // esi
  Scaleform::Render::RenderBuffer::RenderTargetData *v7; // eax
  Scaleform::Render::RenderBuffer::RenderTargetData_vtbl *v8; // eax
  Scaleform::Render::RenderBuffer *pBuffer; // eax
  Scaleform::Render::DepthStencilBuffer *pObject; // ecx

  if ( buffer )
  {
    pRenderTargetData = buffer->pRenderTargetData;
    if ( pRenderTargetData )
    {
      if ( prt )
        prt->AddRef(prt);
      if ( pdss )
        pdss->AddRef(pdss);
      v8 = pRenderTargetData[1].__vftable;
      if ( v8 )
        (*((void (__stdcall **)(Scaleform::Render::RenderBuffer::RenderTargetData_vtbl *))v8->~Scaleform::Render::RenderBuffer::RenderTargetData
         + 2))(pRenderTargetData[1].__vftable);
      pBuffer = pRenderTargetData[1].pBuffer;
      if ( pBuffer )
        ((void (__stdcall *)(Scaleform::Render::RenderBuffer *))pBuffer->Release)(pRenderTargetData[1].pBuffer);
      if ( pdsb )
        pdsb->AddRef(pdsb);
      pObject = pRenderTargetData->pDepthStencilBuffer.pObject;
      if ( pObject )
        pObject->Release(pObject);
      pRenderTargetData->pDepthStencilBuffer.pObject = pdsb;
      pRenderTargetData[1].pBuffer = (Scaleform::Render::RenderBuffer *)pdss;
      pRenderTargetData[1].__vftable = (Scaleform::Render::RenderBuffer::RenderTargetData_vtbl *)prt;
    }
    else
    {
      v6 = (Scaleform::Render::D3D1x::RenderTargetData *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                           Scaleform::Memory::pGlobalHeap,
                                                           24,
                                                           0);
      if ( v6 )
      {
        Scaleform::Render::D3D1x::RenderTargetData::RenderTargetData(v6, buffer, prt, pdsb, pdss);
        buffer->pRenderTargetData = v7;
      }
      else
      {
        buffer->pRenderTargetData = 0;
      }
    }
  }
}
