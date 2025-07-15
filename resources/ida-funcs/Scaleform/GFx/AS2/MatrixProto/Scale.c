void __cdecl Scaleform::GFx::AS2::MatrixProto::Scale(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::MatrixObject *p_pProto; // edi
  Scaleform::GFx::AS2::Value *v3; // eax
  Scaleform::GFx::AS2::Value *v4; // eax
  Scaleform::GFx::AS2::Environment *sy; // [esp+4h] [ebp-34h]
  Scaleform::GFx::AS2::Environment *sya; // [esp+4h] [ebp-34h]
  float v7; // [esp+10h] [ebp-28h]
  float sx; // [esp+14h] [ebp-24h]
  Scaleform::Render::Matrix2x4<float> result; // [esp+18h] [ebp-20h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Matrix )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = (Scaleform::GFx::AS2::MatrixObject *)&ThisPtr[-2].pProto;
      if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 && fn->NArgs > 1 )
      {
        sy = fn->Env;
        v3 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        sx = Scaleform::GFx::AS2::Value::ToNumber(v3, sy);
        sya = fn->Env;
        v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
        v7 = Scaleform::GFx::AS2::Value::ToNumber(v4, sya);
        Scaleform::GFx::AS2::MatrixObject::GetMatrix(p_pProto, &result, fn->Env);
        Scaleform::Render::Matrix2x4<float>::AppendScaling(&result, sx, v7);
        Scaleform::GFx::AS2::MatrixObject::SetMatrix(p_pProto, fn->Env, &result);
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
