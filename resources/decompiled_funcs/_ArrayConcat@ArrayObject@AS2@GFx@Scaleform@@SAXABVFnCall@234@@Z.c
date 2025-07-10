void __cdecl Scaleform::GFx::AS2::ArrayObject::ArrayConcat(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::Object *p_pProto; // edi
  Scaleform::GFx::AS2::ArrayObject *v4; // ebx
  int i; // edi
  Scaleform::MemoryHeap *Env; // ecx
  unsigned int v7; // eax
  Scaleform::GFx::AS2::Value *v8; // edx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value val; // [esp+4h] [ebp-10h] BYREF
  Scaleform::GFx::AS2::ArrayObject *ao; // [esp+18h] [ebp+4h]

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Array )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      p_pProto = (Scaleform::GFx::AS2::Object *)&ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    LOBYTE(p_pProto[1].pProto.pObject) = 0;
    v4 = (Scaleform::GFx::AS2::ArrayObject *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                               fn->Env,
                                               fn->Env->StringContext.pContext->pGlobal.pObject,
                                               (const Scaleform::GFx::ASString *)&fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].pASSupport,
                                               0,
                                               -1);
    ao = v4;
    if ( v4 )
    {
      Scaleform::GFx::AS2::Value::Value(&val, p_pProto);
      Scaleform::GFx::AS2::ArrayObject::Concat(v4, (Scaleform::MemoryHeap *)fn->Env, &val);
      if ( val.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&val);
      for ( i = 0; i < fn->NArgs; ++i )
      {
        Env = (Scaleform::MemoryHeap *)fn->Env;
        v7 = fn->FirstArgBottomIndex - i;
        v8 = 0;
        if ( v7 <= 32 * ((int)Env->pAutoRelease - 1) + (((char *)Env->pPrev - (char *)Env->pNext) >> 4) )
          v8 = (Scaleform::GFx::AS2::Value *)(*(_DWORD *)(Env->OwnerThreadId + 4 * (v7 >> 5)) + 16 * (v7 & 0x1F));
        v4 = ao;
        Scaleform::GFx::AS2::ArrayObject::Concat(ao, Env, v8);
      }
    }
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v4);
    if ( v4 )
    {
      RefCount = v4->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v4->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
      }
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
