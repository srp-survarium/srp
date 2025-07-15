void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteHitTest(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::GFx::InteractiveObject *Target; // edi
  Scaleform::GFx::AS2::Value *Result; // ebx
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
  unsigned __int8 *WorldMatrix3D; // eax
  bool v17; // al
  Scaleform::Render::Matrix2x4<float> *LevelMatrix; // eax
  bool v19; // al
  Scaleform::GFx::AS2::Value *v20; // esi
  bool v21; // bl
  bool v22; // al
  Scaleform::GFx::AS2::Value *v23; // eax
  Scaleform::GFx::InteractiveObject *v24; // ebx
  Scaleform::GFx::AS2::Environment *Env; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  const Scaleform::Render::Matrix2x4<float> *v27; // eax
  Scaleform::Render::Matrix2x4<float> *WorldMatrix; // eax
  Scaleform::Render::Matrix2x4<float> *v29; // eax
  bool v30; // al
  Scaleform::GFx::AS2::Environment *v31; // [esp+984h] [ebp-104h]
  Scaleform::GFx::AS2::Environment *v32; // [esp+984h] [ebp-104h]
  Scaleform::GFx::AS2::Environment *v33; // [esp+984h] [ebp-104h]
  Scaleform::GFx::AS2::Environment *v34; // [esp+984h] [ebp-104h]
  unsigned __int8 v35; // [esp+998h] [ebp-F0h]
  Scaleform::GFx::DisplayObjectBase *v36; // [esp+998h] [ebp-F0h]
  float v37; // [esp+99Ch] [ebp-ECh]
  float v38; // [esp+99Ch] [ebp-ECh]
  float v39; // [esp+99Ch] [ebp-ECh]
  float v40; // [esp+99Ch] [ebp-ECh]
  float v41; // [esp+99Ch] [ebp-ECh]
  Scaleform::GFx::ASString varname; // [esp+9A0h] [ebp-E8h] BYREF
  float v43; // [esp+9A4h] [ebp-E4h]
  Scaleform::Render::Rect<float> ptOut; // [esp+9A8h] [ebp-E0h] BYREF
  Scaleform::GFx::AS2::Value v45; // [esp+9B8h] [ebp-D0h] BYREF
  Scaleform::Render::Rect<float> r; // [esp+9C8h] [ebp-C0h] BYREF
  Scaleform::Render::Matrix3x4<float> v47; // [esp+9D8h] [ebp-B0h] BYREF
  Scaleform::Render::Matrix3x4<float> v48; // [esp+A08h] [ebp-80h] BYREF
  Scaleform::Render::Rect<float> v49; // [esp+A38h] [ebp-50h] BYREF
  Scaleform::Render::Matrix4x4<float> v50; // [esp+A48h] [ebp-40h] BYREF

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
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    v47.M[0][0] = 1.0;
    Result->T.Type = 2;
    v47.M[0][1] = 0.0;
    Result->V.BooleanValue = 0;
    v4 = Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
    v47.M[0][2] = 0.0;
    GetBounds = v4->GetBounds;
    v47.M[0][3] = 0.0;
    v47.M[1][0] = 0.0;
    v47.M[1][2] = 0.0;
    v47.M[1][3] = 0.0;
    v47.M[1][1] = 1.0;
    GetBounds(Target, &r, (const Scaleform::Render::Matrix2x4<float> *)&v47);
    if ( r.x1 != r.x2 || r.y1 != r.y2 )
    {
      NArgs = fn->NArgs;
      if ( NArgs < 2 )
      {
        if ( NArgs == 1 )
        {
          v23 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
          v24 = 0;
          v36 = 0;
          if ( v23->T.Type == 7 )
          {
            v24 = Scaleform::GFx::AS2::Value::ToCharacter(v23, fn->Env);
            v36 = v24;
          }
          else
          {
            Scaleform::GFx::AS2::Value::ToStringImpl(v23, &varname, fn->Env, -1, 0);
            Env = fn->Env;
            v45.T.Type = 0;
            if ( Scaleform::GFx::AS2::Environment::GetVariable(Env, &varname, &v45, 0, 0, 0, 0) )
            {
              v24 = Scaleform::GFx::AS2::Value::ToCharacter(&v45, fn->Env);
              v36 = v24;
            }
            if ( v45.T.Type >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs(&v45);
            pNode = varname.pNode;
            --varname.pNode->RefCount;
            if ( !pNode->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
          }
          if ( v24 )
          {
            v43 = *(float *)&v24->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
            Scaleform::Render::Matrix2x4<float>::Matrix2x4<float>((Scaleform::Render::Matrix2x4<float> *)&v48);
            (*(void (__thiscall **)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Rect<float> *, const Scaleform::Render::Matrix2x4<float> *))(LODWORD(v43) + 236))(
              v36,
              &ptOut,
              v27);
            if ( !Scaleform::Render::Rect<float>::IsNull(&ptOut) )
            {
              WorldMatrix = Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(
                              Target,
                              (Scaleform::Render::Matrix2x4<float> *)&v48);
              Scaleform::Render::Matrix2x4<float>::EncloseTransform(
                WorldMatrix,
                (Scaleform::Render::Rect<float> *)&v47,
                &r);
              v29 = Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v36, (Scaleform::Render::Matrix2x4<float> *)&v48);
              Scaleform::Render::Matrix2x4<float>::EncloseTransform(v29, &v49, &ptOut);
              v30 = Scaleform::Render::Rect<float>::Intersects((Scaleform::Render::Rect<float> *)&v47, &v49);
              Scaleform::GFx::AS2::Value::SetBool(fn->Result, v30);
            }
          }
        }
      }
      else
      {
        v31 = fn->Env;
        v35 = 0;
        v7 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
        v37 = Scaleform::GFx::AS2::Value::ToNumber(v7, v31);
        v32 = fn->Env;
        v8 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        *(float *)&varname.pNode = Scaleform::GFx::AS2::Value::ToNumber(v8, v32);
        v9 = fn->NArgs < 3;
        ptOut.x1 = *(float *)&varname.pNode * 20.0;
        ptOut.y1 = 20.0 * v37;
        if ( !v9 )
        {
          v33 = fn->Env;
          v10 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
          v35 = Scaleform::GFx::AS2::Value::ToBool(v10, v33) != 0;
        }
        if ( fn->NArgs >= 4 )
        {
          v34 = fn->Env;
          v11 = Scaleform::GFx::AS2::FnCall::Arg(fn, 3);
          v35 |= Scaleform::GFx::AS2::Value::ToBool(v11, v34) != 0 ? 2 : 0;
        }
        pMovieImpl = Target->pASRoot->pMovieImpl;
        if ( pMovieImpl && Scaleform::GFx::DisplayObjectBase::Is3D(Target, 1) )
        {
          ViewOffsetY = pMovieImpl->ViewOffsetY;
          varname.pNode = (Scaleform::GFx::ASStringNode *)&pMovieImpl->ScreenToWorld;
          v38 = ViewOffsetY * 20.0;
          v14 = ptOut.y1 - v38;
          v39 = pMovieImpl->VisibleFrameRect.y2 - pMovieImpl->VisibleFrameRect.y1;
          v43 = v14 / v39 * 2.0 - 1.0;
          v40 = 20.0 * pMovieImpl->ViewOffsetX;
          v15 = ptOut.x1 - v40;
          v41 = pMovieImpl->VisibleFrameRect.x2 - pMovieImpl->VisibleFrameRect.x1;
          pMovieImpl->ScreenToWorld.Sx = v15 / v41 * 2.0 - 1.0;
          pMovieImpl->ScreenToWorld.Sy = -v43;
          Scaleform::Render::Matrix3x4<float>::Matrix3x4<float>(&v48);
          Scaleform::Render::Matrix4x4<float>::Matrix4x4<float>(&v50);
          if ( Target->GetProjectionMatrix3D(Target, &v50, 0) )
            memcpy((unsigned __int8 *)&varname.pNode->HashFlags, (unsigned __int8 *)&v50, 0x40u);
          if ( Target->GetViewMatrix3D(Target, &v48, 0) )
            memcpy((unsigned __int8 *)&varname.pNode[3].8, (unsigned __int8 *)&v48, 0x30u);
          WorldMatrix3D = (unsigned __int8 *)Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(Target, &v47);
          memcpy((unsigned __int8 *)&varname.pNode[5].8, WorldMatrix3D, 0x30u);
          Scaleform::Render::ScreenToWorld::GetWorldPoint(
            (Scaleform::Render::ScreenToWorld *)varname.pNode,
            (Scaleform::Render::Point<float> *)&ptOut);
          v17 = Target->PointTestLocal(Target, (const Scaleform::Render::Point<float> *)&ptOut, v35);
          Scaleform::GFx::AS2::Value::SetBool(fn->Result, v17);
        }
        else
        {
          LevelMatrix = Scaleform::GFx::DisplayObjectBase::GetLevelMatrix(
                          Target,
                          (Scaleform::Render::Matrix2x4<float> *)&v47);
          Scaleform::Render::Matrix2x4<float>::TransformByInverse(
            LevelMatrix,
            (Scaleform::Render::Point<float> *)&v45,
            (const Scaleform::Render::Point<float> *)&ptOut);
          if ( (Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 1) != 0 )
          {
            v19 = Target->PointTestLocal(Target, (const Scaleform::Render::Point<float> *)&v45, v35);
            v20 = fn->Result;
            v21 = v19;
            Scaleform::GFx::AS2::Value::DropRefs(v20);
            v20->T.Type = 2;
            v20->V.BooleanValue = v21;
          }
          else if ( Scaleform::Render::Rect<float>::Contains(&r, (const Scaleform::Render::Point<float> *)&v45) )
          {
            if ( (v35 & 1) != 0 )
            {
              v22 = Target->PointTestLocal(Target, (const Scaleform::Render::Point<float> *)&v45, v35);
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
