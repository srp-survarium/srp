int __thiscall Scaleform::Render::MorphInterpolator::GetStartingPos(Scaleform::Render::MorphInterpolator *this)
{
  char v1; // bl
  Scaleform::Render::MorphShapeData *pObject; // eax
  Scaleform::RefCountVImpl *p_ShapeData1; // esi
  Scaleform::RefCountVImpl *v4; // ecx
  int *p_pShapeData; // eax
  int v6; // edi
  Scaleform::RefCountVImpl *v8; // [esp+8h] [ebp-4h] BYREF

  v1 = 0;
  v8 = 0;
  pObject = this->pMorphData.pObject;
  if ( pObject )
  {
    p_ShapeData1 = (Scaleform::RefCountVImpl *)&pObject->ShapeData1;
    v1 = 1;
    if ( pObject != (Scaleform::Render::MorphShapeData *)-36 )
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)&pObject->ShapeData1);
    v4 = p_ShapeData1;
    v8 = p_ShapeData1;
    p_pShapeData = (int *)&v8;
  }
  else
  {
    p_pShapeData = (int *)&this->pShapeData;
    v4 = v8;
  }
  v6 = *p_pShapeData;
  if ( (v1 & 1) != 0 && v4 )
    Scaleform::RefCountImpl::Release(v4);
  return (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 24))(v6);
}
