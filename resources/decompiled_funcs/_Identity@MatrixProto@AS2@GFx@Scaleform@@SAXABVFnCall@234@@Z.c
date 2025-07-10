void __cdecl Scaleform::GFx::AS2::MatrixProto::Identity(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::MatrixObject *p_pProto; // ecx
  Scaleform::GFx::AS2::Environment *Env; // eax
  Scaleform::Render::Matrix2x4<float> m; // [esp+10h] [ebp-20h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Matrix )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = (Scaleform::GFx::AS2::MatrixObject *)&ThisPtr[-2].pProto;
      if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 )
      {
        Env = fn->Env;
        m.M[0][0] = 1.0;
        m.M[0][1] = 0.0;
        m.M[0][2] = 0.0;
        m.M[0][3] = 0.0;
        m.M[1][0] = 0.0;
        m.M[1][2] = 0.0;
        m.M[1][3] = 0.0;
        m.M[1][1] = 1.0;
        Scaleform::GFx::AS2::MatrixObject::SetMatrix(p_pProto, Env, &m);
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
