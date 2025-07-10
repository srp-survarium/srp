char __usercall Scaleform::Render::D3D1x::HAL::RestoreAfterReset@<al>(
        Scaleform::Render::D3D1x::HAL *this@<ecx>,
        Scaleform::Render::HAL *a2@<esi>)
{
  char result; // al
  Scaleform::Render::HAL::RenderTargetEntry *Data; // edi
  Scaleform::Render::RenderBuffer::RenderTargetData *pRenderTargetData; // eax
  ID3D11RenderTargetView *rtView; // [esp+10h] [ebp-8h] BYREF
  ID3D11DepthStencilView *dsView; // [esp+14h] [ebp-4h] BYREF

  result = a2->IsInitialized(a2);
  if ( result )
  {
    if ( (a2->HALState & 0x2000) != 0 )
    {
      if ( a2->RenderTargetStack.Data.Size )
      {
        Data = a2->RenderTargetStack.Data.Data;
        (*(void (__stdcall **)(_DWORD, int, ID3D11RenderTargetView **, ID3D11DepthStencilView **))(**(_DWORD **)&a2[137].QueueProcessor.PrepareItemBufferBytes[88]
                                                                                                 + 356))(
          *(_DWORD *)&a2[137].QueueProcessor.PrepareItemBufferBytes[88],
          1,
          &rtView,
          &dsView);
        if ( Data->pRenderTarget.pObject )
        {
          if ( rtView )
          {
            pRenderTargetData = Data->pRenderTarget.pObject->pRenderTargetData;
            pRenderTargetData[1].__vftable = (Scaleform::Render::RenderBuffer::RenderTargetData_vtbl *)rtView;
            if ( dsView )
              pRenderTargetData[1].pBuffer = (Scaleform::Render::RenderBuffer *)dsView;
          }
        }
      }
      Scaleform::Render::HAL::notifyHandlers(a2, HAL_RestoreAfterReset);
      a2->HALState &= ~0x2000u;
    }
    return 1;
  }
  return result;
}
