bool __usercall Scaleform::Render::D3D1x::HAL::RestoreAfterReset@<al>(
        Scaleform::Render::D3D1x::HAL *this@<ecx>,
        Scaleform::Render::HAL *a2@<esi>)
{
  bool result; // al
  Scaleform::Render::HAL::RenderTargetEntry *Data; // edi
  Scaleform::Render::RenderBuffer::RenderTargetData *pRenderTargetData; // eax
  Scaleform::Render::RenderBuffer *v5; // [esp+0h] [ebp-8h] BYREF
  Scaleform::Render::RenderBuffer::RenderTargetData_vtbl *v6; // [esp+4h] [ebp-4h] BYREF

  result = a2->IsInitialized(a2);
  if ( result )
  {
    if ( (a2->HALState & 0x2000) != 0 )
    {
      if ( a2->RenderTargetStack.Data.Size )
      {
        Data = a2->RenderTargetStack.Data.Data;
        (*(void (__stdcall **)(_DWORD, int, Scaleform::Render::RenderBuffer::RenderTargetData_vtbl **, Scaleform::Render::RenderBuffer **))(**(_DWORD **)&a2[102].QueueProcessor.PrepareItemBufferBytes[8] + 356))(
          *(_DWORD *)&a2[102].QueueProcessor.PrepareItemBufferBytes[8],
          1,
          &v6,
          &v5);
        if ( Data->pRenderTarget.pObject )
        {
          if ( v6 )
          {
            pRenderTargetData = Data->pRenderTarget.pObject->pRenderTargetData;
            pRenderTargetData[1].__vftable = v6;
            if ( v5 )
              pRenderTargetData[1].pBuffer = v5;
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
