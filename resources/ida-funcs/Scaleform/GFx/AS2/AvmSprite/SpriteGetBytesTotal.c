void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteGetBytesTotal(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::GFx::InteractiveObject *Target; // ecx
  int v3; // eax
  Scaleform::GFx::AS2::Value *Result; // esi
  int v5; // edi

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
    v3 = (int)Target->GetResourceMovieDef(Target);
    Result = fn->Result;
    v5 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v3 + 28) + 12) + 32) + 48);
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
    Result->NV.Int32Value = v5;
    Result->T.Type = 4;
  }
}
