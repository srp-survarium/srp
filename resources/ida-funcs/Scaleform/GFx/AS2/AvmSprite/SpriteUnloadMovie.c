void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteUnloadMovie(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::GFx::InteractiveObject *Target; // eax

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
    Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntry(
      (Scaleform::GFx::AS2::MovieRoot *)Target->pASRoot,
      (Scaleform::String)Target,
      (const __m128i *)uri,
      LM_None,
      0);
}
