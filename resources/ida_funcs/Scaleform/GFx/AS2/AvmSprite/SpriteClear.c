void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteClear(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::GFx::InteractiveObject *Target; // esi
  Scaleform::GFx::DrawingContext *v3; // eax

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
    if ( Target->GetDrawingContext(Target) )
    {
      v3 = Target->GetDrawingContext(Target);
      Scaleform::GFx::DrawingContext::Clear(v3);
    }
    Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(Target);
    Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)Target);
  }
}
