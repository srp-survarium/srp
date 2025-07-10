void __thiscall Scaleform::GFx::ImageResource::ImageDelegate::Release(
        Scaleform::GFx::ImageResource::ImageDelegate *this)
{
  Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)&this[-1].pTexture);
}
