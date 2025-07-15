char __userpurge Scaleform::Render::TextMeshProvider::generateMask@<al>(
        Scaleform::Render::TextMeshProvider *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        Scaleform::Render::VertexOutput *verOut,
        const Scaleform::Render::TextMeshLayer *layer)
{
  unsigned int Start; // edx
  Scaleform::Render::TextMeshEntry *Data; // eax
  bool (__thiscall *BeginOutput)(Scaleform::Render::VertexOutput *, const Scaleform::Render::VertexOutput::Fill *, unsigned int, const Scaleform::Render::Matrix2x4<float> *); // eax
  char result; // al
  _WORD v9[14]; // [esp+28h] [ebp-58h] BYREF
  _DWORD v10[7]; // [esp+44h] [ebp-3Ch] BYREF
  Scaleform::Render::Matrix2x4<float> v11; // [esp+60h] [ebp-20h] BYREF

  Start = layer->Start;
  v11.M[0][0] = 1.0;
  Data = this->Entries.Data.Data;
  v11.M[0][1] = 0.0;
  v11.M[0][2] = 0.0;
  v11.M[0][3] = 0.0;
  v11.M[1][0] = 0.0;
  v11.M[1][2] = 0.0;
  v11.M[1][3] = 0.0;
  v11.M[1][1] = 1.0;
  Scaleform::Render::Matrix2x4<float>::SetRectToRect(
    &v11,
    -32764.0,
    -32764.0,
    32764.0,
    32764.0,
    Data[Start].EntryData.RasterData.Coord[0],
    Data[Start].EntryData.RasterData.Coord[1],
    Data[Start].EntryData.RasterData.Coord[2],
    Data[Start].EntryData.RasterData.Coord[3]);
  v9[7] = -32764;
  v9[6] = -32764;
  v9[9] = -32764;
  v9[12] = -32764;
  v9[10] = 32764;
  v9[13] = 32764;
  v9[1] = 1;
  v9[8] = 32764;
  v9[11] = 32764;
  v9[4] = 2;
  v9[2] = 2;
  v9[0] = 0;
  v9[3] = 0;
  BeginOutput = verOut->BeginOutput;
  v9[5] = 3;
  v10[0] = 4;
  v10[1] = 6;
  v10[2] = &Scaleform::Render::VertexXY16i::Format;
  memset(&v10[3], 0, 16);
  result = ((int (__thiscall *)(Scaleform::Render::VertexOutput *, _DWORD *, int, Scaleform::Render::Matrix2x4<float> *, int, int))BeginOutput)(
             verOut,
             v10,
             1,
             &v11,
             a2,
             a3);
  if ( result )
  {
    ((void (__thiscall *)(Scaleform::Render::VertexOutput *, _DWORD, _DWORD))verOut->SetVertices)(verOut, 0, 0);
    verOut->SetIndices(verOut, 0, 0, v9, 6u);
    verOut->EndOutput(verOut);
    return 1;
  }
  return result;
}
