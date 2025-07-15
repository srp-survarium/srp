void __usercall Scaleform::GFx::AS2::AvmSprite::SpriteGlobalToLocal(int a1@<edi>, float fn, char a3)
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
  Scaleform::GFx::AS2::GlobalContext *pContext; // eax
  bool (__thiscall *SetMemberRaw)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, const Scaleform::GFx::AS2::Value *, const Scaleform::GFx::AS2::PropFlags *); // edx
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v18; // eax
  Scaleform::GFx::AS2::GlobalContext *v19; // ecx
  bool v20; // cf
  Scaleform::GFx::AS2::Value result; // [esp+38h] [ebp-38h] BYREF
  Scaleform::Render::Point<float> pt; // [esp+48h] [ebp-28h] BYREF
  Scaleform::GFx::AS2::Value xval; // [esp+50h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value yval; // [esp+60h] [ebp-10h] BYREF

  v3 = (Scaleform::GFx::AS2::FnCall *)LODWORD(fn);
  v4 = *(Scaleform::GFx::AS2::Value **)(LODWORD(fn) + 4);
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
      xval.T.Type = 0;
      yval.T.Type = 0;
      v12->GetMemberRaw(
        v12,
        p_StringContext,
        (const Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[34],
        &xval);
      v12->GetMemberRaw(
        v12,
        p_StringContext,
        (const Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[34].RefCount,
        &yval);
      Type = xval.T.Type;
      if ( (xval.T.Type == 3 || xval.T.Type == 4) && (yval.T.Type == 3 || yval.T.Type == 4) )
      {
        *(float *)&result.T.Type = Scaleform::GFx::AS2::Value::ToNumber(&yval, v3->Env);
        fn = Scaleform::GFx::AS2::Value::ToNumber(&xval, v3->Env);
        pt.x = fn * 20.0;
        pt.y = 20.0 * *(float *)&result.T.Type;
        v15 = Scaleform::GFx::DisplayObjectBase::GlobalToLocal(Target, (Scaleform::Render::Point<float> *)&result, &pt);
        fn = v15->y;
        pt.x = v15->x;
        pt.y = fn;
        pContext = p_StringContext->pContext;
        SetMemberRaw = v12->SetMemberRaw;
        result.T.Type = 3;
        LOBYTE(fn) = 0;
        result.NV.NumberValue = pt.x * 0.05;
        ((void (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::AS2::Value *, float *, int))SetMemberRaw)(
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
        *(double *)((char *)&result.NV.NumberValue + 4) = *(float *)&xval.T.Type * 0.05;
        result.V.BooleanValue = 3;
        a3 = 0;
        ((void (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, volatile int *, $B8BD913BABC9324639AA48504BEFB2FC *))v18->SetMemberRaw)(
          v12,
          p_StringContext,
          &v19->pMovieRoot->pASMovieRoot.pObject[34].RefCount,
          &result.NV.4);
        if ( result.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&result);
        if ( yval.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&yval);
        v20 = xval.T.Type < 5u;
      }
      else
      {
        if ( yval.T.Type >= 5u )
        {
          Scaleform::GFx::AS2::Value::DropRefs(&yval);
          Type = xval.T.Type;
        }
        v20 = Type < 5u;
      }
      if ( !v20 )
        Scaleform::GFx::AS2::Value::DropRefs(&xval);
    }
  }
}
