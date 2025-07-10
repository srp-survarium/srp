void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteNextFrame(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::GFx::InteractiveObject *Target; // esi
  int v3; // edi
  int v4; // eax

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
    v3 = Target->GetLoadingFrame(Target);
    v4 = Target->GetCurrentFrame(Target);
    if ( v4 < v3 )
      Target->GotoFrame(Target, v4 + 1);
    Target->SetPlayState(Target, State_Stopped);
  }
}
