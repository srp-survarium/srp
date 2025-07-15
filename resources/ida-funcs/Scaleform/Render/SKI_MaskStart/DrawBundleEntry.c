void __thiscall Scaleform::Render::SKI_MaskStart::DrawBundleEntry(
        Scaleform::Render::SKI_UserData *this,
        void *__formal,
        Scaleform::Render::BundleEntry *p,
        Scaleform::Render::Renderer2DImpl *r2d)
{
  Scaleform::Render::Bundle *pObject; // eax
  Scaleform::Render::HAL *v5; // ecx
  Scaleform::ArrayLH<Scaleform::Render::BundleEntry *,2,Scaleform::ArrayDefaultPolicy> *p_Entries; // eax
  void (__thiscall *Draw)(Scaleform::Render::HAL *, const Scaleform::Render::RenderQueueItem *); // eax
  _DWORD v8[2]; // [esp+0h] [ebp-8h] BYREF

  pObject = p->pBundle.pObject;
  if ( pObject )
  {
    v5 = r2d->pHal.pObject;
    if ( pObject == (Scaleform::Render::Bundle *)-32 )
      p_Entries = 0;
    else
      p_Entries = &pObject[1].Entries;
    v8[0] = p_Entries;
    Draw = v5->Draw;
    v8[1] = 0;
    Draw(v5, (const Scaleform::Render::RenderQueueItem *)v8);
  }
}
