char __usercall Scaleform::Render::D3D1x::HAL::checkMaskBufferCaps@<al>(
        Scaleform::Render::D3D1x::HAL *this@<ecx>,
        int a2@<esi>)
{
  int v2; // eax
  ID3D11DepthStencilView *pObject; // eax
  ID3D11RenderTargetView *v4; // ecx
  Scaleform::Ptr<ID3D11DepthStencilView> depthStencilTarget; // [esp+1Ch] [ebp-24h] BYREF
  Scaleform::Ptr<ID3D11RenderTargetView> renderTarget; // [esp+20h] [ebp-20h] BYREF
  D3D11_DEPTH_STENCIL_VIEW_DESC desc; // [esp+24h] [ebp-1Ch] BYREF

  if ( !*(_BYTE *)(a2 + 64208) )
  {
    v2 = *(_DWORD *)(a2 + 63796);
    *(_BYTE *)(a2 + 64209) = 0;
    *(_BYTE *)(a2 + 64210) = 0;
    depthStencilTarget.pObject = 0;
    renderTarget.pObject = 0;
    (*(void (__stdcall **)(int, int, Scaleform::Ptr<ID3D11RenderTargetView> *, Scaleform::Ptr<ID3D11DepthStencilView> *))(*(_DWORD *)v2 + 356))(
      v2,
      1,
      &renderTarget,
      &depthStencilTarget);
    pObject = depthStencilTarget.pObject;
    if ( depthStencilTarget.pObject )
    {
      depthStencilTarget.pObject->GetDesc(depthStencilTarget.pObject, &desc);
      switch ( desc.Format )
      {
        case DXGI_FORMAT_D32_FLOAT_S8X24_UINT:
        case DXGI_FORMAT_D24_UNORM_S8_UINT:
          *(_BYTE *)(a2 + 64209) = 1;
          goto $LN4_145;
        case DXGI_FORMAT_D32_FLOAT:
        case DXGI_FORMAT_D16_UNORM:
$LN4_145:
          *(_BYTE *)(a2 + 64210) = 1;
          break;
        default:
          break;
      }
      pObject = depthStencilTarget.pObject;
    }
    v4 = renderTarget.pObject;
    *(_BYTE *)(a2 + 64208) = 1;
    if ( v4 )
    {
      v4->Release(v4);
      pObject = depthStencilTarget.pObject;
    }
    if ( pObject )
      pObject->Release(pObject);
  }
  if ( *(_BYTE *)(a2 + 64209) || *(_BYTE *)(a2 + 64210) )
    return 1;
  if ( !warned_0 )
    warned_0 = 1;
  return 0;
}
