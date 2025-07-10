void __thiscall Scaleform::Render::SKI_MaskEnd::DrawBundleEntry(
        Scaleform::Render::SKI_MaskEnd *this,
        void *data,
        Scaleform::Render::BundleEntry *__formal,
        Scaleform::Render::Renderer2DImpl *r2d)
{
  Scaleform::Render::HAL *pObject; // ecx
  Scaleform::Render::RenderQueueItem rqi; // [esp+0h] [ebp-8h] BYREF

  pObject = r2d->pHal.pObject;
  rqi.Data = data;
  rqi.pImpl = &Scaleform::Render::SKI_MaskEnd::RQII_Instance;
  pObject->Draw(pObject, &rqi);
}
