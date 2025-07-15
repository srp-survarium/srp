bool __thiscall Scaleform::GFx::AS3::AvmSprite::ActsAsButton(Scaleform::GFx::AS3::AvmSprite *this)
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v2; // ecx

  if ( (this->Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Flags
      & 1) != 0 )
    return 1;
  if ( this[-1].Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AvmDisplayObjContainerBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable )
    goto LABEL_16;
  if ( !*(_DWORD *)&this[-1].MouseOverCnt )
    return 0;
  if ( !this[-1].Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AvmDisplayObjContainerBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable
    && !*(_DWORD *)&this[-1].MouseOverCnt )
  {
    return 1;
  }
LABEL_16:
  if ( this[-1].Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AvmDisplayObjContainerBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable )
    v2 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)this[-1].Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AvmDisplayObjContainerBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable;
  else
    v2 = *(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher **)&this[-1].MouseOverCnt;
  if ( ((unsigned __int8)v2 & 1) != 0 )
    v2 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)v2 - 1);
  return Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::HasButtonHandlers(v2);
}


bool __thiscall Scaleform::GFx::AS3::AvmSprite::ActsAsButton(char *this)
{
  return Scaleform::GFx::AS3::AvmSprite::ActsAsButton((Scaleform::GFx::AS3::AvmSprite *)(this - 8));
}


bool __thiscall Scaleform::GFx::AS3::AvmSprite::ActsAsButton(char *this)
{
  return Scaleform::GFx::AS3::AvmSprite::ActsAsButton((Scaleform::GFx::AS3::AvmSprite *)(this - 12));
}
