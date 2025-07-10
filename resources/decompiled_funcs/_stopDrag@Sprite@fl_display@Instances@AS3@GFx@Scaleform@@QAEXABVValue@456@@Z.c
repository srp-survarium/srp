void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Sprite::stopDrag(
        Scaleform::GFx::AS3::Instances::fl_display::Sprite *this,
        const Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::InteractiveObject *pObject; // esi
  unsigned int Flags; // eax
  int v5; // eax

  Scaleform::GFx::MovieImpl::StopDrag(this->pDispObj.pObject->pASRoot->pMovieImpl, 0);
  pObject = (Scaleform::GFx::InteractiveObject *)this->pDispObj.pObject;
  Flags = pObject->Flags;
  LOBYTE(Flags) = (Flags & 0x200000) != 0 && (Flags >>= 22, (Flags & 1) == 0);
  v5 = pObject->CheckAdvanceStatus(pObject, Flags);
  if ( v5 == -1 )
  {
    pObject->Flags |= (unsigned int)Scaleform::GFx::AS2::CreateShadow;
  }
  else if ( v5 == 1 )
  {
    Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(pObject);
  }
}
