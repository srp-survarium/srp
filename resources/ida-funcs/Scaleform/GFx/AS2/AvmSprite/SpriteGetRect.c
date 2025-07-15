void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteGetRect(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::GFx::InteractiveObject *Target; // edi
  Scaleform::GFx::AS2::Value *v3; // eax
  Scaleform::GFx::InteractiveObject *v4; // eax
  Scaleform::GFx::DisplayObjectBase *v5; // ecx
  double v6; // st6
  double v7; // st7
  const Scaleform::Render::Matrix2x4<float> *WorldMatrix; // eax
  const Scaleform::Render::Matrix2x4<float> *v9; // eax
  Scaleform::Render::Rect<float> *(__thiscall *GetRectBounds)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Rect<float> *, const Scaleform::Render::Matrix2x4<float> *); // edx
  __m128 *v11; // eax
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::Object *v13; // eax
  Scaleform::GFx::AS2::Object *v14; // eax
  Scaleform::GFx::AS2::Object *v15; // ebx
  Scaleform::GFx::AS2::Environment *v16; // esi
  bool (__thiscall *SetMemberRaw)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, const Scaleform::GFx::AS2::Value *, const Scaleform::GFx::AS2::PropFlags *); // edx
  Scaleform::GFx::AS2::GlobalContext *pContext; // eax
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // esi
  Scaleform::GFx::AS2::ObjectInterface_vtbl **v20; // edi
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v21; // eax
  Scaleform::GFx::AS2::GlobalContext *v22; // ecx
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v23; // eax
  Scaleform::GFx::AS2::GlobalContext *v24; // ecx
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v25; // eax
  Scaleform::GFx::AS2::GlobalContext *v26; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp+26h] [ebp-74h]
  char v29; // [esp+39h] [ebp-61h] BYREF
  float v30; // [esp+3Ah] [ebp-60h] BYREF
  float v31; // [esp+3Eh] [ebp-5Ch]
  float v32; // [esp+42h] [ebp-58h]
  Scaleform::GFx::AS2::Value v33; // [esp+46h] [ebp-54h] BYREF
  Scaleform::Render::Matrix2x4<float> v34; // [esp+5Ah] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> result; // [esp+7Ah] [ebp-20h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( ThisPtr->GetObjectType(fn->ThisPtr) == Object_Sprite )
      Target = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].__vftable;
    else
      Target = 0;
  }
  else
  {
    Target = fn->Env->Target;
  }
  if ( Target )
  {
    if ( fn->NArgs <= 0 )
    {
      v4 = Target;
    }
    else
    {
      Env = fn->Env;
      v3 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      v4 = Scaleform::GFx::AS2::Value::ToCharacter(v3, Env);
    }
    if ( v4 )
      v5 = (v4->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 ? v4 : 0;
    else
      v5 = 0;
    v30 = 0.0;
    v31 = 0.0;
    v32 = 0.0;
    *(float *)&v33.T.Type = 0.0;
    v34.M[0][0] = 1.0;
    v34.M[1][1] = 1.0;
    v6 = 0.0;
    v7 = 1.0;
    v34.M[0][1] = 0.0;
    v34.M[0][2] = 0.0;
    v34.M[0][3] = 0.0;
    v34.M[1][0] = 0.0;
    v34.M[1][2] = 0.0;
    v34.M[1][3] = 0.0;
    if ( v5 )
    {
      if ( v5 != Target )
      {
        WorldMatrix = Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v5, &result);
        Scaleform::Render::Matrix2x4<float>::SetInverse(&v34, WorldMatrix);
        v9 = Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(Target, &result);
        Scaleform::Render::Matrix2x4<float>::Prepend(&v34, v9);
        v7 = 1.0;
        v6 = 0.0;
      }
      GetRectBounds = Target->GetRectBounds;
      result.M[0][0] = v7;
      result.M[1][1] = result.M[0][0];
      result.M[0][1] = v6;
      result.M[0][2] = result.M[0][1];
      result.M[0][3] = result.M[0][1];
      result.M[1][0] = result.M[0][1];
      result.M[1][2] = result.M[0][1];
      result.M[1][3] = result.M[0][1];
      v11 = (__m128 *)GetRectBounds(Target, (Scaleform::Render::Rect<float> *)&v33.NV.4, &result);
      Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v34, (__m128 *)&v30, v11);
    }
    pHeap = fn->Env->StringContext.pContext->pHeap;
    v13 = (Scaleform::GFx::AS2::Object *)pHeap->Alloc(pHeap, 52u, 0);
    if ( v13 )
    {
      Scaleform::GFx::AS2::Object::Object(v13, fn->Env);
      v15 = v14;
    }
    else
    {
      v15 = 0;
    }
    v16 = fn->Env;
    SetMemberRaw = v15->SetMemberRaw;
    *(double *)((char *)&v33.NV.NumberValue + 4) = v30 * 0.05;
    pContext = v16->StringContext.pContext;
    p_StringContext = &v16->StringContext;
    v33.V.BooleanValue = 3;
    v29 = 0;
    v20 = &v15->Scaleform::GFx::AS2::ObjectInterface::__vftable;
    SetMemberRaw(
      &v15->Scaleform::GFx::AS2::ObjectInterface,
      p_StringContext,
      (const Scaleform::GFx::ASString *)&pContext->pMovieRoot->pASMovieRoot.pObject[34].pMovieImpl,
      (const Scaleform::GFx::AS2::Value *)&v33.NV.4,
      (const Scaleform::GFx::AS2::PropFlags *)&v29);
    if ( v33.V.BooleanValue >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v33.NV.4);
    v21 = *v20;
    v22 = p_StringContext->pContext;
    *(double *)((char *)&v33.NV.NumberValue + 4) = v32 * 0.05;
    v33.V.BooleanValue = 3;
    v29 = 0;
    v21->SetMemberRaw(
      &v15->Scaleform::GFx::AS2::ObjectInterface,
      p_StringContext,
      (const Scaleform::GFx::ASString *)&v22->pMovieRoot->pASMovieRoot.pObject[34].pASSupport,
      (const Scaleform::GFx::AS2::Value *)&v33.NV.4,
      (const Scaleform::GFx::AS2::PropFlags *)&v29);
    if ( v33.V.BooleanValue >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v33.NV.4);
    v23 = *v20;
    v24 = p_StringContext->pContext;
    *(double *)((char *)&v33.NV.NumberValue + 4) = v31 * 0.05;
    v33.V.BooleanValue = 3;
    v29 = 0;
    v23->SetMemberRaw(
      &v15->Scaleform::GFx::AS2::ObjectInterface,
      p_StringContext,
      (const Scaleform::GFx::ASString *)&v24->pMovieRoot->pASMovieRoot.pObject[34].AVMVersion,
      (const Scaleform::GFx::AS2::Value *)&v33.NV.4,
      (const Scaleform::GFx::AS2::PropFlags *)&v29);
    if ( v33.V.BooleanValue >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v33.NV.4);
    v25 = *v20;
    v26 = p_StringContext->pContext;
    *(double *)((char *)&v33.NV.NumberValue + 4) = *(float *)&v33.T.Type * 0.05;
    v33.V.BooleanValue = 3;
    v29 = 0;
    v25->SetMemberRaw(
      &v15->Scaleform::GFx::AS2::ObjectInterface,
      p_StringContext,
      (const Scaleform::GFx::ASString *)&v26->pMovieRoot->pASMovieRoot.pObject[35],
      (const Scaleform::GFx::AS2::Value *)&v33.NV.4,
      (const Scaleform::GFx::AS2::PropFlags *)&v29);
    if ( v33.V.BooleanValue >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v33.NV.4);
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v15);
    RefCount = v15->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v15->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v15);
    }
  }
}
