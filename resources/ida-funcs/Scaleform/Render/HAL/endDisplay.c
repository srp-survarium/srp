void __thiscall Scaleform::Render::HAL::EndDisplay(Scaleform::Render::HAL *this)
{
  Scaleform::Render::HAL_vtbl *v2; // eax
  void (__thiscall *Draw)(Scaleform::Render::HAL *, const Scaleform::Render::RenderQueueItem *); // edx
  _DWORD v4[2]; // [esp+4h] [ebp-8h] BYREF

  v2 = this->__vftable;
  if ( (this->HALState & 0x200) != 0 )
  {
    ((void (*)(void))v2->Flush)();
    this->endDisplay(this);
  }
  else
  {
    Draw = v2->Draw;
    v4[0] = &Scaleform::Render::HALEndDisplayItem::Instance;
    v4[1] = 0;
    Draw(this, (const Scaleform::Render::RenderQueueItem *)v4);
  }
}
