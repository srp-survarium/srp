char __thiscall Scaleform::Render::TextMeshProvider::generateNullVectorMesh(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::VertexOutput *verOut)
{
  bool (__thiscall *BeginOutput)(Scaleform::Render::VertexOutput *, const Scaleform::Render::VertexOutput::Fill *, unsigned int, const Scaleform::Render::Matrix2x4<float> *); // edx
  char result; // al
  unsigned __int16 tri[4]; // [esp+1Ch] [ebp-30h] BYREF
  Scaleform::Render::VertexXY16iCF32 ver[1]; // [esp+24h] [ebp-28h] BYREF
  Scaleform::Render::VertexOutput::Fill vfill; // [esp+30h] [ebp-1Ch] BYREF

  tri[2] = 0;
  BeginOutput = verOut->BeginOutput;
  memset(ver, 0, 10);
  tri[1] = 0;
  tri[0] = 0;
  vfill.VertexCount = 1;
  vfill.IndexCount = 3;
  vfill.pFormat = &Scaleform::Render::VertexXY16iCF32::Format;
  memset(&vfill.FillIndex0, 0, 16);
  result = BeginOutput(verOut, &vfill, 1u, &Scaleform::Render::Matrix2x4<float>::Identity);
  if ( result )
  {
    verOut->SetVertices(verOut, 0, 0, ver, 1u);
    verOut->SetIndices(verOut, 0, 0, tri, 3u);
    verOut->EndOutput(verOut);
    return 1;
  }
  return result;
}
