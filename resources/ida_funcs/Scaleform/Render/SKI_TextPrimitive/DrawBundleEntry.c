void __thiscall Scaleform::Render::SKI_TextPrimitive::DrawBundleEntry(
        Scaleform::Render::SKI_TextPrimitive *this,
        void *__formal,
        Scaleform::Render::BundleEntry *p,
        Scaleform::Render::Renderer2DImpl *r)
{
  Scaleform::Render::Bundle *pObject; // eax
  Scaleform::Render::HAL *v5; // ecx
  void (__thiscall *Draw)(Scaleform::Render::HAL *, const Scaleform::Render::RenderQueueItem *); // edx
  _DWORD v7[2]; // [esp+0h] [ebp-8h] BYREF

  pObject = p->pBundle.pObject;
  if ( pObject )
  {
    v5 = r->pHal.pObject;
    Draw = v5->Draw;
    v7[0] = pObject + 1;
    v7[1] = 0;
    Draw(v5, (const Scaleform::Render::RenderQueueItem *)v7);
  }
}
