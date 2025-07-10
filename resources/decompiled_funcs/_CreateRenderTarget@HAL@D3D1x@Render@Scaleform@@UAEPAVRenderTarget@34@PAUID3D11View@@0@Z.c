Scaleform::Render::RenderTarget *__thiscall Scaleform::Render::D3D1x::HAL::CreateRenderTarget(
        Scaleform::Render::D3D1x::HAL *this,
        ID3D11View *pcolor,
        ID3D11View *pdepth)
{
  void (__stdcall *GetResource)(ID3D11View *, ID3D11Resource **); // eax
  Scaleform::Render::RenderBufferManager *pObject; // ecx
  Scaleform::Render::RenderBuffer *v6; // eax
  Scaleform::Render::DepthStencilBuffer *v7; // ebx
  unsigned int Width; // ebx
  void *(__thiscall *AllocAutoHeap)(Scaleform::MemoryHeap *, const void *, unsigned int, const Scaleform::AllocInfo *); // edx
  Scaleform::Render::DepthStencilBuffer *v10; // eax
  unsigned int Height; // ecx
  Scaleform::Render::RenderBuffer *v12; // esi
  Scaleform::Ptr<ID3D11Texture2D> pdepthStencilTarget; // [esp+3Ch] [ebp-78h] BYREF
  Scaleform::Ptr<ID3D11Texture2D> prenderTarget; // [esp+40h] [ebp-74h] BYREF
  int v16; // [esp+44h] [ebp-70h] BYREF
  Scaleform::Render::RenderBuffer *buffer; // [esp+48h] [ebp-6Ch]
  Scaleform::Render::Size<unsigned long> rtSize; // [esp+4Ch] [ebp-68h] BYREF
  Scaleform::Render::Size<unsigned long> dsSize; // [esp+54h] [ebp-60h]
  D3D11_TEXTURE2D_DESC rtDesc; // [esp+5Ch] [ebp-58h] BYREF
  D3D11_TEXTURE2D_DESC dsDesc; // [esp+88h] [ebp-2Ch] BYREF

  GetResource = pcolor->GetResource;
  prenderTarget.pObject = 0;
  pdepthStencilTarget.pObject = 0;
  rtSize.Width = 0;
  rtSize.Height = 0;
  GetResource(pcolor, &prenderTarget.pObject);
  prenderTarget.pObject->GetDesc(prenderTarget.pObject, &rtDesc);
  rtSize.Width = rtDesc.Width;
  pObject = this->pRenderBufferManager.pObject;
  rtSize.Height = rtDesc.Height;
  v6 = pObject->CreateRenderTarget(pObject, &rtSize, RBuffer_User, Image_R8G8B8A8, 0);
  buffer = v6;
  if ( v6 )
    v6->AddRef(v6);
  v7 = 0;
  if ( pdepth )
  {
    pdepth->GetResource(pdepth, (ID3D11Resource **)&pdepthStencilTarget);
    pdepthStencilTarget.pObject->GetDesc(pdepthStencilTarget.pObject, &dsDesc);
    Width = dsDesc.Width;
    dsSize.Height = dsDesc.Height;
    AllocAutoHeap = Scaleform::Memory::pGlobalHeap->AllocAutoHeap;
    v16 = 75;
    v10 = (Scaleform::Render::DepthStencilBuffer *)AllocAutoHeap(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     this,
                                                     28u,
                                                     (const Scaleform::AllocInfo *)&v16);
    if ( v10 )
    {
      Height = dsSize.Height;
      v10->__vftable = (Scaleform::Render::DepthStencilBuffer_vtbl *)&Scaleform::RefCountImplCore::`vftable';
      v10->RefCount = 1;
      v10->Type = RBuffer_DepthStencil;
      v10->pManager = 0;
      v10->pRenderTargetData = 0;
      v10->BufferSize.Width = Width;
      v10->BufferSize.Height = Height;
      v10->__vftable = (Scaleform::Render::DepthStencilBuffer_vtbl *)&Scaleform::Render::DepthStencilBuffer::`vftable';
    }
    else
    {
      v10 = 0;
    }
    v7 = v10;
  }
  v12 = buffer;
  Scaleform::Render::D3D1x::RenderTargetData::UpdateData(v7, buffer, pcolor, pdepth);
  if ( v7 )
    v7->Release(v7);
  if ( v12 )
    v12->Release(v12);
  if ( pdepthStencilTarget.pObject )
    pdepthStencilTarget.pObject->Release(pdepthStencilTarget.pObject);
  if ( prenderTarget.pObject )
    prenderTarget.pObject->Release(prenderTarget.pObject);
  return (Scaleform::Render::RenderTarget *)v12;
}
