void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteLineStyle(float fn)
{
  float v1; // esi
  Scaleform::GFx::AS2::ObjectInterface *v2; // edi
  unsigned int v3; // ebp
  Scaleform::GFx::InteractiveObject *v4; // ebx
  Scaleform::GFx::InteractiveObject *v5; // edi
  Scaleform::GFx::AS2::Value *v6; // eax
  bool v7; // cc
  int v8; // edi
  Scaleform::GFx::AS2::Value *v9; // eax
  Scaleform::GFx::AS2::Value *v10; // eax
  int v11; // edi
  double v12; // st7
  bool v13; // c0
  bool v14; // c3
  double v15; // st7
  Scaleform::GFx::AS2::Value *v16; // eax
  bool v17; // al
  Scaleform::GFx::AS2::Value *v18; // eax
  Scaleform::GFx::AS2::Value *v19; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v21; // zf
  Scaleform::GFx::AS2::Value *v22; // eax
  Scaleform::GFx::ASStringNode *v23; // ecx
  Scaleform::GFx::AS2::Value *v24; // eax
  float v25; // ecx
  Scaleform::GFx::AS2::Environment *v26; // [esp+10h] [ebp-3Ch]
  Scaleform::GFx::AS2::Environment *v27; // [esp+10h] [ebp-3Ch]
  Scaleform::GFx::AS2::Environment *v28; // [esp+10h] [ebp-3Ch]
  Scaleform::GFx::AS2::Environment *miterLimit; // [esp+18h] [ebp-34h]
  Scaleform::GFx::AS2::Environment *miterLimita; // [esp+18h] [ebp-34h]
  Scaleform::GFx::AS2::Environment *miterLimitb; // [esp+18h] [ebp-34h]
  const Scaleform::GFx::AS2::Environment *miterLimitc; // [esp+18h] [ebp-34h]
  Scaleform::GFx::AS2::Environment *miterLimitd; // [esp+18h] [ebp-34h]
  float v34; // [esp+2Ch] [ebp-20h]
  Scaleform::GFx::InteractiveObject *v35; // [esp+30h] [ebp-1Ch]
  unsigned int joins; // [esp+34h] [ebp-18h]
  unsigned int caps; // [esp+38h] [ebp-14h]
  Scaleform::GFx::ASString src[2]; // [esp+3Ch] [ebp-10h] BYREF
  bool hinting[4]; // [esp+44h] [ebp-8h]
  float lineWidth; // [esp+48h] [ebp-4h]

  v1 = fn;
  v2 = *(Scaleform::GFx::AS2::ObjectInterface **)(LODWORD(fn) + 8);
  v3 = 0;
  if ( v2 )
  {
    if ( v2->GetObjectType(*(Scaleform::GFx::AS2::ObjectInterface **)(LODWORD(fn) + 8)) == Object_Sprite )
      v5 = (Scaleform::GFx::InteractiveObject *)v2[1].__vftable;
    else
      v5 = 0;
    v35 = v5;
    v4 = v5;
  }
  else
  {
    v4 = *(Scaleform::GFx::InteractiveObject **)(*(_DWORD *)(LODWORD(fn) + 24) + 112);
    v35 = v4;
  }
  if ( v4 )
  {
    if ( *(int *)(LODWORD(v1) + 28) <= 0 )
    {
      Scaleform::GFx::AS2::AvmSprite::SetNoLine((Scaleform::GFx::AS2::AvmSprite *)(&v4->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                                 + v4->AvmObjOffset));
      return;
    }
    miterLimit = *(Scaleform::GFx::AS2::Environment **)(LODWORD(v1) + 24);
    v6 = Scaleform::GFx::AS2::FnCall::Arg((Scaleform::GFx::AS2::FnCall *)LODWORD(v1), 0);
    lineWidth = Scaleform::GFx::AS2::Value::ToNumber(v6, miterLimit);
    v7 = *(_DWORD *)(LODWORD(v1) + 28) <= 1;
    v34 = 3.0;
    v8 = -16777216;
    hinting[0] = 0;
    caps = 0;
    joins = 0;
    if ( v7 )
      goto LABEL_45;
    miterLimita = *(Scaleform::GFx::AS2::Environment **)(LODWORD(v1) + 24);
    v9 = Scaleform::GFx::AS2::FnCall::Arg((Scaleform::GFx::AS2::FnCall *)LODWORD(v1), 1);
    v8 = Scaleform::GFx::AS2::Value::ToUInt32(v9, miterLimita) | 0xFF000000;
    if ( *(int *)(LODWORD(v1) + 28) <= 2 )
      goto LABEL_45;
    miterLimitb = *(Scaleform::GFx::AS2::Environment **)(LODWORD(v1) + 24);
    v10 = Scaleform::GFx::AS2::FnCall::Arg((Scaleform::GFx::AS2::FnCall *)LODWORD(v1), 2);
    fn = Scaleform::GFx::AS2::Value::ToNumber(v10, miterLimitb);
    v11 = v8 & 0xFFFFFF;
    fn = fn * 255.0 / 100.0;
    v12 = fn;
    if ( fn >= 255.0 )
    {
      fn = 255.0;
    }
    else
    {
      v13 = v12 > 0.0;
      v14 = 0.0 == v12;
      v15 = 0.0;
      if ( !v13 && !v14 )
      {
LABEL_14:
        fn = v15;
        *(_QWORD *)&src[0].pNode = (__int64)fn;
        v8 = ((int)src[0].pNode << 24) | v11;
        if ( *(int *)(LODWORD(v1) + 28) > 3 )
        {
          miterLimitc = *(const Scaleform::GFx::AS2::Environment **)(LODWORD(v1) + 24);
          v16 = Scaleform::GFx::AS2::FnCall::Arg((Scaleform::GFx::AS2::FnCall *)LODWORD(v1), 3);
          v17 = Scaleform::GFx::AS2::Value::ToBool(v16, v8, miterLimitc);
          v7 = *(_DWORD *)(LODWORD(v1) + 28) <= 4;
          hinting[0] = v17;
          if ( !v7 )
          {
            v26 = *(Scaleform::GFx::AS2::Environment **)(LODWORD(v1) + 24);
            v18 = Scaleform::GFx::AS2::FnCall::Arg((Scaleform::GFx::AS2::FnCall *)LODWORD(v1), 4);
            Scaleform::GFx::AS2::Value::ToStringImpl(v18, (Scaleform::GFx::ASString *)&fn, v26, -1, 0);
            if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&fn, "none") )
            {
              v3 = 6;
            }
            else if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&fn, "vertical") )
            {
              v3 = 4;
            }
            else if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&fn, "horizontal") )
            {
              v3 = 2;
            }
            if ( *(int *)(LODWORD(v1) + 28) > 5 )
            {
              v27 = *(Scaleform::GFx::AS2::Environment **)(LODWORD(v1) + 24);
              v19 = Scaleform::GFx::AS2::FnCall::Arg((Scaleform::GFx::AS2::FnCall *)LODWORD(v1), 5);
              Scaleform::GFx::AS2::Value::ToStringImpl(v19, src, v27, -1, 0);
              Scaleform::GFx::ASString::operator=((Scaleform::GFx::ASString *)&fn, src);
              pNode = src[0].pNode;
              v21 = src[0].pNode->RefCount-- == 1;
              if ( v21 )
                Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
              if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&fn, "none") )
              {
                caps = 320;
              }
              else if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&fn, "square") )
              {
                caps = 640;
              }
              if ( *(int *)(LODWORD(v1) + 28) > 6 )
              {
                v28 = *(Scaleform::GFx::AS2::Environment **)(LODWORD(v1) + 24);
                v22 = Scaleform::GFx::AS2::FnCall::Arg((Scaleform::GFx::AS2::FnCall *)LODWORD(v1), 6);
                Scaleform::GFx::AS2::Value::ToStringImpl(v22, src, v28, -1, 0);
                Scaleform::GFx::ASString::operator=((Scaleform::GFx::ASString *)&fn, src);
                v23 = src[0].pNode;
                v21 = src[0].pNode->RefCount-- == 1;
                if ( v21 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v23);
                if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&fn, "miter") )
                {
                  joins = 32;
                }
                else if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&fn, "bevel") )
                {
                  joins = 16;
                }
                if ( *(int *)(LODWORD(v1) + 28) > 7 )
                {
                  miterLimitd = *(Scaleform::GFx::AS2::Environment **)(LODWORD(v1) + 24);
                  v24 = Scaleform::GFx::AS2::FnCall::Arg((Scaleform::GFx::AS2::FnCall *)LODWORD(v1), 7);
                  v34 = Scaleform::GFx::AS2::Value::ToNumber(v24, miterLimitd);
                  if ( v34 < 1.0 )
                    v34 = 1.0;
                  if ( v34 > 255.0 )
                    v34 = 255.0;
                }
              }
            }
            v25 = fn;
            v21 = (*(_DWORD *)(LODWORD(fn) + 12))-- == 1;
            if ( v21 )
              Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)LODWORD(v25));
            v4 = v35;
          }
        }
LABEL_45:
        Scaleform::GFx::AS2::AvmSprite::SetLineStyle(
          (Scaleform::GFx::AS2::AvmSprite *)(&v4->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                           + v4->AvmObjOffset),
          lineWidth,
          v8,
          hinting[0],
          v3,
          caps,
          joins,
          v34);
        return;
      }
    }
    v15 = fn;
    goto LABEL_14;
  }
}
