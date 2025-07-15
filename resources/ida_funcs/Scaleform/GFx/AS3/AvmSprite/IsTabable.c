char __thiscall Scaleform::GFx::AS3::AvmSprite::IsTabable(Scaleform::GFx::AS3::AvmSprite *this)
{
  Scaleform::GFx::AvmSpriteBase_vtbl *v3; // eax
  bool (__thiscall *OnEvent)(Scaleform::GFx::AvmDisplayObjBase *, const Scaleform::GFx::EventId *); // eax

  if ( !(*((unsigned __int8 (__thiscall **)(Scaleform::GFx::AvmSpriteBase_vtbl *))this[-1].~Scaleform::GFx::AvmDisplayObjBase
         + 57))(this[-1].Scaleform::GFx::AvmSpriteBase::Scaleform::GFx::AvmDisplayObjContainerBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable) )
    return 0;
  v3 = this[-1].Scaleform::GFx::AvmSpriteBase::Scaleform::GFx::AvmDisplayObjContainerBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable;
  if ( ((int)v3->ExecuteFrame0Events & 0x60) != 0 )
  {
    if ( ((int)v3->ExecuteFrame0Events & 0x60) != 0x60 )
      return 0;
    OnEvent = v3->OnEvent;
    if ( OnEvent )
    {
      while ( (*((_DWORD *)OnEvent + 26) & 0x8000) == 0 )
      {
        OnEvent = (bool (__thiscall *)(Scaleform::GFx::AvmDisplayObjBase *, const Scaleform::GFx::EventId *))*((_DWORD *)OnEvent + 8);
        if ( !OnEvent )
          return 1;
      }
      return 0;
    }
    return 1;
  }
  if ( SLOWORD(v3->ExecuteFrameTags) > 0 )
    return 1;
  return this->Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Flags
       & 1;
}


bool __thiscall Scaleform::GFx::AS3::AvmSprite::IsTabable(char *this)
{
  return Scaleform::GFx::AS3::AvmSprite::IsTabable((Scaleform::GFx::AS3::AvmSprite *)(this - 8));
}


bool __thiscall Scaleform::GFx::AS3::AvmSprite::IsTabable(char *this)
{
  return Scaleform::GFx::AS3::AvmSprite::IsTabable((Scaleform::GFx::AS3::AvmSprite *)(this - 12));
}
