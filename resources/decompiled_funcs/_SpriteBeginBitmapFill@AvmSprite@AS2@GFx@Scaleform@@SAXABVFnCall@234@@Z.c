void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteBeginBitmapFill(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::GFx::InteractiveObject *v2; // edi
  Scaleform::GFx::AS2::Value *v3; // eax
  Scaleform::GFx::AS2::Object *v4; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v5; // edi
  Scaleform::GFx::AS2::Value *v6; // eax
  Scaleform::GFx::AS2::Object *v7; // eax
  Scaleform::GFx::AS2::MatrixObject *v8; // ebx
  const Scaleform::Render::Matrix2x4<float> *Matrix; // eax
  Scaleform::GFx::AS2::Value *v10; // eax
  char v11; // bl
  Scaleform::GFx::AS2::Value *v12; // eax
  Scaleform::GFx::FillType v13; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp+80h] [ebp-64h]
  Scaleform::GFx::AS2::Environment *v16; // [esp+80h] [ebp-64h]
  Scaleform::GFx::AS2::Environment *v17; // [esp+80h] [ebp-64h]
  Scaleform::GFx::AS2::Environment *v18; // [esp+80h] [ebp-64h]
  Scaleform::GFx::InteractiveObject *Target; // [esp+9Ch] [ebp-48h]
  Scaleform::GFx::ImageResource *pRCC; // [esp+A0h] [ebp-44h]
  Scaleform::Render::Matrix2x4<float> mtx; // [esp+A4h] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> result; // [esp+C4h] [ebp-20h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( ThisPtr->GetObjectType(fn->ThisPtr) == Object_Sprite )
      v2 = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].__vftable;
    else
      v2 = 0;
    Target = v2;
  }
  else
  {
    Target = fn->Env->Target;
  }
  if ( Target )
  {
    if ( fn->NArgs > 0 )
    {
      Env = fn->Env;
      v3 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      v4 = Scaleform::GFx::AS2::Value::ToObject(v3, Env);
      v5 = v4;
      if ( v4 )
      {
        v4->RefCount = (v4->RefCount + 1) & 0x8FFFFFFF;
        if ( v4->GetObjectType(&v4->Scaleform::GFx::AS2::ObjectInterface) != Object_BitmapData )
          goto LABEL_24;
        pRCC = (Scaleform::GFx::ImageResource *)v5[3].pRCC;
        if ( !pRCC )
          goto LABEL_24;
        Scaleform::Render::Matrix2x4<float>::Matrix2x4<float>(&mtx);
        if ( fn->NArgs > 1 )
        {
          v16 = fn->Env;
          v6 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
          v7 = Scaleform::GFx::AS2::Value::ToObject(v6, v16);
          v8 = (Scaleform::GFx::AS2::MatrixObject *)v7;
          if ( v7 && v7->GetObjectType(&v7->Scaleform::GFx::AS2::ObjectInterface) == Object_Matrix )
          {
            Matrix = Scaleform::GFx::AS2::MatrixObject::GetMatrix(v8, &result, fn->Env);
            Scaleform::Render::Matrix2x4<float>::operator=(&mtx, Matrix);
          }
          if ( fn->NArgs > 2 )
          {
            v17 = fn->Env;
            v10 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
            v11 = Scaleform::GFx::AS2::Value::ToBool(v10, v17);
            if ( fn->NArgs > 3 )
            {
              v18 = fn->Env;
              v12 = Scaleform::GFx::AS2::FnCall::Arg(fn, 3);
              if ( Scaleform::GFx::AS2::Value::ToBool(v12, v18) )
              {
                v13 = (v11 == 0) + 64;
LABEL_23:
                Scaleform::GFx::AS2::AvmSprite::BeginBitmapFill(
                  (Scaleform::GFx::AS2::AvmSprite *)(&Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                   + Target->AvmObjOffset),
                  v13,
                  pRCC,
                  &mtx);
LABEL_24:
                RefCount = v5->RefCount;
                if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
                {
                  v5->RefCount = RefCount - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
                }
                return;
              }
            }
            if ( !v11 )
            {
              v13 = Fill_ClippedImage;
              goto LABEL_23;
            }
          }
        }
        v13 = Fill_TiledImage;
        goto LABEL_23;
      }
    }
  }
}
