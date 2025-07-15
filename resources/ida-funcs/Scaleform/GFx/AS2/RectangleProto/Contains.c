void __cdecl Scaleform::GFx::AS2::RectangleProto::Contains(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // eax
  int v2; // edi
  unsigned int Size; // ebx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // eax
  const Scaleform::GFx::AS2::Value *v; // edx
  Scaleform::GFx::AS2::Environment *v6; // ecx
  int v7; // edi
  unsigned int v8; // ebx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v9; // ecx
  unsigned int v10; // eax
  const Scaleform::GFx::AS2::Value *v11; // edx
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::RectangleObject *p_pProto; // ecx
  Scaleform::GFx::AS2::Environment *v14; // eax
  Scaleform::GFx::AS2::Value *v15; // esi
  Scaleform::GFx::AS2::Value *v16; // esi
  Scaleform::GFx::AS2::Value *Result; // esi
  double pyn; // [esp+40h] [ebp-50h]
  double pxn; // [esp+48h] [ebp-48h]
  Scaleform::GFx::AS2::Value py; // [esp+50h] [ebp-40h] BYREF
  Scaleform::GFx::AS2::Value px; // [esp+60h] [ebp-30h] BYREF
  Scaleform::Render::Rect<double> r; // [esp+70h] [ebp-20h] BYREF

  if ( fn->NArgs <= 1 )
  {
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 2;
    Result->V.BooleanValue = 0;
  }
  else
  {
    Env = fn->Env;
    v2 = (char *)Env->Stack.pCurrent - (char *)Env->Stack.pPageStart;
    Size = Env->Stack.Pages.Data.Size;
    p_Stack = &Env->Stack;
    v = 0;
    if ( fn->FirstArgBottomIndex <= 32 * (Size - 1) + (v2 >> 4) )
      v = &p_Stack->Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
    Scaleform::GFx::AS2::Value::Value(&px, v);
    v6 = fn->Env;
    v7 = (char *)v6->Stack.pCurrent - (char *)v6->Stack.pPageStart;
    v8 = v6->Stack.Pages.Data.Size;
    v9 = &v6->Stack;
    v10 = fn->FirstArgBottomIndex - 1;
    v11 = 0;
    if ( v10 <= 32 * (v8 - 1) + (v7 >> 4) )
      v11 = &v9->Pages.Data.Data[v10 >> 5]->Values[v10 & 0x1F];
    Scaleform::GFx::AS2::Value::Value(&py, v11);
    if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Rectangle )
    {
      ThisPtr = fn->ThisPtr;
      if ( ThisPtr )
        p_pProto = (Scaleform::GFx::AS2::RectangleObject *)&ThisPtr[-2].pProto;
      else
        p_pProto = 0;
      v14 = fn->Env;
      r.x1 = 0.0;
      r.y1 = 0.0;
      r.x2 = 0.0;
      r.y2 = 0.0;
      Scaleform::GFx::AS2::RectangleObject::GetProperties(p_pProto, v14, &r);
      pxn = Scaleform::GFx::AS2::Value::ToNumber(&px, fn->Env);
      pyn = Scaleform::GFx::AS2::Value::ToNumber(&py, fn->Env);
      if ( Scaleform::GFx::NumberUtil::IsNaN(pxn) || Scaleform::GFx::NumberUtil::IsNaN(pyn) )
      {
        v16 = fn->Result;
        Scaleform::GFx::AS2::Value::DropRefs(v16);
        v16->T.Type = 2;
        v16->V.BooleanValue = 0;
        if ( py.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&py);
        if ( px.T.Type >= 5u )
          goto LABEL_28;
      }
      else
      {
        if ( pxn == r.x2 )
          pxn = pxn + 1.0;
        if ( pyn == r.y2 )
          pyn = pyn + 1.0;
        v15 = fn->Result;
        Scaleform::GFx::AS2::Value::DropRefs(v15);
        v15->T.Type = 2;
        v15->V.BooleanValue = Scaleform::Render::Rect<double>::Contains(&r, pxn, pyn);
        if ( py.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&py);
        if ( px.T.Type >= 5u )
          goto LABEL_28;
      }
    }
    else
    {
      Scaleform::GFx::AS2::Environment::LogScriptError(
        fn->Env,
        "Error: Null or invalid 'this' is used for a method of %s class.\n",
        "Rectangle");
      if ( py.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&py);
      if ( px.T.Type >= 5u )
LABEL_28:
        Scaleform::GFx::AS2::Value::DropRefs(&px);
    }
  }
}
