void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteCreateGradient(
        const Scaleform::GFx::AS2::FnCall *fn,
        Scaleform::Render::ComplexFill *complexFill)
{
  Scaleform::GFx::AS2::Value *v2; // ecx
  Scaleform::GFx::AS2::Environment *Env; // edx
  Scaleform::GFx::AS2::Value *v4; // eax
  Scaleform::GFx::AS2::Object *v5; // eax
  Scaleform::GFx::AS2::Object *v6; // edi
  Scaleform::GFx::AS2::Value *v7; // eax
  Scaleform::GFx::AS2::Object *v8; // eax
  Scaleform::GFx::AS2::Object *v9; // edi
  bool v10; // cc
  Scaleform::GFx::AS2::Object *v11; // ebx
  Scaleform::GFx::AS2::Value *v12; // eax
  Scaleform::GFx::AS2::Object *v13; // eax
  Scaleform::GFx::AS2::Object *v14; // edi
  int RootIndex; // eax
  Scaleform::GFx::ASStringNode *p_StringContext; // ebx
  Scaleform::GFx::AS2::Value *v17; // eax
  Scaleform::GFx::ASStringNode *v18; // eax
  unsigned int HashFlags; // edx
  Scaleform::GFx::AS2::ObjectInterface *p_HashFlags; // edi
  const Scaleform::Render::Matrix2x4<float> *Matrix; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v23; // zf
  Scaleform::GFx::AS2::Value *v24; // eax
  Scaleform::GFx::AS2::Value *v25; // eax
  bool v26; // al
  Scaleform::GFx::ASStringNode *v27; // ecx
  Scaleform::GFx::ASStringNode *v28; // ecx
  Scaleform::Render::GradientData *v29; // ebx
  Scaleform::Render::GradientData *v30; // eax
  Scaleform::Render::GradientData *v31; // eax
  Scaleform::Render::ComplexFill *v32; // edi
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::Render::GradientData *v34; // eax
  signed int v35; // ebx
  unsigned int v36; // edi
  int v37; // edi
  double v38; // st7
  bool v39; // c0
  bool v40; // c3
  double v41; // st7
  double v42; // st7
  Scaleform::GFx::AS2::RefCountCollector<323> *pRCC; // eax
  unsigned int v44; // edi
  double v45; // st7
  bool v46; // c0
  bool v47; // c3
  double v48; // st7
  Scaleform::Render::GradientRecord *v49; // ecx
  double v50; // st7
  double v51; // st7
  const Scaleform::Render::Matrix2x4<float> *Inverse; // eax
  Scaleform::GFx::ASStringNode *v53; // ecx
  Scaleform::GFx::AS2::Environment *v54; // [esp-4h] [ebp-9Ch]
  Scaleform::GFx::AS2::Environment *v55; // [esp-4h] [ebp-9Ch]
  Scaleform::GFx::AS2::Environment *v56; // [esp-4h] [ebp-9Ch]
  Scaleform::GFx::AS2::Environment *radians; // [esp+4h] [ebp-94h]
  Scaleform::GFx::AS2::Environment *radiansa; // [esp+4h] [ebp-94h]
  Scaleform::GFx::AS2::Environment *radiansb; // [esp+4h] [ebp-94h]
  Scaleform::GFx::AS2::Environment *radiansc; // [esp+4h] [ebp-94h]
  Scaleform::GFx::ASStringNode *radiansd; // [esp+4h] [ebp-94h]
  Scaleform::GFx::AS2::Environment *radianse; // [esp+4h] [ebp-94h]
  float v63; // [esp+1Ch] [ebp-7Ch]
  float v64; // [esp+1Ch] [ebp-7Ch]
  Scaleform::GFx::AS2::Object *v65; // [esp+20h] [ebp-78h]
  float v66; // [esp+24h] [ebp-74h]
  float v67; // [esp+24h] [ebp-74h]
  float v68; // [esp+24h] [ebp-74h]
  float v69; // [esp+24h] [ebp-74h]
  Scaleform::GFx::ASString v70; // [esp+28h] [ebp-70h] BYREF
  Scaleform::Render::GradientType type; // [esp+2Ch] [ebp-6Ch] BYREF
  Scaleform::GFx::ASString sx[2]; // [esp+30h] [ebp-68h] BYREF
  Scaleform::GFx::ASString v73; // [esp+3Ch] [ebp-5Ch] BYREF
  Scaleform::GFx::AS2::Object *v74; // [esp+40h] [ebp-58h]
  Scaleform::GFx::AS2::Object *v75; // [esp+44h] [ebp-54h]
  Scaleform::GFx::AS2::Value v76; // [esp+48h] [ebp-50h] BYREF
  Scaleform::Render::Matrix2x4<float> v77; // [esp+58h] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> result; // [esp+78h] [ebp-20h] BYREF

  v2 = 0;
  *(float *)&type = 0.0;
  if ( fn->NArgs <= 0 )
    return;
  Env = fn->Env;
  if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
    v2 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
  Scaleform::GFx::AS2::Value::ToStringImpl(v2, &v73, Env, -1, 0);
  if ( fn->NArgs <= 1 )
    goto LABEL_77;
  radians = fn->Env;
  v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
  v5 = Scaleform::GFx::AS2::Value::ToObject(v4, radians);
  v6 = v5;
  if ( !v5 )
    goto LABEL_77;
  if ( v5->GetObjectType(&v5->Scaleform::GFx::AS2::ObjectInterface) != Object_Array )
    goto LABEL_77;
  v65 = v6;
  if ( fn->NArgs <= 2 )
    goto LABEL_77;
  radiansa = fn->Env;
  v7 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
  v8 = Scaleform::GFx::AS2::Value::ToObject(v7, radiansa);
  v9 = v8;
  if ( !v8 )
    goto LABEL_77;
  if ( v8->GetObjectType(&v8->Scaleform::GFx::AS2::ObjectInterface) != Object_Array )
    goto LABEL_77;
  v10 = fn->NArgs <= 3;
  v11 = v9;
  v74 = v9;
  if ( v10 )
    goto LABEL_77;
  radiansb = fn->Env;
  v12 = Scaleform::GFx::AS2::FnCall::Arg(fn, 3);
  v13 = Scaleform::GFx::AS2::Value::ToObject(v12, radiansb);
  v14 = v13;
  if ( !v13 )
    goto LABEL_77;
  if ( v13->GetObjectType(&v13->Scaleform::GFx::AS2::ObjectInterface) != Object_Array )
    goto LABEL_77;
  v10 = fn->NArgs <= 4;
  v75 = v14;
  if ( v10 )
    goto LABEL_77;
  RootIndex = v65[1].RootIndex;
  if ( RootIndex <= 0 || RootIndex != v11[1].RootIndex || RootIndex != v14[1].RootIndex )
    goto LABEL_77;
  Scaleform::Render::Matrix2x4<float>::Matrix2x4<float>(&v77);
  radiansc = fn->Env;
  v76.T.Type = 0;
  p_StringContext = (Scaleform::GFx::ASStringNode *)&radiansc->StringContext;
  v17 = Scaleform::GFx::AS2::FnCall::Arg(fn, 4);
  v18 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::AS2::Value::ToObject(v17, radiansc);
  HashFlags = v18->HashFlags;
  p_HashFlags = (Scaleform::GFx::AS2::ObjectInterface *)&v18->HashFlags;
  sx[0].pNode = v18;
  if ( (*(int (__thiscall **)(unsigned int *))(HashFlags + 8))(&v18->HashFlags) == 15 )
  {
    Matrix = Scaleform::GFx::AS2::MatrixObject::GetMatrix(
               (Scaleform::GFx::AS2::MatrixObject *)sx[0].pNode,
               &result,
               fn->Env);
    Scaleform::Render::Matrix2x4<float>::operator=(&v77, Matrix);
  }
  else
  {
    if ( !Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(p_HashFlags, p_StringContext, "matrixType", &v76)
      || (v54 = fn->Env,
          type = GradientRadial,
          Scaleform::GFx::AS2::Value::ToStringImpl(&v76, &v70, v54, -1, 0),
          LOBYTE(v63) = 1,
          !Scaleform::GFx::ASString::operator==(&v70, "box")) )
    {
      LOBYTE(v63) = 0;
    }
    if ( (type & 1) != 0 )
    {
      pNode = v70.pNode;
      v23 = v70.pNode->RefCount-- == 1;
      if ( v23 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    if ( LOBYTE(v63) )
    {
      v64 = 0.0;
      v66 = 0.0;
      *(float *)&type = 100.0;
      *(float *)&v70.pNode = 100.0;
      *(float *)&sx[0].pNode = 0.0;
      if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(p_HashFlags, p_StringContext, "x", &v76) )
        v64 = Scaleform::GFx::AS2::Value::ToNumber(&v76, fn->Env);
      if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(p_HashFlags, p_StringContext, "y", &v76) )
        v66 = Scaleform::GFx::AS2::Value::ToNumber(&v76, fn->Env);
      if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(p_HashFlags, p_StringContext, "w", &v76) )
        *(float *)&type = Scaleform::GFx::AS2::Value::ToNumber(&v76, fn->Env);
      if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(p_HashFlags, p_StringContext, "h", &v76) )
        *(float *)&v70.pNode = Scaleform::GFx::AS2::Value::ToNumber(&v76, fn->Env);
      if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(p_HashFlags, p_StringContext, "r", &v76) )
        *(float *)&sx[0].pNode = Scaleform::GFx::AS2::Value::ToNumber(&v76, fn->Env);
      v63 = *(float *)&type * 0.5 + v64;
      v67 = 0.5 * *(float *)&v70.pNode + v66;
      Scaleform::Render::Matrix2x4<float>::AppendRotation(&v77, *(float *)&sx[0].pNode);
      *(float *)&sx[0].pNode = *(float *)&v70.pNode * 0.0006103515625;
      radiansd = sx[0].pNode;
      *(float *)&sx[0].pNode = 0.0006103515625 * *(float *)&type;
      Scaleform::Render::Matrix2x4<float>::AppendScaling(&v77, *(float *)&sx[0].pNode, *(float *)&radiansd);
      v77.M[0][3] = v77.M[0][3] + v63;
      v77.M[1][3] = v77.M[1][3] + v67;
    }
    else
    {
      if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(
             p_HashFlags,
             p_StringContext,
             (char *)&stru_809F70,
             &v76) )
      {
        *(float *)&sx[0].pNode = Scaleform::GFx::AS2::Value::ToNumber(&v76, fn->Env);
        v77.M[0][0] = *(float *)&sx[0].pNode * 0.0006103515625;
      }
      if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(p_HashFlags, p_StringContext, "d", &v76) )
      {
        *(float *)&sx[0].pNode = Scaleform::GFx::AS2::Value::ToNumber(&v76, fn->Env);
        v77.M[0][1] = *(float *)&sx[0].pNode * 0.0006103515625;
      }
      if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(p_HashFlags, p_StringContext, "g", &v76) )
        v77.M[0][3] = Scaleform::GFx::AS2::Value::ToNumber(&v76, fn->Env);
      if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(p_HashFlags, p_StringContext, "b", &v76) )
      {
        *(float *)&sx[0].pNode = Scaleform::GFx::AS2::Value::ToNumber(&v76, fn->Env);
        v77.M[1][0] = *(float *)&sx[0].pNode * 0.0006103515625;
      }
      if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(p_HashFlags, p_StringContext, "e", &v76) )
      {
        *(float *)&sx[0].pNode = Scaleform::GFx::AS2::Value::ToNumber(&v76, fn->Env);
        v77.M[1][1] = *(float *)&sx[0].pNode * 0.0006103515625;
      }
      if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(p_HashFlags, p_StringContext, "h", &v76) )
        v77.M[1][3] = Scaleform::GFx::AS2::Value::ToNumber(&v76, fn->Env);
    }
  }
  v10 = fn->NArgs <= 5;
  LOBYTE(v70.pNode) = 0;
  if ( !v10 )
  {
    v55 = fn->Env;
    v24 = Scaleform::GFx::AS2::FnCall::Arg(fn, 5);
    Scaleform::GFx::AS2::Value::ToStringImpl(v24, (Scaleform::GFx::ASString *)&type, v55, -1, 0);
    if ( fn->NArgs > 6 )
    {
      v56 = fn->Env;
      v25 = Scaleform::GFx::AS2::FnCall::Arg(fn, 6);
      Scaleform::GFx::AS2::Value::ToStringImpl(v25, sx, v56, -1, 0);
      v26 = Scaleform::GFx::ASString::operator==(sx, "linearRGB");
      v27 = sx[0].pNode;
      v23 = sx[0].pNode->RefCount-- == 1;
      LOBYTE(v70.pNode) = v26;
      if ( v23 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v27);
    }
    v28 = (Scaleform::GFx::ASStringNode *)type;
    v23 = (*(_DWORD *)(type + 12))-- == 1;
    if ( v23 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v28);
  }
  v29 = 0;
  type = Scaleform::GFx::ASString::operator==(&v73, "radial");
  v30 = (Scaleform::Render::GradientData *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::operator new(0x18u);
  if ( v30 )
  {
    Scaleform::Render::GradientData::GradientData(v30, type, v65[1].RootIndex, (bool)v70.pNode);
    v29 = v31;
  }
  v32 = complexFill;
  pObject = (Scaleform::RefCountVImpl *)complexFill->pGradient.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v34 = v29;
  complexFill->pGradient.pObject = v29;
  if ( !v29 )
    goto LABEL_75;
  v35 = 0;
  v34->FocalRatio = 0.0;
  if ( (int)v65[1].RootIndex <= 0 )
    goto LABEL_69;
  do
  {
    v36 = Scaleform::GFx::AS2::Value::ToUInt32(
            (Scaleform::GFx::AS2::Value *)(&v65[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$C9E2C53B7BF33D1B05D56CCE19B38030::__vftable)[v35],
            fn->Env)
        | 0xFF000000;
    *(float *)&sx[0].pNode = Scaleform::GFx::AS2::Value::ToNumber(
                               (Scaleform::GFx::AS2::Value *)(&v74[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$C9E2C53B7BF33D1B05D56CCE19B38030::__vftable)[v35],
                               fn->Env);
    v37 = v36 & 0xFFFFFF;
    *(float *)&sx[0].pNode = *(float *)&sx[0].pNode * 255.0 / 100.0;
    v38 = *(float *)&sx[0].pNode;
    if ( *(float *)&sx[0].pNode >= 255.0 )
    {
      *(float *)&sx[0].pNode = 255.0;
    }
    else
    {
      v39 = v38 > 0.0;
      v40 = 0.0 == v38;
      v41 = 0.0;
      if ( !v39 && !v40 )
        goto LABEL_64;
    }
    v41 = *(float *)&sx[0].pNode;
LABEL_64:
    *(float *)&sx[0].pNode = v41;
    v42 = *(float *)&sx[0].pNode;
    sx[0].pNode = (Scaleform::GFx::ASStringNode *)(LOWORD(v63) | 0xC00);
    pRCC = v75[1].pRCC;
    radianse = fn->Env;
    *(_QWORD *)&sx[0].pNode = (__int64)v42;
    v44 = ((unsigned int)(__int64)v42 << 24) | v37;
    v68 = Scaleform::GFx::AS2::Value::ToNumber((Scaleform::GFx::AS2::Value *)(&pRCC->__vftable)[v35], radianse);
    v45 = v68;
    if ( v68 >= 255.0 )
    {
      *(float *)&sx[0].pNode = 255.0;
    }
    else
    {
      *(float *)&sx[0].pNode = v68;
      v46 = v45 > 0.0;
      v47 = 0.0 == v45;
      v48 = 0.0;
      if ( !v46 && !v47 )
        goto LABEL_67;
    }
    v48 = *(float *)&sx[0].pNode;
LABEL_67:
    v69 = v48;
    v49 = &complexFill->pGradient.pObject->pRecords[v35++];
    sx[0].pNode = (Scaleform::GFx::ASStringNode *)(int)v69;
    v49->Ratio = (unsigned __int8)sx[0].pNode;
    v49->ColorV.Raw = v44;
  }
  while ( v35 < (signed int)v65[1].RootIndex );
  v32 = complexFill;
LABEL_69:
  v77.M[0][3] = v77.M[0][3] * 20.0;
  v77.M[1][3] = 20.0 * v77.M[1][3];
  Scaleform::Render::Matrix2x4<float>::SetIdentity(&v32->ImageMatrix);
  Scaleform::Render::Matrix2x4<float>::AppendScaling(&v32->ImageMatrix, 0.000030517578);
  v50 = v32->ImageMatrix.M[0][3];
  if ( *(float *)&type == 0.0 )
  {
    v32->ImageMatrix.M[0][3] = v50 + 0.5;
    v51 = v32->ImageMatrix.M[1][3] + 0.0;
  }
  else
  {
    v32->ImageMatrix.M[0][3] = v50 + 0.5;
    v51 = v32->ImageMatrix.M[1][3] + 0.5;
  }
  v32->ImageMatrix.M[1][3] = v51;
  Inverse = Scaleform::Render::Matrix2x4<float>::GetInverse(&v77, &result);
  Scaleform::Render::Matrix2x4<float>::Prepend(&v32->ImageMatrix, Inverse);
LABEL_75:
  if ( v76.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v76);
LABEL_77:
  v53 = v73.pNode;
  v23 = v73.pNode->RefCount-- == 1;
  if ( v23 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v53);
}
