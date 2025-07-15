void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteStartDrag(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::GFx::Sprite *Target; // edi
  bool v3; // cc
  Scaleform::GFx::AS2::Value *v4; // eax
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::AS2::Value *v6; // eax
  Scaleform::GFx::AS2::Value *v7; // eax
  Scaleform::GFx::AS2::Value *v8; // eax
  unsigned int Flags; // eax
  bool v10; // al
  int v11; // eax
  Scaleform::GFx::AS2::Environment *st_32; // [esp+A8h] [ebp-64h]
  Scaleform::GFx::AS2::Environment *st_32a; // [esp+A8h] [ebp-64h]
  Scaleform::GFx::AS2::Environment *st_32b; // [esp+A8h] [ebp-64h]
  Scaleform::GFx::AS2::Environment *st_32c; // [esp+A8h] [ebp-64h]
  Scaleform::GFx::AS2::Environment *st_32d; // [esp+A8h] [ebp-64h]
  char v17; // [esp+C4h] [ebp-48h]
  float v18; // [esp+C8h] [ebp-44h]
  float v19; // [esp+C8h] [ebp-44h]
  float v20; // [esp+C8h] [ebp-44h]
  float v21; // [esp+C8h] [ebp-44h]
  Scaleform::Render::Rect<float> v22; // [esp+CCh] [ebp-40h] BYREF
  Scaleform::GFx::MovieImpl::DragState st; // [esp+E8h] [ebp-24h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( ThisPtr->GetObjectType(fn->ThisPtr) == Object_Sprite )
      Target = (Scaleform::GFx::Sprite *)ThisPtr[1].__vftable;
    else
      Target = 0;
  }
  else
  {
    Target = (Scaleform::GFx::Sprite *)fn->Env->Target;
  }
  if ( Target )
  {
    v3 = fn->NArgs <= 0;
    st.BoundLT.y = 0.0;
    st.pCharacter = 0;
    st.BoundLT.x = 0.0;
    st.LockCenter = 0;
    st.BoundRB.y = 0.0;
    st.Bound = 0;
    st.BoundRB.x = 0.0;
    st.MouseIndex = -1;
    st.CenterDelta.y = 0.0;
    v17 = 0;
    st.CenterDelta.x = 0.0;
    if ( !v3 )
    {
      st_32 = fn->Env;
      v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      v17 = Scaleform::GFx::AS2::Value::ToBool(v4, st_32);
      if ( fn->NArgs > 4 )
      {
        st_32a = fn->Env;
        st.Bound = 1;
        v5 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
        v18 = Scaleform::GFx::AS2::Value::ToNumber(v5, st_32a);
        st_32b = fn->Env;
        v22.x1 = v18 * 20.0;
        v6 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
        v19 = Scaleform::GFx::AS2::Value::ToNumber(v6, st_32b);
        st_32c = fn->Env;
        v22.y1 = v19 * 20.0;
        v7 = Scaleform::GFx::AS2::FnCall::Arg(fn, 3);
        v20 = Scaleform::GFx::AS2::Value::ToNumber(v7, st_32c);
        st_32d = fn->Env;
        v22.x2 = v20 * 20.0;
        v8 = Scaleform::GFx::AS2::FnCall::Arg(fn, 4);
        v21 = Scaleform::GFx::AS2::Value::ToNumber(v8, st_32d);
        v22.y2 = v21 * 20.0;
        Scaleform::Render::Rect<float>::Normalize(&v22);
        st.BoundLT.x = v22.x1;
        st.BoundLT.y = v22.y1;
        st.BoundRB.x = v22.x2;
        st.BoundRB.y = v22.y2;
      }
    }
    st.pCharacter = Target;
    Scaleform::GFx::MovieImpl::DragState::InitCenterDelta(&st, v17, 0);
    Scaleform::GFx::MovieImpl::SetDragState(Target->pASRoot->pMovieImpl, &st);
    Flags = Target->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags;
    v10 = (Flags & 0x200000) != 0 && (Flags & 0x400000) == 0;
    v11 = Scaleform::GFx::Sprite::CheckAdvanceStatus(Target, v10);
    if ( v11 == -1 )
    {
      Target->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags |= (unsigned int)Scaleform::GFx::AS2::CreateShadow;
    }
    else if ( v11 == 1 )
    {
      Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(Target);
    }
  }
}
