void __thiscall Scaleform::Render::TreeRoot::SetBackgroundColor(
        Scaleform::Render::TreeRoot *this,
        const Scaleform::Render::Color *color)
{
  if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                             + 4 * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000)) / 28)
                             + 20)
                 + 204) != color->Raw )
    *(Scaleform::Render::Color *)&Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x1000u)[25].Type = *color;
}
