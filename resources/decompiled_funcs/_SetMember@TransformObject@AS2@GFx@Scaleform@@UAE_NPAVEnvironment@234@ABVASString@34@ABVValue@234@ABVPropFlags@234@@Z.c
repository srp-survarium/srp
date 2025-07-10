char __thiscall Scaleform::GFx::AS2::TransformObject::SetMember(
        Scaleform::GFx::AS2::TransformObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        const Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::MovieImpl *pLocalFrame; // eax
  Scaleform::GFx::InteractiveObject *v6; // eax
  Scaleform::GFx::DisplayObjectBase *v7; // edi
  Scaleform::GFx::AS2::Object *v8; // eax
  Scaleform::GFx::AS2::ColorTransformObject *v9; // esi
  unsigned int RefCount; // eax
  Scaleform::GFx::MovieImpl *v12; // eax
  Scaleform::GFx::InteractiveObject *v13; // eax
  Scaleform::GFx::DisplayObjectBase *v14; // esi
  Scaleform::GFx::AS2::Object *v15; // eax
  Scaleform::GFx::AS2::MatrixObject *v16; // edi
  void (__thiscall *SetMatrix)(Scaleform::GFx::DisplayObjectBase *, const Scaleform::Render::Matrix2x4<float> *); // edx
  unsigned int v18; // eax
  Scaleform::Render::Cxform result; // [esp+170h] [ebp-80h] BYREF
  Scaleform::GFx::DisplayObjectBase::GeomDataType gd; // [esp+190h] [ebp-60h] BYREF

  if ( !strcmp(name->pNode->pData, "pixelBounds") )
    return 1;
  if ( !strcmp(name->pNode->pData, "colorTransform") )
  {
    pLocalFrame = (Scaleform::GFx::MovieImpl *)this->ResolveHandler.pLocalFrame;
    if ( pLocalFrame )
    {
      v6 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
             *(Scaleform::GFx::CharacterHandle **)&this->ResolveHandler.Flags,
             pLocalFrame);
      v7 = v6;
      if ( v6 )
      {
        ++v6->RefCount;
        v8 = Scaleform::GFx::AS2::Value::ToObject(val, penv);
        v9 = (Scaleform::GFx::AS2::ColorTransformObject *)v8;
        if ( v8 )
        {
          v8->RefCount = (v8->RefCount + 1) & 0x8FFFFFFF;
          if ( v8->GetObjectType(&v8->Scaleform::GFx::AS2::ObjectInterface) == Object_ColorTransform )
          {
            Scaleform::GFx::AS2::ColorTransformObject::GetCxform(v9, &result);
            Scaleform::GFx::DisplayObjectBase::SetCxform(v7, &result);
            v7->SetAcceptAnimMoves(v7, 0);
          }
          RefCount = v9->RefCount;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
          {
            v9->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
          }
        }
        Scaleform::RefCountNTSImpl::Release(v7);
      }
    }
    return 1;
  }
  if ( strcmp(name->pNode->pData, "matrix") )
    return Scaleform::GFx::AS2::Object::SetMember(this, penv, name, val, flags);
  v12 = (Scaleform::GFx::MovieImpl *)this->ResolveHandler.pLocalFrame;
  if ( v12 )
  {
    v13 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
            *(Scaleform::GFx::CharacterHandle **)&this->ResolveHandler.Flags,
            v12);
    v14 = v13;
    if ( v13 )
    {
      ++v13->RefCount;
      v15 = Scaleform::GFx::AS2::Value::ToObject(val, penv);
      v16 = (Scaleform::GFx::AS2::MatrixObject *)v15;
      if ( v15 )
      {
        v15->RefCount = (v15->RefCount + 1) & 0x8FFFFFFF;
        if ( v15->GetObjectType(&v15->Scaleform::GFx::AS2::ObjectInterface) == Object_Matrix )
        {
          Scaleform::GFx::AS2::MatrixObject::GetMatrix(v16, (Scaleform::Render::Matrix2x4<float> *)&result, penv);
          SetMatrix = v14->SetMatrix;
          result.M[0][3] = result.M[0][3] * 20.0;
          result.M[1][3] = 20.0 * result.M[1][3];
          SetMatrix(v14, (const Scaleform::Render::Matrix2x4<float> *)&result);
          Scaleform::GFx::DisplayObjectBase::GeomDataType::GeomDataType(&gd);
          Scaleform::GFx::DisplayObjectBase::GetGeomData(v14, &gd);
          gd.X = (int)result.M[0][3];
          gd.Y = (int)result.M[1][3];
          gd.Rotation = atan2(result.M[1][0], result.M[0][0]) * 180.0 / 3.141592653589793;
          gd.XScale = sqrt(result.M[1][0] * result.M[1][0] + result.M[0][0] * result.M[0][0]) * 100.0;
          gd.YScale = sqrt(result.M[1][1] * result.M[1][1] + result.M[0][1] * result.M[0][1]) * 100.0;
          Scaleform::GFx::DisplayObjectBase::SetGeomData(v14, &gd);
        }
        v18 = v16->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v18) != 0 )
        {
          v16->RefCount = v18 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v16);
        }
      }
      Scaleform::RefCountNTSImpl::Release(v14);
    }
  }
  return 1;
}
