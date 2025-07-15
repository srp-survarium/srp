bool __thiscall Scaleform::Render::ShapeMeshProvider::createNullMesh(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::VertexOutput *pout,
        unsigned int drawLayer,
        unsigned int meshGenFlags)
{
  Scaleform::Render::VertexOutput_vtbl *v4; // eax
  bool (__thiscall *BeginOutput)(Scaleform::Render::VertexOutput *, const Scaleform::Render::VertexOutput::Fill *, unsigned int, const Scaleform::Render::Matrix2x4<float> *); // edx
  bool result; // al
  _WORD v7[4]; // [esp+1Ch] [ebp-40h] BYREF
  _WORD v8[2]; // [esp+24h] [ebp-38h] BYREF
  int v9; // [esp+28h] [ebp-34h]
  Scaleform::Render::FillData v10; // [esp+2Ch] [ebp-30h] BYREF
  _DWORD v11[7]; // [esp+40h] [ebp-1Ch] BYREF

  v8[1] = 0;
  v7[0] = 0;
  v8[0] = 0;
  v9 = 0;
  v7[2] = 0;
  v7[1] = 0;
  Scaleform::Render::FillData::FillData(&v10, Fill_VColor);
  v4 = pout->__vftable;
  v11[2] = v10.pVFormat;
  BeginOutput = v4->BeginOutput;
  v11[0] = 1;
  v11[1] = 3;
  memset(&v11[3], 0, 16);
  result = BeginOutput(
             pout,
             (const Scaleform::Render::VertexOutput::Fill *)v11,
             1u,
             &Scaleform::Render::Matrix2x4<float>::Identity);
  if ( result )
  {
    pout->SetVertices(pout, 0, 0, v8, 1u);
    pout->SetIndices(pout, 0, 0, v7, 3u);
    pout->EndOutput(pout);
    return 1;
  }
  return result;
}
