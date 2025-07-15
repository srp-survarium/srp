void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteHitTest(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::GFx::InteractiveObject *Target; // edi
  Scaleform::GFx::AS2::Value *v3; // ebx
  Scaleform::GFx::InteractiveObject_vtbl *v4; // edx
  Scaleform::Render::Rect<float> *(__thiscall *GetBounds)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Rect<float> *, const Scaleform::Render::Matrix2x4<float> *); // edx
  int NArgs; // eax
  Scaleform::GFx::AS2::Value *v7; // eax
  Scaleform::GFx::AS2::Value *v8; // eax
  bool v9; // cc
  Scaleform::GFx::AS2::Value *v10; // eax
  Scaleform::GFx::AS2::Value *v11; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // ebx
  double ViewOffsetY; // st6
  double v14; // st7
  double v15; // st6
  const __m128i *WorldMatrix3D; // eax
  bool v17; // al
  Scaleform::Render::Matrix2x4<float> *LevelMatrix; // eax
  bool v19; // al
  Scaleform::GFx::AS2::Value *v20; // esi
  bool v21; // bl
  bool v22; // al
  Scaleform::GFx::AS2::Value *v23; // eax
  Scaleform::GFx::InteractiveObject *v24; // ebx
  Scaleform::GFx::AS2::Environment *Env; // ecx
  Scaleform::GFx::ASStringNode *v26; // eax
  const Scaleform::Render::Matrix2x4<float> *v27; // eax
  Scaleform::Render::Matrix2x4<float> *WorldMatrix; // eax
  Scaleform::Render::Matrix2x4<float> *v29; // eax
  bool v30; // al
  __int64 v31; // [esp-10h] [ebp-118h]
  Scaleform::GFx::AS2::Environment *v32; // [esp+4h] [ebp-104h]
  Scaleform::GFx::AS2::Environment *v33; // [esp+4h] [ebp-104h]
  Scaleform::GFx::AS2::Environment *v34; // [esp+4h] [ebp-104h]
  Scaleform::GFx::AS2::Environment *v35; // [esp+4h] [ebp-104h]
  unsigned __int8 v36; // [esp+18h] [ebp-F0h]
  Scaleform::GFx::DisplayObjectBase *v37; // [esp+18h] [ebp-F0h]
  float v38; // [esp+1Ch] [ebp-ECh]
  float v39; // [esp+1Ch] [ebp-ECh]
  float v40; // [esp+1Ch] [ebp-ECh]
  float v41; // [esp+1Ch] [ebp-ECh]
  float v42; // [esp+1Ch] [ebp-ECh]
  Scaleform::Render::ScreenToWorld *p_ScreenToWorld; // [esp+20h] [ebp-E8h] BYREF
  float v44; // [esp+24h] [ebp-E4h]
  __m128 ptOut; // [esp+28h] [ebp-E0h] BYREF
  Scaleform::GFx::AS2::Value v46; // [esp+38h] [ebp-D0h] BYREF
  Scaleform::Render::Rect<float> r; // [esp+48h] [ebp-C0h] BYREF
  Scaleform::Render::Matrix3x4<float> result; // [esp+58h] [ebp-B0h] BYREF
  Scaleform::Render::Matrix3x4<float> v49; // [esp+88h] [ebp-80h] BYREF
  Scaleform::Render::Rect<float> v50; // [esp+B8h] [ebp-50h] BYREF
  Scaleform::Render::Matrix4x4<float> v51; // [esp+C8h] [ebp-40h] BYREF

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
    v3 = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v3);
    result.M[0][0] = 1.0;
    v3->T.Type = 2;
    result.M[0][1] = 0.0;
    v3->V.BooleanValue = 0;
    v4 = Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
    result.M[0][2] = 0.0;
    GetBounds = v4->GetBounds;
    result.M[0][3] = 0.0;
    result.M[1][0] = 0.0;
    result.M[1][2] = 0.0;
    result.M[1][3] = 0.0;
    result.M[1][1] = 1.0;
    GetBounds(Target, &r, (const Scaleform::Render::Matrix2x4<float> *)&result);
    if ( r.x1 != r.x2 || r.y1 != r.y2 )
    {
      NArgs = fn->NArgs;
      if ( NArgs < 2 )
      {
        if ( NArgs == 1 )
        {
          v23 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
          v24 = 0;
          v37 = 0;
          if ( v23->T.Type == 7 )
          {
            v24 = Scaleform::GFx::AS2::Value::ToCharacter(v23, fn->Env);
            v37 = v24;
          }
          else
          {
            Scaleform::GFx::AS2::Value::ToStringImpl(v23, (Scaleform::GFx::ASString *)&p_ScreenToWorld, fn->Env, -1, 0);
            Env = fn->Env;
            HIDWORD(v31) = &v46;
            LODWORD(v31) = &p_ScreenToWorld;
            v46.T.Type = 0;
            if ( Scaleform::GFx::AS2::Environment::GetVariable(Env, v31, 0, 0, 0) )
            {
              v24 = Scaleform::GFx::AS2::Value::ToCharacter(&v46, fn->Env);
              v37 = v24;
            }
            if ( v46.T.Type >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs(&v46);
            v26 = (Scaleform::GFx::ASStringNode *)p_ScreenToWorld;
            --LODWORD(p_ScreenToWorld->LastY);
            if ( !v26->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(v26);
          }
          if ( v24 )
          {
            v44 = *(float *)&v24->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
            Scaleform::Render::Matrix2x4<float>::Matrix2x4<float>((Scaleform::Render::Matrix2x4<float> *)&v49);
            (*(void (__thiscall **)(Scaleform::GFx::DisplayObjectBase *, __m128 *, const Scaleform::Render::Matrix2x4<float> *))(LODWORD(v44) + 236))(
              v37,
              &ptOut,
              v27);
            if ( !Scaleform::Render::Rect<float>::IsNull((Scaleform::Render::Rect<float> *)&ptOut) )
            {
              WorldMatrix = Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(
                              Target,
                              (Scaleform::Render::Matrix2x4<float> *)&v49);
              Scaleform::Render::Matrix2x4<float>::EncloseTransform(WorldMatrix, (__m128 *)&result, (__m128 *)&r);
              v29 = Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v37, (Scaleform::Render::Matrix2x4<float> *)&v49);
              Scaleform::Render::Matrix2x4<float>::EncloseTransform(v29, (__m128 *)&v50, &ptOut);
              v30 = Scaleform::Render::Rect<float>::Intersects((Scaleform::Render::Rect<float> *)&result, &v50);
              Scaleform::GFx::AS2::Value::SetBool(fn->Result, v30);
            }
          }
        }
      }
      else
      {
        v32 = fn->Env;
        v36 = 0;
        v7 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
        v38 = Scaleform::GFx::AS2::Value::ToNumber(v7, v32);
        v33 = fn->Env;
        v8 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        *(float *)&p_ScreenToWorld = Scaleform::GFx::AS2::Value::ToNumber(v8, v33);
        v9 = fn->NArgs < 3;
        ptOut.m128_f32[0] = *(float *)&p_ScreenToWorld * 20.0;
        ptOut.m128_f32[1] = 20.0 * v38;
        if ( !v9 )
        {
          v34 = fn->Env;
          v10 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
          v36 = Scaleform::GFx::AS2::Value::ToBool(v10, (int)Target, v34);
        }
        if ( fn->NArgs >= 4 )
        {
          v35 = fn->Env;
          v11 = Scaleform::GFx::AS2::FnCall::Arg(fn, 3);
          v36 |= Scaleform::GFx::AS2::Value::ToBool(v11, (int)Target, v35) ? 2 : 0;
        }
        pMovieImpl = Target->pASRoot->pMovieImpl;
        if ( pMovieImpl && Scaleform::GFx::DisplayObjectBase::Is3D(Target, 1) )
        {
          ViewOffsetY = pMovieImpl->ViewOffsetY;
          p_ScreenToWorld = &pMovieImpl->ScreenToWorld;
          v39 = ViewOffsetY * 20.0;
          v14 = ptOut.m128_f32[1] - v39;
          v40 = pMovieImpl->VisibleFrameRect.y2 - pMovieImpl->VisibleFrameRect.y1;
          v44 = v14 / v40 * 2.0 - 1.0;
          v41 = 20.0 * pMovieImpl->ViewOffsetX;
          v15 = ptOut.m128_f32[0] - v41;
          v42 = pMovieImpl->VisibleFrameRect.x2 - pMovieImpl->VisibleFrameRect.x1;
          pMovieImpl->ScreenToWorld.Sx = v15 / v42 * 2.0 - 1.0;
          pMovieImpl->ScreenToWorld.Sy = -v44;
          Scaleform::Render::Matrix3x4<float>::Matrix3x4<float>(&v49);
          Scaleform::Render::Matrix4x4<float>::Matrix4x4<float>(&v51);
          if ( Target->GetProjectionMatrix3D(Target, &v51, 0) )
            memcpy((int)&p_ScreenToWorld->MatProj, (const __m128i *)&v51, sizeof(p_ScreenToWorld->MatProj));
          if ( Target->GetViewMatrix3D(Target, &v49, 0) )
            memcpy((int)&p_ScreenToWorld->MatView, (const __m128i *)&v49, sizeof(p_ScreenToWorld->MatView));
          WorldMatrix3D = (const __m128i *)Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(Target, &result);
          memcpy((int)&p_ScreenToWorld->MatWorld, WorldMatrix3D, sizeof(p_ScreenToWorld->MatWorld));
          Scaleform::Render::ScreenToWorld::GetWorldPoint(p_ScreenToWorld, (Scaleform::Render::Point<float> *)&ptOut);
          v17 = Target->PointTestLocal(Target, (const Scaleform::Render::Point<float> *)&ptOut, v36);
          Scaleform::GFx::AS2::Value::SetBool(fn->Result, v17);
        }
        else
        {
          LevelMatrix = Scaleform::GFx::DisplayObjectBase::GetLevelMatrix(
                          Target,
                          (Scaleform::Render::Matrix2x4<float> *)&result);
          Scaleform::Render::Matrix2x4<float>::TransformByInverse(
            LevelMatrix,
            (Scaleform::Render::Point<float> *)&v46,
            (const Scaleform::Render::Point<float> *)&ptOut);
          if ( (Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 1) != 0 )
          {
            v19 = Target->PointTestLocal(Target, (const Scaleform::Render::Point<float> *)&v46, v36);
            v20 = fn->Result;
            v21 = v19;
            Scaleform::GFx::AS2::Value::DropRefs(v20);
            v20->T.Type = 2;
            v20->V.BooleanValue = v21;
          }
          else if ( Scaleform::Render::Rect<float>::Contains(&r, (const Scaleform::Render::Point<float> *)&v46) )
          {
            if ( (v36 & 1) != 0 )
            {
              v22 = Target->PointTestLocal(Target, (const Scaleform::Render::Point<float> *)&v46, v36);
              Scaleform::GFx::AS2::Value::SetBool(fn->Result, v22);
            }
            else
            {
              Scaleform::GFx::AS2::Value::SetBool(fn->Result, 1);
            }
          }
          else
          {
            Scaleform::GFx::AS2::Value::SetBool(fn->Result, 0);
          }
        }
      }
    }
  }
}
