void __usercall Scaleform::GFx::AS2::AvmSprite::SpriteLocalToGlobal(
        int a1@<edi>,
        Scaleform::GFx::AS2::FnCall *fn,
        char a3)
{
  Scaleform::GFx::AS2::FnCall *v3; // ebp
  Scaleform::GFx::AS2::Value *v4; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::GFx::DisplayObjectBase *Target; // ebx
  Scaleform::GFx::DisplayObjectBase *v7; // esi
  Scaleform::GFx::AS2::Environment *Env; // esi
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // edi
  Scaleform::GFx::AS2::Value *v10; // ecx
  Scaleform::GFx::AS2::AvmCharacter *v11; // eax
  Scaleform::GFx::AS2::ObjectInterface *v12; // esi
  Scaleform::GFx::AS2::Object *v13; // eax
  unsigned __int8 Type; // al
  Scaleform::Render::Point<float> *v15; // eax
  bool (__thiscall *SetMemberRaw)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, const Scaleform::GFx::AS2::Value *, const Scaleform::GFx::AS2::PropFlags *); // edx
  Scaleform::GFx::AS2::GlobalContext *pContext; // eax
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v18; // eax
  Scaleform::GFx::AS2::GlobalContext *v19; // ecx
  bool v20; // cf
  Scaleform::GFx::AS2::Value result; // [esp+38h] [ebp-38h] BYREF
  Scaleform::Render::Point<float> ptIn; // [esp+48h] [ebp-28h] BYREF
  Scaleform::GFx::AS2::Value v24; // [esp+50h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v25; // [esp+60h] [ebp-10h] BYREF

  v3 = fn;
  v4 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v4);
  v4->T.Type = 0;
  ThisPtr = v3->ThisPtr;
  if ( ThisPtr )
  {
    if ( ThisPtr->GetObjectType(v3->ThisPtr) == Object_Sprite )
      v7 = (Scaleform::GFx::DisplayObjectBase *)ThisPtr[1].__vftable;
    else
      v7 = 0;
    Target = v7;
  }
  else
  {
    Target = v3->Env->Target;
  }
  if ( Target && v3->NArgs >= 1 )
  {
    Env = v3->Env;
    p_StringContext = &Env->StringContext;
    v10 = Scaleform::GFx::AS2::FnCall::Arg(v3, 0);
    if ( v10->T.Type == 7 )
    {
      v11 = Scaleform::GFx::AS2::Value::ToAvmCharacter(v10, Env);
      if ( !v11 )
        return;
      v12 = &v11->Scaleform::GFx::AS2::ObjectInterface;
    }
    else
    {
      v13 = Scaleform::GFx::AS2::Value::ToObject(v10, Env);
      if ( !v13 )
        return;
      v12 = &v13->Scaleform::GFx::AS2::ObjectInterface;
    }
    if ( v12 )
    {
      v24.T.Type = 0;
      v25.T.Type = 0;
      v12->GetMemberRaw(
        v12,
        p_StringContext,
        (const Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[34],
        &v24);
      v12->GetMemberRaw(
        v12,
        p_StringContext,
        (const Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[34].RefCount,
        &v25);
      Type = v24.T.Type;
      if ( (v24.T.Type == 3 || v24.T.Type == 4) && (v25.T.Type == 3 || v25.T.Type == 4) )
      {
        *(float *)&result.T.Type = Scaleform::GFx::AS2::Value::ToNumber(&v25, v3->Env);
        *(float *)&fn = Scaleform::GFx::AS2::Value::ToNumber(&v24, v3->Env);
        ptIn.x = *(float *)&fn * 20.0;
        ptIn.y = 20.0 * *(float *)&result.T.Type;
        v15 = Scaleform::GFx::DisplayObjectBase::LocalToGlobal(
                Target,
                (Scaleform::Render::Point<float> *)&result,
                &ptIn);
        SetMemberRaw = v12->SetMemberRaw;
        ptIn.x = v15->x;
        ptIn.y = v15->y;
        pContext = p_StringContext->pContext;
        result.T.Type = 3;
        result.NV.NumberValue = ptIn.x * 0.05;
        LOBYTE(fn) = 0;
        ((void (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::FnCall **, int))SetMemberRaw)(
          v12,
          p_StringContext,
          &pContext->pMovieRoot->pASMovieRoot.pObject[34],
          &result,
          &fn,
          a1);
        if ( result.V.BooleanValue >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&result.NV.4);
        v18 = v12->__vftable;
        v19 = p_StringContext->pContext;
        *(double *)((char *)&result.NV.NumberValue + 4) = *(float *)&v24.T.Type * 0.05;
        result.V.BooleanValue = 3;
        a3 = 0;
        ((void (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, volatile int *, $B8BD913BABC9324639AA48504BEFB2FC *))v18->SetMemberRaw)(
          v12,
          p_StringContext,
          &v19->pMovieRoot->pASMovieRoot.pObject[34].RefCount,
          &result.NV.4);
        if ( result.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&result);
        if ( v25.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v25);
        v20 = v24.T.Type < 5u;
      }
      else
      {
        if ( v25.T.Type >= 5u )
        {
          Scaleform::GFx::AS2::Value::DropRefs(&v25);
          Type = v24.T.Type;
        }
        v20 = Type < 5u;
      }
      if ( !v20 )
        Scaleform::GFx::AS2::Value::DropRefs(&v24);
    }
  }
}
