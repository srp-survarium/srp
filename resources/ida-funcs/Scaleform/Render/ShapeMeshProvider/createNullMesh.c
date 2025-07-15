char __thiscall Scaleform::Render::ShapeMeshProvider::createNullMesh(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::VertexOutput *pout,
        unsigned int drawLayer,
        unsigned int meshGenFlags)
{
  Scaleform::Render::VertexOutput_vtbl *v4; // eax
  bool (__thiscall *BeginOutput)(Scaleform::Render::VertexOutput *, const Scaleform::Render::VertexOutput::Fill *, unsigned int, const Scaleform::Render::Matrix2x4<float> *); // edx
  char result; // al
  unsigned __int16 tri[4]; // [esp+1Ch] [ebp-40h] BYREF
  Scaleform::Render::VertexXY16iC32 ver[1]; // [esp+24h] [ebp-38h] BYREF
  Scaleform::Render::FillData fd; // [esp+2Ch] [ebp-30h] BYREF
  Scaleform::Render::VertexOutput::Fill vfill; // [esp+40h] [ebp-1Ch] BYREF

  ver[0].y = 0;
  tri[0] = 0;
  ver[0].x = 0;
  ver[0].Color = 0;
  tri[2] = 0;
  tri[1] = 0;
  Scaleform::Render::FillData::FillData(&fd, Fill_VColor);
  v4 = pout->__vftable;
  vfill.pFormat = fd.pVFormat;
  BeginOutput = v4->BeginOutput;
  vfill.VertexCount = 1;
  vfill.IndexCount = 3;
  memset(&vfill.FillIndex0, 0, 16);
  result = BeginOutput(pout, &vfill, 1u, &Scaleform::Render::Matrix2x4<float>::Identity);
  if ( result )
  {
    pout->SetVertices(pout, 0, 0, ver, 1u);
    pout->SetIndices(pout, 0, 0, tri, 3u);
    pout->EndOutput(pout);
    return 1;
  }
  return result;
}
