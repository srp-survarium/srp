void __thiscall Scaleform::Render::TreeRoot::SetViewport(
        Scaleform::Render::TreeRoot *this,
        const Scaleform::Render::Viewport *vp)
{
  if ( !Scaleform::Render::Viewport::operator==(
          (Scaleform::Render::Viewport *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                                                    + 4
                                                    * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000))
                                                     / 28)
                                                    + 20)
                                        + 160),
          vp) )
    qmemcpy(&Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x1000u)[20], vp, 0x2Cu);
}
