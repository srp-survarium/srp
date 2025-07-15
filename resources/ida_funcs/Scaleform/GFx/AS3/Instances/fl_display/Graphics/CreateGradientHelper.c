void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Graphics::CreateGradientHelper(
        Scaleform::GFx::AS3::Instances::fl_display::Graphics *this,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv,
        Scaleform::Render::ComplexFill *complexFill)
{
  Scaleform::GFx::ASStringNode *VStr; // esi
  const char *pData; // edi
  Scaleform::GFx::AS3::VM *pVM; // edi
  const Scaleform::GFx::AS3::VM::Error *v7; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  bool v9; // zf
  int v10; // eax
  Scaleform::GFx::AS3::Value::Extra v11; // eax
  int v12; // eax
  const Scaleform::Render::Matrix2x4<double> *Matrix; // eax
  Scaleform::GFx::ASStringNode *v14; // esi
  Scaleform::GFx::ASStringNode *v15; // edi
  bool v16; // al
  Scaleform::Render::GradientData *v17; // edi
  Scaleform::Render::GradientData *v18; // eax
  Scaleform::Render::GradientData *v19; // eax
  Scaleform::Render::ComplexFill *v20; // esi
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::Render::GradientData *v22; // eax
  unsigned int v23; // edi
  Scaleform::GFx::AS3::Impl::SparseArray *v24; // ebx
  Scaleform::GFx::AS3::Value *v25; // eax
  unsigned __int32 v26; // esi
  Scaleform::GFx::AS3::Value *v27; // eax
  unsigned int v28; // eax
  unsigned int v29; // esi
  Scaleform::GFx::AS3::Value *v30; // eax
  double v31; // st7
  bool v32; // c0
  bool v33; // c3
  double v34; // st7
  Scaleform::Render::GradientRecord *v35; // ecx
  double v36; // st7
  double v37; // st7
  const Scaleform::Render::Matrix2x4<float> *Inverse; // eax
  Scaleform::GFx::ASStringNode *v39; // ecx
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
    pVM = v47->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v53, eInvalidEnumError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v7);
    pNode = v53.Message.pNode;
    --v53.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    goto LABEL_6;
  }
  if ( (argv[1].Flags & 0x1F) - 12 > 3
    || (v43 = argv[1].value.VS._1, v10 = *(_DWORD *)(v43.VInt + 20), *(_DWORD *)(v10 + 60) != 7)
    || (*(_DWORD *)(v10 + 56) & 0x20) != 0
    || (argv[2].Flags & 0x1F) - 12 > 3
    || (VInt = (Scaleform::GFx::AS3::Impl::SparseArray *)argv[2].value.VS._1.VInt,
        v11.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)VInt->DefaultValue.Bonus,
        v11.pWeakProxy[7].pObject != (Scaleform::GFx::AS3::GASRefCountBase *)7)
    || (v11.pWeakProxy[7].RefCount & 0x20) != 0
    || (argv[3].Flags & 0x1F) - 12 > 3
    || (v53.ID = argv[3].value.VS._1.VInt, v12 = *(_DWORD *)(v53.ID + 20), *(_DWORD *)(v12 + 60) != 7)
    || (*(_DWORD *)(v12 + 56) & 0x20) != 0 )
  {
LABEL_6:
    v9 = VStr->RefCount-- == 1;
    if ( v9 )
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
    v14 = argv[5].value.VS._1.VStr;
    ++v14->RefCount;
    if ( argc > 6 )
    {
      v15 = argv[6].value.VS._1.VStr;
      ++v15->RefCount;
      v45.pNode = v15;
      v16 = Scaleform::GFx::ASString::operator==(&v45, "linearRGB");
      v9 = v15->RefCount-- == 1;
      linearRgb[0] = v16;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
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
    v9 = v14->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  }
  v17 = 0;
  v45.pNode = 0;
  if ( Scaleform::GFx::ASString::operator==(&v52, "radial") )
  {
    v45.pNode = (Scaleform::GFx::ASStringNode *)1;
    if ( 0.0 != VNumber )
      v45.pNode = (Scaleform::GFx::ASStringNode *)2;
  }
  v18 = (Scaleform::Render::GradientData *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::operator new(0x18u);
  if ( v18 )
  {
    Scaleform::Render::GradientData::GradientData(
      v18,
      (Scaleform::Render::GradientType)v45.pNode,
      *(_DWORD *)(v43.VInt + 32),
      linearRgb[0]);
    v17 = v19;
  }
  v20 = complexFill;
  pObject = (Scaleform::RefCountVImpl *)complexFill->pGradient.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v22 = v17;
  complexFill->pGradient.pObject = v17;
  if ( !v17 )
    goto LABEL_56;
  v23 = 0;
  v22->FocalRatio = VNumber;
  v24 = (Scaleform::GFx::AS3::Impl::SparseArray *)(v43.VInt + 32);
  if ( !*(_DWORD *)(v43.VInt + 32) )
    goto LABEL_51;
  VInt = (Scaleform::GFx::AS3::Impl::SparseArray *)((char *)VInt + 32);
  *(_DWORD *)linearRgb = v53.ID + 32;
  do
  {
    v25 = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Impl::SparseArray::At(v24, v23);
    Scaleform::GFx::AS3::Value::Convert2UInt32(v25, &v49, (unsigned int *)&v53);
    v26 = v53.ID | 0xFF000000;
    v27 = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Impl::SparseArray::At(VInt, v23);
    Scaleform::GFx::AS3::Value::Convert2Number(v27, &v48, &v55);
    v28 = (__int64)(v55 * 255.0);
    if ( v28 >= 0xFF )
      v28 = 255;
    v29 = (unsigned int)&vostok::memory::s_CRT_arena[5574199] & v26 | (v28 << 24);
    v30 = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Impl::SparseArray::At(
                                          *(Scaleform::GFx::AS3::Impl::SparseArray **)linearRgb,
                                          v23);
    Scaleform::GFx::AS3::Value::Convert2Number(v30, &v51, &v54);
    v41 = v54;
    v31 = v41;
    if ( v41 >= 255.0 )
    {
      v44 = 255.0;
    }
    else
    {
      v44 = v54;
      v32 = v31 > 0.0;
      v33 = 0.0 == v31;
      v34 = 0.0;
      if ( !v32 && !v33 )
        goto LABEL_49;
    }
    v34 = v44;
LABEL_49:
    v42 = v34;
    v35 = &complexFill->pGradient.pObject->pRecords[v23++];
    v35->Ratio = (int)v42;
    v35->ColorV.Raw = v29;
  }
  while ( v23 < v24->Length );
  v20 = complexFill;
LABEL_51:
  Scaleform::GFx::AS3::Instances::fl_display::Graphics::AcquirePath(v47, 1);
  Scaleform::Render::Matrix2x4<float>::Matrix2x4<float>((Scaleform::Render::Matrix2x4<float> *)&result);
  *(float *)&result.M[0][0] = v57.M[0][0];
  *(float *)&result.M[0][2] = v57.M[1][0];
  *((float *)&result.M[0][0] + 1) = v57.M[0][1];
  *((float *)&result.M[0][2] + 1) = v57.M[1][1];
  *((float *)&result.M[0][1] + 1) = v57.M[0][3] * 20.0;
  *((float *)&result.M[0][3] + 1) = 20.0 * v57.M[1][3];
  Scaleform::Render::Matrix2x4<float>::SetIdentity(&v20->ImageMatrix);
  Scaleform::Render::Matrix2x4<float>::AppendScaling(&v20->ImageMatrix, 0.000030517578);
  v36 = v20->ImageMatrix.M[0][3];
  if ( v45.pNode )
  {
    v20->ImageMatrix.M[0][3] = v36 + 0.5;
    v37 = v20->ImageMatrix.M[1][3] + 0.5;
  }
  else
  {
    v20->ImageMatrix.M[0][3] = v36 + 0.5;
    v37 = v20->ImageMatrix.M[1][3] + 0.0;
  }
  v20->ImageMatrix.M[1][3] = v37;
  Inverse = Scaleform::Render::Matrix2x4<float>::GetInverse(
              (Scaleform::Render::Matrix2x4<float> *)&result,
              (Scaleform::Render::Matrix2x4<float> *)&v57);
  Scaleform::Render::Matrix2x4<float>::Prepend(&v20->ImageMatrix, Inverse);
LABEL_56:
  v39 = v52.pNode;
  v9 = v52.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v39);
}
