void __cdecl Scaleform::GFx::AS2::MatrixProto::DeltaTransformPoint(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // ebx
  Scaleform::GFx::AS2::MatrixObject *p_pProto; // ebx
  Scaleform::GFx::AS2::Value *v3; // eax
  Scaleform::GFx::AS2::Object *v4; // eax
  Scaleform::GFx::AS2::PointObject *v5; // edi
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::PointObject *v7; // eax
  Scaleform::GFx::AS2::PointObject *v8; // eax
  Scaleform::GFx::AS2::PointObject *v9; // edi
  Scaleform::GFx::AS2::Environment *v10; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp-4h] [ebp-94h]
  Scaleform::GFx::AS2::Value v13; // [esp+Ch] [ebp-84h] BYREF
  Scaleform::GFx::AS2::Value v; // [esp+1Ch] [ebp-74h] BYREF
  Scaleform::GFx::AS2::Value v15; // [esp+30h] [ebp-60h] BYREF
  Scaleform::GFx::AS2::Value v16; // [esp+40h] [ebp-50h] BYREF
  Scaleform::GFx::AS2::Value params; // [esp+50h] [ebp-40h] BYREF
  Scaleform::GFx::AS2::Value v18; // [esp+60h] [ebp-30h] BYREF
  Scaleform::Render::Matrix2x4<float> result; // [esp+70h] [ebp-20h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Matrix )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = (Scaleform::GFx::AS2::MatrixObject *)&ThisPtr[-2].pProto;
      if ( p_pProto )
      {
        if ( fn->NArgs > 0 )
        {
          Env = fn->Env;
          v3 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
          v4 = Scaleform::GFx::AS2::Value::ToObject(v3, Env);
          v5 = (Scaleform::GFx::AS2::PointObject *)v4;
          if ( v4 )
          {
            if ( v4->GetObjectType(&v4->Scaleform::GFx::AS2::ObjectInterface) == Object_Point )
            {
              Scaleform::GFx::AS2::MatrixObject::GetMatrix(p_pProto, &result, fn->Env);
              `vector constructor iterator'(
                (char *)&params,
                0x10u,
                2,
                (void *(__thiscall *)(void *))Scaleform::GFx::AS2::Value::Value);
              Scaleform::GFx::AS2::PointObject::GetProperties(v5, &fn->Env->StringContext, &params);
              pHeap = fn->Env->StringContext.pContext->pHeap;
              v7 = (Scaleform::GFx::AS2::PointObject *)pHeap->Alloc(pHeap, 52u, 0);
              if ( v7 )
              {
                Scaleform::GFx::AS2::PointObject::PointObject(v7, fn->Env);
                v9 = v8;
              }
              else
              {
                v9 = 0;
              }
              `vector constructor iterator'(
                (char *)&v15,
                0x10u,
                2,
                (void *(__thiscall *)(void *))Scaleform::GFx::AS2::Value::Value);
              v10 = fn->Env;
              *(double *)((char *)&v13.NV.NumberValue + 4) = result.M[0][0];
              v13.V.BooleanValue = 3;
              Scaleform::GFx::AS2::Value::Mul((Scaleform::GFx::AS2::Value *)&v13.NV.4, v10, &params);
              *(double *)((char *)&v.NV.NumberValue + 4) = result.M[0][1];
              v.V.BooleanValue = 3;
              Scaleform::GFx::AS2::Value::operator=(&v15, (const Scaleform::GFx::AS2::Value *)&v.NV.4);
              if ( v.V.BooleanValue >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v.NV.4);
              Scaleform::GFx::AS2::Value::Mul(&v15, fn->Env, &v18);
              Scaleform::GFx::AS2::Value::Add(&v15, fn->Env, (Scaleform::GFx::AS2::Value *)&v13.NV.4);
              *(double *)((char *)&v.NV.NumberValue + 4) = result.M[1][0];
              v.V.BooleanValue = 3;
              Scaleform::GFx::AS2::Value::operator=(
                (Scaleform::GFx::AS2::Value *)&v13.NV.4,
                (const Scaleform::GFx::AS2::Value *)&v.NV.4);
              if ( v.V.BooleanValue >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v.NV.4);
              Scaleform::GFx::AS2::Value::Mul((Scaleform::GFx::AS2::Value *)&v13.NV.4, fn->Env, &params);
              *(double *)((char *)&v.NV.NumberValue + 4) = result.M[1][1];
              v.V.BooleanValue = 3;
              Scaleform::GFx::AS2::Value::operator=(&v16, (const Scaleform::GFx::AS2::Value *)&v.NV.4);
              if ( v.V.BooleanValue >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v.NV.4);
              Scaleform::GFx::AS2::Value::Mul(&v16, fn->Env, &v18);
              Scaleform::GFx::AS2::Value::Add(&v16, fn->Env, (Scaleform::GFx::AS2::Value *)&v13.NV.4);
              Scaleform::GFx::AS2::PointObject::SetProperties(v9, &fn->Env->StringContext, &v15);
              Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v9);
              if ( v13.V.BooleanValue >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v13.NV.4);
              `vector destructor iterator'(
                (char *)&v15,
                0x10u,
                2,
                (void (__thiscall *)(void *))Scaleform::GFx::AS2::Value::~Value);
              if ( v9 )
              {
                RefCount = v9->RefCount;
                if ( (RefCount & 0x3FFFFFF) != 0 )
                {
                  v9->RefCount = RefCount - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
                }
              }
              `vector destructor iterator'(
                (char *)&params,
                0x10u,
                2,
                (void (__thiscall *)(void *))Scaleform::GFx::AS2::Value::~Value);
            }
          }
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
