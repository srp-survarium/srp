D3DX11_IMAGE_LOAD_INFO *__usercall D3DX11_IMAGE_LOAD_INFO::D3DX11_IMAGE_LOAD_INFO@<eax>(
        D3DX11_IMAGE_LOAD_INFO *this@<ecx>,
        D3DX11_IMAGE_LOAD_INFO *result@<eax>)
{
  result->pSrcInfo = 0;
  result->Width = -1;
  result->Height = -1;
  result->Depth = -1;
  result->FirstMipLevel = -1;
  result->MipLevels = -1;
  result->Usage = -1;
  result->BindFlags = -1;
  result->CpuAccessFlags = -1;
  result->MiscFlags = -1;
  result->Format = -3;
  result->Filter = -1;
  result->MipFilter = -1;
  return result;
}
