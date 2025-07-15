void __cdecl Scaleform::GFx::AS2::MatrixProto::Concat(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::MatrixObject *p_pProto; // ebx
  Scaleform::GFx::AS2::Value *v3; // eax
  Scaleform::GFx::AS2::MatrixObject *v4; // edi
  const Scaleform::Render::Matrix2x4<float> *Matrix; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp-4h] [ebp-54h]
  Scaleform::Render::Matrix2x4<float> result; // [esp+10h] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> v8; // [esp+30h] [ebp-20h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Matrix )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = (Scaleform::GFx::AS2::MatrixObject *)&ThisPtr[-2].pProto;
      if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 && fn->NArgs > 0 )
      {
        Env = fn->Env;
        v3 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        v4 = (Scaleform::GFx::AS2::MatrixObject *)Scaleform::GFx::AS2::Value::ToObject(v3, Env);
        if ( v4->GetObjectType(&v4->Scaleform::GFx::AS2::ObjectInterface) == Object_Matrix )
        {
          Scaleform::GFx::AS2::MatrixObject::GetMatrix(p_pProto, &result, fn->Env);
          Matrix = Scaleform::GFx::AS2::MatrixObject::GetMatrix(v4, &v8, fn->Env);
          Scaleform::Render::Matrix2x4<float>::Append(&result, Matrix);
          Scaleform::GFx::AS2::MatrixObject::SetMatrix(p_pProto, fn->Env, &result);
        }
      }
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
