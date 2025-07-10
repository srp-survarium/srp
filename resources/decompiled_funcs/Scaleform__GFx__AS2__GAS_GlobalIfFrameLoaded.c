void __cdecl Scaleform::GFx::AS2::GAS_GlobalIfFrameLoaded(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // edi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // ecx
  void *Target; // edi
  Scaleform::GFx::AS2::Value *v4; // eax
  int v5; // ebp
  Scaleform::GFx::AS2::Value *v6; // esi
  Scaleform::GFx::AS2::Environment *Env; // [esp-Ch] [ebp-10h]

  if ( fn->NArgs >= 1 )
  {
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 2;
    Result->V.BooleanValue = 0;
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      if ( ThisPtr->GetObjectType(ThisPtr) != Object_Sprite )
        return;
      Target = fn->ThisPtr;
    }
    else
    {
      Target = fn->Env->Target;
    }
    if ( Target )
    {
      Env = fn->Env;
      v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      v5 = Scaleform::GFx::AS2::Value::ToInt32(v4, Env);
      if ( v5 < (*(int (__thiscall **)(void *))(*(_DWORD *)Target + 436))(Target) )
      {
        v6 = fn->Result;
        Scaleform::GFx::AS2::Value::DropRefs(v6);
        v6->T.Type = 2;
        v6->V.BooleanValue = 1;
      }
    }
  }
}
