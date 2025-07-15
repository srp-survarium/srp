Scaleform::GFx::ImageResource *__thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::GetImageResource(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this)
{
  Scaleform::GFx::ImageResource *result; // eax
  Scaleform::Render::ImageBase *pObject; // eax
  Scaleform::GFx::ImageResource *v4; // eax
  Scaleform::GFx::ImageResource *v5; // eax
  Scaleform::GFx::ImageResource *v6; // edi
  Scaleform::GFx::ImageResource *v7; // ecx
  int v8; // [esp+4h] [ebp-4h] BYREF

  result = this->pImageResource.pObject;
  if ( !result )
  {
    pObject = this->pImage.pObject;
    if ( pObject )
    {
      v8 = 2;
      v4 = (Scaleform::GFx::ImageResource *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                              Scaleform::Memory::pGlobalHeap,
                                              pObject,
                                              52,
                                              &v8);
      if ( v4 )
      {
        Scaleform::GFx::ImageResource::ImageResource(
          v4,
          (Scaleform::Render::ImageSource *)this->pImage.pObject,
          Use_Bitmap);
        v6 = v5;
      }
      else
      {
        v6 = 0;
      }
      v7 = this->pImageResource.pObject;
      if ( v7 )
        Scaleform::GFx::Resource::Release(v7);
      this->pImageResource.pObject = v6;
      return v6;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
