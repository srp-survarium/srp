void __thiscall Scaleform::GFx::AS3::AvmSprite::ExecuteFrameTags(
        Scaleform::GFx::AS3::AvmSprite *this,
        unsigned int frame)
{
  Scaleform::GFx::InteractiveObject *pDispObj; // ecx

  pDispObj = (Scaleform::GFx::InteractiveObject *)this->pDispObj;
  this->Flags |= 2u;
  if ( Scaleform::GFx::InteractiveObject::IsInPlayList(pDispObj) )
    Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList((Scaleform::GFx::InteractiveObject *)this->pDispObj);
  this->pDispObj->Flags &= ~0x20u;
}


void __thiscall Scaleform::GFx::AS3::AvmSprite::ExecuteFrameTags(char *this, unsigned int a2)
{
  Scaleform::GFx::AS3::AvmSprite::ExecuteFrameTags((Scaleform::GFx::AS3::AvmSprite *)(this - 40), a2);
}
