long double __thiscall Scaleform::GFx::AS2::Value::ToNumber(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  unsigned __int8 Type; // al
  Scaleform::GFx::AS2::ObjectInterface *v5; // eax
  Scaleform::GFx::AS2::ObjectInterface *v6; // ebp
  unsigned __int16 FuncCallNestingLevel; // ax
  Scaleform::GFx::AS2::FunctionObject *Function; // edi
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ebx
  long double v10; // st7
  unsigned int RefCount; // eax
  unsigned int v12; // eax
  bool v13; // cf
  long double v14; // st7
  char *v15; // eax
  double v16; // [esp+18h] [ebp-58h] BYREF
  Scaleform::GFx::AS2::FunctionRef result; // [esp+20h] [ebp-50h] BYREF
  Scaleform::GFx::AS2::Value v18; // [esp+2Ch] [ebp-44h] BYREF
  Scaleform::GFx::AS2::Value ResIn; // [esp+3Ch] [ebp-34h] BYREF
  Scaleform::GFx::AS2::FnCall v20; // [esp+4Ch] [ebp-24h] BYREF

  Type = this->T.Type;
  if ( this->T.Type == 3 )
    return this->NV.NumberValue;
  switch ( Type )
  {
    case 4u:
      return (double)this->NV.Int32Value;
    case 5u:
      if ( Scaleform::GFx::AS2::StringToNumber((char *)this->V.pStringNode->pData, (int)this, &v16) )
        return v16;
      return Scaleform::GFx::NumberUtil::NaN();
    case 1u:
      if ( penv->StringContext.SWFVersion <= 6u )
        return 0.0;
      return Scaleform::GFx::NumberUtil::NaN();
    case 2u:
      if ( this->V.BooleanValue )
        return 1.0;
      return 0.0;
    case 7u:
      return Scaleform::GFx::NumberUtil::NaN();
  }
  if ( (Type != 6 || !this->NV.Int32Value) && Type != 8 )
  {
    if ( !Scaleform::GFx::AS2::Value::IsUndefined(this) || (unsigned int)penv->StringContext.SWFVersion - 1 <= 5 )
      return 0.0;
    return Scaleform::GFx::NumberUtil::NaN();
  }
  v18.T.Type = 0;
  v5 = Scaleform::GFx::AS2::Value::ToObjectInterface(this, penv);
  v6 = v5;
  if ( penv
    && v5->GetMemberRaw(
         v5,
         &penv->StringContext,
         (const Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[25].pASSupport,
         &v18) )
  {
    FuncCallNestingLevel = penv->FuncCallNestingLevel;
    penv->FuncCallNestingLevel = FuncCallNestingLevel + 1;
    if ( FuncCallNestingLevel >= 0xFFu )
    {
      v16 = Scaleform::GFx::NumberUtil::NaN();
      if ( penv->IsVerboseActionErrors(penv) )
        Scaleform::GFx::AS2::Environment::LogScriptError(
          penv,
          "Stack overflow, max level of 255 nested calls of valueOf is reached.");
    }
    else
    {
      ResIn.T.Type = 0;
      Scaleform::GFx::AS2::Value::ToFunction(&v18, &result, penv);
      Function = result.Function;
      pLocalFrame = result.pLocalFrame;
      if ( result.Function )
      {
        Scaleform::GFx::AS2::FnCall::FnCall(&v20, &ResIn, v6, penv, 0, 0);
        Function->Invoke(Function, &v20, pLocalFrame, 0);
        Scaleform::GFx::AS2::FnCall::~FnCall(&v20);
      }
      if ( Scaleform::GFx::AS2::Value::IsPrimitive(&ResIn) )
        v10 = Scaleform::GFx::AS2::Value::ToNumber(&ResIn, penv);
      else
        v10 = Scaleform::GFx::NumberUtil::NaN();
      v16 = v10;
      if ( (result.Flags & 2) == 0 )
      {
        if ( Function )
        {
          RefCount = Function->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            Function->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
          }
        }
      }
      if ( (result.Flags & 1) == 0 )
      {
        if ( pLocalFrame )
        {
          v12 = pLocalFrame->RefCount;
          if ( (v12 & 0x3FFFFFF) != 0 )
          {
            pLocalFrame->RefCount = v12 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
          }
        }
      }
      if ( ResIn.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&ResIn);
    }
    --penv->FuncCallNestingLevel;
    v13 = v18.T.Type < 5u;
    goto LABEL_42;
  }
  if ( this->T.Type == 7 )
  {
    v14 = Scaleform::GFx::NumberUtil::NaN();
LABEL_41:
    v13 = v18.T.Type < 5u;
    v16 = v14;
LABEL_42:
    if ( !v13 )
      Scaleform::GFx::AS2::Value::DropRefs(&v18);
    return v16;
  }
  v15 = (char *)v6->GetTextValue(v6, penv);
  if ( v15 )
  {
    v14 = atof((int)this, v15);
    goto LABEL_41;
  }
  if ( v18.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v18);
  return 0.0;
}
