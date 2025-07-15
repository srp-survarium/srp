void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteStopDrag(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::GFx::Sprite *Target; // esi
  unsigned int Flags; // eax
  bool v4; // al
  int v5; // eax

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( ThisPtr->GetObjectType(fn->ThisPtr) == Object_Sprite )
      Target = (Scaleform::GFx::Sprite *)ThisPtr[1].__vftable;
    else
      Target = 0;
  }
  else
  {
    Target = (Scaleform::GFx::Sprite *)fn->Env->Target;
  }
  if ( Target )
  {
    Scaleform::GFx::MovieImpl::StopDrag(Target->pASRoot->pMovieImpl, 0);
    Flags = Target->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags;
    v4 = (Flags & 0x200000) != 0 && (Flags & 0x400000) == 0;
    v5 = Scaleform::GFx::Sprite::CheckAdvanceStatus(Target, v4);
    if ( v5 == -1 )
    {
      Target->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags |= (unsigned int)&loc_400000;
    }
    else if ( v5 == 1 )
    {
      Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(Target);
    }
  }
}
