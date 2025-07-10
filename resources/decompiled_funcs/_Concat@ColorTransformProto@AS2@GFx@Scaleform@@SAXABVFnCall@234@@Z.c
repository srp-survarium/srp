void __cdecl Scaleform::GFx::AS2::ColorTransformProto::Concat(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // edx
  Scaleform::GFx::AS2::Value *v2; // ecx
  Scaleform::GFx::AS2::Object *v3; // edi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Render::Cxform *p_pProto; // ebx
  Scaleform::Render::Cxform c; // [esp+130h] [ebp-A0h] BYREF
  Scaleform::GFx::AS2::Value __t; // [esp+150h] [ebp-80h] BYREF
  Scaleform::GFx::AS2::Value v8; // [esp+160h] [ebp-70h] BYREF
  Scaleform::GFx::AS2::Value v9; // [esp+170h] [ebp-60h] BYREF
  Scaleform::GFx::AS2::Value v10; // [esp+180h] [ebp-50h] BYREF
  Scaleform::GFx::AS2::Value v11; // [esp+190h] [ebp-40h] BYREF
  Scaleform::GFx::AS2::Value v12; // [esp+1A0h] [ebp-30h] BYREF
  Scaleform::GFx::AS2::Value v13; // [esp+1B0h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v14; // [esp+1C0h] [ebp-10h] BYREF

  if ( fn->NArgs > 0 )
  {
    Env = fn->Env;
    v2 = 0;
    if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v2 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex
                                                                                         & 0x1F];
    v3 = Scaleform::GFx::AS2::Value::ToObject(v2, fn->Env);
    if ( v3 )
    {
      if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_ColorTransform )
      {
        ThisPtr = fn->ThisPtr;
        if ( ThisPtr )
          p_pProto = (Scaleform::Render::Cxform *)&ThisPtr[-2].pProto;
        else
          p_pProto = 0;
        if ( v3->GetObjectType(&v3->Scaleform::GFx::AS2::ObjectInterface) == Object_ColorTransform )
        {
          Scaleform::Render::Cxform::Prepend(p_pProto + 2, (const Scaleform::Render::Cxform *)&v3[1].RefCount);
        }
        else
        {
          `vector constructor iterator'(
            (char *)&__t,
            0x10u,
            8,
            (void *(__thiscall *)(void *))Scaleform::GFx::AS2::Value::Value);
          Scaleform::GFx::AS2::GFxObject_GetColorTransformProperties(fn->Env, v3, &__t);
          Scaleform::Render::Cxform::Cxform(&c);
          c.M[0][0] = Scaleform::GFx::AS2::Value::ToNumber(&__t, fn->Env);
          c.M[0][1] = Scaleform::GFx::AS2::Value::ToNumber(&v8, fn->Env);
          c.M[0][2] = Scaleform::GFx::AS2::Value::ToNumber(&v9, fn->Env);
          c.M[0][3] = Scaleform::GFx::AS2::Value::ToNumber(&v10, fn->Env);
          c.M[1][0] = Scaleform::GFx::AS2::Value::ToNumber(&v11, fn->Env);
          c.M[1][1] = Scaleform::GFx::AS2::Value::ToNumber(&v12, fn->Env);
          c.M[1][2] = Scaleform::GFx::AS2::Value::ToNumber(&v13, fn->Env);
          c.M[1][3] = Scaleform::GFx::AS2::Value::ToNumber(&v14, fn->Env);
          Scaleform::Render::Cxform::Prepend(p_pProto + 2, &c);
          `vector destructor iterator'(
            (char *)&__t,
            0x10u,
            8,
            (void (__thiscall *)(void *))Scaleform::GFx::AS2::Value::~Value);
        }
      }
      else
      {
        Scaleform::GFx::AS2::Environment::LogScriptError(
          fn->Env,
          "Error: Null or invalid 'this' is used for a method of %s class.\n",
          "ColorTransform");
      }
    }
  }
}
