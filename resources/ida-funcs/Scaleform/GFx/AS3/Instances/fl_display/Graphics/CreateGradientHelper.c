void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Graphics::CreateGradientHelper(
        Scaleform::GFx::AS3::Instances::fl_display::Graphics *this,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv,
        Scaleform::Render::ComplexFill *complexFill)
{
  Scaleform::GFx::ASStringNode *VStr; // edi
  const char *pData; // esi
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  bool v8; // zf
  int v9; // eax
  Scaleform::GFx::AS3::Value::Extra v10; // eax
  int v11; // eax
  const Scaleform::Render::Matrix2x4<double> *Matrix; // eax
  Scaleform::GFx::ASStringNode *v13; // esi
  Scaleform::GFx::ASStringNode *v14; // edi
  bool v15; // al
  Scaleform::Render::GradientData *v16; // edi
  Scaleform::Render::GradientData *v17; // eax
  Scaleform::Render::GradientData *v18; // eax
  Scaleform::Render::ComplexFill *v19; // esi
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::Render::GradientData *v21; // eax
  unsigned int v22; // edi
  Scaleform::GFx::AS3::Impl::SparseArray *v23; // ebx
  Scaleform::GFx::AS3::Value *v24; // eax
  unsigned __int32 v25; // esi
  Scaleform::GFx::AS3::Value *v26; // eax
  unsigned int v27; // eax
  int v28; // esi
  Scaleform::GFx::AS3::Value *v29; // eax
  double v30; // st7
  bool v31; // c0
  bool v32; // c3
  double v33; // st7
  Scaleform::Render::GradientRecord *v34; // ecx
  double v35; // st7
  double v36; // st7
  const Scaleform::Render::Matrix2x4<float> *Inverse; // eax
  Scaleform::GFx::ASStringNode *v38; // ecx
  Scaleform::StringDataPtr matrix_56; // [esp+5F0h] [ebp-D8h]
  float VNumber; // [esp+604h] [ebp-C4h]
  float v41; // [esp+604h] [ebp-C4h]
  float v42; // [esp+604h] [ebp-C4h]
  Scaleform::GFx::AS3::Value::V1U v43; // [esp+608h] [ebp-C0h]
  float v44; // [esp+608h] [ebp-C0h]
  Scaleform::GFx::ASString v45; // [esp+614h] [ebp-B4h] BYREF
  bool linearRgb[4]; // [esp+618h] [ebp-B0h]
  Scaleform::GFx::AS3::Instances::fl_display::Graphics *v47; // [esp+61Ch] [ebp-ACh]
  Scaleform::GFx::AS3::CheckResult v48; // [esp+622h] [ebp-A6h] BYREF
  Scaleform::GFx::AS3::CheckResult v49; // [esp+623h] [ebp-A5h] BYREF
  Scaleform::GFx::AS3::Impl::SparseArray *VInt; // [esp+624h] [ebp-A4h]
  Scaleform::GFx::AS3::CheckResult v51; // [esp+62Bh] [ebp-9Dh] BYREF
  Scaleform::GFx::ASString v52; // [esp+62Ch] [ebp-9Ch] BYREF
  Scaleform::GFx::AS3::VM::Error v53; // [esp+630h] [ebp-98h] BYREF
  long double v54; // [esp+638h] [ebp-90h] BYREF
  long double v55; // [esp+640h] [ebp-88h] BYREF
  Scaleform::Render::Matrix2x4<double> result; // [esp+648h] [ebp-80h] BYREF
  Scaleform::Render::Matrix2x4<double> v57; // [esp+688h] [ebp-40h] BYREF

  v47 = this;
  if ( argc < 4 )
    return;
  VStr = argv->value.VS._1.VStr;
  ++VStr->RefCount;
  pData = VStr->pData;
  v52.pNode = VStr;
  if ( strcmp(pData, "linear") && strcmp(pData, "radial") )
  {
    matrix_56.pStr = "type";
    matrix_56.Size = 4;
    Scaleform::GFx::AS3::VM::Error::Error(&v53, eInvalidEnumError, v47->pTraits.pObject->pVM, matrix_56);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(v47->pTraits.pObject->pVM, v6);
    pNode = v53.Message.pNode;
    --v53.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    goto LABEL_6;
  }
  if ( (argv[1].Flags & 0x1F) - 12 > 3
    || (v43 = argv[1].value.VS._1, v9 = *(_DWORD *)(v43.VInt + 20), *(_DWORD *)(v9 + 60) != 7)
    || (*(_DWORD *)(v9 + 56) & 0x20) != 0
    || (argv[2].Flags & 0x1F) - 12 > 3
    || (VInt = (Scaleform::GFx::AS3::Impl::SparseArray *)argv[2].value.VS._1.VInt,
        v10.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)VInt->DefaultValue.Bonus,
        v10.pWeakProxy[7].pObject != (Scaleform::GFx::AS3::GASRefCountBase *)7)
    || (v10.pWeakProxy[7].RefCount & 0x20) != 0
    || (argv[3].Flags & 0x1F) - 12 > 3
    || (v53.ID = argv[3].value.VS._1.VInt, v11 = *(_DWORD *)(v53.ID + 20), *(_DWORD *)(v11 + 60) != 7)
    || (*(_DWORD *)(v11 + 56) & 0x20) != 0 )
  {
LABEL_6:
    v8 = VStr->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
    return;
  }
  Scaleform::Render::Matrix2x4<double>::Matrix2x4<double>(&v57);
  if ( argc > 4
    && Scaleform::GFx::AS3::VM::IsOfType(
         v47->pTraits.pObject->pVM,
         argv + 4,
         "flash.geom.Matrix",
         v47->pTraits.pObject->pVM->CurrentDomain) )
  {
    Matrix = Scaleform::GFx::AS3::Instances::fl_geom::Matrix::GetMatrix(
               (Scaleform::GFx::AS3::Instances::fl_geom::Matrix *)argv[4].value.VS._1.VInt,
               &result);
    Scaleform::Render::Matrix2x4<double>::operator=(&v57, Matrix);
  }
  linearRgb[0] = 0;
  VNumber = 0.0;
  if ( argc > 5 )
  {
    v13 = argv[5].value.VS._1.VStr;
    ++v13->RefCount;
    if ( argc > 6 )
    {
      v14 = argv[6].value.VS._1.VStr;
      ++v14->RefCount;
      v45.pNode = v14;
      v15 = Scaleform::GFx::ASString::operator==(&v45, "linearRGB");
      v8 = v14->RefCount-- == 1;
      linearRgb[0] = v15;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      if ( argc > 7 )
      {
        VNumber = argv[7].value.VNumber;
        if ( Scaleform::GFx::NumberUtil::IsNaN(VNumber) )
        {
          VNumber = 0.0;
        }
        else if ( VNumber >= -1.0 )
        {
          if ( VNumber > 1.0 )
            VNumber = 1.0;
        }
        else
        {
          VNumber = -1.0;
        }
      }
    }
    v8 = v13->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  }
  v16 = 0;
  v45.pNode = 0;
  if ( Scaleform::GFx::ASString::operator==(&v52, "radial") )
  {
    v45.pNode = (Scaleform::GFx::ASStringNode *)1;
    if ( 0.0 != VNumber )
      v45.pNode = (Scaleform::GFx::ASStringNode *)2;
  }
  v17 = (Scaleform::Render::GradientData *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::operator new(0x18u);
  if ( v17 )
  {
    Scaleform::Render::GradientData::GradientData(
      v17,
      (Scaleform::Render::GradientType)v45.pNode,
      *(_DWORD *)(v43.VInt + 32),
      linearRgb[0]);
    v16 = v18;
  }
  v19 = complexFill;
  pObject = (Scaleform::RefCountVImpl *)complexFill->pGradient.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v21 = v16;
  complexFill->pGradient.pObject = v16;
  if ( !v16 )
    goto LABEL_56;
  v22 = 0;
  v21->FocalRatio = VNumber;
  v23 = (Scaleform::GFx::AS3::Impl::SparseArray *)(v43.VInt + 32);
  if ( !*(_DWORD *)(v43.VInt + 32) )
    goto LABEL_51;
  VInt = (Scaleform::GFx::AS3::Impl::SparseArray *)((char *)VInt + 32);
  *(_DWORD *)linearRgb = v53.ID + 32;
  do
  {
    v24 = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Impl::SparseArray::At(v23, v22);
    Scaleform::GFx::AS3::Value::Convert2UInt32(v24, &v49, (unsigned int *)&v53);
    v25 = v53.ID | 0xFF000000;
    v26 = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Impl::SparseArray::At(VInt, v22);
    Scaleform::GFx::AS3::Value::Convert2Number(v26, &v48, &v55);
    v27 = (__int64)(v55 * 255.0);
    if ( v27 >= 0xFF )
      v27 = 255;
    v28 = v25 & 0xFFFFFF | (v27 << 24);
    v29 = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Impl::SparseArray::At(
                                          *(Scaleform::GFx::AS3::Impl::SparseArray **)linearRgb,
                                          v22);
    Scaleform::GFx::AS3::Value::Convert2Number(v29, &v51, &v54);
    v41 = v54;
    v30 = v41;
    if ( v41 >= 255.0 )
    {
      v44 = 255.0;
    }
    else
    {
      v44 = v54;
      v31 = v30 > 0.0;
      v32 = 0.0 == v30;
      v33 = 0.0;
      if ( !v31 && !v32 )
        goto LABEL_49;
    }
    v33 = v44;
LABEL_49:
    v42 = v33;
    v34 = &complexFill->pGradient.pObject->pRecords[v22++];
    v34->Ratio = (int)v42;
    v34->ColorV.Raw = v28;
  }
  while ( v22 < v23->Length );
  v19 = complexFill;
LABEL_51:
  Scaleform::GFx::AS3::Instances::fl_display::Graphics::AcquirePath(v47, 1);
  Scaleform::Render::Matrix2x4<float>::Matrix2x4<float>((Scaleform::Render::Matrix2x4<float> *)&result);
  *(float *)&result.M[0][0] = v57.M[0][0];
  *(float *)&result.M[0][2] = v57.M[1][0];
  *((float *)&result.M[0][0] + 1) = v57.M[0][1];
  *((float *)&result.M[0][2] + 1) = v57.M[1][1];
  *((float *)&result.M[0][1] + 1) = v57.M[0][3] * 20.0;
  *((float *)&result.M[0][3] + 1) = 20.0 * v57.M[1][3];
  Scaleform::Render::Matrix2x4<float>::SetIdentity(&v19->ImageMatrix);
  Scaleform::Render::Matrix2x4<float>::AppendScaling(&v19->ImageMatrix, 0.000030517578);
  v35 = v19->ImageMatrix.M[0][3];
  if ( v45.pNode )
  {
    v19->ImageMatrix.M[0][3] = v35 + 0.5;
    v36 = v19->ImageMatrix.M[1][3] + 0.5;
  }
  else
  {
    v19->ImageMatrix.M[0][3] = v35 + 0.5;
    v36 = v19->ImageMatrix.M[1][3] + 0.0;
  }
  v19->ImageMatrix.M[1][3] = v36;
  Inverse = Scaleform::Render::Matrix2x4<float>::GetInverse(
              (Scaleform::Render::Matrix2x4<float> *)&result,
              (Scaleform::Render::Matrix2x4<float> *)&v57);
  Scaleform::Render::Matrix2x4<float>::Prepend(&v19->ImageMatrix, Inverse);
LABEL_56:
  v38 = v52.pNode;
  v8 = v52.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v38);
}
