void __cdecl Scaleform::GFx::AS2::AvmSprite::SpritePrevFrame(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::GFx::InteractiveObject *Target; // esi
  int v3; // eax

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( ThisPtr->GetObjectType(fn->ThisPtr) == Object_Sprite )
      Target = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].__vftable;
    else
      Target = 0;
  }
  else
  {
    Target = fn->Env->Target;
  }
  if ( Target )
  {
    v3 = Target->GetCurrentFrame(Target);
    if ( v3 > 0 )
      Target->GotoFrame(Target, v3 - 1);
    Target->SetPlayState(Target, State_Stopped);
  }
}
