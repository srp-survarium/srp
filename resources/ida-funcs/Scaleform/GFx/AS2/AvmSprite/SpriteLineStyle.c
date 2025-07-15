void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteLineStyle(float fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::ObjectInterface *v2; // edi
  unsigned int v3; // ebp
  Scaleform::GFx::InteractiveObject *v4; // ebx
  Scaleform::GFx::InteractiveObject *v5; // edi
  Scaleform::GFx::AS2::Value *v6; // eax
  bool v7; // cc
  unsigned int v8; // edi
  Scaleform::GFx::AS2::Value *v9; // eax
  Scaleform::GFx::AS2::Value *v10; // eax
  unsigned int v11; // edi
  double v12; // st7
  bool v13; // c0
  bool v14; // c3
  double v15; // st7
  Scaleform::GFx::AS2::Value *v16; // eax
  char v17; // al
  Scaleform::GFx::AS2::Value *v18; // eax
  Scaleform::GFx::AS2::Value *v19; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v21; // zf
  Scaleform::GFx::AS2::Value *v22; // eax
  Scaleform::GFx::ASStringNode *v23; // ecx
  Scaleform::GFx::AS2::Value *v24; // eax
  Scaleform::GFx::ASStringNode *v25; // ecx
  Scaleform::GFx::AS2::Environment *v26; // [esp+10h] [ebp-3Ch]
  Scaleform::GFx::AS2::Environment *v27; // [esp+10h] [ebp-3Ch]
  Scaleform::GFx::AS2::Environment *v28; // [esp+10h] [ebp-3Ch]
  Scaleform::GFx::AS2::Environment *Env; // [esp+18h] [ebp-34h]
  Scaleform::GFx::AS2::Environment *v30; // [esp+18h] [ebp-34h]
  Scaleform::GFx::AS2::Environment *v31; // [esp+18h] [ebp-34h]
  const Scaleform::GFx::AS2::Environment *v32; // [esp+18h] [ebp-34h]
  Scaleform::GFx::AS2::Environment *v33; // [esp+18h] [ebp-34h]
  float miterLimit; // [esp+2Ch] [ebp-20h]
  Scaleform::GFx::InteractiveObject *v35; // [esp+30h] [ebp-1Ch]
  unsigned int joins; // [esp+34h] [ebp-18h]
  unsigned int caps; // [esp+38h] [ebp-14h]
  Scaleform::GFx::ASString result[2]; // [esp+3Ch] [ebp-10h] BYREF
  BOOL hinting; // [esp+44h] [ebp-8h]
  float lineWidth; // [esp+48h] [ebp-4h]

  v1 = (const Scaleform::GFx::AS2::FnCall *)LODWORD(fn);
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
    if ( v1->NArgs <= 0 )
    {
      Scaleform::GFx::AS2::AvmSprite::SetNoLine((Scaleform::GFx::AS2::AvmSprite *)(&v4->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                                 + v4->AvmObjOffset));
      return;
    }
    Env = v1->Env;
    v6 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
    lineWidth = Scaleform::GFx::AS2::Value::ToNumber(v6, Env);
    v7 = v1->NArgs <= 1;
    miterLimit = 3.0;
    v8 = -16777216;
    LOBYTE(hinting) = 0;
    caps = 0;
    joins = 0;
    if ( v7 )
      goto LABEL_45;
    v30 = v1->Env;
    v9 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
    v8 = Scaleform::GFx::AS2::Value::ToUInt32(v9, v30) | 0xFF000000;
    if ( v1->NArgs <= 2 )
      goto LABEL_45;
    v31 = v1->Env;
    v10 = Scaleform::GFx::AS2::FnCall::Arg(v1, 2);
    fn = Scaleform::GFx::AS2::Value::ToNumber(v10, v31);
    v11 = (unsigned int)&vostok::memory::s_CRT_arena[5574199] & v8;
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
        *(_QWORD *)&result[0].pNode = (__int64)fn;
        v8 = ((int)result[0].pNode << 24) | v11;
        if ( v1->NArgs > 3 )
        {
          v32 = v1->Env;
          v16 = Scaleform::GFx::AS2::FnCall::Arg(v1, 3);
          v17 = Scaleform::GFx::AS2::Value::ToBool(v16, v32);
          v7 = v1->NArgs <= 4;
          LOBYTE(hinting) = v17;
          if ( !v7 )
          {
            v26 = v1->Env;
            v18 = Scaleform::GFx::AS2::FnCall::Arg(v1, 4);
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
            if ( v1->NArgs > 5 )
            {
              v27 = v1->Env;
              v19 = Scaleform::GFx::AS2::FnCall::Arg(v1, 5);
              Scaleform::GFx::AS2::Value::ToStringImpl(v19, result, v27, -1, 0);
              Scaleform::GFx::ASString::operator=((Scaleform::GFx::ASString *)&fn, result);
              pNode = result[0].pNode;
              v21 = result[0].pNode->RefCount-- == 1;
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
              if ( v1->NArgs > 6 )
              {
                v28 = v1->Env;
                v22 = Scaleform::GFx::AS2::FnCall::Arg(v1, 6);
                Scaleform::GFx::AS2::Value::ToStringImpl(v22, result, v28, -1, 0);
                Scaleform::GFx::ASString::operator=((Scaleform::GFx::ASString *)&fn, result);
                v23 = result[0].pNode;
                v21 = result[0].pNode->RefCount-- == 1;
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
                if ( v1->NArgs > 7 )
                {
                  v33 = v1->Env;
                  v24 = Scaleform::GFx::AS2::FnCall::Arg(v1, 7);
                  miterLimit = Scaleform::GFx::AS2::Value::ToNumber(v24, v33);
                  if ( miterLimit < 1.0 )
                    miterLimit = 1.0;
                  if ( miterLimit > 255.0 )
                    miterLimit = 255.0;
                }
              }
            }
            v25 = (Scaleform::GFx::ASStringNode *)LODWORD(fn);
            v21 = (*(_DWORD *)(LODWORD(fn) + 12))-- == 1;
            if ( v21 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v25);
            v4 = v35;
          }
        }
LABEL_45:
        Scaleform::GFx::AS2::AvmSprite::SetLineStyle(
          (Scaleform::GFx::AS2::AvmSprite *)(&v4->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                           + v4->AvmObjOffset),
          lineWidth,
          v8,
          hinting,
          v3,
          caps,
          joins,
          miterLimit);
        return;
      }
    }
    v15 = fn;
    goto LABEL_14;
  }
}
