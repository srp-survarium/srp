double __thiscall Scaleform::Render::TextMeshProvider::snapY(
        Scaleform::Render::TextMeshProvider *this,
        const Scaleform::Render::GlyphRunData *data)
{
  float NewLineX; // [esp+Ch] [ebp-8h]
  float v5; // [esp+10h] [ebp-4h]
  float v6; // [esp+10h] [ebp-4h]
  float v7; // [esp+10h] [ebp-4h]
  float NewLineY; // [esp+18h] [ebp+4h]
  float v9; // [esp+18h] [ebp+4h]

  NewLineX = data->NewLineX;
  NewLineY = data->NewLineY;
  v5 = data->DirMtx.M[1][1] * NewLineY + data->DirMtx.M[1][0] * NewLineX + data->DirMtx.M[1][3];
  v6 = v5 + 0.5;
  v7 = floor(v6);
  v9 = data->DirMtx.M[0][1] * NewLineY + data->DirMtx.M[0][0] * NewLineX + data->DirMtx.M[0][3];
  return (float)(v7 * data->InvMtx.M[1][1] + v9 * data->InvMtx.M[1][0] + data->InvMtx.M[1][3]);
}
