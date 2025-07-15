void __cdecl Scaleform::GFx::AS2::RectangleProto::Inflate(const Scaleform::GFx::AS2::FnCall *fn)
{
  unsigned __int8 Type; // bl
  bool v2; // cc
  Scaleform::GFx::AS2::Environment *Env; // eax
  int v4; // edi
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // eax
  const Scaleform::GFx::AS2::Value *v6; // edx
  const Scaleform::GFx::AS2::Value *v7; // eax
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::RectangleObject *p_pProto; // edi
  Scaleform::GFx::AS2::Environment *v10; // eax
  long double v11; // st7
  Scaleform::GFx::AS2::Environment *v12; // [esp-8h] [ebp-5Ch]
  long double v13; // [esp+Ch] [ebp-48h]
  Scaleform::GFx::AS2::Value dw; // [esp+14h] [ebp-40h] BYREF
  Scaleform::GFx::AS2::Value v15; // [esp+24h] [ebp-30h] BYREF
  Scaleform::Render::Rect<double> o1; // [esp+34h] [ebp-20h] BYREF

  Type = 0;
  v2 = fn->NArgs <= 0;
  dw.T.Type = 0;
  v15.T.Type = 0;
  if ( !v2 )
  {
    Env = fn->Env;
    v4 = (char *)Env->Stack.pCurrent - (char *)Env->Stack.pPageStart;
    p_Stack = &Env->Stack;
    v6 = 0;
    if ( fn->FirstArgBottomIndex <= 32 * (p_Stack->Pages.Data.Size - 1) + (v4 >> 4) )
      v6 = &p_Stack->Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
    Scaleform::GFx::AS2::Value::operator=(&dw, v6);
    if ( fn->NArgs > 1 )
    {
      v7 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
      Scaleform::GFx::AS2::Value::operator=(&v15, v7);
      Type = v15.T.Type;
    }
  }
  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Rectangle )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      p_pProto = (Scaleform::GFx::AS2::RectangleObject *)&ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    v10 = fn->Env;
    o1.x1 = 0.0;
    o1.y1 = 0.0;
    o1.x2 = 0.0;
    o1.y2 = 0.0;
    Scaleform::GFx::AS2::RectangleObject::GetProperties(p_pProto, v10, &o1);
    v13 = Scaleform::GFx::AS2::Value::ToNumber(&dw, fn->Env);
    v11 = Scaleform::GFx::AS2::Value::ToNumber(&v15, fn->Env);
    v12 = fn->Env;
    o1.x1 = o1.x1 - v13;
    o1.x2 = v13 + o1.x2;
    o1.y1 = o1.y1 - v11;
    o1.y2 = v11 + o1.y2;
    Scaleform::GFx::AS2::RectangleObject::SetProperties(p_pProto, v12, &o1);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Rectangle");
  }
  if ( Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v15);
  if ( dw.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&dw);
}
