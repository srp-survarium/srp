bool __thiscall Scaleform::Render::TextMeshProvider::generateNullVectorMesh(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::VertexOutput *verOut)
{
  bool (__thiscall *BeginOutput)(Scaleform::Render::VertexOutput *, const Scaleform::Render::VertexOutput::Fill *, unsigned int, const Scaleform::Render::Matrix2x4<float> *); // edx
  bool result; // al
  _WORD v4[4]; // [esp+1Ch] [ebp-30h] BYREF
  _WORD v5[2]; // [esp+24h] [ebp-28h] BYREF
  int v6; // [esp+28h] [ebp-24h]
  char v7; // [esp+2Ch] [ebp-20h]
  char v8; // [esp+2Dh] [ebp-1Fh]
  _DWORD v9[7]; // [esp+30h] [ebp-1Ch] BYREF

  v4[2] = 0;
  BeginOutput = verOut->BeginOutput;
  v5[0] = 0;
  v4[1] = 0;
  v5[1] = 0;
  v4[0] = 0;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9[0] = 1;
  v9[1] = 3;
  v9[2] = &Scaleform::Render::VertexXY16iCF32::Format;
  memset(&v9[3], 0, 16);
  result = BeginOutput(
             verOut,
             (const Scaleform::Render::VertexOutput::Fill *)v9,
             1u,
             &Scaleform::Render::Matrix2x4<float>::Identity);
  if ( result )
  {
    verOut->SetVertices(verOut, 0, 0, v5, 1u);
    verOut->SetIndices(verOut, 0, 0, v4, 3u);
    verOut->EndOutput(verOut);
    return 1;
  }
  return result;
}
