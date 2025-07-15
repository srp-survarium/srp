void __cdecl Scaleform::GFx::AS2::MatrixProto::Clone(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::MatrixObject *p_pProto; // ebx
  Scaleform::GFx::AS2::Value *v3; // esi
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::MatrixObject *v5; // eax
  Scaleform::GFx::AS2::MatrixObject *v6; // eax
  Scaleform::GFx::AS2::MatrixObject *v7; // edi
  const Scaleform::Render::Matrix2x4<float> *Matrix; // eax
  unsigned int RefCount; // eax
  Scaleform::Render::Matrix2x4<float> result; // [esp+10h] [ebp-20h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Matrix )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr
      && (p_pProto = (Scaleform::GFx::AS2::MatrixObject *)&ThisPtr[-2].pProto,
          ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16) )
    {
      pHeap = fn->Env->StringContext.pContext->pHeap;
      v5 = (Scaleform::GFx::AS2::MatrixObject *)pHeap->Alloc(pHeap, 52u, 0);
      if ( v5 )
      {
        Scaleform::GFx::AS2::MatrixObject::MatrixObject(v5, fn->Env);
        v7 = v6;
      }
      else
      {
        v7 = 0;
      }
      Matrix = Scaleform::GFx::AS2::MatrixObject::GetMatrix(p_pProto, &result, fn->Env);
      Scaleform::GFx::AS2::MatrixObject::SetMatrix(v7, fn->Env, Matrix);
      Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v7);
      if ( v7 )
      {
        RefCount = v7->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v7->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
        }
      }
    }
    else
    {
      v3 = fn->Result;
      Scaleform::GFx::AS2::Value::DropRefs(v3);
      v3->T.Type = 0;
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Matrix");
  }
}
