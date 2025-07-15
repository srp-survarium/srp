void __cdecl Scaleform::GFx::AS2::AvmCharacter::CharacterGetDepth(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::GFx::InteractiveObject *Target; // eax
  Scaleform::GFx::AS2::Value *Result; // esi
  int Depth; // ebx

  ThisPtr = fn->ThisPtr;
  if ( (unsigned int)(ThisPtr->GetObjectType(ThisPtr) - 2) > 3 )
    Target = 0;
  else
    Target = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].__vftable;
  if ( !Target )
    Target = fn->Env->Target;
  Result = fn->Result;
  Depth = Target->Depth;
  if ( Result->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  Result->NV.Int32Value = Depth - 0x4000;
  Result->T.Type = 4;
}
