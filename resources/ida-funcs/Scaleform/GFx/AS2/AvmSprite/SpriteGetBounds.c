void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteGetBounds(const Scaleform::GFx::AS2::FnCall *fn)
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
  Scaleform::Render::Rect<float> *(__thiscall *GetBounds)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Rect<float> *, const Scaleform::Render::Matrix2x4<float> *); // edx
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
  Scaleform::GFx::AS2::Environment *Env; // [esp+9Ch] [ebp-74h]
  char v29; // [esp+AFh] [ebp-61h] BYREF
  Scaleform::Render::Rect<float> pr; // [esp+B0h] [ebp-60h] BYREF
  Scaleform::GFx::AS2::Value v31; // [esp+C0h] [ebp-50h] BYREF
  Scaleform::Render::Matrix2x4<float> v32; // [esp+D0h] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> result; // [esp+F0h] [ebp-20h] BYREF

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
    pr.x1 = 0.0;
    pr.y1 = 0.0;
    pr.x2 = 0.0;
    pr.y2 = 0.0;
    v32.M[0][0] = 1.0;
    v32.M[1][1] = 1.0;
    v6 = 0.0;
    v7 = 1.0;
    v32.M[0][1] = 0.0;
    v32.M[0][2] = 0.0;
    v32.M[0][3] = 0.0;
    v32.M[1][0] = 0.0;
    v32.M[1][2] = 0.0;
    v32.M[1][3] = 0.0;
    if ( v5 )
    {
      if ( v5 != Target )
      {
        WorldMatrix = Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v5, &result);
        Scaleform::Render::Matrix2x4<float>::SetInverse(&v32, WorldMatrix);
        v9 = Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(Target, &result);
        Scaleform::Render::Matrix2x4<float>::Prepend(&v32, v9);
        v7 = 1.0;
        v6 = 0.0;
      }
      GetBounds = Target->GetBounds;
      result.M[0][0] = v7;
      result.M[1][1] = result.M[0][0];
      result.M[0][1] = v6;
      result.M[0][2] = result.M[0][1];
      result.M[0][3] = result.M[0][1];
      result.M[1][0] = result.M[0][1];
      result.M[1][2] = result.M[0][1];
      result.M[1][3] = result.M[0][1];
      v11 = (__m128 *)GetBounds(Target, (Scaleform::Render::Rect<float> *)&v31, &result);
      Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v32, &pr, v11);
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
    v31.NV.NumberValue = pr.x1 * 0.05;
    pContext = v16->StringContext.pContext;
    p_StringContext = &v16->StringContext;
    v31.T.Type = 3;
    v29 = 0;
    v20 = &v15->Scaleform::GFx::AS2::ObjectInterface::__vftable;
    SetMemberRaw(
      &v15->Scaleform::GFx::AS2::ObjectInterface,
      p_StringContext,
      (const Scaleform::GFx::ASString *)&pContext->pMovieRoot->pASMovieRoot.pObject[34].pMovieImpl,
      &v31,
      (const Scaleform::GFx::AS2::PropFlags *)&v29);
    if ( v31.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v31);
    v21 = *v20;
    v22 = p_StringContext->pContext;
    v31.NV.NumberValue = pr.x2 * 0.05;
    v31.T.Type = 3;
    v29 = 0;
    v21->SetMemberRaw(
      &v15->Scaleform::GFx::AS2::ObjectInterface,
      p_StringContext,
      (const Scaleform::GFx::ASString *)&v22->pMovieRoot->pASMovieRoot.pObject[34].pASSupport,
      &v31,
      (const Scaleform::GFx::AS2::PropFlags *)&v29);
    if ( v31.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v31);
    v23 = *v20;
    v24 = p_StringContext->pContext;
    v31.NV.NumberValue = pr.y1 * 0.05;
    v31.T.Type = 3;
    v29 = 0;
    v23->SetMemberRaw(
      &v15->Scaleform::GFx::AS2::ObjectInterface,
      p_StringContext,
      (const Scaleform::GFx::ASString *)&v24->pMovieRoot->pASMovieRoot.pObject[34].AVMVersion,
      &v31,
      (const Scaleform::GFx::AS2::PropFlags *)&v29);
    if ( v31.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v31);
    v25 = *v20;
    v26 = p_StringContext->pContext;
    v31.NV.NumberValue = pr.y2 * 0.05;
    v31.T.Type = 3;
    v29 = 0;
    v25->SetMemberRaw(
      &v15->Scaleform::GFx::AS2::ObjectInterface,
      p_StringContext,
      (const Scaleform::GFx::ASString *)&v26->pMovieRoot->pASMovieRoot.pObject[35],
      &v31,
      (const Scaleform::GFx::AS2::PropFlags *)&v29);
    if ( v31.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v31);
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v15);
    RefCount = v15->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      v15->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v15);
    }
  }
}
