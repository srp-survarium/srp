void __cdecl Scaleform::GFx::AS2::MatrixProto::Invert(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::MatrixObject *p_pProto; // edi
  Scaleform::Render::Matrix2x4<float> *Matrix; // eax
  const Scaleform::Render::Matrix2x4<float> *v4; // eax
  Scaleform::Render::Matrix2x4<float> result; // [esp+10h] [ebp-20h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Matrix )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = (Scaleform::GFx::AS2::MatrixObject *)&ThisPtr[-2].pProto;
      if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 )
      {
        Matrix = Scaleform::GFx::AS2::MatrixObject::GetMatrix(
                   (Scaleform::GFx::AS2::MatrixObject *)&ThisPtr[-2].pProto,
                   &result,
                   fn->Env);
        v4 = Scaleform::Render::Matrix2x4<float>::Invert(Matrix);
        Scaleform::GFx::AS2::MatrixObject::SetMatrix(p_pProto, fn->Env, v4);
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
