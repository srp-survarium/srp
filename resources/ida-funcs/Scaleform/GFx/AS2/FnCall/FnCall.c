void __thiscall Scaleform::GFx::AS2::FnCall::FnCall(
        Scaleform::GFx::AS2::FnCall *this,
        Scaleform::GFx::AS2::Value *ResIn,
        Scaleform::GFx::AS2::Value *ThisIn,
        Scaleform::GFx::AS2::Environment *EnvIn,
        int NargsIn,
        int FirstIn)
{
  Scaleform::GFx::AS2::AvmCharacter *v7; // eax
  Scaleform::GFx::AS2::ObjectInterface *v8; // eax
  Scaleform::GFx::AS2::Object *v9; // eax
  Scaleform::GFx::AS2::FunctionRef *v10; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int v13; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  Scaleform::GFx::AS2::FunctionRef result; // [esp+10h] [ebp-Ch] BYREF

  this->__vftable = (Scaleform::GFx::AS2::FnCall_vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
  this->Result = ResIn;
  if ( ThisIn->T.Type != 7 )
  {
    v9 = Scaleform::GFx::AS2::Value::ToObject(ThisIn, EnvIn);
    if ( v9 )
    {
      v8 = &v9->Scaleform::GFx::AS2::ObjectInterface;
      goto LABEL_7;
    }
LABEL_6:
    v8 = 0;
    goto LABEL_7;
  }
  v7 = Scaleform::GFx::AS2::Value::ToAvmCharacter(ThisIn, EnvIn);
  if ( !v7 )
    goto LABEL_6;
  v8 = &v7->Scaleform::GFx::AS2::ObjectInterface;
LABEL_7:
  this->ThisPtr = v8;
  this->ThisFunctionRef.Flags = 0;
  this->ThisFunctionRef.Function = 0;
  this->ThisFunctionRef.pLocalFrame = 0;
  this->Env = EnvIn;
  this->NArgs = NargsIn;
  this->FirstArgBottomIndex = FirstIn;
  if ( ThisIn->T.Type == 8 || ThisIn->T.Type == 11 )
  {
    v10 = Scaleform::GFx::AS2::Value::ToFunction(ThisIn, &result, EnvIn);
    Scaleform::GFx::AS2::FunctionRefBase::Assign(&this->ThisFunctionRef, v10);
    if ( (result.Flags & 2) == 0 )
    {
      if ( result.Function )
      {
        RefCount = result.Function->RefCount;
        Function = result.Function;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          result.Function->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
        }
      }
    }
    result.Function = 0;
    if ( (result.Flags & 1) == 0 && result.pLocalFrame )
    {
      v13 = result.pLocalFrame->RefCount;
      pLocalFrame = result.pLocalFrame;
      if ( (v13 & 0x3FFFFFF) != 0 )
      {
        result.pLocalFrame->RefCount = v13 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
}


void __thiscall Scaleform::GFx::AS2::FnCall::FnCall(
        Scaleform::GFx::AS2::FnCall *this,
        Scaleform::GFx::AS2::Value *ResIn,
        Scaleform::GFx::AS2::ObjectInterface *ThisIn,
        Scaleform::GFx::AS2::Environment *EnvIn,
        int NargsIn,
        int FirstIn)
{
  this->Result = ResIn;
  this->ThisPtr = ThisIn;
  this->__vftable = (Scaleform::GFx::AS2::FnCall_vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
  this->ThisFunctionRef.Flags = 0;
  this->ThisFunctionRef.Function = 0;
  this->ThisFunctionRef.pLocalFrame = 0;
  this->Env = EnvIn;
  this->NArgs = NargsIn;
  this->FirstArgBottomIndex = FirstIn;
}
