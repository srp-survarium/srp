void __cdecl Scaleform::GFx::AS2::AvmSprite::InitializeClassInstance(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::GFx::AS2::AvmCharacter *p_pProto; // edi
  Scaleform::GFx::AS2::Environment *Env; // edx
  Scaleform::GFx::AS2::Value *v4; // ecx
  Scaleform::GFx::AS2::FunctionObject *Function; // esi
  Scaleform::GFx::AS2::ObjectInterface *v6; // eax
  unsigned __int8 Flags; // bl
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v10; // eax
  Scaleform::GFx::AS2::FunctionRef ctorFunc; // [esp+Ch] [ebp-Ch] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr->GetObjectType(ThisPtr) == Object_Sprite )
    p_pProto = (Scaleform::GFx::AS2::AvmCharacter *)&ThisPtr[-1].pProto;
  else
    p_pProto = 0;
  Env = fn->Env;
  v4 = 0;
  if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
    v4 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
  Scaleform::GFx::AS2::Value::ToFunction(v4, &ctorFunc, Env);
  Function = ctorFunc.Function;
  if ( ctorFunc.Function )
    v6 = &ctorFunc.Function->Scaleform::GFx::AS2::ObjectInterface;
  else
    v6 = 0;
  Scaleform::GFx::AS2::AvmCharacter::SetProtoToPrototypeOf(p_pProto, v6);
  Flags = ctorFunc.Flags;
  if ( (ctorFunc.Flags & 2) == 0 )
  {
    if ( Function )
    {
      RefCount = Function->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        Function->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
      }
    }
  }
  if ( (Flags & 1) == 0 )
  {
    pLocalFrame = ctorFunc.pLocalFrame;
    if ( ctorFunc.pLocalFrame )
    {
      v10 = ctorFunc.pLocalFrame->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v10) != 0 )
      {
        ctorFunc.pLocalFrame->RefCount = v10 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
}
