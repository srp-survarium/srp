char __thiscall Scaleform::Render::TextMeshProvider::GetData(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::MeshBase *mesh,
        Scaleform::Render::VertexOutput *verOut,
        char meshGenFlags)
{
  Scaleform::Render::TextMeshLayer *Data; // edx
  Scaleform::Render::Renderer2DImpl *pRenderer2D; // esi
  unsigned int Layer; // eax
  const Scaleform::Render::TextMeshLayer *v7; // edx
  unsigned int Start; // eax
  Scaleform::Render::TextMeshEntry *v9; // eax
  int Type; // edi
  char result; // al
  Scaleform::Render::Matrix2x4<float> mtx; // [esp+28h] [ebp-20h] BYREF

  Data = this->Layers.Data.Data;
  pRenderer2D = mesh->pRenderer2D;
  mtx.M[0][0] = this->HeightRatio;
  Layer = mesh->Layer;
  mtx.M[0][1] = 0.0;
  v7 = &Data[Layer];
  mtx.M[0][2] = 0.0;
  Start = v7->Start;
  mtx.M[0][3] = 0.0;
  mtx.M[1][0] = 0.0;
  v9 = &this->Entries.Data.Data[Start];
  mtx.M[1][2] = 0.0;
  mtx.M[1][3] = 0.0;
  Type = v7->Type;
  mtx.M[1][1] = mtx.M[0][0];
  switch ( Type )
  {
    case 0:
      result = Scaleform::Render::TextMeshProvider::generateRectangle(
                 this,
                 pRenderer2D,
                 verOut,
                 &mtx,
                 v9->EntryData.RasterData.Coord,
                 v9->mColor,
                 v9->EntryData.BackgroundData.BorderColor,
                 meshGenFlags);
      break;
    case 1:
      result = Scaleform::Render::TextMeshProvider::generateSelection(this, pRenderer2D, verOut, v7, &mtx, meshGenFlags);
      break;
    case 2:
    case 3:
    case 4:
      result = Scaleform::Render::TextMeshProvider::generateRasterMesh(this, verOut, v7);
      break;
    case 5:
    case 6:
      result = Scaleform::Render::TextMeshProvider::generatePackedMesh(this, verOut, v7);
      break;
    case 7:
      result = Scaleform::Render::TextMeshProvider::generateImageMesh(this, verOut, v7);
      break;
    case 9:
    case 13:
      result = Scaleform::Render::TextMeshProvider::generateUnderlines(
                 this,
                 pRenderer2D,
                 verOut,
                 v7,
                 &mtx,
                 meshGenFlags);
      break;
    case 10:
      result = Scaleform::Render::TextMeshProvider::generateRectangle(
                 this,
                 pRenderer2D,
                 verOut,
                 &mtx,
                 v9->EntryData.RasterData.Coord,
                 v9->mColor,
                 0,
                 meshGenFlags);
      break;
    case 11:
      result = Scaleform::Render::TextMeshProvider::generateMask(this, Type, (int)pRenderer2D, verOut, v7);
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
