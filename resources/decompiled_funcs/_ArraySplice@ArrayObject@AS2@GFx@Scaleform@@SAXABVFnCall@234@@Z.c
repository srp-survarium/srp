void __cdecl Scaleform::GFx::AS2::ArrayObject::ArraySplice(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::ArrayObject *p_pProto; // ebp
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::AS2::Value *v5; // eax
  int v6; // eax
  int v7; // ebx
  signed int Size; // eax
  int v9; // edi
  Scaleform::GFx::AS2::Value *v10; // eax
  signed int v11; // eax
  Scaleform::GFx::AS2::ArrayObject *v12; // ecx
  int v13; // ebp
  Scaleform::GFx::AS2::Value **Data; // edx
  int NArgs; // eax
  int i; // edi
  Scaleform::GFx::AS2::Environment *v17; // ecx
  int v18; // ebx
  unsigned int v19; // ebp
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // ecx
  unsigned int v21; // eax
  const Scaleform::GFx::AS2::Value *v22; // edx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Environment *v24; // [esp-10h] [ebp-20h]
  Scaleform::GFx::AS2::Environment *Env; // [esp-Ch] [ebp-1Ch]
  int start; // [esp+4h] [ebp-Ch]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *ao; // [esp+8h] [ebp-8h]
  int v28; // [esp+Ch] [ebp-4h]
  Scaleform::GFx::AS2::ArrayObject *pThis; // [esp+14h] [ebp+4h]

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Array )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = (Scaleform::GFx::AS2::ArrayObject *)&ThisPtr[-2].pProto;
      pThis = (Scaleform::GFx::AS2::ArrayObject *)&ThisPtr[-2].pProto;
    }
    else
    {
      pThis = 0;
      p_pProto = 0;
    }
    if ( fn->NArgs )
    {
      p_pProto->LengthValueOverriden = 0;
      Env = fn->Env;
      v5 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      v6 = Scaleform::GFx::AS2::Value::ToInt32(v5, Env);
      v7 = v6;
      start = v6;
      if ( v6 < 0 )
      {
        v7 = p_pProto->Elements.Data.Size + v6;
        start = v7;
        if ( v7 < 0 )
        {
          v7 = 0;
          start = 0;
        }
      }
      Size = p_pProto->Elements.Data.Size;
      if ( v7 > Size )
      {
        v7 = p_pProto->Elements.Data.Size;
        start = v7;
      }
      v9 = Size - v7;
      if ( fn->NArgs >= 2 )
      {
        v24 = fn->Env;
        v10 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
        v9 = Scaleform::GFx::AS2::Value::ToInt32(v10, v24);
        if ( v9 < 0 )
          v9 = 0;
        v11 = p_pProto->Elements.Data.Size;
        if ( v9 + v7 >= v11 )
          v9 = v11 - v7;
      }
      v12 = (Scaleform::GFx::AS2::ArrayObject *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                                  fn->Env,
                                                  fn->Env->StringContext.pContext->pGlobal.pObject,
                                                  (const Scaleform::GFx::ASString *)&fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].pASSupport,
                                                  0,
                                                  -1);
      ao = v12;
      if ( v12 )
      {
        if ( v9 > 0 )
        {
          v13 = v7;
          v28 = v9;
          do
          {
            Data = pThis->Elements.Data.Data;
            if ( Data[v13] )
              Scaleform::GFx::AS2::ArrayObject::PushBack(v12, Data[v13]);
            else
              Scaleform::GFx::AS2::ArrayObject::PushBack(v12);
            v12 = (Scaleform::GFx::AS2::ArrayObject *)ao;
            ++v13;
            --v28;
          }
          while ( v28 );
          p_pProto = pThis;
        }
        Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v12);
        if ( v9 )
          Scaleform::GFx::AS2::ArrayObject::RemoveElements(p_pProto, v7, v9);
        NArgs = fn->NArgs;
        if ( NArgs >= 3 )
        {
          Scaleform::GFx::AS2::ArrayObject::InsertEmpty(p_pProto, v7, NArgs - 2);
          for ( i = 2; i < fn->NArgs; ++i )
          {
            v17 = fn->Env;
            v18 = (char *)v17->Stack.pCurrent - (char *)v17->Stack.pPageStart;
            v19 = v17->Stack.Pages.Data.Size;
            p_Stack = &v17->Stack;
            v21 = fn->FirstArgBottomIndex - i;
            v22 = 0;
            if ( v21 <= 32 * (v19 - 1) + (v18 >> 4) )
              v22 = &p_Stack->Pages.Data.Data[v21 >> 5]->Values[v21 & 0x1F];
            Scaleform::GFx::AS2::ArrayObject::SetElement(pThis, start + i - 2, v22);
          }
        }
        RefCount = ao->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
        {
          ao->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(ao);
        }
      }
    }
    else
    {
      Result = fn->Result;
      Scaleform::GFx::AS2::Value::DropRefs(Result);
      Result->T.Type = 0;
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Array");
  }
}
