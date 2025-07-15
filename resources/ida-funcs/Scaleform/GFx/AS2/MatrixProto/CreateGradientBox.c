void __cdecl Scaleform::GFx::AS2::MatrixProto::CreateGradientBox(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::MatrixObject *p_pProto; // edi
  Scaleform::GFx::AS2::Environment *Env; // ecx
  Scaleform::GFx::AS2::Value *v4; // eax
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::AS2::Value *v6; // eax
  Scaleform::GFx::AS2::Value *v7; // eax
  Scaleform::GFx::AS2::Value *v8; // eax
  Scaleform::GFx::AS2::Environment *sx; // [esp+0h] [ebp-48h]
  Scaleform::GFx::AS2::Environment *radians; // [esp+4h] [ebp-44h]
  Scaleform::GFx::AS2::Environment *radiansa; // [esp+4h] [ebp-44h]
  Scaleform::GFx::AS2::Environment *radiansb; // [esp+4h] [ebp-44h]
  Scaleform::GFx::AS2::Environment *radiansc; // [esp+4h] [ebp-44h]
  Scaleform::GFx::AS2::Environment *radiansd; // [esp+4h] [ebp-44h]
  float radianse; // [esp+4h] [ebp-44h]
  float v16; // [esp+10h] [ebp-38h]
  float v17; // [esp+14h] [ebp-34h]
  float v18; // [esp+18h] [ebp-30h]
  float v19; // [esp+1Ch] [ebp-2Ch]
  float v20; // [esp+20h] [ebp-28h]
  float v21; // [esp+24h] [ebp-24h]
  float v22; // [esp+24h] [ebp-24h]
  float v23; // [esp+24h] [ebp-24h]
  float v24; // [esp+24h] [ebp-24h]
  Scaleform::Render::Matrix2x4<float> m; // [esp+28h] [ebp-20h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Matrix )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = (Scaleform::GFx::AS2::MatrixObject *)&ThisPtr[-2].pProto;
      if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 && fn->NArgs > 1 )
      {
        Env = fn->Env;
        m.M[0][0] = 1.0;
        radians = Env;
        m.M[0][1] = 0.0;
        m.M[0][2] = 0.0;
        m.M[0][3] = 0.0;
        m.M[1][0] = 0.0;
        m.M[1][2] = 0.0;
        m.M[1][3] = 0.0;
        m.M[1][1] = 1.0;
        v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        v20 = Scaleform::GFx::AS2::Value::ToNumber(v4, radians);
        radiansa = fn->Env;
        v5 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
        v19 = Scaleform::GFx::AS2::Value::ToNumber(v5, radiansa);
        v18 = 0.0;
        v16 = v20 * 0.5;
        v17 = 0.5 * v19;
        if ( fn->NArgs > 2 )
        {
          radiansb = fn->Env;
          v6 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
          v18 = Scaleform::GFx::AS2::Value::ToNumber(v6, radiansb);
          if ( fn->NArgs > 3 )
          {
            radiansc = fn->Env;
            v7 = Scaleform::GFx::AS2::FnCall::Arg(fn, 3);
            v21 = Scaleform::GFx::AS2::Value::ToNumber(v7, radiansc);
            v16 = v21 + v16;
            if ( fn->NArgs > 4 )
            {
              radiansd = fn->Env;
              v8 = Scaleform::GFx::AS2::FnCall::Arg(fn, 4);
              v22 = Scaleform::GFx::AS2::Value::ToNumber(v8, radiansd);
              v17 = v22 + v17;
            }
          }
        }
        Scaleform::Render::Matrix2x4<float>::AppendRotation(&m, v18);
        v23 = v19 * 0.0006103515625;
        radianse = v23;
        v24 = 0.0006103515625 * v20;
        Scaleform::Render::Matrix2x4<float>::AppendScaling(&m, v24, radianse);
        sx = fn->Env;
        m.M[0][3] = m.M[0][3] + v16;
        m.M[1][3] = m.M[1][3] + v17;
        Scaleform::GFx::AS2::MatrixObject::SetMatrix(p_pProto, sx, &m);
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
