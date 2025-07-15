void __cdecl Scaleform::GFx::AS2::DateProto::DateGetMonth(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // eax
  Scaleform::GFx::AS2::Object *pObject; // ecx
  int v5; // esi
  int v6; // ebx
  bool v7; // al
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::AS2::Value *v9; // esi
  int i; // [esp+8h] [ebp+4h]

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Date )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      p_pProto = &ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    pObject = p_pProto[23].pObject;
    v5 = 0;
    v6 = (int)p_pProto[24].pObject;
    while ( 1 )
    {
      v7 = !((int)pObject % 4) && ((int)pObject % 100 || !((int)pObject % 400));
      if ( v6 < months[v7][v5] )
        break;
      if ( ++v5 >= 12 )
      {
        Result = fn->Result;
        if ( Result->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
        Result->NV.NumberValue = -1.0;
        Result->T.Type = 3;
        return;
      }
    }
    i = v5;
    v9 = fn->Result;
    if ( v9->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
    v9->NV.NumberValue = (double)i;
    v9->T.Type = 3;
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Date");
  }
}
