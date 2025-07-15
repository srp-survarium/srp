char __thiscall Scaleform::GFx::AS2::AvmSprite::ActsAsButton(Scaleform::GFx::AS2::AvmSprite *this)
{
  Scaleform::GFx::AS2::MovieClipObject *pObject; // eax

  if ( !this->IsLevelMovie(&this->Scaleform::GFx::AvmSpriteBase)
    && (this->pDispObj->Flags & 0x10) != 0
    && ((pObject = this->ASMovieClipObj.pObject) != 0
     || (pObject = (Scaleform::GFx::AS2::MovieClipObject *)this->pProto.pObject) != 0) )
  {
    return Scaleform::GFx::AS2::MovieClipObject::ActsAsButton(pObject);
  }
  else
  {
    return 0;
  }
}


char __thiscall Scaleform::GFx::AS2::AvmSprite::ActsAsButton(char *this)
{
  return Scaleform::GFx::AS2::AvmSprite::ActsAsButton((Scaleform::GFx::AS2::AvmSprite *)(this - 24));
}
