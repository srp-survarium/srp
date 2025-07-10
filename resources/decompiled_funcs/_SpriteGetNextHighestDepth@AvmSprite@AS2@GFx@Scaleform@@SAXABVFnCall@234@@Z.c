void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteGetNextHighestDepth(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::GFx::InteractiveObject *Target; // eax
  int LargestDepthInUse; // eax
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
    LargestDepthInUse = Scaleform::GFx::DisplayList::GetLargestDepthInUse((Scaleform::GFx::DisplayList *)&Target[1]);
    Result = fn->Result;
    v5 = (LargestDepthInUse - 0x3FFF) & ((LargestDepthInUse - 0x3FFF < 0) - 1);
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
    Result->NV.Int32Value = v5;
    Result->T.Type = 4;
  }
}
