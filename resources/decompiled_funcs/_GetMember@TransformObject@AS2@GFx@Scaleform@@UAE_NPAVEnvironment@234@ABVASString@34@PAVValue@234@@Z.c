char __thiscall Scaleform::GFx::AS2::TransformObject::GetMember(
        Scaleform::GFx::AS2::TransformObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::MovieImpl *pLocalFrame; // eax
  Scaleform::GFx::InteractiveObject *v6; // eax
  Scaleform::RefCountNTSImpl *v7; // esi
  Scaleform::GFx::InteractiveObject_vtbl *v8; // ebx
  int v9; // eax
  double v10; // st4
  double v11; // st4
  double v12; // st3
  double v13; // st3
  double v14; // st3
  double v15; // st2
  double v16; // st2
  double v17; // st5
  double v18; // st5
  Scaleform::GFx::MovieImpl *pMovieRoot; // ecx
  char result; // al
  Scaleform::GFx::MovieImpl *v21; // eax
  Scaleform::GFx::InteractiveObject *v22; // eax
  Scaleform::RefCountNTSImpl *v23; // ebx
  int v24; // edx
  Scaleform::GFx::InteractiveObject *v25; // eax
  Scaleform::RefCountNTSImpl *v26; // esi
  const Scaleform::Render::Matrix2x4<float> *v27; // eax
  Scaleform::GFx::InteractiveObject *v28; // eax
  Scaleform::RefCountNTSImpl *v29; // edi
  Scaleform::GFx::DisplayObjectBase *pParent; // esi
  const Scaleform::Render::Cxform *Cxform; // eax
  Scaleform::GFx::AS2::ColorTransformObject *v32; // eax
  Scaleform::GFx::AS2::ColorTransformObject *v33; // eax
  Scaleform::GFx::AS2::ColorTransformObject *v34; // esi
  const Scaleform::GFx::AS2::Value *v35; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::InteractiveObject *v37; // eax
  Scaleform::RefCountNTSImpl *v38; // edi
  _DWORD *v39; // esi
  const Scaleform::Render::Matrix2x4<float> *v40; // eax
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // edi
  Scaleform::GFx::AS2::MatrixObject *v42; // eax
  Scaleform::GFx::AS2::MatrixObject *v43; // eax
  float v44; // [esp+15Ch] [ebp-38h]
  float v45; // [esp+15Ch] [ebp-38h]
  float v47; // [esp+160h] [ebp-34h]
  float v48; // [esp+160h] [ebp-34h]
  float v49; // [esp+160h] [ebp-34h]
  float v50; // [esp+160h] [ebp-34h]
  Scaleform::GFx::AS2::Value v51; // [esp+164h] [ebp-30h] BYREF
  Scaleform::Render::Rect<double> v52; // [esp+174h] [ebp-20h] BYREF

  if ( !strcmp(name->pNode->pData, "pixelBounds") )
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
        v8 = v6->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
        v9 = (int)v6->GetMatrix(v6);
        v8->GetBounds(
          (Scaleform::GFx::DisplayObjectBase *)v7,
          (Scaleform::Render::Rect<float> *)&v51,
          (const Scaleform::Render::Matrix2x4<float> *)v9);
        v47 = *((float *)&v51.NV + 3) - *(float *)&v51.V.pStringNode;
        v48 = v47 * 0.05000000074505806;
        v10 = v48;
        if ( v48 <= 0.0 )
          v11 = v10 - 0.5;
        else
          v11 = v10 + 0.5;
        v44 = *(float *)&v51.V.FunctionValue.pLocalFrame - *(float *)&v51.T.Type;
        v45 = v44 * 0.05000000074505806;
        v12 = v45;
        if ( v45 <= 0.0 )
          v13 = v12 - 0.5;
        else
          v13 = v12 + 0.5;
        v14 = (double)(int)v13;
        v49 = *(float *)&v51.V.pStringNode * 0.05000000074505806;
        v15 = v49;
        if ( v49 <= 0.0 )
          v16 = v15 - 0.5;
        else
          v16 = v15 + 0.5;
        v50 = 0.05000000074505806 * *(float *)&v51.T.Type;
        v17 = v50;
        if ( v50 <= 0.0 )
          v18 = v17 - 0.5;
        else
          v18 = v17 + 0.5;
        pMovieRoot = this->pMovieRoot;
        v52.x1 = (double)(int)v18;
        v52.y1 = (double)(int)v16;
        v52.x2 = v52.x1 + v14;
        v52.y2 = (double)(int)v11 + v52.y1;
        Scaleform::GFx::AS2::RectangleObject::SetProperties(
          (Scaleform::GFx::AS2::RectangleObject *)pMovieRoot,
          penv,
          &v52);
        Scaleform::GFx::AS2::Value::SetAsObject(val, (Scaleform::GFx::AS2::Object *)this->pMovieRoot);
        Scaleform::RefCountNTSImpl::Release(v7);
        return 1;
      }
    }
LABEL_17:
    Scaleform::GFx::AS2::Value::DropRefs(val);
    result = 0;
    val->T.Type = 0;
    return result;
  }
  if ( !strcmp(name->pNode->pData, "colorTransform") )
  {
    v21 = (Scaleform::GFx::MovieImpl *)this->ResolveHandler.pLocalFrame;
    if ( v21 )
    {
      v22 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
              *(Scaleform::GFx::CharacterHandle **)&this->ResolveHandler.Flags,
              v21);
      v23 = v22;
      if ( v22 )
      {
        ++v22->RefCount;
        qmemcpy(&v52, Scaleform::GFx::DisplayObjectBase::GetCxform(v22), sizeof(v52));
        Scaleform::GFx::AS2::ColorTransformObject::SetCxform(
          *(Scaleform::GFx::AS2::ColorTransformObject **)&this->ArePropertiesSet,
          (const Scaleform::Render::Cxform *)&v52);
        Scaleform::GFx::AS2::Value::SetAsObject(val, *(Scaleform::GFx::AS2::Object **)(v24 + 48));
        Scaleform::RefCountNTSImpl::Release(v23);
        return 1;
      }
    }
    goto LABEL_17;
  }
  if ( !strcmp(name->pNode->pData, "matrix") )
  {
    if ( this->ResolveHandler.pLocalFrame
      && (v25 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
                  *(Scaleform::GFx::CharacterHandle **)&this->ResolveHandler.Flags,
                  (Scaleform::GFx::MovieImpl *)this->ResolveHandler.pLocalFrame),
          (v26 = v25) != 0) )
    {
      ++v25->RefCount;
      v27 = v25->GetMatrix(v25);
      Scaleform::Render::Matrix2x4<float>::operator=((Scaleform::Render::Matrix2x4<float> *)&v52, v27);
      Scaleform::GFx::AS2::MatrixObject::SetMatrixTwips(
        (Scaleform::GFx::AS2::MatrixObject *)this->pWatchpoints,
        &penv->StringContext,
        (const Scaleform::Render::Matrix2x4<float> *)&v52);
      Scaleform::GFx::AS2::Value::SetAsObject(val, (Scaleform::GFx::AS2::Object *)this->pWatchpoints);
      Scaleform::RefCountNTSImpl::Release(v26);
      return 1;
    }
    else
    {
      Scaleform::GFx::AS2::Value::DropRefs(val);
      val->T.Type = 0;
      return 0;
    }
  }
  else
  {
    if ( Scaleform::GFx::ASString::operator==(name, "concatenatedColorTransform") )
    {
      Scaleform::Render::Cxform::Cxform((Scaleform::Render::Cxform *)&v52);
      if ( this->ResolveHandler.pLocalFrame )
      {
        v28 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
                *(Scaleform::GFx::CharacterHandle **)&this->ResolveHandler.Flags,
                (Scaleform::GFx::MovieImpl *)this->ResolveHandler.pLocalFrame);
        v29 = v28;
        if ( v28 )
        {
          ++v28->RefCount;
          pParent = v28;
          do
          {
            Cxform = Scaleform::GFx::DisplayObjectBase::GetCxform(pParent);
            Scaleform::Render::Cxform::Prepend((Scaleform::Render::Cxform *)&v52, Cxform);
            pParent = pParent->pParent;
          }
          while ( pParent );
          Scaleform::RefCountNTSImpl::Release(v29);
        }
      }
      v32 = (Scaleform::GFx::AS2::ColorTransformObject *)penv->StringContext.pContext->pHeap->Alloc(
                                                           penv->StringContext.pContext->pHeap,
                                                           96,
                                                           0);
      if ( v32 )
      {
        Scaleform::GFx::AS2::ColorTransformObject::ColorTransformObject(v32, penv);
        v34 = v33;
      }
      else
      {
        v34 = 0;
      }
      Scaleform::GFx::AS2::ColorTransformObject::SetCxform(v34, (const Scaleform::Render::Cxform *)&v52);
    }
    else
    {
      if ( !Scaleform::GFx::ASString::operator==(name, "concatenatedMatrix") )
        return ((int (__thiscall *)(Scaleform::GFx::AS2::TransformObject *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].~Scaleform::GFx::AS2::TransformObject)(
                 this,
                 &penv->StringContext,
                 name,
                 val);
      Scaleform::Render::Matrix2x4<float>::Matrix2x4<float>((Scaleform::Render::Matrix2x4<float> *)&v52);
      if ( this->ResolveHandler.pLocalFrame )
      {
        v37 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
                *(Scaleform::GFx::CharacterHandle **)&this->ResolveHandler.Flags,
                (Scaleform::GFx::MovieImpl *)this->ResolveHandler.pLocalFrame);
        v38 = v37;
        if ( v37 )
        {
          ++v37->RefCount;
          v39 = &v37->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
          do
          {
            v40 = (const Scaleform::Render::Matrix2x4<float> *)(*(int (__thiscall **)(_DWORD *))(*v39 + 8))(v39);
            Scaleform::Render::Matrix2x4<float>::Prepend((Scaleform::Render::Matrix2x4<float> *)&v52, v40);
            v39 = (_DWORD *)v39[8];
          }
          while ( v39 );
          Scaleform::RefCountNTSImpl::Release(v38);
        }
      }
      p_StringContext = &penv->StringContext;
      v42 = (Scaleform::GFx::AS2::MatrixObject *)penv->StringContext.pContext->pHeap->Alloc(
                                                   penv->StringContext.pContext->pHeap,
                                                   52,
                                                   0);
      if ( v42 )
      {
        Scaleform::GFx::AS2::MatrixObject::MatrixObject(v42, penv);
        v34 = (Scaleform::GFx::AS2::ColorTransformObject *)v43;
        Scaleform::GFx::AS2::MatrixObject::SetMatrixTwips(
          v43,
          p_StringContext,
          (const Scaleform::Render::Matrix2x4<float> *)&v52);
      }
      else
      {
        v34 = 0;
        Scaleform::GFx::AS2::MatrixObject::SetMatrixTwips(
          0,
          p_StringContext,
          (const Scaleform::Render::Matrix2x4<float> *)&v52);
      }
    }
    Scaleform::GFx::AS2::Value::Value(&v51, v34);
    Scaleform::GFx::AS2::Value::operator=(val, v35);
    if ( v51.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v51);
    if ( v34 )
    {
      RefCount = v34->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v34->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v34);
      }
    }
    return 1;
  }
}
