Scaleform::Render::ImageData *__thiscall Scaleform::Render::DrawableImage::getMappedData(
        Scaleform::Render::DrawableImage *this)
{
  Scaleform::Render::Fence *pObject; // eax
  Scaleform::Render::FenceImpl *Data; // eax
  Scaleform::Render::Fence *v4; // eax
  Scaleform::Render::FenceImpl *v5; // eax
  Scaleform::Render::Fence *v6; // ecx

  pObject = this->pFence.pObject;
  if ( pObject )
  {
    if ( pObject->HasData )
    {
      Data = pObject->Data;
      if ( Data )
      {
        if ( Scaleform::Render::FenceImpl::IsPending(Data, FenceType_Fragment) )
        {
          v4 = this->pFence.pObject;
          if ( v4->HasData )
          {
            v5 = v4->Data;
            if ( v5 )
              Scaleform::Render::FenceImpl::WaitFence(v5, FenceType_Fragment);
          }
        }
      }
    }
  }
  v6 = this->pFence.pObject;
  if ( v6 )
    Scaleform::Render::Fence::Release(v6);
  this->pFence.pObject = 0;
  return &this->MappedData;
}
