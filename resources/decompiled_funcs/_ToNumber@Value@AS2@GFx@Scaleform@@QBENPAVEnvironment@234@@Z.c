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
  double retVal; // [esp+18h] [ebp-58h] BYREF
  Scaleform::GFx::AS2::FunctionRef func; // [esp+20h] [ebp-50h] BYREF
  Scaleform::GFx::AS2::Value toValueFunc; // [esp+2Ch] [ebp-44h] BYREF
  Scaleform::GFx::AS2::Value result; // [esp+3Ch] [ebp-34h] BYREF
  Scaleform::GFx::AS2::FnCall fnCall; // [esp+4Ch] [ebp-24h] BYREF

  Type = this->T.Type;
  if ( this->T.Type == 3 )
    return this->NV.NumberValue;
  switch ( Type )
  {
    case 4u:
      return (double)this->NV.Int32Value;
    case 5u:
      if ( Scaleform::GFx::AS2::StringToNumber((char *)this->V.pStringNode->pData, &retVal) )
        return retVal;
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
  toValueFunc.T.Type = 0;
  v5 = Scaleform::GFx::AS2::Value::ToObjectInterface(this, penv);
  v6 = v5;
  if ( penv
    && v5->GetMemberRaw(
         v5,
         &penv->StringContext,
         (const Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[25].pASSupport,
         &toValueFunc) )
  {
    FuncCallNestingLevel = penv->FuncCallNestingLevel;
    penv->FuncCallNestingLevel = FuncCallNestingLevel + 1;
    if ( FuncCallNestingLevel >= 0xFFu )
    {
      retVal = Scaleform::GFx::NumberUtil::NaN();
    }
    else
    {
      result.T.Type = 0;
      Scaleform::GFx::AS2::Value::ToFunction(&toValueFunc, &func, penv);
      Function = func.Function;
      pLocalFrame = func.pLocalFrame;
      if ( func.Function )
      {
        Scaleform::GFx::AS2::FnCall::FnCall(&fnCall, &result, v6, penv, 0, 0);
        Function->Invoke(Function, &fnCall, pLocalFrame, 0);
        Scaleform::GFx::AS2::FnCall::~FnCall(&fnCall);
      }
      if ( Scaleform::GFx::AS2::Value::IsPrimitive(&result) )
        v10 = Scaleform::GFx::AS2::Value::ToNumber(&result, penv);
      else
        v10 = Scaleform::GFx::NumberUtil::NaN();
      retVal = v10;
      if ( (func.Flags & 2) == 0 )
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
      if ( (func.Flags & 1) == 0 )
      {
        if ( pLocalFrame )
        {
          v12 = pLocalFrame->RefCount;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v12) != 0 )
          {
            pLocalFrame->RefCount = v12 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
          }
        }
      }
      if ( result.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&result);
    }
    --penv->FuncCallNestingLevel;
    v13 = toValueFunc.T.Type < 5u;
    goto LABEL_41;
  }
  if ( this->T.Type == 7 )
  {
    v14 = Scaleform::GFx::NumberUtil::NaN();
LABEL_40:
    v13 = toValueFunc.T.Type < 5u;
    retVal = v14;
LABEL_41:
    if ( !v13 )
      Scaleform::GFx::AS2::Value::DropRefs(&toValueFunc);
    return retVal;
  }
  v15 = (char *)v6->GetTextValue(v6, penv);
  if ( v15 )
  {
    v14 = atof(v15);
    goto LABEL_40;
  }
  if ( toValueFunc.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&toValueFunc);
  return 0.0;
}
