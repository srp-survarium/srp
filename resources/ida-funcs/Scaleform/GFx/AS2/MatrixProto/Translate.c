void __cdecl Scaleform::GFx::AS2::MatrixProto::Translate(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::MatrixObject *p_pProto; // edi
  Scaleform::GFx::AS2::Value *v3; // eax
  Scaleform::GFx::AS2::Value *v4; // eax
  Scaleform::GFx::AS2::Environment *v5; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp-4h] [ebp-34h]
  Scaleform::GFx::AS2::Environment *v7; // [esp-4h] [ebp-34h]
  float v8; // [esp+8h] [ebp-28h]
  float v9; // [esp+Ch] [ebp-24h]
  Scaleform::Render::Matrix2x4<float> result; // [esp+10h] [ebp-20h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Matrix )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = (Scaleform::GFx::AS2::MatrixObject *)&ThisPtr[-2].pProto;
      if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 && fn->NArgs > 1 )
      {
        Env = fn->Env;
        v3 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        v8 = Scaleform::GFx::AS2::Value::ToNumber(v3, Env);
        v7 = fn->Env;
        v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
        v9 = Scaleform::GFx::AS2::Value::ToNumber(v4, v7);
        Scaleform::GFx::AS2::MatrixObject::GetMatrix(p_pProto, &result, fn->Env);
        v5 = fn->Env;
        result.M[0][3] = result.M[0][3] + v8;
        result.M[1][3] = result.M[1][3] + v9;
        Scaleform::GFx::AS2::MatrixObject::SetMatrix(p_pProto, v5, &result);
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
