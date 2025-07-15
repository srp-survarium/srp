void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteGetBytesLoaded(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::GFx::Sprite *Target; // ecx
  unsigned int BytesLoaded; // eax
  Scaleform::GFx::AS2::Value *Result; // esi
  unsigned int v5; // edi

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
    BytesLoaded = Scaleform::GFx::Sprite::GetBytesLoaded(Target);
    Result = fn->Result;
    v5 = BytesLoaded;
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
    Result->NV.Int32Value = v5;
    Result->T.Type = 4;
  }
}
